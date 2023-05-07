/ This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
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
	ch552	// for ch522 backend
}

pub fn backend_from_string(s string) !Backend {
	// TODO: unify the "different js backend" options into a single `-b js`
	// + a separate option, to choose the wanted JS output.
	match s {
		'c' { return .c }
		'go' { return .golang }
		'interpret' { return .interpret }
		'js' { return .js_node }
		'js_node' { return .js_node }
		'js_browser' { return .js_browser }
		'js_freestanding' { return .js_freestanding }
		'native' { return .native }
		'wasm' { return .wasm }
		else { return error('Unknown backend type ${s}') }
	}
}