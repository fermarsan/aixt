module main

import os
import strings

// create_readme_files.v
//
// Usage:
//   v run aixt/docs/create_readme_files.v [docs_root] [api_root]
//
// Defaults (when run from project root):
//   docs_root = "docs"
//   api_root  = "api"
//
// The script searches recursively under `docs_root` for files named `quickref.md`.
// For each found `docs/.../quickref.md` it computes the corresponding
// `api/.../header.md` path (replacing the docs root with the api root while
// keeping the rest of the path). Then it creates (or overwrites) a file
// `api/.../README.md` containing:
//
//   <header.md contents> \n\n <quickref.md contents>
//
// If `header.md` does not exist, README.md will contain only the quickref.md contents.
//
// Notes:
// - This script prefers POSIX-style paths (/) which match the repository layout.
// - You can pass absolute or relative paths for docs_root and api_root.
// - Run it from the repository root to use the default arguments.

fn main() {
	// args := os.args
	// mut docs_root := if args.len > 1 { args[1] } else { 'docs' }
	// mut api_root  := if args.len > 2 { args[2] } else { 'api' }
	docs_root := os.norm_path(if os.args.len > 1 { os.args[1] } else { 'docs' })
	api_root := os.norm_path(if os.args.len > 2 { os.args[2] } else { 'api' })

	// Normalize: remove trailing slashes
	// docs_root = strings.trim_right(docs_root, '/')
	// api_root  = strings.trim_right(api_root, '/')
	// docs_root = os.norm_path(docs_root)
	// api_root  = os.norm_path(api_root)

	if !os.exists(docs_root) {
		eprintln('docs root not found: ${docs_root}')
		exit(1)
	}

	quickref_paths := find_quickref_paths(docs_root)
	if quickref_paths.len == 0 {
		println('No quickref.md files found under ${docs_root}')
		return
	}

	println('Found ${quickref_paths.len} quickref.md files. Processing...')

	for qpath in quickref_paths {
		println(qpath)
	// 	// Compute relative path from docs_root
	// 	rel := path_relative_to_root(qpath, docs_root)
	// 	// Ensure rel ends with 'quickref.md'
	// 	if !strings.ends_with(rel, 'quickref.md') {
	// 		// Shouldn't happen, but skip if it does
	// 		eprintln('Skipping unexpected path (not ending with quickref.md): ${qpath}')
	// 		continue
	// 	}
	// 	// dir part under docs (e.g. 'arduino/uno/')
	// 	dir_under_docs := strings.trim_suffix(rel, 'quickref.md')
	// 	// Compose header path under api root: api_root + '/' + dir_under_docs + 'header.md'
	// 	header_path := api_root + '/' + dir_under_docs + 'header.md'
	// 	// Compose target README path: api_root + '/' + dir_under_docs + 'README.md'
	// 	target_dir := api_root + '/' + dir_under_docs
	// 	target_readme := target_dir + 'README.md'

	// 	// Read quickref contents
	// 	quickref_content := os.read_file(qpath) or {
	// 		eprintln('Failed to read ${qpath} : ${err}')
	// 		continue
	// 	}

	// 	// Read header if exists
	// 	mut header_content := ''
	// 	if os.exists(header_path) {
	// 		header_content = os.read_file(header_path) or {
	// 			eprintln('Failed to read ${header_path} : ${err}')
	// 			'' // continue with empty header
	// 		}
	// 	} else {
	// 		// header missing - will create README with only quickref
	// 	}

	// 	// Assemble README content
	// 	mut readme_content := ''
	// 	if header_content.len > 0 {
	// 		readme_content = header_content.trim_right('\n') + '\n\n' + quickref_content
	// 	} else {
	// 		readme_content = quickref_content
	// 	}

	// 	// Ensure target directory exists
	// 	if !os.exists(target_dir) {
	// 		// create directories (mkdir_all)
	// 		os.mkdir_all(target_dir) or {
	// 			eprintln('Failed to create directory ${target_dir} : ${err}')
	// 			continue
	// 		}
	// 	}

	// 	// Write README.md
	// 	os.write_file(target_readme, readme_content) or {
	// 		eprintln('Failed to write ${target_readme} : ${err}')
	// 		continue
	// 	}

	// 	println('Created: ${target_readme}')
	}

	println('Done.')
}

// Recursively find files named 'quickref.md' under the given root directory.
// Returns a list of full file paths.
fn find_quickref_paths(root string) []string {
	mut result := []string{}
	entries := os.ls(root) or {
		eprintln('Failed to list directory ${root} : ${err}')
		return result
	}

	for entry in entries {
		full := os.norm_path(root + '/' + entry)
		if os.is_dir(full) {
			// recurse
			sub := find_quickref_paths(full)
			result << sub
		} else {
			if entry == 'quickref.md' {
				result << full
			}
		}
	}

	return result
}

// Compute path relative to the given root.
// Example: path_relative_to_root('docs/arduino/uno/quickref.md', 'docs') -> 'arduino/uno/quickref.md'
// fn path_relative_to_root(path string, root string) string {
// 	p := if strings.starts_with(path, root + '/') {
// 		strings.trim_prefix(path, root + '/')
// 	} else if path == root {
// 		''
// 	} else {
// 		// If path does not start with root + '/', try to remove a leading './' and try again
// 		p2 := if strings.starts_with(path, './') { strings.trim_prefix(path, './') } else { path }
// 		if strings.starts_with(p2, root + '/') {
// 			strings.trim_prefix(p2, root + '/')
// 		} else {
// 			// Fallback: return the original path
// 			path
// 		}
// 	}
// 	return p
// }
