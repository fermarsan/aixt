// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Strings module for NXT (NXC backend)

module str

// cstring.h
@[as_macro]
pub fn to_num(str string) any {
	return C.StrToNum(str) 
}

@[as_macro]
pub fn index(str string, idx u16) u8 {
	return C.StrIndex(str, idx) 
}

@[as_macro]
pub fn sub(str string, idx u16, len u16) string {
	return C.SubStr(str, idx, len) 
}

@[as_macro]
pub fn replace(str string, idx u16, new string) string {
	return C.StrReplace(str, idx, new) 
}

@[as_macro]
pub fn pos(sub string, s string) i16 {
	return C.Pos(sub, s) 
}

@[as_macro]
pub fn from_byte_array(data []u8) string {
	return C.ByteArrayToStr(data) 
}

@[as_macro]
pub fn to_byte_array(str string, data &[]u8{}) {
	C.StrToByteArray(str, data) 
}

@[as_macro]
pub fn copy(str string, idx u16, len u16) string {
	return C.Copy(str, idx, len) 
}

@[as_macro]
pub fn mid(str string, idx u16, len u16) string {
	return C.MidStr(str, idx, len) 
}

@[as_macro]
pub fn right(str string, size u16) string {
	return C.RightStr(str, size) 
}

@[as_macro]
pub fn left(str string, size u16) string {
	return C.LeftStr(str, size) 
}

@[as_macro]
pub fn len(str string) i16 {
	return C.strlen(str) 
}

// Functions for use with NXC array types.
@[as_macro]
pub fn to_upper(src string) string {
	return C.UpperCase(src) 
}
 
@[as_macro]
pub fn to_lower(src string) string {
	return C.LowerCase(src) 
}
