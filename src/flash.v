// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module main

import os
import aixt.setup

// flash downloads (uploads) the binary file to the device.
// example:
// ``` v
// build.flash_file('example.hex', '/dev/ttyUSB0', setup)
// ```
// Calls the flashing tool to pass the binary file to the device
pub fn flash(path string, port string, project_setup setup.Setup) {
	// println('>>>>>>>>>>>>>>>>>> Flashing by: ${port} <<<<<<<<<<<<<<<<<<')

	flasher := $if windows { // flashing tool depending on the OS
		project_setup.flasher_windows
	} $else {
		project_setup.flasher_linux
	}

	mut flags := project_setup.flasher_flags
	flags = flags.replace('@{file_no_ext}', '${path}')
	flags = flags.replace('@{file_dir_name}', '${os.dir(path)}')
	flags = flags.replace('@{device}', '${project_setup.device}')
	flags = flags.replace('@{port}', '${port}')

	input_ext := match project_setup.backend {
		'nxc' { '.nxc' }
		'arduino' { '.ino' }
		else { '.c' }
	}
	flags = flags.replace('@{input_ext}', '${input_ext}')

	println('${flasher} ${flags}')
	println(os.execute('${flasher} ${flags}').output)
}
