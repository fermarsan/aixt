// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions Arduino devices
module pin

fn C.digitalWrite(name u8, val u8)
fn C.digitalRead(name u8) u8
fn C.pinMode(name u8, mode u8)