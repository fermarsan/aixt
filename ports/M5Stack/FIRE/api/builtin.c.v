module main

#include <M5Stack.h>
#include "builtin.c"

@[as_macro]
fn init() {
	C.M5_BEGIN()
}

@[as_macro]
fn update() {
	C.M5_UPDATE()
}