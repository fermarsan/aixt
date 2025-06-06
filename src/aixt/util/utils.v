// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
// Description: util functions module
module util

import os

// get_file_paths function look for file paths in a folder recursively
pub fn get_file_paths(path string) []string {
	mut paths := []string{}
	dir_content := os.ls(path) or { [] }
	for item in dir_content {
		if os.is_dir('${path}/${item}') {
			paths << get_file_paths('${path}/${item}')
		} else {
			paths << '${path}/${item}'
		}
	}
	return paths
}

// get_subfolders function look for sub-folders in a folder recursively
pub fn get_subfolders(path string) []string {
	mut paths := []string{}
	dir_content := os.ls(path) or { [] }
	for item in dir_content {
		if os.is_dir('${path}/${item}') {
			paths << '${path}/${item}'
			paths << get_subfolders('${path}/${item}')
		} 
	}
	return paths
}