// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Strings module for NXT (NXC backend)

module str


fn C.StrToNum(args ...any) any
fn C.StrIndex(args ...any) u8
fn C.SubStr(args ...any) string
fn C.StrReplace(args ...any) string
fn C.Pos(args ...any) i16
fn C.ByteArrayToStr(args ...any) string
fn C.StrToByteArray(args ...any)
fn C.Copy(args ...any) string
fn C.MidStr(args ...any) string
fn C.RightStr(args ...any) string
fn C.LeftStr(args ...any) string
fn C.strlen(args ...any) i16
fn C.UpperCase(args ...any) string
fn C.LowerCase(args ...any) string


// cstring.h
@[as_macro]
pub fn to_num[T](args ..any) T {
	return C.StrToNum(...args) 
}

@[as_macro]
pub fn index(args ..any) u8 {
	return C.StrIndex(...args) 
}

@[as_macro]
pub fn sub(args ..any) string {
	return C.SubStr(...args) 
}

@[as_macro]
pub fn replace(args ..any) string {
	return C.StrReplace(...args) 
}

@[as_macro]
pub fn pos(args ..any) i16 {
	return C.Pos(...args) 
}

@[as_macro]
pub fn from_byte_array(args ..any) string {
	return C.ByteArrayToStr(...args) 
}

@[as_macro]
pub fn to_byte_array(args ..any) {
	C.StrToByteArray(...args) 
}

@[as_macro]
pub fn copy(args ..any) string {
	return C.Copy(...args) 
}

@[as_macro]
pub fn mid(args ..any) string {
	return C.MidStr(...args) 
}

@[as_macro]
pub fn right(args ..any) string {
	return C.RightStr(...args) 
}

@[as_macro]
pub fn left(args ..any) string {
	return C.LeftStr(...args) 
}

@[as_macro]
pub fn len(args ..any) i16 {
	return C.strlen(...args) 
}

// Functions for use with NXC array types.
@[as_macro]
pub fn to_upper(args ..any) string {
	return C.UpperCase(...args) 
}
 
@[as_macro]
pub fn to_lower(args ..any) string {
	return C.LowerCase(...args) 
}
