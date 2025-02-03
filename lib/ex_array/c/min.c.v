// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 29/01/2025
// License: MIT
//
// Description: Example of a Library module (array).
//
module ex_array

// min returns the minimum value of an array.
pub fn min(src []int, len_ u16) int {
	mut minimum := src[0]
	for i in 1..len_ {
		minimum = if minimum < src[i] { 
			minimum 
		} else { 
			src[i] 
		}
	}
	return minimum
}