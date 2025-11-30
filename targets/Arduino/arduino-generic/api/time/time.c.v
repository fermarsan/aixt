// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Time module (Arduino devices)
module time

fn C.delay(tms int)
fn C.delayMicroseconds(tus int)

// sleep is a delay function in seconds for Arduino devices 
@[as_macro]
pub fn sleep(ts int) {
    C.delay(ts*1000)
}

// sleep is a delay function in milliseconds for Arduino devices 
@[as_macro]
pub fn sleep_ms(tms int) {
	C.delay(tms)
}

// sleep is a delay function in microseconds for Arduino devices
@[as_macro]
pub fn sleep_us(tus int) {
	C.delayMicroseconds(tus)
}