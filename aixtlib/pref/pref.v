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