// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
// ## Description
// This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli

// build_cmd is called after command `aixt build [flags] source_file`
fn build_cmd(cmd cli.Command) ! {
	transpile_cmd(cmd)!
	c_compile_cmd(cmd)!
}
