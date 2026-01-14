#!/usr/bin/env python3
"""
Strip leading header up to the first underscore for immediate child directories
of a given parent, and rename .v files inside each resulting directory to
`main.v`.

Behavior:
- Operates on immediate children of the specified parent directory.
- For each child directory whose name contains an underscore ("_"):
  - The new name becomes the substring after the first underscore.
    Example: "16F627A_uart_hello" -> "uart_hello".
  - The directory is renamed (dry-run by default; use --apply to actually change).
  - Inside the renamed directory (walked non-recursively by default),
    find files with the extension ".v" (case-insensitive) and rename them so
    the first such file becomes "main.v". If "main.v" already exists and is a
    different file, the script will skip renaming and report a conflict. If
    multiple .v files exist, only one will be renamed to "main.v"; the rest are
    reported and left alone.
- The script is careful about case-only renames (filesystems that treat case
  changes specially). It uses a temporary rename strategy when necessary.
- Prints a summary at the end.

Usage:
    python3 aixt/scripts/strip_prefix_and_set_main.py \
        --parent examples/microchip/pic16f6xx_18p         # dry-run
    python3 aixt/scripts/strip_prefix_and_set_main.py \
        --parent examples/microchip/pic16f6xx_18p --apply  # apply changes

Options:
    --parent PATH    Parent directory whose immediate child directories will be processed.
                     Default: examples/microchip/pic16f6xx_18p
    --apply          Perform actual renames. Without this flag it's a dry-run.
    --recursive      When renaming .v files, walk directories recursively.
                     Default: False (only files directly inside the child dir).
    --verbose        Print verbose output.
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
        description="Strip header up to first underscore from child directories and rename .v to main.v"
    )
    p.add_argument(
        "--parent",
        type=Path,
        default=Path("examples/microchip/pic16f6xx_18p"),
        help="Parent directory containing child folders to process.",
    )
    p.add_argument(
        "--apply",
        action="store_true",
        help="Apply changes. Without this flag the script runs as a dry-run.",
    )
    p.add_argument(
        "--recursive",
        action="store_true",
        help="Search for .v files recursively inside each child directory (default: only direct files).",
    )
    p.add_argument(
        "--verbose", action="store_true", help="Verbose output for debugging."
    )
    return p.parse_args()


def is_same_path(a: Path, b: Path) -> bool:
    try:
        return a.exists() and b.exists() and os.path.samefile(a, b)
    except Exception:
        return False


def safe_case_only_rename(src: Path, dst: Path, apply: bool) -> Tuple[bool, str]:
    """
    Handle case-only renames (or filesystems preventing direct rename to only
    change case) by renaming to a temporary name in the same directory and then
    replacing to the destination.
    """
    parent = dst.parent
    tmp = parent / (f".tmp_rename_{uuid.uuid4().hex}")
    if not apply:
        return True, f"[dry-run] would case-only rename {src} -> {dst} via {tmp}"
    try:
        src.rename(tmp)
        # tmp.replace(dst) would be ideal but Path has no replace; use os.replace
        os.replace(str(tmp), str(dst))
        return True, f"Renamed (case-only) {src} -> {dst}"
    except Exception as exc:
        # attempt rollback if possible
        try:
            if tmp.exists() and not src.exists():
                tmp.rename(src)
        except Exception:
            pass
        return False, f"Failed case-only rename {src} -> {dst}: {exc}"


def rename_dir(src: Path, dst: Path, apply: bool) -> Tuple[bool, str]:
    """
    Rename directory src -> dst, handling case-only rename and conflicts.
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


def find_v_files(dirpath: Path, recursive: bool) -> List[Path]:
    """Return list of .v files (case-insensitive) either direct children or recursive."""
    if recursive:
        return [
            p for p in dirpath.rglob("*") if p.is_file() and p.suffix.lower() == ".v"
        ]
    else:
        return [
            p for p in dirpath.iterdir() if p.is_file() and p.suffix.lower() == ".v"
        ]


def rename_v_to_main(v_files: List[Path], target_dir: Path, apply: bool) -> List[str]:
    """
    Rename the first .v file in v_files to target_dir / "main.v".
    Return messages for actions taken. If target already exists and is different,
    skip and report conflict. Extra .v files are reported.
    """
    msgs: List[str] = []
    if not v_files:
        msgs.append(f"No .v files found in {target_dir}")
        return msgs

    dst = target_dir / "main.v"
    # If dst exists and is not the same as one of the v_files, we cannot overwrite
    if dst.exists():
        # If dst is the same as one of v_files (case-only), treat carefully
        for vf in v_files:
            try:
                if is_same_path(vf, dst):
                    # Already the main file (possibly case-different)
                    msgs.append(f"Already main: {dst} (same file as {vf})")
                    break
            except Exception:
                continue
        else:
            # No vf matched dst
            msgs.append(
                f"Conflict: target {dst} already exists and is different; skipping renames in {target_dir}"
            )
            return msgs

    # Choose first candidate that is not already dst (or is samefile)
    selected = None
    for vf in v_files:
        # Skip if vf is already named main.v and same path
        if vf.resolve() == dst.resolve():
            selected = vf
            break
        selected = vf
        break

    if not selected:
        msgs.append(f"No suitable .v file to rename in {target_dir}")
        return msgs

    # If selected is the dst (case-equal) and exists, nothing to do
    if selected.resolve() == dst.resolve():
        msgs.append(f"Already named main.v: {dst}")
    else:
        # If dst does not exist -> rename
        if not dst.exists():
            if not apply:
                msgs.append(f"[dry-run] would rename {selected} -> {dst}")
            else:
                try:
                    # Use simple rename; handle case-only via safe helper if needed
                    try:
                        selected.rename(dst)
                        msgs.append(f"Renamed {selected} -> {dst}")
                    except OSError:
                        ok, msg = safe_case_only_rename(selected, dst, apply=True)
                        msgs.append(msg)
                except Exception as exc:
                    msgs.append(f"Failed to rename {selected} -> {dst}: {exc}")
        else:
            # dst exists: maybe case-only or same file handled above; otherwise conflict
            try:
                if is_same_path(selected, dst):
                    ok, msg = safe_case_only_rename(selected, dst, apply)
                    msgs.append(msg)
                else:
                    msgs.append(
                        f"Conflict: {dst} exists and differs; skipped renaming {selected}"
                    )
            except Exception as exc:
                msgs.append(f"Error checking samefile for {selected} and {dst}: {exc}")

    # Report the remaining .v files (if more than one)
    extras = [p for p in v_files if p.resolve() != dst.resolve()]
    # If the selected rename succeeded (or dry-run), extras remain; report but don't modify them
    for ex in (
        extras[1:]
        if len(extras) > 0 and extras[0].resolve() == dst.resolve()
        else extras
    ):
        msgs.append(f"Left extra .v file in {target_dir}: {ex}")

    return msgs


