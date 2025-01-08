// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Random numbers module for NXT (NXC backend)

module rand

fn C.srand(seed int) int 
fn C.rand() u32 
fn C.Random(n i16) i16

//cstdlib.c
@[as_macro]
pub fn srand(seed int) int{
	return C.srand(seed) 
}

@[as_macro]
pub fn rand() u32 {
	return C.rand() 
}

@[as_macro]
pub fn random(n i16) i16 {
	return C.Random(n) 
}