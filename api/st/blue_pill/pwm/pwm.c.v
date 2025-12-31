// Authors:
//	 - Julian Camilo Guzmán Zambrano
//	 - Juan Pablo Gonzalez Penagos
//	 - Fernando M. Santa
// Date: 2022-2025
//
// ## Description
// PWM functions (Blue-Pill port)
module pwm

fn C.analogWriteFreq(freq any)
fn C.analogWriteRange(range any)
fn C.analogWriteResolution(res any)

// setup function configures de PWM hardware
@[inline]
pub fn setup(freq u32, range u32, res u8) {
    // C.analogWriteFreq(freq)
    // C.analogWriteRange(range)
    C.analogWriteResolution(res)
}