def process_parent(parent: Path, apply: bool, recursive_v: bool, verbose: bool) -> dict:
    """
    Process immediate child directories of parent:
    - For each child whose name contains an underscore, compute new name as substring after first underscore.
    - Rename directory to new name (dry-run unless apply).
    - Rename .v files inside to main.v (one per directory).
    Returns a summary dict.
    """
    summary = {
        "dirs_examined": 0,
        "dirs_renamed": [],
        "dir_rename_conflicts": [],
        "files_renamed": [],
        "file_conflicts": [],
        "skipped_no_underscore": [],
    }

    if not parent.exists() or not parent.is_dir():
        if verbose:
            print(f"Parent not found or not a directory: {parent}")
        return summary

    for child in sorted(parent.iterdir()):
        if not child.is_dir():
            continue
        summary["dirs_examined"] += 1
        name = child.name
        if "_" not in name:
            summary["skipped_no_underscore"].append(str(child))
            if verbose:
                print(f"Skipping (no underscore): {child}")
            continue

        new_name = name.split("_", 1)[1]
        if not new_name:
            summary["dir_rename_conflicts"].append(
                (str(child), str(child), "empty new name")
            )
            if verbose:
                print(f"Skipping rename for {child}: resulting name would be empty")
            continue

        dst = child.with_name(new_name)
        ok, msg = rename_dir(child, dst, apply)
        if verbose:
            print(msg)
        if ok:
            summary["dirs_renamed"].append((str(child), str(dst)))
            target_dir = dst
        else:
            summary["dir_rename_conflicts"].append((str(child), str(dst), msg))
            # If the dst exists and is usable, we'll still try to rename files inside it
            if dst.exists() and dst.is_dir():
                target_dir = dst
            else:
                # Skip file renames for this child
                if verbose:
                    print(
                        f"Skipping file renames for {child} due to dir rename problem"
                    )
                continue

        # Find .v files (direct or recursive)
        v_files = find_v_files(target_dir, recursive_v)
        if verbose:
            print(f"Found {len(v_files)} .v files in {target_dir}")
        msgs = rename_v_to_main(v_files, target_dir, apply)
        for m in msgs:
            if m.startswith("Renamed"):
                summary["files_renamed"].append((str(target_dir), m))
            elif m.startswith("Conflict") or m.startswith("Failed"):
                summary["file_conflicts"].append((str(target_dir), m))
            else:
                # informational messages
                if verbose:
                    print(m)

    return summary


def main() -> int:
    args = parse_args()
    parent: Path = args.parent
    apply: bool = args.apply
    recursive_v: bool = args.recursive
    verbose: bool = args.verbose

    if verbose:
        print(f"Parent: {parent}")
        print(f"Apply: {apply}")
        print(f"Recursive .v search: {recursive_v}")

    summary = process_parent(parent, apply, recursive_v, verbose)

    # Print overall summary
    print("\nSummary:")
    print(f"  Directories examined: {summary['dirs_examined']}")
    print(f"  Directories renamed: {len(summary['dirs_renamed'])}")
    for old, new in summary["dirs_renamed"]:
        print(f"    - {old} -> {new}")
    print(f"  Directory rename conflicts: {len(summary['dir_rename_conflicts'])}")
    for item in summary["dir_rename_conflicts"]:
        print(f"    - {item}")
    print(f"  Files renamed (main.v): {len(summary['files_renamed'])}")
    for d, msg in summary["files_renamed"]:
        print(f"    - {d}: {msg}")
    print(f"  File rename conflicts/errors: {len(summary['file_conflicts'])}")
    for d, msg in summary["file_conflicts"]:
        print(f"    - {d}: {msg}")
    print(f"  Skipped (no underscore): {len(summary['skipped_no_underscore'])}")
    if verbose and summary["skipped_no_underscore"]:
        for s in summary["skipped_no_underscore"]:
            print(f"    - {s}")

    if not apply:
        print("\nDry-run mode. Re-run with --apply to perform the changes.")

    return (
        0
        if not summary["file_conflicts"] and not summary["dir_rename_conflicts"]
        else 2
    )


if __name__ == "__main__":
    raise SystemExit(main())
