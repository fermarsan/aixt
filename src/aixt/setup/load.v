// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
// Description: setup files loading for the device and the compiler
module setup

import os
import json

// load function loads the setup files for the device and the compiler
pub fn (mut stp Setup) load(device string) {

	aixt_path := os.dir(os.executable())

	eq_devices := json.decode(
		map[string]string,
		os.read_file('${aixt_path}/setup/equivalent-devices.json') or { panic(err) }
	) or { panic(err) }
	
	port := if device in eq_devices {
		eq_devices[device]
	} else {
		device
	}

	dev_setup := os.read_file('${aixt_path}/setup/${port}.json') or { panic(err) }
	setup := json.decode(Setup, dev_setup) or { panic(err) }

	// println(setup)

	comp_setup := os.read_file('${aixt_path}/${setup.compiler_setup_path}') or { panic(err) }
	complete_setup :=  dev_setup.all_before_last('}') + ',\n' + comp_setup.all_after_first('{')
	stp = json.decode(Setup, complete_setup)  or { panic(err) }
	stp.device = device

	println('Setup files:\n\t${aixt_path}/setup/${stp.port}.json')
	println('\t${aixt_path}/${stp.compiler_setup_path}\n')
}