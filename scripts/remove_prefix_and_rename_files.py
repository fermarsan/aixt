#!/usr/bin/env python3
"""
remove_prefix_and_rename_files.py

Utility to remove a leading prefix from child directory names under one or more
parent directories, and to rename files inside those directories to match the
directory name.

Behavior:
- For each provided parent directory, examines its immediate child directories.
- If a child's name starts with the provided prefix, computes a new name that
  removes that leading prefix.
- Attempts to rename the child directory to the new name:
  - If the lowercase/new-name target does not exist: rename directly (or case-only safe
    rename when necessary).
  - If the target exists and refers to the same entry (case-only difference): perform
    a safe case-only rename.
  - If the target exists and is a different entry: skip and report conflict.
- After a directory is (or already is) present with the final name, optionally
  renames files inside the directory that match the configured extensions so
  their filename matches the directory name (optionally lowercased).
- Supports dry-run (default) and `--apply` to perform changes.
- Does not overwrite different existing files; reports conflicts.

Usage:
    python3 aixt/scripts/remove_prefix_and_rename_files.py \
        --parents examples/m5stack/fire,examples/arduino/uno \
        --prefix FIRE_ \
        --exts .v \
        [--apply] [--lower-files] [--verbose]

Notes:
- The script operates on immediate children of the parent directories. It does
  not traverse arbitrarily deep to rename directories (only the immediate child
  directories of each parent are considered for prefix removal).
- File renames operate recursively within each affected child directory.
- Be careful when running with `--apply`; it's recommended to run without it
  first to see a dry-run report.
"""

from __future__ import annotations

import argparse
import os
import sys
import uuid
from pathlib import Path
from typing import List, Tuple


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(
        description="Remove a leading prefix from child directories and rename files inside them."
    )
    p.add_argument(
        "--parents",
        type=str,
        required=True,
        help="Comma-separated list of parent directories to scan (relative to repo root or absolute).",
    )
    p.add_argument(
        "--prefix",
        type=str,
        required=True,
        help="Leading prefix string to remove from child directory names (e.g. 'FIRE_').",
    )
    p.add_argument(
        "--exts",
        type=str,
        default=".v",
        help="Comma-separated list of file extensions to rename inside renamed directories (default: .v). Example: .v,.sim1",
    )
    p.add_argument(
        "--apply",
        action="store_true",
        help="Perform the renames. Without this flag the script runs as a dry-run.",
    )
    p.add_argument(
        "--lower-files",
        action="store_true",
        help="Also convert target file names to lowercase when renaming files.",
    )
    p.add_argument(
        "--verbose",
        action="store_true",
        help="Verbose output.",
    )
    return p.parse_args()


def is_same_path(a: Path, b: Path) -> bool:
    try:
        return a.exists() and b.exists() and os.path.samefile(a, b)
    except Exception:
        return False


def safe_case_only_rename(src: Path, dst: Path, apply: bool) -> Tuple[bool, str]:
    """
    Safely handle case-only renames (or filesystems that prevent direct case-only rename)
    by renaming to a temporary name in the same directory and then replacing the
    temporary name to the destination.
    Returns (success, message).
    """
    parent = dst.parent
    tmp = parent / (f".tmp_rename_{uuid.uuid4().hex}")
    if not apply:
        return True, f"[dry-run] would case-only rename {src} -> {dst} via {tmp}"
    try:
        src.rename(tmp)
        # Use replace to overwrite atomically where possible
        tmp.replace(dst)
        return True, f"Renamed (case-only) {src} -> {dst}"
    except Exception as exc:
        # Try to roll back if tmp exists and src missing
        try:
            if tmp.exists() and not src.exists():
                tmp.rename(src)
        except Exception:
            pass
        return False, f"Failed case-only rename {src} -> {dst}: {exc}"


