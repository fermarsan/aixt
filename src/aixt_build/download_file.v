// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module aixt_build

import os
import aixt_setup

// download_file downloads (uploads) the binary file to the device.
// example:
// ``` v
// aixt_build.download_file('example.hex', '/dev/ttyUSB0', setup)
// ``` 
// Calls the flashing tool to pass the binary file to the device
pub fn download_file(path string, port string, setup aixt_setup.Setup) {

	cc := $if windows { // C compiler depending on the OS
		setup.cc_windows
	} $else {
		setup.cc_linux
	}

	mut flags := setup.cc_make_flags
	flags = flags.replace('@{file_no_ext}', '${path}')	
	flags = flags.replace('@{file_dir_name}', '${os.dir(path)}')	
	flags = flags.replace('@{device}', '${setup.device}')

	input_ext := match setup.backend {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}
	flags = flags.replace('@{input_ext}', '${input_ext}')

	output_ext := match setup.port {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else	{ '' }
	}
	flags = flags.replace('@{output_ext}', '${output_ext}')	

	// println('-------- ${os.dir(path)} --------')
	if os.exists('${os.dir(path)}/Makefile') {		// calling compiler through Makefile
		println('make -f ${os.dir(path)}/Makefile ${flags}')
		println(os.execute('make -f ${os.dir(path)}/Makefile ${flags}').output)
	} else {
		println('${cc} ${flags}')
		println(os.execute('${cc} ${flags}').output)
	}
}