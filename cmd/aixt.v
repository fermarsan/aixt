// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
import toml

device_path := {
	'Arduino-Nano':					'Atmel/Arduino-nano__ATmega328p/'
	'CY8C27443-24PXI':				'Cypress/CY8C27443-24PXI/'
	'CY8C29466-24PXI':				'Cypress/CY8C29466-24PXI/'
	'CY8CKIT-049-4245AXI-483':		'Cypress/CY8CKIT-049-42xx__CY8C4245AXI-483/'
	'CY3209ExEVK-21434-24LFX':		'Cypress/CY3209-ExpressEVK__CY8C21434-24LFX/'
	'CY3209ExEVK-24894-24LFXI':		'Cypress/CY3209-ExpressEVK__CY8C24894-24LFXI/'
	'CY3209ExEVK-27643-24LFXI':		'Cypress/CY3209-ExpressEVK__CY8C27643-24LFXI/'
	'CY3209ExEVK-29666-24LFXI':		'Cypress/CY3209-ExpressEVK__CY8C29666-24LFXI/'
	'ESP32-DEVKITV1':				'Espressif/ESP32-DEVKITV1__ESP32-S3/'
	'LQFP32-MiniEVB':				'LogicGreen/LQFP32-MiniEVB__lgt8f328p/'
	'Explorer-16-dsPIC33':			'Microchip/Explorer-16__dsPIC33FJ256GP710A/'
	'Explorer-16-PIC24':			'Microchip/Explorer-16__PIC24FJ128GA010/'
	'PIC16F84A':					'Microchip/PIC16F84A/'
	'PIC16F628A':					'Microchip/PIC16F628A/'
	'PIC16F676':					'Microchip/PIC16F676/'
	'PIC16F873A':					'Microchip/PIC16F873A/'
	'PIC16F886':					'Microchip/PIC16F886/'
	'PIC18F452':					'Microchip/PIC18F452/'
	'PIC18F2550':					'Microchip/PIC18F2550/'
	'NXC':							'NXC/'
	'PC':							'PC/'
	'RP2040':						'Raspberry-Pi/Raspberry-Pi-Pico__RP2040/'
	'Blue-Pill':					'ST/Blue-Pill__STM32F103C6/'
	'CH552-Core-Board':				'WCH/CH552-Core-Board__CH552/'
}

aixt_path := os.dir(os.dir(os.args[0]))	// aixt base path
os.chdir(aixt_path)?

command, device, input_name := os.args[1], os.args[2], os.args[3]	// capture arguments

println(device_path[device])

setup_file := os.norm_path('${aixt_path}/platforms/${device_path[device]}setup.toml')
setup := toml.parse_file(setup_file) or { panic(err) }


// base_name	:= input_name.replace('.aixt', '')	// input file base name

// cc := $if windows { setup.value('cc_windows').string() } $else { setup.value('cc_linux').string() }	

// aixt_path := setup.value('aixt_path').string()
// $if windows { aixt_path = aixt_api.replace('/', '\\') }

aixt_builder := os.norm_path(setup.value('aixt_builder').string())

match command {
	'transpile' {		
		file_list := os.walk_ext(os.dir(input_name), '.aixt')		// transpile secondary files
		for file in file_list { 
			if file != input_name {
				println(os.execute('v run ${aixt_builder} ${device} ${file}').output) 
			}
		}
		println(os.execute('v run ${aixt_builder} ${device} ${input_name}').output)	// transpile the main file
	}
	// 'compile' {	
	// 	// mut file_str_list := walk_ext(api_path, '.c').join(' ')
	// 	// println('file_str_list: ${file_str_list}')
	// 	// file_str_list += ' ' + walk_ext(dir(input_name), '.c').join(' ')
	// 	// println('file_str_list: ${file_str_list}')
	// 	// println(execute('${cc} ${file_str_list} -o ${base_name}').output)
	// 	println(execute('${cc} ${base_name}.c -o ${base_name}').output)
	// }
	// 'run' {
	// 	result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
	// 	println(result.output)
	// }
	// 'build' {		
	// 	println( execute('${python} ${aixtt} ${input_name}').output )							// transpile
	// 	// compile_directory(api_path, cc)
	// 	println( execute('${cc} ${base_name}.c -o ${base_name}').output )					// compile
	// 	result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }	// run
	// 	println(result.output)
	// }
	// 'clean' {
	// 	rm(base_name) or {}
	// 	rm('${base_name}.exe') or {}
	// 	rm('${base_name}.c') or {}
	// 	println('Output files cleaned.')
	// }
	// 'clean_all' {
	// 	mut result := execute('find . -name "*.c" -type f -delete') 
	// 	println(result.output)
	// 	result = execute('find . -name "*.exe" -type f -delete') 
	// 	println(result.output)
	// 	// result := execute('find . -name "*.c" -type f -delete') 
	// 	// println(result.output)
	// }
	else {
		println('Invalid make option.')
	}
}
