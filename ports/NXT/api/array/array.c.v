module array

// Functions for use with NXC array types.
@[as_macro]
pub fn build(args ...any) {
	C.ArrayBuild(args) 
}
 
@[as_macro]
pub fn len(arg any) u16{
	return C.ArrayLen(arg) 
}
 
@[as_macro]
pub fn subset(args ...any) {
	C.ArraySubset(args) 
}
 
@[as_macro]
pub fn sum(args ...any) any {
	return C.ArraySum(args) 
}
 
@[as_macro]
pub fn mean(args ...any) any {
	return C.ArrayMean(args) 
}
 
@[as_macro]
pub fn sum_sqr(args ...any) any {
	return C.ArraySumSqr(args) 
}
 
@[as_macro]
pub fn std(args ...any) any {
	return C.ArrayStd(args) 
}
 
@[as_macro]
pub fn min(args ...any) any {
	return C.ArrayMin(args) 
}
 
@[as_macro]
pub fn max(args ...any) any {
	return C.ArrayMax(args) 
}
 
@[as_macro]
pub fn sort(args ...any) {
	C.ArraySort(args) 
}
 
@[as_macro]
pub fn op(args ...any) {
	C.ArrayOp(args) 
}
