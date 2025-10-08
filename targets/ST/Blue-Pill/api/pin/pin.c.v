// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 11/06/2025
// License: MIT
//
// Description: Pin management Blue-Pill
module pin

// pin names
@[as_macro]	pub const a0	=	192
@[as_macro]	pub const a1	=	193
@[as_macro]	pub const a2	=	194
@[as_macro]	pub const a3	=	195
@[as_macro]	pub const a4	=	196
@[as_macro]	pub const a5	=	197
@[as_macro]	pub const a6	=	198
@[as_macro]	pub const a7	=	199
@[as_macro]	pub const a8	=	12
@[as_macro]	pub const a9	=	11
@[as_macro]	pub const a10	=	10
@[as_macro]	pub const a11	=	9		// USB DM
@[as_macro]	pub const a12	=	8		// USB DP

@[as_macro]	pub const a15	=	7

@[as_macro]	pub const b0	=	200
@[as_macro]	pub const b1	=	201

@[as_macro]	pub const b3	=	6
@[as_macro]	pub const b4	=	5
@[as_macro]	pub const b5	=	4
@[as_macro]	pub const b6	=	3
@[as_macro]	pub const b7	=	2
@[as_macro]	pub const b8	=	1
@[as_macro]	pub const b9	=	0
@[as_macro]	pub const b10	=	30
@[as_macro]	pub const b11	=	31
@[as_macro]	pub const b12	=	16
@[as_macro]	pub const b13	=	15
@[as_macro]	pub const b14	=	14
@[as_macro]	pub const b15	=	13

@[as_macro]	pub const c13	=	17		// LED Bluepill
@[as_macro]	pub const c14	=	18
@[as_macro]	pub const c15	=	19

// builtin LED
@[as_macro]	pub const led0 = 17