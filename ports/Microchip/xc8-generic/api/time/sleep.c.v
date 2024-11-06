// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: seconds delay function for XC8 compiler
module time

// sleep function does a delay in seconds
@[inline]
pub fn sleep(ts u16) {
	C.__delay_ms(ts << 10) // ts*1024
}