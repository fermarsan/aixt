// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
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

// sleep is a delay function in seconds for the Aixt PC port. 
pub fn sleep(ts int) {
	$if linux {
        C.sleep(ts)
	} $else {
        C.Sleep(ts*1000)
	}
}

// sleep_ms is a delay function in milliseconds for the Aixt PC port. 
pub fn sleep_ms(tms int) {
	$if linux {
		C.usleep(tms*1000)
    } $else {
        C.Sleep(tms)
	}
}