// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
module time

// sleep is a delay function in milliseconds for the Aixt PC port. 
pub fn sleep_ms(tms int) {
	$if linux {
		C.usleep(tms*1000)
    } $else {
        C.Sleep(tms)
	}
}