// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
// License: MIT
module time

// sleep is a delay function in seconds for Arduino devices 
@[as_macro]
pub fn sleep(ts int) {
    C.delay(ts*1000)
}