// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 29/01/2025
// License: MIT
//
// Description: Example of a Library module (array).
//
module ex_array

// min returns the minimum value of an array.
@[as_macro]
pub fn min(src []any, len u16) any {
	return C.ArrayMin(src, C.NA, len)
}