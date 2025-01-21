// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module aixt_build

import os
import aixt_setup

// flash_file downloads (uploads) the binary file to the device.
// example:
// ``` v
// aixt_build.flash_file('example.hex', '/dev/ttyUSB0', setup)
// ``` 
// Calls the flashing tool to pass the binary file to the device
pub fn flash_file(path string, port string, setup aixt_setup.Setup) {

	flasher := $if windows { // flashing tool depending on the OS
		setup.flasher_windows
	} $else {
		setup.flasher_linux
	}

	mut flags := setup.cc_make_flags
	flags = flags.replace('@{file_no_ext}', '${path}')	
	flags = flags.replace('@{file_dir_name}', '${os.dir(path)}')	
	flags = flags.replace('@{device}', '${setup.device}')	
	flags = flags.replace('@{port}', '${port}')

	input_ext := match setup.backend {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}
	flags = flags.replace('@{input_ext}', '${input_ext}')

	println('${flasher} ${flags}')
	println(os.execute('${flasher} ${flags}').output)
}