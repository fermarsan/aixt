// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Rune (characters) module for NXT (NXC backend)

module rune

fn C.isupper(c i16) i16
fn C.islower(c i16) i16
fn C.isalpha(c i16) i16
fn C.isdigit(c i16) i16
fn C.isalnum(c i16) i16
fn C.isspace(c i16) i16
fn C.iscntrl(c i16) i16
fn C.isprint(c i16) i16
fn C.isgraph(c i16) i16
fn C.ispunct(c i16) i16
fn C.isxdigit(c i16) i16
fn C.toupper(c i16) i16
fn C.tolower(c i16) i16 



// ctype.h
@[as_macro]
pub fn is_upper(c i16) i16 {
	return C.isupper(c) 
}


@[as_macro]
pub fn is_lower(c i16) i16 {
	return C.islower(c) 
}

@[as_macro]
pub fn is_alpha(c i16) i16 {
	return C.isalpha(c) 
}

@[as_macro]
pub fn is_digit(c i16) i16 {
	return C.isdigit(c) 
}

@[as_macro]
pub fn is_alnum(c i16) i16 {
	return C.isalnum(c) 
}

@[as_macro]
pub fn is_space(c i16) i16 {
	return C.isspace(c) 
}

@[as_macro]
pub fn is_cntrl(c i16) i16 {
	return C.iscntrl(c) 
}

@[as_macro]
pub fn is_print(c i16) i16 {
	return C.isprint(c) 
}

@[as_macro]
pub fn is_graph(c i16) i16 {
	return C.isgraph(c) 
}

@[as_macro]
pub fn is_punct(c i16) i16 {
	return C.ispunct(c) 
}

@[as_macro]
pub fn is_xdigit(c i16) i16 {
	return C.isxdigit(c) 
}

@[as_macro]
pub fn to_upper(c i16) i16 {
	return C.toupper(c) 
}

@[as_macro]
pub fn to_lower(c i16) i16 {
	return C.tolower(c) 
}

