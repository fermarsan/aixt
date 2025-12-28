// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2023-2025
// License: MIT
module main

// description returns a string containing the description for the Aixt tool
fn description() string {
	return 'Aixt is a microcontrollers programming framework on Vlang.
		
Examples:
  aixt transpile -d NXC hello.v   Transpile the file `hello.v` into `hello.nxc`
  aixt transpile -d FIRE hello.v  Transpile the file `hello.v` into `hello.ino`
  aixt transpile -d Emu hello.v   Transpile the file `hello.v` into `hello.c`
  aixt c_compile -d Emu hello.v   Compile the file `hello.c` (transpiled from 
                                  `hello.v`) into `hello` or `hello.exe`
  aixt build -d NXT hello.v       Transpile, compile and download `hello.v` to 
                                  NXT Intelligent brick
  aixt clean hello.v              Clean all the generated files from `hello.v`
  aixt -help                      Print this help message
  aixt -version                   Print the Aixt version number
  aixt flash -p COM1 hello.v      Flash the device with the generate binary 
                                  after transpile and compile `hello.v`
  aixt new -d NXT -f . -n proj_1  Create an NXT project named `proj_1` at
                                  current folder'
}
