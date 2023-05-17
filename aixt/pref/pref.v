// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

module pref

pub enum Backend {
	pc		// The PC C compiler backend (default)
	atmega	// XC8 compiler for ATmega backend
	psoc1	// imagecraft compiler for PSoC1 backend
	psoc4	// imagecraft compiler for PSoC3 backend
	esp32	// ESPIDF for ESP32 backend
	lqfp32	// XC8 compiler for lgt8f328p
	pic16	// XC8 compiler for PIC16 backend 
	pic18	// XC8 compiler for PIC18 backend 
	pic24	// XC16 compiler for PIC24 backend 
	dspic33	// XC16 compiler for dsPIC33 backend
	nxc		// NXC compiler for LEGO Mindstorms NXC backend
	rppico	// for raspberry pi pico backend
	st		// st compiler backend
	ch552	// ch522 backend
}

pub fn backend_from_string(s string) !Backend {
	match s {
		'pc'		{ return .pc }	
		'atmega'	{ return .atmega }	
		'psoc1'		{ return .psoc1 }
		'psoc4'		{ return .psoc4 }
		'esp32'		{ return .esp32 }
		'lqfp32'	{ return .lqfp32 }	
		'pic16'		{ return .pic16 }
		'pic18'		{ return .pic18 }
		'pic24'		{ return .pic24 }
		'dspic33'	{ return .dspic33 }	
		'nxc'		{ return .nxc }	
		'rppico'	{ return .rppico }	
		'st'		{ return .st }	
		'ch552'		{ return .ch552	}
		else { return error('Unknown backend type ${s}') }
	}
}

pub device_path := {
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
	'RP2040'						'Raspberry-Pi/Raspberry-Pi-Pico__RP2040/'
	'Blue-Pill':					'ST/Blue-Pill__STM32F103C6/'
	'CH552-Core-Board':				'WCH/CH552-Core-Board__CH552/'
}