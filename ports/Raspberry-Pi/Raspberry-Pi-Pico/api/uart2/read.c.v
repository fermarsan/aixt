// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart2

// read function reads incoming serial data
@[inline]
pub fn read() u8 {
	return C.Serial2.read()
}