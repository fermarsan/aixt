// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin-port functions for 16F family
module port

// b_pull_ups function enable or disable the pull up resistors of port B
@[as_macro]
pub fn b_pull_ups(enable bool) {
	C.RBPU = int(!enable)
}
