// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Random numbers module for NXT (NXC backend)

module rand

//cstdlib.c
@[as_macro]
pub fn srand(seed int) int{
	return C.srand() 
}

@[as_macro]
pub fn rand() u32 {
	return C.rand() 
}

@[as_macro]
pub fn random(n i16) i16 {
	return C.Random(n) 
}