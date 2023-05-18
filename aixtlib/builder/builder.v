// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

module builder


import os
import toml
import v.ast
import v.checker
import v.pref
import v.parser
import strings
import aixtlib.gen.cemb_gen

pub fn build(path string) {
	println('Building........')
}

fn cemb_build(path string) {
	// println(os.args)
	// println(os.args.len)

	if os.args.len > 1 {
		device := os.args[2]
		path := os.args[1]
		table := ast.new_table()	
		mut vpref := &pref.Preferences{}
		vpref.is_script = true

		// ---------- Parsing ----------
		tree := parser.parse_file(path, table, .skip_comments, vpref)
		mut checker_ := checker.new_checker(table, vpref)
		checker_.check(tree)
		// println(tree)
		// println(strings.repeat_string('_', 60) + '\n')
		// println(table)
		println(strings.repeat_string('_', 60) + '\n')

		println(vpref.path)

		// mut trans_code := c_embedded.gen(tree)
		mut trans_code := ''
		if os.args.len > 2 {
			if os.args[2] == '-nxc' {	// if -nxt flag
				equivalents := toml.parse_file('../api/equivalents.toml') or { panic('file does not exist. ') }
				for eq in equivalents.to_any().as_map().keys() {
					trans_code = trans_code.replace(eq,equivalents.value(eq).string())	// replace the NXC equivalents
				}
			} else {
				println('Invalid flag.\n')
			}
		}
		println(trans_code)
		println(strings.repeat_string('_', 60) + '\n')

		// saves the output file
		output_ext := if os.args.len > 2 && os.args[2] == '-nxc' { '.nxc' } else { '.c' }
		output_path := path.replace('.v', output_ext)   
		// os.write_file(output_path, trans_code)!
	} else {
		println('no input file path.\n')
	}
}

fn build_api(path string) bool{
	return true
}