// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions Arduino devices
module pin

// fn C.pinMode(name u8, mode u8)		// uncomment if not included in api/builtin.c.v 
// fn C.digitalWrite(name u8, val u8)	// uncomment if not included in api/builtin.c.v 
fn C.digitalRead(name u8) u8
fn C.DIGITAL_TOGGLE(name u8)
// fn C.digitalPinToPort(name u8)
// fn C.digitalPinToBitMask(name u8)
// fn C.portInputRegister(name u32)