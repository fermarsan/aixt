// Author: Fernando M. Santa
// Date: 2025

module main

import os
import aixt.setup

// flash downloads (uploads) the binary file to the device.
// example:
// ``` v
// flash('example.v', '~/nbc/nbc', '/dev/ttyUSB0', setup)
// ```
// Calls the flashing tool to pass the binary file to the device
pub fn flash(path string, flasher_path string, flasher_args string, port string, project_setup setup.Setup) {
	// println('>>>>>>>>>>>>>>>>>> Flashing by: ${port} <<<<<<<<<<<<<<<<<<')

	mut args := flasher_args
	args = args.replace('@{file_no_ext}', '${path}')
	args = args.replace('@{file_dir_name}', '${os.dir(path)}')
	args = args.replace('@{device}', '${project_setup.device}')
	args = args.replace('@{port}', '${port}')

	input_ext := match project_setup.backend {
		'nxc' { '.nxc' }
		'arduino' { '.ino' }
		else { '.c' }
	}
	args = args.replace('@{input_ext}', '${input_ext}')

	println('${flasher_args} ${args}')
	println(os.execute('${flasher_args} ${args}').output)
}
