// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: aixt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is the main file of the Aixt project. It works as a make file too.
//
// Usage:
// 1. Run the program using `v run aixt.v command port input_file_name`
import os
import toml
import aixt_build

fn main() {
	if os.args.len < 2 {
		println(help_message())
	} else {
		aixt_path := os.abs_path(os.dir(os.args[0])) // aixt base path
		command := os.args[1] // command
		match command {
			'help', '--help', '-h' {
				println(help_message())
			}
			'version' {	
				lines := os.read_lines('v.mod') or {['']}
				for line in lines {
					if line.contains('version:') {
						println('Aixt ${line.replace('\tversion:\t', '')}')
					}
				}
			}
			else {
				if os.args.len < 4 {
					println(help_message())
				} else {
					port, input_name := os.args[2], os.abs_path(os.args[3]) // the other parameters
					mut base_name := input_name.replace('.aixt', '') // input file base name
					base_name = base_name.replace('.v', '')
					setup := toml.parse_file('${aixt_path}/ports/setup/${port}.toml') or { return } // load the device's setup file
					match command {
						'transpile', '-t' {
							aixt_build.transpile_file(input_name, setup, aixt_path)
							println('\n${input_name} transpilation finished.\n')
						}
						'compile', '-c' {
							aixt_build.compile_file(base_name, setup)
							ext := match setup.value('backend').string() {
								'nxc' { 'nxc' }
								'arduino' { 'ino' }
								else { 'c' }
							}
							println('\n${base_name}.${ext} compilation finished.\n')
						}
						'build', '-b' {
							aixt_build.transpile_file(input_name, setup, aixt_path)
							println('\n${input_name} transpilation finished.\n')
							aixt_build.compile_file(base_name, setup)
							ext := match setup.value('backend').string() {
								'nxc' { 'nxc' }
								'arduino' { 'ino' }
								else { 'c' }
							}
							println('\n${base_name}.${ext} compilation finished.\n')
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
							path, name := os.args[2], os.args[3]
							os.mkdir('${path}/${name}') or {}
							os.cp('${aixt_path}/.template/main.v', '${path}/${name}/main.v') or {}
							os.cp_all('${aixt_path}/.vscode/', '${path}/${name}/.vscode/', true) or {}
							mut lines := os.read_file('${path}/${name}/.vscode/settings.json') or {''}
							$if windows {
								lines = lines.replace('.\\aixt.v', '${os.getwd()}\\aixt.v')
							} $else {
								lines = lines.replace('./aixt.v', '${os.getwd()}/aixt.v')
							}
							os.write_file('${path}/${name}/.vscode/settings.json', lines) or {}							
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

fn help_message() string {
	return 'aixt is a tool for managing Aixt source code (*.aixt or *.v).

Usage:
  aixt command device input_file_name

Examples:
  aixt transpile NXC hello.aixt	Transpile the file `hello.aixt` and output it as
	                            `hello.nxc`.
  aixt build NXC hello.v        Transpile, compile and download `hello.v` to NXT
                                Intelligent brick.
  aixt -t Arduino_Nano hello.v	Transpile the file `hello.v` and output it as
                                `hello.c` or `hello.ino` (depending on the Backend).
  aixt -c Emulator hello.aixt	Compile a previously transpiled `hello.c` (from
                                `hello.aixt`) and output it as `hello` or `hello.exe`
  aixt clean NXC hello.aixt     Clean all the generated files `hello.*`
  aixt -h                       Print this help message
  aixt version                  Print the Aixt version number

aixt supports the following commands:
  transpile, -t                 Transpile to C an Aixt source file.
  compile, -c                   Compile the previosly generated C file.
  build, -b                     Build (transpile and compile) an Aixt program.
  clean, -cl                    Clean all the generated file (C and executables).
  help, --help, -h              Call this help
  version                       Returns the Aixt version number'
}
