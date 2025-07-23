// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: adc functions (CY8CKIT-049-42XX)
module adc


@[as_macro]	pub const ch0 = 0	
@[as_macro]	pub const ch1 = 1	
@[as_macro]	pub const ch2 = 2	
@[as_macro]	pub const ch3 = 3	

fn C.adc_Start()           
fn C.amux_Start()      
fn C.amux_FastSelect(channel int)   
fn C.adc_StartConvert()   
fn C.adc_StopConvert()    
fn C.adc_IsEndConversion(status int) bool
fn C.adc_GetResult16(channel int) u16 
fn C.CyDelay(tms int) 

