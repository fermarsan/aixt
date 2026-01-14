#!/usr/bin/env python3
"""
Lowercase .v and .sim1 filenames under examples/arduino/{uno,nano,mega} (or other root).

This script:
- Walks the target directories recursively.
- For every file with extension `.v` or `.sim1` (case-insensitive), renames the
  file so its filename (base + extension) is entirely lowercase.
- Avoids overwriting existing files. If a lowercase target exists:
  - If it refers to the same filesystem entry (case-only difference on
    case-insensitive filesystems), performs a safe two-step rename via a
    temporary name to enforce the lowercase name.
  - If it's a different file, reports a conflict and skips it.
- Default mode is dry-run. Use `--apply` to perform changes.
- Prints a summary at the end.

Usage:
    python3 aixt/scripts/lowercase_arduino_files.py            # dry-run
    python3 aixt/scripts/lowercase_arduino_files.py --apply  # apply changes

Options:
    --root ROOT        Root directory to search (default: examples/arduino)
    --targets LIST     Comma-separated list of subdirs under root to process
                       (default: uno,nano,mega)
    --exts LIST        Comma-separated list of file extensions to process
                       (default: .v,.sim1)
    --apply            Actually perform renames (default: dry-run)
    --verbose          Print verbose logs
"""

from __future__ import annotations

import argparse
import os
import sys
import uuid
from pathlib import Path
from typing import List, Tuple

DEFAULT_ROOT = Path("examples/arduino")
DEFAULT_TARGETS = ["uno", "nano", "mega"]
DEFAULT_EXTS = [".v", ".sim1"]


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(
        description="Lowercase .v and .sim1 filenames under Arduino examples."
    )
    p.add_argument(
        "--root",
        type=Path,
        default=DEFAULT_ROOT,
        help=f"Root directory to search (default: {DEFAULT_ROOT})",
    )
    p.add_argument(
        "--targets",
        type=str,
        default=",".join(DEFAULT_TARGETS),
        help=f"Comma-separated subdirectories under root to process (default: {','.join(DEFAULT_TARGETS)})",
    )
    p.add_argument(
        "--exts",
        type=str,
        default=",".join(DEFAULT_EXTS),
        help=f"Comma-separated extensions to process (default: {','.join(DEFAULT_EXTS)})",
    )
    p.add_argument(
        "--apply",
        action="store_true",
        help="Apply changes. Without this flag the script runs in dry-run mode.",
    )
    p.add_argument("--verbose", action="store_true", help="Verbose output.")
    return p.parse_args()


def safe_case_only_rename(src: Path, dst: Path, apply: bool) -> Tuple[bool, str]:
    """
    Handle case-only rename by doing a temporary rename in same directory.
    Returns (success, message).
    """
    parent = dst.parent
    tmp = parent / (f".tmp_lowercase_{uuid.uuid4().hex}")
    if not apply:
        return True, f"[dry-run] would case-only rename {src} -> {dst} via {tmp}"
    try:
        src.rename(tmp)
        # os.replace semantics: atomic where possible
        tmp.replace(dst)
        return True, f"Renamed (case-only) {src} -> {dst}"
    except Exception as exc:
        # try to roll back
        try:
            if tmp.exists() and not src.exists():
                tmp.rename(src)
        except Exception:
            pass
        return False, f"Failed case-only rename {src} -> {dst}: {exc}"


def rename_file(src: Path, dst: Path, apply: bool, verbose: bool) -> Tuple[bool, str]:
    """
    Rename src -> dst, handling conflicts and case-only renames.
    Returns (success, message).
    """
    if not dst.exists():
        if not apply:
            return True, f"[dry-run] would rename {src} -> {dst}"
        try:
            src.rename(dst)
            return True, f"Renamed {src} -> {dst}"
        except OSError:
            # Could be filesystem that disallows case-only rename; try safe path
            ok, msg = safe_case_only_rename(src, dst, apply=True)
            return ok, msg
        except Exception as exc:
            return False, f"Failed to rename {src} -> {dst}: {exc}"

    # dst exists
    try:
        # If they refer to same underlying file (case-insensitive FS), force case-only rename
        if src.exists() and dst.exists() and os.path.samefile(src, dst):
            ok, msg = safe_case_only_rename(src, dst, apply)
            return ok, msg
    except Exception:
        # If samefile check failed for any reason, fall through to conflict handling
        pass

    # dst exists and is a different file; do not overwrite
    return False, f"Conflict: target exists and is different, skipping {src} -> {dst}"


def gather_files(
    root: Path, targets: List[str], exts: List[str], verbose: bool
) -> List[Path]:
    """Collect files under root/target for given extensions (case-insensitive)."""
    found = []
    for t in targets:
        dirpath = root / t
        if not dirpath.exists():
            if verbose:
                print(f"Skipping missing target directory: {dirpath}")
            continue
        for dirpath_str, _, filenames in os.walk(dirpath):
            dp = Path(dirpath_str)
            for fn in filenames:
                p = dp / fn
                if p.suffix.lower() in (e.lower() for e in exts):
                    found.append(p)
    return found


def main() -> int:
    args = parse_args()
    root: Path = args.root
    targets: List[str] = [t.strip() for t in args.targets.split(",") if t.strip()]
    exts: List[str] = [e.strip() for e in args.exts.split(",") if e.strip()]
    apply: bool = args.apply
    verbose: bool = args.verbose

    if verbose:
        print(f"Root: {root}")
        print(f"Targets: {targets}")
        print(f"Extensions: {exts}")
        print(f"Apply: {apply}")

    if not root.exists() or not root.is_dir():
        print(f"Root directory not found: {root}", file=sys.stderr)
        return 2

    files = gather_files(root, targets, exts, verbose)
    if not files:
        print("No matching files found.")
        return 0

    actions = []
    renamed = 0
    skipped_conflicts = 0
    errors = 0

    for src in files:
        desired_name = src.name.lower()
        dst = src.with_name(desired_name)
        if src == dst:
            if verbose:
                print(f"Already lowercase: {src}")
            continue

        ok, msg = rename_file(src, dst, apply, verbose)
        actions.append(msg)
        if ok:
            if (
                msg.startswith("Renamed")
                or msg.startswith("[dry-run] would rename")
                or "case-only" in msg
            ):
                renamed += 1
        else:
            # check if conflict or failure
            if msg.startswith("Conflict"):
                skipped_conflicts += 1
            else:
                errors += 1

        if verbose:
            print(msg)

    # Summary
    print("")
    print("Summary:")
    print(f"  Files processed that would/are renamed: {renamed}")
    print(f"  Conflicts skipped: {skipped_conflicts}")
    print(f"  Errors: {errors}")
    if not apply:
        print("")
        print("This was a dry-run. Re-run with --apply to perform the renames.")
    return 0 if errors == 0 else 2


if __name__ == "__main__":
    raise SystemExit(main())
