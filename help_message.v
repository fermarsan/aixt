// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module main

// help_message is the help option message function
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