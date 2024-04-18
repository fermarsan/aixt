// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
// Description: This is the main file of the Aixt project. It works as a makefile too.
module main
// Aixt transpiler

import os
import toml
import aixt_build

// main function for Aixt transpiler.
// Usage:
//     v run aixt.v <command> <device_or_board> <source_path>
fn main() {
	if os.args.len < 2 {
		println(help_message())
	} else {
		// aixt_path := '${os.abs_path(os.dir(os.args[0]))}/..' // aixt base path (get out from `src` folder)
		aixt_path := os.executable().all_before_last('.exe').all_before_last('/aixt')
		println(aixt_path)
		command := os.args[1] // command
		match command {
			'help', '--help', '-h' {
				println(help_message())
			}
			'version' {	
				lines := os.read_lines('./src/v.mod') or {['']}
				for line in lines {
					if line.contains('version:') {
						println('Aixt ${line.replace('\tversion:\t', '')}')
					}
				}
			}
			'symlink' {
				aixt_symlink(aixt_path)
			}
			else {
				if os.args.len < 4 {
					println(help_message())
				} else {
					port, input_name := os.args[2], os.abs_path(os.args[3])	// port name and source path input
					mut base_name := input_name.replace('.aixt', '') // input file base name
					base_name = base_name.replace('.v', '')
					println('setup file:\n\t${aixt_path}/setup/${port}.toml\n')
					// println(os.read_file('${aixt_path}/setup/${port}.toml') or { 'file doesn\'t exist' } )
					setup := toml.parse_file('${aixt_path}/setup/${port}.toml') or { panic(err) } // load the device's setup file
					// println('++++++++++++++++\n${setup}\n++++++++++++++++')
					match command {
						'transpile', '-t' {
							aixt_build.transpile_file(input_name, setup, aixt_path)
							println('\n${input_name} transpiling finished.\n')
						}
						'compile', '-c' {
							aixt_build.compile_file(base_name, setup)
							ext := match setup.value('backend').string() {
								'nxc' 		{ 'nxc' }
								'arduino' 	{ 'ino' }
								else 		{ 'c' }
							}
							println('\n${base_name}.${ext} compiling finished.\n')
						}
						'build', '-b' {
							aixt_build.transpile_file(input_name, setup, aixt_path)
							println('\n${input_name} transpiling finished.\n')
							aixt_build.compile_file(base_name, setup)
							ext := match setup.value('backend').string() {
								'nxc' { 'nxc' }
								'arduino' { 'ino' }
								else { 'c' }
							}
							println('\n${base_name}.${ext} compiling finished.\n')
						}
						'clean', '-cl' {
							os.rm('${base_name}.c') or {} // clean c-type files
							os.rm('${base_name}.nxc') or {}
							os.rm('${base_name}.ino') or {}
							$if windows { // and executables
								os.rm('${base_name}.exe') or {}
							} $else {
								os.rm('${base_name}') or {}
							}
							println('Output files cleaned.')
						}
						'new_project', '-np' {
							device, path := os.args[2], os.args[3]
							name := os.args[4] or { 'project' }
							if !os.exists('${path}/${name}') {
								os.mkdir('${path}/${name}') or { panic(err) }
							}
							os.cp('${aixt_path}/templates/main.v', '${path}/${name}/main.v') or {}
							os.cp_all('${aixt_path}/templates/vscode/${device}/', '${path}/${name}/', true) or {
								panic(err)
							}						
						}
						else {
							println('Invalid command.')
						}
					}
				}
			}
		}
	}
}

