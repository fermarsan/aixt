module rune

// ctype.h
@[inline] is_upper() { return C.isupper() }
@[inline] is_lower() { return C.islower() }
@[inline] is_alpha() { return C.isalpha() }
@[inline] is_digit() { return C.isdigit() }
@[inline] is_alnum() { return C.isalnum() }
@[inline] is_space() { return C.isspace() }
@[inline] is_cntrl() { return C.iscntrl() }
@[inline] is_print() { return C.isprint() }
@[inline] is_graph() { return C.isgraph() }
@[inline] is_punct() { return C.ispunct() }
@[inline] is_xdigit() { return C.isxdigit() }
@[inline] to_upper() { return C.toupper() }
@[inline] to_lower() { return C.tolower() }
