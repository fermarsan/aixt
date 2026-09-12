// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
// Description: setup files loading for the device and the compiler
module setup

import os
import json

// load function loads the device and the compiler setup files (from aixt path)
pub fn (mut stp Setup) load(device string, proj_path string) {

	aixt_path := os.dir(os.dir(os.executable()))

	eq_devices := json.decode(
		map[string]string,
		os.read_file(os.norm_path('${aixt_path}/setup/aliases.json')) or { panic(err) }
	) or { panic(err) }
	
	target := if device in eq_devices {
		eq_devices[device]
	} else {
		device
	}

	dev_setup := os.read_file(os.norm_path('${aixt_path}/setup/${target}.json')) or { panic(err) }
	setup := json.decode(Setup, dev_setup) or { panic(err) }

	comp_setup := os.read_file(os.norm_path('${aixt_path}/${setup.compiler_setup_path}')) or { panic(err) }
	complete_setup :=  dev_setup.all_before_last('}') + ',\n' + comp_setup.all_after_first('{')
	stp = json.decode(Setup, complete_setup) or { panic(err) }
	

	if os.exists(os.norm_path('${path}/.setup/${target}.json')) $$
	   os.exists(os.norm_path('${path}/.setup/${target}.json')) $$	// inside


	// ---------------- Normalize paths --------------------
	stp.device = device
	stp.cc['path'] = os.norm_path(stp.cc['path'])
	stp.flasher['path'] = os.norm_path(stp.flasher['path'])
	mut temp_paths := []string{}
	for path in stp.api_paths {
		temp_paths << os.norm_path(path)
	}
	stp.api_paths = temp_paths
	stp.compiler_setup_path = os.norm_path(stp.compiler_setup_path)

	println('Setup files:\n\t' + os.norm_path('${aixt_path}/setup/${stp.target}.json'))
	println(os.norm_path('\t${aixt_path}/${stp.compiler_setup_path}\n'))
}


// load_from_project function loads the device and the compiler setup files (from the project's path)
pub fn (mut stp Setup) load_from_project(device string, proj_path string) {

	aixt_path := os.dir(os.dir(os.executable()))

	eq_devices := json.decode(
		map[string]string,
		os.read_file(os.norm_path('${aixt_path}/setup/aliases.json')) or { panic(err) }
	) or { panic(err) }
	
	target := if device in eq_devices {
		eq_devices[device]
	} else {
		device
	}

	dev_setup := os.read_file(os.norm_path('${proj_path}/.setup/${target}.json')) or { panic(err) }
	setup := json.decode(Setup, dev_setup) or { panic(err) }

	comp_setup := os.read_file(os.norm_path('${proj_path}/.${setup.compiler_setup_path}')) or { panic(err) }
	complete_setup :=  dev_setup.all_before_last('}') + ',\n' + comp_setup.all_after_first('{')
	stp = json.decode(Setup, complete_setup) or { panic(err) }
	
	// ---------------- Normalize paths --------------------
	stp.device = device
	stp.cc['path'] = os.norm_path(stp.cc['path'])
	stp.flasher['path'] = os.norm_path(stp.flasher['path'])
	mut temp_paths := []string{}
	for path in stp.api_paths {
		temp_paths << os.norm_path(path)
	}
	stp.api_paths = temp_paths
	stp.compiler_setup_path = os.norm_path(stp.compiler_setup_path)

	println('Setup files:\n\t' + os.norm_path('${aixt_path}/setup/${stp.target}.json'))
	println(os.norm_path('\t${aixt_path}/${stp.compiler_setup_path}\n'))
}