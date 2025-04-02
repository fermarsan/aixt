// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Random numbers functions
module random


// rand generates a random number from 0 to max
@[inline]
pub fn rand(max int) int {
	return C.random(max)
}