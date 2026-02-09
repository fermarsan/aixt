// Author: Fernando M. Santa
// Date: 2026
// ## Description
module main

import os
import v.vmod

// c_compile_cmd is called after command `aixt c_compile [flags] source_file`
fn aixt_vmod_load(path string) vmod.Manifest {
	v_mod := vmod.from_file(os.norm_path('${path}/v.mod')) or { 
		vmod.Manifest {
			name: ''
			description: ''
			version: ''
			license: ''
			dependencies: []
			unknown: { 
				'target': [''], 
				'port': ['/dev/ttyUSB0'], 
				'cc': ['', ''],
				'flasher': ['', '']
			}
		}
	}

	return v_mod
}