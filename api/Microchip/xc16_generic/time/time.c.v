// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// delay functions for XC8 compiler

module time

fn C.__delay_ms(tms u16)
fn C.__delay_us(tus u16)

// sleep function does a delay in seconds
@[as_macro]
pub fn sleep(ts u16) {
	C.__delay_ms(ts << 10) // ts*1024
}

// sleep_ms function does a delay in milliseconds
@[as_macro]
pub fn sleep_ms(tms u16) {
	C.__delay_ms(tms)
}

// sleep_us function does a delay in microseconds
@[as_macro]
pub fn sleep_us(tus u16) {
	C.__delay_us(tus)
}
