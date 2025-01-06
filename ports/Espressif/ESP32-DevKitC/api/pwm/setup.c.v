// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM setup (ESP32 port)
module pwm

// setup function configures de PWM hardware
@[inline]
pub fn setup(pin u8, freq u32, res u8) {
    C.analogWriteFrequency(pin, freq)
    // C.analogWriteRange(range) 
    C.analogWriteResolution(pin, res)                                                                                                                  
}                                                                                                                                                                                                                                                                                                        


