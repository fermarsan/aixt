// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

#include "sleep.c"

// sleep is a delay function in seconds for the Aixt PC port. 
@[inline]
pub fn sleep(ts int) {
	C.sleep_s(ts)
}
