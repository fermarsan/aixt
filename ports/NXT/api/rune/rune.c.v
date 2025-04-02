// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Rune (characters) module for NXT (NXC backend)

module rune

fn C.isupper(args ...any) i16
fn C.islower(args ...any) i16
fn C.isalpha(args ...any) i16
fn C.isdigit(args ...any) i16
fn C.isalnum(args ...any) i16
fn C.isspace(args ...any) i16
fn C.iscntrl(args ...any) i16
fn C.isprint(args ...any) i16
fn C.isgraph(args ...any) i16
fn C.ispunct(args ...any) i16
fn C.isxdigit(args ...any) i16
fn C.toupper(args ...any) i16
fn C.tolower(args ...any) i16 



// ctype.h
@[as_macro]
pub fn is_upper(args ...any) i16 {
	return C.isupper(...args) 
}


@[as_macro]
pub fn is_lower(args ...any) i16 {
	return C.islower(...args) 
}

@[as_macro]
pub fn is_alpha(args ...any) i16 {
	return C.isalpha(...args) 
}

@[as_macro]
pub fn is_digit(args ...any) i16 {
	return C.isdigit(...args) 
}

@[as_macro]
pub fn is_alnum(args ...any) i16 {
	return C.isalnum(...args) 
}

@[as_macro]
pub fn is_space(args ...any) i16 {
	return C.isspace(...args) 
}

@[as_macro]
pub fn is_cntrl(args ...any) i16 {
	return C.iscntrl(...args) 
}

@[as_macro]
pub fn is_print(args ...any) i16 {
	return C.isprint(...args) 
}

@[as_macro]
pub fn is_graph(args ...any) i16 {
	return C.isgraph(...args) 
}

@[as_macro]
pub fn is_punct(args ...any) i16 {
	return C.ispunct(...args) 
}

@[as_macro]
pub fn is_xdigit(args ...any) i16 {
	return C.isxdigit(...args) 
}

@[as_macro]
pub fn to_upper(args ...any) i16 {
	return C.toupper(...args) 
}

@[as_macro]
pub fn to_lower(args ...any) i16 {
	return C.tolower(...args) 
}

