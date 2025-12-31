// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// PWM management functions (PIC16F88x port)
module pwm

@[as_macro] pub const ch1	    = 0b11111_01_1  // PWM channels
@[as_macro] pub const ch2	    = 0b11111_10_1  // for both use pwm.ch1 & pwm.ch2

@[as_macro] pub const f_high	= 0b000000_00 // PWM frequency div by 1
@[as_macro] pub const f_med	  = 0b000000_01 // div by 4
@[as_macro] pub const f_low	  = 0b000000_10 // div by 16

// setup function configures the PWM
//
// for a resolution of 100 steps by period (res = 100):
//
// | fosc   | f_high   | f_med     | f_low    |
// |--------|----------|-----------|----------|
// | 20 Mhz | 50 khz   | 12.5 khz  | 3125 hz  |
// | 16 Mhz | 40 khz   | 10 khz    | 2500 hz  |
// | 12 Mhz | 30 khz   | 7.5 khz   | 1875 hz  |
// | 10 Mhz | 25 khz   | 6.25 khz  | 1563 hz  |
// | 8 Mhz  | 20 khz   | 5 khz     | 1250 hz  |
// | 4 Mhz  | 10 khz   | 2.5 khz   | 625 hz   |
//
// for a resolution of 100 steps by period (res = 250):
//
// | fosc   | f_high   | f_med     | f_low    |
// |--------|----------|-----------|----------|
// | 20 Mhz | 20 khz   | 5 khz     | 1.25 khz |
// | 16 Mhz | 16 khz   | 4 khz     | 1 khz    |
// | 12 Mhz | 12 khz   | 3 khz     | 750 hz   |
// | 10 Mhz | 10 khz   | 2.5 khz   | 625 hz   |
// | 8 Mhz  | 8 khz    | 2 khz     | 500 hz   |
// | 4 Mhz  | 4 khz    | 1 khz     | 250 hz   |
@[as_macro]
pub fn setup(channel u8, res u8, freq u8) {
  C.TRISC &= channel
  C.PR2 = res
  C.T2CON &= 0b111111_00;   C.T2CON |= freq
  C.TMR2 = 0
  C.TMR2ON = 1
  if (channel | ch1) == ch1 {
    C.CCP1CON = 0b00_00_1100
  }
  if (channel | ch2) == ch2 {
    C.CCP2CON = 0b00_00_1100
  }
}

// write function sets the 8-bit duty cycle to a PWM channel
@[as_macro]
pub fn write(channel u8, duty u8) {
  if channel == ch1 {
    C.CCPR1L = duty
  } else if channel == ch2 {
    C.CCPR2L = duty
  }
}

// Función para el ciclo de trabajo
// @[as_macro]
// fn write(duty u16) {
//     pwm := ((duty - 0) * (60 - 0) / (256 - 0) + 0)
//     C.CCPR2L = (pwm >> 2)
// }
