// Author: Fernando M. Santa
// Date: 2026
//
// ## Description
// Time module (ESP-IDF)
module time

fn C.vTaskDelay(tms int)

// sleep is a delay function in seconds for Arduino devices 
@[as_macro]
pub fn sleep(ts int) {
    C.vTaskDelay(ts*1000 / C.portTICK_PERIOD_MS)
}

// sleep is a delay function in milliseconds for Arduino devices 
@[as_macro]
pub fn sleep_ms(tms int) {
	C.vTaskDelay(tms / C.portTICK_PERIOD_MS)
}

// sleep is a delay function in microseconds for Arduino devices
// @[as_macro]
// pub fn sleep_us(tus int) {
// 	C.delay_Microseconds(tus)
// }