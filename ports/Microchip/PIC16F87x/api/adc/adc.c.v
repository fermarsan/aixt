// Project name: Aixt,
 https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)
module adc


@[as_macro] pub const all_analogs		= 0b0000_0000
@[as_macro] pub const all_analogs_rp	= 0b0000_0001
@[as_macro] pub const in0_to_in4		= 0b0000_0010
@[as_macro] pub const in0_to_in4_rp		= 0b0000_0011
@[as_macro] pub const in0_in1_in3		= 0b0000_0100
@[as_macro] pub const in0_in1_rp		= 0b0000_0101
@[as_macro] pub const all_digitals		= 0b0000_0110
// @[as_macro] pub const all_digitals		= 0b0000_0111
@[as_macro] pub const all_analogs_rp_rn	= 0b0000_1000
@[as_macro] pub const in0_to_in5		= 0b0000_1001
@[as_macro] pub const in0_to_in5_rp		= 0b0000_1010
@[as_macro] pub const in0_to_in5_rp_rn	= 0b0000_1011
@[as_macro] pub const in0_to_in4_rp_rn	= 0b0000_1100
@[as_macro] pub const in0_in1_rp_rn		= 0b0000_1101
@[as_macro] pub const in0				= 0b0000_1110
@[as_macro] pub const in0_rp_rn			= 0b0000_1111