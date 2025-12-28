// Project name: Aixt,
// https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)
module adc

#include "adc.c"

// ADC analog pins
@[as_macro] pub const all_analogs       = u8(0b0000)
@[as_macro] pub const all_analogs_rp    = u8(0b0001)
@[as_macro] pub const in0_to_in4	      = u8(0b0010)
@[as_macro] pub const in0_to_in4_rp     = u8(0b0011)
@[as_macro] pub const in0_in1_in3	      = u8(0b0100)
@[as_macro] pub const in0_in1_rp	      = u8(0b0101)
@[as_macro] pub const all_digitals	    = u8(0b0110)
// @[as_macro] pub const all_digitals      = u8(0b0111)
@[as_macro] pub const all_analogs_rp_rn = u8(0b1000)
@[as_macro] pub const in0_to_in5	      = u8(0b1001)
@[as_macro] pub const in0_to_in5_rp     = u8(0b1010)
@[as_macro] pub const in0_to_in5_rp_rn  = u8(0b1011)
@[as_macro] pub const in0_to_in4_rp_rn  = u8(0b1100)
@[as_macro] pub const in0_in1_rp_rn	    = u8(0b1101)
@[as_macro] pub const in0			          = u8(0b1110)
@[as_macro] pub const in0_rp_rn	        = u8(0b1111)

// ADC conversion bits
@[as_macro] pub const bits_8	= u8(0)
@[as_macro] pub const bits_10	= u8(1)

// ADC input channels
@[as_macro] pub const ch0 	= 0
@[as_macro] pub const ch1 	= 1
@[as_macro] pub const ch2 	= 2
@[as_macro] pub const ch3 	= 3
@[as_macro] pub const ch4 	= 4
@[as_macro] pub const ch5 	= 5
@[as_macro] pub const ch6 	= 6
@[as_macro] pub const ch7 	= 7

@[as_macro]
pub fn setup(pins u8, n_bits u8) {
  match pins {
    all_analogs,
    all_analogs_rp,
    all_analogs_rp_rn   { C.TRISA |= 0b00_1_0_1111;   C.TRISE |= 0b00000_111 }
    in0_to_in5,
    in0_to_in5_rp,
    in0_to_in5_rp_rn    { C.TRISA |= 0b00_1_0_1111;   C.TRISE |= 0b00000_001 }
    in0_to_in4,
    in0_to_in4_rp,
    in0_to_in4_rp_rn    { C.TRISA |= 0b00_1_0_1111 }
    in0_in1_in3,
    in0_in1_rp          { C.TRISA |= 0b00_0_0_1011 }
    in0_in1_rp_rn       { C.TRISA |= 0b00_0_0_1111 }
    in0_rp_rn           { C.TRISA |= 0b00_0_0_1101 }
    in0                 { C.TRISA |= 0b00_0_0_0001 }
    else                {  } // all_digitals
  }
  C.ADFM = n_bits
  C.ADCON1_PCFG = pins
  C.ADCON0_ADCS = match C._const_main__cpu_freq_mhz { // depends on CPU frequency
    6 ... 20  { 0b10 }
    2 ... 5   { 0b01 }
    else      { 0b00 }
  }
  C.ADON = 1
}

@[as_macro]
fn start_conversion(channel u8) {
  C.ADCON0_CHS = channel  // Assigns the ADC channel
  C.GO_DONE = 1    // Starts conversion
  for C.GO_DONE == 1 {}	// Waits for conversion to end
}

@[inline]
pub fn read(channel u8) u16 {
  start_conversion(channel)
  return u16((C.ADRESH << 8) | C.ADRESL )  // Return the ADC value
}

@[inline]
pub fn read_byte(channel u8) u8 {
  start_conversion(channel)
  return u8(C.ADRESH) // Return the ADC value
}