def rename_directory(src: Path, dst: Path, apply: bool) -> Tuple[bool, str]:
    """
    Rename directory src -> dst handling case-only rename and conflicts.
    Returns (success, message).
    """
    if not dst.exists():
        if not apply:
            return True, f"[dry-run] would rename dir {src} -> {dst}"
        try:
            src.rename(dst)
            return True, f"Renamed dir {src} -> {dst}"
        except OSError:
            ok, msg = safe_case_only_rename(src, dst, apply=True)
            return ok, msg
        except Exception as exc:
            return False, f"Failed to rename dir {src} -> {dst}: {exc}"

    # dst exists
    try:
        if is_same_path(src, dst):
            ok, msg = safe_case_only_rename(src, dst, apply)
            return ok, msg
    except Exception:
        pass

    return (
        False,
        f"Target directory exists and is different; skipping rename {src} -> {dst}",
    )


def rename_file_to_match_dir(
    file_path: Path,
    target_basename: str,
    exts: List[str],
    apply: bool,
    lower_files: bool,
) -> Tuple[bool, str]:
    """
    If file_path has an extension in exts (case-insensitive), rename it so its
    base name equals target_basename (optionally lowercased). The extension is
    kept as-is (but can be normalized to lowercase).
    Returns (success, message).
    """
    suffix = file_path.suffix  # keeps original extension's case
    if suffix.lower() not in [e.lower() for e in exts]:
        return True, f"Skipped (extension not targeted): {file_path}"

    # Choose target filename
    base = target_basename.lower() if lower_files else target_basename
    # Normalize extension to lower-case for consistency
    ext = suffix.lower()
    dst = file_path.with_name(base + ext)

    if file_path == dst:
        return True, f"Already matching: {file_path}"

    if not dst.exists():
        if not apply:
            return True, f"[dry-run] would rename file {file_path} -> {dst}"
        try:
            file_path.rename(dst)
            return True, f"Renamed file {file_path} -> {dst}"
        except OSError:
            # attempt case-only safe rename
            ok, msg = safe_case_only_rename(file_path, dst, apply=True)
            return ok, msg
        except Exception as exc:
            return False, f"Failed to rename file {file_path} -> {dst}: {exc}"

    # Destination exists
    try:
        if is_same_path(file_path, dst):
            ok, msg = safe_case_only_rename(file_path, dst, apply)
            return ok, msg
    except Exception:
        pass

    return (
        False,
        f"Conflict: target file exists and is different, skipping {file_path} -> {dst}",
    )


def process_parent(
    parent: Path,
    prefix: str,
    exts: List[str],
    apply: bool,
    lower_files: bool,
    verbose: bool,
    summary: dict,
):
    """
    Process a single parent directory: examine its immediate child directories and
    remove prefix from any child's name that starts with the prefix. Then rename
    files within renamed (or existing) directories to match their directory name.
    """
    if not parent.exists() or not parent.is_dir():
        summary["missing_parents"].append(str(parent))
        if verbose:
            print(f"Skipping missing parent: {parent}")
        return

    for child in sorted(parent.iterdir()):
        if not child.is_dir():
            continue

        name = child.name
        if not name.startswith(prefix):
            # Not a target for directory rename; still optionally process files
            target_dir = child
            renamed_dir = False
        else:
            new_name = name[len(prefix) :]
            if not new_name:
                summary["skipped_empty_target"].append(str(child))
                if verbose:
                    print(f"Skipping rename of {child}: new name would be empty")
                continue
            dst = child.with_name(new_name)
            ok, msg = rename_directory(child, dst, apply)
            if verbose:
                print(msg)
            if ok:
                summary["dirs_renamed"].append((str(child), str(dst)))
                target_dir = dst
                renamed_dir = True
            else:
                summary["dir_rename_conflicts"].append((str(child), str(dst), msg))
                # If we couldn't rename due to conflict, skip further file renames for this dir
                if (
                    "skipping" in msg
                    or "Target directory exists and is different" in msg
                ):
                    if verbose:
                        print(
                            f"Skipping files inside {child} due to directory rename conflict"
                        )
                    continue
                # If the rename failed for another reason, still attempt to use dst if it exists
                if dst.exists() and dst.is_dir():
                    target_dir = dst
                    renamed_dir = True
                else:
                    # Keep original as target if dst not usable
                    target_dir = child
                    renamed_dir = False

        # Now rename files inside target_dir matching extensions to match directory name
        if not target_dir.exists() or not target_dir.is_dir():
            if verbose:
                print(f"Target directory not available for file renames: {target_dir}")
            continue

        # Walk recursively inside the directory for files to rename
        for dirpath, _, filenames in os.walk(target_dir):
            dirp = Path(dirpath)
            # Use directory's final name as the base
            final_dir_name = Path(dirpath).name
            for fn in filenames:
                p = dirp / fn
                # Only process files with the selected extensions (case-insensitive)
                if p.suffix.lower() not in [e.lower() for e in exts]:
                    continue
                ok, msg = rename_file_to_match_dir(
                    p, final_dir_name, exts, apply, lower_files
                )
                if ok:
                    summary["files_renamed"].append((str(p), msg))
                else:
                    summary["file_rename_conflicts"].append((str(p), msg))
                if verbose:
                    print(msg)


