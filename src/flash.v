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
pub fn flash(path string, flasher_path string, flasher_flags string, port string, project_setup setup.Setup) {
	// println('>>>>>>>>>>>>>>>>>> Flashing by: ${port} <<<<<<<<<<<<<<<<<<')

	flasher_os := $if windows {
		if project_setup.flasher['windows_path'] != '' {
			project_setup.flasher['windows_path']
		} else {
			project_setup.flasher['path']
		}
	} $else {
		project_setup.flasher['path']
	}

	mut flasher := ''
	if flasher_path != '' {
		flasher = flasher_path
	} else if flasher_os != '' {
		flasher = flasher_os
	} else {
		panic('The flasher path has to be specified as a flag or inside the `setup/<target>.json` file.')
	}
	mut flags := project_setup.flasher['args']
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
