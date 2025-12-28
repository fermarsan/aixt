// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
//
// ## Description
// Random numbers functions
module random


// in_range generates a random number from min to max
@[inline]
pub fn in_range(min int, max int) int {
	return C.RANDOMINRANGE(min, max)
}