def main() -> int:
    args = parse_args()
    parents_arg = [p.strip() for p in args.parents.split(",") if p.strip()]
    parents = [Path(p) for p in parents_arg]
    prefix = args.prefix
    exts = [
        e if e.startswith(".") else ("." + e)
        for e in (x.strip() for x in args.exts.split(","))
    ]
    apply = args.apply
    lower_files = args.lower_files
    verbose = args.verbose

    summary = {
        "missing_parents": [],
        "dirs_renamed": [],  # list of (old, new)
        "dir_rename_conflicts": [],  # list of (old, new, msg)
        "skipped_empty_target": [],
        "files_renamed": [],  # list of (file, msg)
        "file_rename_conflicts": [],  # list of (file, msg)
    }

    if verbose:
        print(f"Parents: {parents}")
        print(f"Prefix to remove: '{prefix}'")
        print(f"Extensions to process: {exts}")
        print(f"Apply mode: {apply}")
        print(f"Lowercase files after rename: {lower_files}")

    for parent in parents:
        process_parent(parent, prefix, exts, apply, lower_files, verbose, summary)

    # Print summary
    print("\nSummary:")
    print(f"  Parents processed: {len(parents)}")
    if summary["missing_parents"]:
        print(f"  Missing parents skipped: {len(summary['missing_parents'])}")
        if verbose:
            for p in summary["missing_parents"]:
                print(f"    - {p}")
    print(f"  Directories renamed: {len(summary['dirs_renamed'])}")
    for old, new in summary["dirs_renamed"]:
        print(f"    - {old} -> {new}")
    print(f"  Directory rename conflicts/skips: {len(summary['dir_rename_conflicts'])}")
    for old, new, msg in summary["dir_rename_conflicts"]:
        print(f"    - {old} -> {new}: {msg}")
    if summary["skipped_empty_target"]:
        print(f"  Skipped (empty new name): {len(summary['skipped_empty_target'])}")
        for s in summary["skipped_empty_target"]:
            print(f"    - {s}")
    print(f"  Files renamed (or dry-run indicated): {len(summary['files_renamed'])}")
    if verbose:
        for f, msg in summary["files_renamed"]:
            print(f"    - {f}: {msg}")
    print(f"  File rename conflicts/errors: {len(summary['file_rename_conflicts'])}")
    if verbose:
        for f, msg in summary["file_rename_conflicts"]:
            print(f"    - {f}: {msg}")

    if not apply:
        print(
            "\nThis was a dry-run. Re-run with --apply to perform the actual renames."
        )

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
