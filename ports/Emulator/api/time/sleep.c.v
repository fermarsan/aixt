// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep is a delay function in seconds for the Aixt PC port. 
@[inline]
pub fn sleep(ts int) {
	$if on_linux {
        C.sleep(ts)
	} $else {
        C.Sleep(ts*1000)
	}
}
