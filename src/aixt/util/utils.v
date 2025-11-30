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
		if os.is_dir(os.norm_path('${path}/${item}')) {
			paths << get_file_paths(os.norm_path('${path}/${item}'))
		} else {
			paths << os.norm_path('${path}/${item}')
		}
	}
	return paths
}

// get_subdirs function look for sub-dirs in a folder recursively
pub fn get_subdirs(path string) []string {
	mut paths := []string{}
	dir_content := os.ls(path) or { [] }
	for item in dir_content {
		if os.is_dir(os.norm_path('${path}/${item}')) {
			paths << os.norm_path('${path}/${item}')
			paths << get_subdirs(os.norm_path('${path}/${item}'))
		} 
	}
	return paths
}