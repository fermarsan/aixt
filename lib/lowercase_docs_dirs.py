#!/usr/bin/env python3
"""
Script to recursively lowercase directory names under a given root.

Behavior:
- Walks the tree bottom-up so children are renamed before parents.
- For each directory whose name is not already lowercase:
  - If the lowercase target does not exist: rename directly.
  - If the lowercase target exists:
    - If it refers to the same directory (case-only difference on
      case-insensitive filesystems), perform a safe two-step rename via a
      temporary name to enforce the lowercase name.
    - If it is a different directory, attempt to merge contents:
      - Move non-conflicting entries from the source into the target.
      - Skip conflicting entries and report them.
      - Remove the source directory if empty after move.
- Supports a dry-run mode (default) and a `--apply` flag to actually perform changes.
- Adds a `--max-depth N` option to limit the depth of directories to process.
  Depth semantics:
    - root directory has depth 0
    - immediate children of root have depth 1
    - and so on.
  A negative value (default -1) means unlimited depth.
- The script operates on directories only (it does not rename files).

Usage:
    python3 aixt/lib/lowercase_docs_dirs.py [--apply] [--root PATH] [--max-depth N]

Notes:
- It's recommended to run this in a git repository so you can inspect changes
  and revert if needed.
- The script avoids overwriting existing files/directories.
"""

from __future__ import annotations

import argparse
import os
import shutil
import sys
import uuid
from typing import Tuple

DEFAULT_ROOT = "docs"


def is_same_path(a: str, b: str) -> bool:
    """Return True if paths refer to the same filesystem entry."""
    try:
        return os.path.exists(a) and os.path.exists(b) and os.path.samefile(a, b)
    except Exception:
        return False


def safe_rename_case_only(src: str, dst: str, apply: bool) -> Tuple[bool, str]:
    """
    Handle renaming when source and destination are same directory differing only by case,
    or when the filesystem forbids direct rename to change only case.
    Returns (success, message).
    """
    parent = os.path.dirname(dst)
    tmp_name = os.path.join(parent, f".tmp_lowercase_{uuid.uuid4().hex}")
    if not apply:
        return True, f"[dry-run] would rename (case-only) {src} -> {dst} via {tmp_name}"
    try:
        os.rename(src, tmp_name)
        os.replace(tmp_name, dst)
        return True, f"Renamed (case-only) {src} -> {dst}"
    except Exception as e:
        # Attempt to roll back if possible
        try:
            if os.path.exists(tmp_name) and not os.path.exists(src):
                os.rename(tmp_name, src)
        except Exception:
            pass
        return False, f"Failed case-only rename {src} -> {dst}: {e}"


def merge_directories(src: str, dst: str, apply: bool) -> Tuple[int, int, int]:
    """
    Merge non-conflicting contents from src into dst.
    Returns a tuple (moved_count, skipped_conflicts, errors).
    This function will not overwrite existing dst entries.
    """
    moved = 0
    skipped = 0
    errors = 0
    for entry in os.listdir(src):
        s = os.path.join(src, entry)
        t = os.path.join(dst, entry)
        if os.path.exists(t):
            # Conflict: both sides have an entry with the same name
            print(f"  Conflict: {t} exists. Skipping {s}")
            skipped += 1
            continue
        if not apply:
            print(f"  [dry-run] would move {s} -> {t}")
            moved += 1
            continue
        try:
            # Use shutil.move which handles files and directories
            shutil.move(s, t)
            print(f"  Moved {s} -> {t}")
            moved += 1
        except Exception as e:
            print(f"  Failed to move {s} -> {t}: {e}")
            errors += 1
    # Try to remove src if empty
    if not apply:
        print(f"  [dry-run] would attempt to remove directory {src} if empty")
    else:
        try:
            os.rmdir(src)
            print(f"  Removed empty directory {src}")
        except OSError:
            # Not empty or other error; leave it and count as non-fatal
            print(f"  Could not remove {src} (not empty or in use)")
    return moved, skipped, errors


def compute_depth(root: str, path: str) -> int:
    """
    Compute depth of `path` relative to `root`.
    Depth semantics:
      - root => 0
      - immediate children => 1
      - deeper levels increment accordingly
    """
    if os.path.abspath(root) == os.path.abspath(path):
        return 0
    rel = os.path.relpath(path, root)
    if rel == ".":
        return 0
    # Normalize separators and count components
    parts = rel.split(os.sep)
    # Filter out empty components (shouldn't normally happen)
    parts = [p for p in parts if p]
    return len(parts)


