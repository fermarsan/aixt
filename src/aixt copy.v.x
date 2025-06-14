// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
// Description: This is the main file of the Aixt project. It works as a makefile too.
module main

// Aixt transpiler
import os
import aixt.setup
import aixt.build
// import aixt.builder

// main function for Aixt transpiler.
// Usage:
//     v run aixt.v <command> <device_or_board> <source_path>
fn main() {
	if os.args.len < 2 {
		println(help_message())
	} else {
		aixt_path := os.dir(os.executable())
		println('Aixt path:\n\t${os.executable()}\n')
		command := os.args[1] // command
		match command {
			'help', '--help', '-h' {
				println(help_message())
			}
			'version', '--version', '-v' {
				lines := os.read_lines('${aixt_path}' + os.path_separator + 'src' + os.path_separator + 'v.mod') or { [''] }
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
					mut device, input_name := os.args[2], os.abs_path(os.args[3]) // device name and source path input
					base_name := input_name.replace('.v', '') // input file base name
					mut project_setup := setup.Setup{}
					project_setup.load(device)
					// println('++++++++++++++++\n${project_setup}\n++++++++++++++++')
					match command {
						'transpile', '-t' {
							build.transpile_file(input_name, project_setup)
							println('\n${input_name} transpiling finished.\n')
						}
						'compile', '-c' {
							build.compile_file(base_name, project_setup)
							ext := match project_setup.backend {
								'nxc' { 'nxc' }
								'arduino' { 'ino' }
								else { 'c' }
							}
							println('\n${base_name}.${ext} compiling finished.\n')
						}
						'flash', '-f' {
							port := os.args[4] or { 'Undefined flashing port.' }
							ext := match project_setup.backend {
								'nxc' { '' }
								'arduino' { '' }
								else { 'hex' }
							}
							name := if ext == '' { base_name } else { '${base_name}.${ext}' }
							build.flash_file(name, port, project_setup)
							println('\n${name} flashing finished.\n')
						}
						'build', '-b' {
							build.transpile_file(input_name, project_setup)
							println('\n${input_name} transpiling finished.\n')
							build.compile_file(base_name, project_setup)
							ext := match project_setup.backend {
								'nxc' { 'nxc' }
								'arduino' { 'ino' }
								else { 'c' }
							}
							println('\n${base_name}.${ext} compiling finished.\n')
						}
						'builder' {
							transpile(input_name, project_setup)
						}
						'clean', '-cl' {
							if os.exists('${os.dir(base_name)}' + os.path_separator + 'Makefile') {
								println(os.execute('make -f ${os.dir(base_name)}' + os.path_separator + 'Makefile clean').output)
							}
							os.rm('${base_name}.c') or {} // clean c-type files
							os.rm('${base_name}.nxc') or {}
							os.rm('${base_name}.ino') or {}
							$if windows { // and executables
								os.rm('${base_name}.exe') or {}
							} $else {
								os.rm('${base_name}') or {}
							}
							if os.exists('${os.dir(base_name)}' + os.path_separator + 'build/') {
								os.rmdir_all('${os.dir(base_name)}' + os.path_separator + 'build/') or { panic(err) }
							}
							// Remove all .c, .cpp, .h, hpp files inside the directory
							files := os.ls(os.dir(base_name)) or { [] }
							for file in files {
								if file.ends_with('.c') || file.ends_with('.cpp')
									|| file.ends_with('.h') || file.ends_with('.hpp') {
									os.rm('${os.dir(base_name)}/${file}') or {}
								}
							}
							println('Output files cleaned.')
						}
						'new_project', '-np' {
							path := os.args[3]
							name := os.args[4] or { 'project' }
							if !os.exists('${path}/${name}') {
								os.mkdir('${path}/${name}') or { panic(err) }
							}
							// os.cp('${aixt_path}' + os.path_separator + 'templates' + os.path_separator + 'main.v', '${path}/${name}' + os.path_separator + 'main.v') or {}
							os.cp_all('${aixt_path}' + os.path_separator + 'templates' + os.path_separator + 'project/${project_setup.port}/',
								'${path}/${name}/', true) or { panic(err) }
							if project_setup.backend == 'arduino' { // arduino-cli sketch name requirement
								os.rename('${path}/${name}' + os.path_separator + 'main.v', '${path}/${name}/${name}.v') or {
									panic(err)
								}
							}
							if os.exists('${path}/${name}' + os.path_separator + 'Makefile') { // adds the device name to de Makefile
								mut makefile := os.read_file('${path}/${name}' + os.path_separator + 'Makefile') or {
									panic(err)
								}
								makefile = makefile.replace('__device_name__', '${device}')
								os.write_file('${path}/${name}' + os.path_separator + 'Makefile', makefile) or {
									panic(err)
								}
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
