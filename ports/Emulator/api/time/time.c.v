// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module time

fn C.sleep(ts any)
fn C.usleep(tms any)
fn C.Sleep(ts any)

$if linux {
	#include <unistd.h>
} $else {
	#include <windows.h>
}

