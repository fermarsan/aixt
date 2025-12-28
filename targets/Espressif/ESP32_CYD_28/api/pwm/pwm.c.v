// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// PWM functions (ESP32 port)
module pwm

fn C.analogWriteFrequency(pin any, freq any) 
// fn C.analogWriteRange(range any) 
fn C.analogWriteResolution(pin any, res any) 

// setup function configures de PWM hardware
@[inline]
pub fn setup(pin u8, freq u32, res u8) {
    C.analogWriteFrequency(pin, freq)
    // C.analogWriteRange(range) 
    C.analogWriteResolution(pin, res)                                                                                                                  
} 