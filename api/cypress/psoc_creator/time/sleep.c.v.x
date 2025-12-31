// Author: Fernando M. Santa
// Date: 2024

module time

// sleep is a delay function in seconds for Arduino devices
@[as_macro]
pub fn sleep(ts int) {
    C.delay(ts*1000)
}
