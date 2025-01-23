// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Random numbers functions
module random


// seed initializes the pseudo-random number generator
@[inline]
pub fn seed(s u32) {
	C.randomSeed(s)
}