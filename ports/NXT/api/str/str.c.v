module str

// cstring.h
@[inline] to_num() { return C.StrToNum() }
@[inline] str_len() { return C.StrLen() }
@[inline] index() { return C.StrIndex() }
@[inline] from_num() { return C.NumToStr() }
@[inline] str_cat() { return C.StrCat() }
@[inline] sub() { return C.SubStr() }
@[inline] flatten() { return C.Flatten() }
@[inline] replace() { return C.StrReplace() }
@[inline] format_num() { return C.FormatNum() }
@[inline] format_val() { return C.FormatVal() }
@[inline] flatten_var() { return C.FlattenVar() }
@[inline] unflatten_var() { return C.UnflattenVar() }
@[inline] pos() { return C.Pos() }
@[inline] byte_array_to() { return C.ByteArrayToStr() }
@[inline] byte_array_to_ex() { return C.ByteArrayToStrEx() }
@[inline] to_byte_array() { return C.StrToByteArray() }
@[inline] copy() { return C.Copy() }
@[inline] mid() { return C.MidStr() }
@[inline] right() { return C.RightStr() }
@[inline] left() { return C.LeftStr() }
@[inline] len() { return C.strlen() }
@[inline] cat() { return C.strcat() }
@[inline] n_cat() { return C.strncat() }
@[inline] cpy() { return C.strcpy() }
@[inline] n_cpy() { return C.strncpy() }
@[inline] cmp() { return C.strcmp() }
@[inline] n_cmp() { return C.strncmp() }
@[inline] memcpy() { return C.memcpy() }
@[inline] memmove() { return C.memmove() }
@[inline] memcmp() { return C.memcmp() }
@[inline] address_of() { return C.addressOf() }
@[inline] reladdress_of() { return C.reladdressOf() }
@[inline] address_of_ex() { return C.addressOfEx() }

// Functions for use with NXC array types.
@[inline] upper_case() { return C.UpperCase() } 
@[inline] lower_case() { return C.LowerCase() } 
@[inline] upper_case_ex() { return C.UpperCaseEx() } 
@[inline] lower_case_ex() { return C.LowerCaseEx() } 
