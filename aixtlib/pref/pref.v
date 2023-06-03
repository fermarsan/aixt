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
	'Arduino-Nano':					'Atmel/Arduino-nano__ATmega328p/'
	'CY8CKIT-049-4245AXI-483':		'Cypress/CY8CKIT-049-42xx__CY8C4245AXI-483/'
	'ESP32-DEVKITV1':				'Espressif/ESP32-DEVKITV1__ESP32-S3/'
	'LQFP32-MiniEVB':				'LogicGreen/LQFP32-MiniEVB__lgt8f328p/'
	'Explorer16-dsPIC33':			'Microchip/Explorer16__dsPIC33FJ256GP710A/'
	'Explorer16-PIC24':				'Microchip/Explorer16__PIC24FJ128GA010/'
	'PIC16F84A':					'Microchip/PIC16F84A/'
	'PIC16F628A':					'Microchip/PIC16F628A/'
	'PIC16F676':					'Microchip/PIC16F676/'
	'PIC16F873A':					'Microchip/PIC16F873A/'
	'PIC16F886':					'Microchip/PIC16F886/'
	'PIC18F452':					'Microchip/PIC18F452/'
	'PIC18F2550':					'Microchip/PIC18F2550/'
	'NXC':							'NXC/'
	'PC':							'PC/'
	'RP2040'						'Raspberry-Pi/Raspberry-Pi-Pico__RP2040/'
	'Blue-Pill':					'ST/Blue-Pill__STM32F103C6T6/'
	'CH552-Core-Board':				'WCH/CH552-Core-Board__CH552/'
	'MH-Tiny':						'Atmel/MH-Tiny__ATtiny88/'
}