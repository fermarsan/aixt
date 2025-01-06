// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
module time

// sleep is a delay function in seconds for the Aixt PC port. 
pub fn sleep(ts int) {
	$if linux {
        C.sleep(ts)
	} $else {
        C.Sleep(ts*1000)
	}
}
