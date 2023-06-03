// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

module aixt_pref

pub enum Backend {
	native		// The native C compiler of each microcontroller (default)
	pc			// The PC C compiler backend
	arduino		// Arduino compiler
	nxc			// NXC compiler for LEGO Mindstorms NXT
}

pub fn backend_from_string(s string) !Backend {
	match s {	
		'native'	{ return .native }
		'pc'		{ return .pc }		
		'arduino'	{ return .arduino }
		'nxc'		{ return .nxc }		
		else		{ return error('Unknown backend type ${s}') }
	}
}

pub map device_path := {
	'Arduino-Nano':			'Atmel/Arduino-nano/'
	'CY8CKIT-049-4245':		'Cypress/CY8CKIT-049-4245/'
	'ESP32-DEVKITV1':		'Espressif/ESP32-DEVKITV1'
	'LQFP32-MiniEVB':		'LogicGreen/LQFP32-MiniEVB/'
	'Explorer16-dsPIC33':	'Microchip/Explorer16/dsPIC33/'
	'Explorer16-PIC24':		'Microchip/Explorer16/PIC24/'
	'PIC16F84A':			'Microchip/PIC16F84A/'
	'PIC16F628A':			'Microchip/PIC16F628A/'
	'PIC16F676':			'Microchip/PIC16F676/'
	'PIC16F873A':			'Microchip/PIC16F873A/'
	'PIC16F886':			'Microchip/PIC16F886/'
	'PIC18F452':			'Microchip/PIC18F452/'
	'PIC18F2550':			'Microchip/PIC18F2550/'
	'NXC':					'NXC/'
	'PC':					'PC/'
	'RP2040'				'Raspberry-Pi/Raspberry-Pi-Pico/'
	'Blue-Pill':			'ST/Blue-Pill/'
	'CH552-Core':			'WCH/CH552-Core-Board/'
	'MH-Tiny':				'Atmel/MH-Tiny/'
}