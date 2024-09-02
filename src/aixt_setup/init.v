// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
// Description: setup files loading for the device and the compiler
module aixt_setup

import toml

// Setup is the struct that defines the setup files
pub struct Setup {
pub mut:
	platform	toml.Doc
	compiler	toml.Doc
	device			string
}

// init function loads the setup files for the device and the compiler
pub fn (mut stp Setup) init(device string, aixt_path string) {
	eq_devices := toml.parse_file('${aixt_path}/setup/equivalent-devices.toml') or { panic(err) }
	port := if device in eq_devices.value('devices').as_map() {
		(eq_devices.value('devices').as_map()[device] or {''}).string()
	} else {
		device
	}
	stp.platform = toml.parse_file('${aixt_path}/setup/${port}.toml') or { panic(err) }
	stp.device = device
	compiler_setup_path := stp.platform.value('compiler_setup_path').string()
	stp.compiler = toml.parse_file('${aixt_path}/${compiler_setup_path}') or { panic(err) }
	println('setup files:\n\t${aixt_path}/setup/${port}.toml')
	println('\t${aixt_path}/${compiler_setup_path}')
}