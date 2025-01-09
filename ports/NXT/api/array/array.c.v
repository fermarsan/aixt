// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Array module for NXT (NXC backend)

module array

@[as_macro] pub const op_sum     = C.OPARR_SUM    
@[as_macro] pub const op_mean    = C.OPARR_MEAN   
@[as_macro] pub const op_sumsqr  = C.OPARR_SUMSQR 
@[as_macro] pub const op_std     = C.OPARR_STD    
@[as_macro] pub const op_min     = C.OPARR_MIN    
@[as_macro] pub const op_max     = C.OPARR_MAX    
@[as_macro] pub const op_sort    = C.OPARR_SORT   
@[as_macro] pub const op_toupper = C.OPARR_TOUPPER
@[as_macro] pub const op_tolower = C.OPARR_TOLOWER

fn C.ArrayBuild(args ...any)
fn C.ArrayLen(args ...any) u16
fn C.ArraySubset(args ...any)
fn C.ArraySum(args ...any) any
fn C.ArrayMean(args ...any) any
fn C.ArraySumSqr(args ...any) any
fn C.ArrayStd(args ...any) any
fn C.ArrayMin(args ...any) any
fn C.ArrayMax(args ...any) any
fn C.ArraySort(args ...any)
fn C.ArrayOp(args ...any)

// Functions for use with NXC array types.
@[as_macro]
pub fn build(args ...any) {
	C.ArrayBuild(...args) 
}
 
@[as_macro]
pub fn len(arg any) u16{
	return C.ArrayLen(arg) 
}
 
@[as_macro]
pub fn subset(args ...any) {
	C.ArraySubset(...args) 
}
 
@[as_macro]
pub fn sum(args ...any) any {
	return C.ArraySum(...args) 
}
 
@[as_macro]
pub fn mean(args ...any) any {
	return C.ArrayMean(...args) 
}
 
@[as_macro]
pub fn sum_sqr(args ...any) any {
	return C.ArraySumSqr(...args) 
}
 
@[as_macro]
pub fn std(args ...any) any {
	return C.ArrayStd(...args) 
}
 
@[as_macro]
pub fn min(args ...any) any {
	return C.ArrayMin(...args) 
}
 
@[as_macro]
pub fn max(args ...any) any {
	return C.ArrayMax(...args) 
}
 
@[as_macro]
pub fn sort(args ...any) {
	C.ArraySort(...args) 
}
 
@[as_macro]
pub fn op(args ...any) {
	C.ArrayOp(...args) 
}
