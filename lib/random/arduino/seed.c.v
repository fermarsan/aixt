// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
//
// ## Description
// Random numbers functions
module random


// seed initializes the pseudo-random number generator
@[inline]
pub fn seed(s u32) {
	C.randomSeed(s)
}