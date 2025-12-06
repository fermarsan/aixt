// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module main

// description returns a string containing the description for the Aixt tool
fn description() string {
	return 'Aixt is a microcontrollers programming framework on Vlang.
		
Examples:
  aixt transpile -d NXC hello.v   Transpile the file `hello.v` and output it as
                                  `hello.nxc`
  aixt transpile -d FIRE hello.v  Transpile the file `hello.v` and output it as
                                  `hello.c` or `hello.ino` (depends on the Backend)
  aixt c_compile -d NXT hello.v   Compile a previously transpiled `hello.c`  (from
                                  `hello.v`) and output it as `hello` or `hello.exe`
  aixt build -d NXT hello.v       Transpile, compile and download `hello.v` to NXT
                                  Intelligent brick
  aixt clean hello.v              Clean all the generated files `hello.*`
  aixt -help                      Print this help message
  aixt -version                   Print the Aixt version number
  aixt flash -p COM1 hello.v      flash the device with the generate binary after 
                                  transpile and compile `hello.v`
  aixt new -d NXT -f . -n proj_1  Create an NXT project named `proj_1` at current
                                  folder'
}
