module main

#include <M5Stack.h>
#include "main.c"

@[as_macro]
fn init() {
	C.M5_BEGIN()
}

@[as_macro]
fn update() {
	C.M5_UPDATE()
}
