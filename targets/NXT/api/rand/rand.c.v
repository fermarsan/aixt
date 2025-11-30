// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Random numbers module for NXT (NXC backend)

module rand

fn C.srand(args ...any) int 
fn C.rand() u32 
fn C.Random(args ...any) i16

//cstdlib.c
@[as_macro]
pub fn srand(args ...any) int{
	return C.srand(...args) 
}

@[as_macro]
pub fn rand() u32 {
	return C.rand() 
}

@[as_macro]
pub fn random(args ...any) i16 {
	return C.Random(...args) 
}