// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC functions
module adc

@[as_macro]	pub const ch0 = 0	
@[as_macro]	pub const ch1 = 1	
@[as_macro]	pub const ch2 = 2	
@[as_macro]	pub const ch3 = 3

fn C.capsense_ADC_Start()
fn C.capsense_ADC_AdcReadResult_mVolts(channel int) u16
fn C.capsense_ADC_AdcGetResult_mVolts(channel int) u16
fn C.capsense_ADC_AdcStartConvert()
fn C.capsense_ADC_AdcStop()
fn C.CyDelay(tms int)
