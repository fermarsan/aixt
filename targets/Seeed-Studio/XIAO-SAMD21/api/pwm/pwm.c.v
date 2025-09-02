// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM functions (Arduino Nano - ATmega328P port)
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