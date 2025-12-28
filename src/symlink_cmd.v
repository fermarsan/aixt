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
import os

// symlink_cmd is called after command `aixt symlink [flags]`
fn symlink_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	aixt_path := os.dir(os.executable())
	if cmd.args.len != 0 {
		println(cmd.help_message())
	} else {		
		aixt_symlink(aixt_path)
	}
}