def process_tree(root: str, apply: bool, max_depth: int = -1) -> Tuple[int, int, int]:
    """
    Walk the directory tree under `root` and rename directories to lowercase.
    Only directories whose depth (relative to `root`) is <= max_depth are considered.
    If max_depth < 0, there is no depth limit.

    Returns totals: (renamed_count, moved_count (from merges), error_count)
    """
    renamed = 0
    merged_moved = 0
    errors = 0

    if not os.path.isdir(root):
        print(f"Root path '{root}' not found or is not a directory.")
        return renamed, merged_moved, errors

    # Walk bottom-up so children are handled before parents
    for dirpath, dirnames, _ in os.walk(root, topdown=False):
        # Compute depth of the current dirpath relative to root
        curr_depth = compute_depth(root, dirpath)
        # The entries in dirnames are immediate children of dirpath; their depth is curr_depth + 1
        child_depth = curr_depth + 1

        # We'll iterate over a copy because we might change the list on disk
        for d in list(dirnames):
            # Skip processing if this child's depth exceeds max_depth (when max_depth >= 0)
            if max_depth >= 0 and child_depth > max_depth:
                continue

            old = os.path.join(dirpath, d)
            new = os.path.join(dirpath, d.lower())

            if old == new:
                continue

            print(f"Processing: {old} -> {new}")

            if not os.path.exists(new):
                # Target doesn't exist: simple rename
                if not apply:
                    print(f"  [dry-run] would rename {old} -> {new}")
                    renamed += 1
                    continue
                try:
                    # Some filesystems don't allow rename that only changes case.
                    # Attempt direct rename; if fails, fallback to safe case-only rename.
                    try:
                        os.rename(old, new)
                        print(f"  Renamed {old} -> {new}")
                        renamed += 1
                    except OSError:
                        ok, msg = safe_rename_case_only(old, new, apply=True)
                        print(f"  {msg}")
                        if ok:
                            renamed += 1
                        else:
                            errors += 1
                except Exception as e:
                    print(f"  Failed to rename {old} -> {new}: {e}")
                    errors += 1
            else:
                # Target exists. Determine if it's the same entry (case-only)
                if is_same_path(old, new):
                    # On case-insensitive FS this may be the same dir; force a case-only rename
                    ok, msg = safe_rename_case_only(old, new, apply)
                    print(f"  {msg}")
                    if ok:
                        renamed += 1
                    else:
                        errors += 1
                    continue

                # Different directory exists at target: attempt to merge
                print(
                    f"  Target {new} exists and is different. Attempting to merge contents."
                )
                moved, skipped, errs = merge_directories(old, new, apply)
                merged_moved += moved
                errors += errs
                if skipped > 0:
                    print(
                        f"  Merge had {skipped} conflicts; source {old} left partially intact."
                    )
                else:
                    # If merge succeeded and src removed, count as a rename/merge
                    if not os.path.exists(old):
                        renamed += 1

    return renamed, merged_moved, errors


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(
        description="Lowercase directory names under a directory tree."
    )
    p.add_argument(
        "--apply",
        action="store_true",
        help="Apply changes. Without this flag the script runs in dry-run mode.",
    )
    p.add_argument(
        "--root",
        default=DEFAULT_ROOT,
        help=f"Root directory to process (default: '{DEFAULT_ROOT}').",
    )
    p.add_argument(
        "--max-depth",
        type=int,
        default=-1,
        help=(
            "Maximum depth (relative to root) of directories to process. "
            "root has depth 0. Negative value means no limit. Default: -1 (unlimited)."
        ),
    )
    return p.parse_args()


def main() -> int:
    args = parse_args()
    apply = args.apply
    root = args.root
    max_depth = args.max_depth

    if max_depth >= 0:
        print(
            f"{'APPLYING' if apply else 'DRY-RUN'} mode. Root: {root} (max-depth={max_depth})"
        )
    else:
        print(
            f"{'APPLYING' if apply else 'DRY-RUN'} mode. Root: {root} (no depth limit)"
        )

    renamed, moved, errors = process_tree(root, apply, max_depth)
    print("Summary:")
    print(f"  Directories renamed/removed via merge: {renamed}")
    print(f"  Entries moved during merges: {moved}")
    print(f"  Errors encountered: {errors}")
    if not apply:
        print("")
        print("This was a dry-run. Re-run with --apply to perform the operations.")
    return 0 if errors == 0 else 2


if __name__ == "__main__":
    sys.exit(main())
