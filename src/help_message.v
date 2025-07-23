// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module main

// help_message returns a string containing the help message for the Aixt tool
//
// The message includes:
// - Usage instructions
// - Examples of common commands
// - List of supported commands and their descriptions
//
// This function is typically called when the user requests help or when
// incorrect command usage is detected.
// help_message is the help option message function
fn help_message() string {
	return 'aixt is a microcontrollers programming framework on Vlang.

Usage:
  aixt [command] [device] [input_file_name]

Examples:
  aixt transpile NXC hello.v       Transpile the file `hello.v`  and output it as
                                   `hello.nxc` .
  aixt build NXT hello.v           Transpile, compile and download `hello.v`  to NXT
                                   Intelligent brick.
  aixt -t Arduino_Nano hello.v     Transpile the file `hello.v`  and output it as
                                   `hello.c` or `hello.ino`  (depending on the Backend).
  aixt -c Emulator hello.v         Compile a previously transpiled `hello.c`  (from
                                   `hello.v`) and output it as `hello` or `hello.exe`
  aixt clean NXC hello.v           Clean all the generated files `hello.*`
  aixt -h                          Print this help message
  aixt version                     Print the Aixt version number
  aixt flash hello.v /dev/ttyUSB0  flash the device with the generate binary after 
                                   transpile and compile `hello.v`
  aixt -np NXT /home proj_1        Create the `proj_1` NXT project in `/home`

aixt supports the following commands:
  transpile, -t                    Transpile to C an Aixt source file.
  c_compile, -c                    Compile the previosly generated C file.
  build, -b                        Build (transpile and compile) an Aixt program.
  flash, -f                        Flash the device with the generated binary file 
  clean, -cl                       Clean all the generated file (C and executables).
  help, --help, -h                 Call this help
  version, --version, -v           Returns the Aixt version number
  new_project, -np                 Create new project (main.v and editor setup files)
  symlink, -s                      Create a symbolic link to the Aixt source file.'
}
