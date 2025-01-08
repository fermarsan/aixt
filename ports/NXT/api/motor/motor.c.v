// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Motor module for NXT (NXC backend)

module motor	// NXC Output

// Output port constants are used when calling motor control API functions. 
@[as_macro] const a   = 0x00
@[as_macro] const b   = 0x01	
@[as_macro] const c   = 0x02	
@[as_macro] const ab  = 0x03	
@[as_macro] const ac  = 0x04	
@[as_macro] const bc  = 0x05	
@[as_macro] const abc = 0x06

// Use these constants to configure the desired regulation mode for the specified motor          
// multi-motor synchronization, or position regulation                               
@[as_macro] const regmode_idle    = C.UT_REGMODE_IDLE  
@[as_macro] const regmode_speed   = C.UT_REGMODE_SPEED 
@[as_macro] const regmode_sync    = C.UT_REGMODE_SYNC  
@[as_macro] const regmode_pos     = C.UT_REGMODE_POS 

@[as_macro] 
pub fn off(outputs u8) {
	C.Off(outputs)
}
                     
@[as_macro] 
pub fn coast(outputs u8) {
	C.Coast(outputs)
}
                   
@[as_macro] 
pub fn float(outputs u8) {
	C.Float(outputs)
}
                     
@[as_macro] 
pub fn write(outputs u8, pwr i8) {
	C.OnFwd(output, pwr)
	// C.OnRev()
}
             
@[as_macro] 
pub fn rotate(outputs u8, pwr i8, angle int) {
	C.RotateMotor(outputs, pwr, angle)
}
                 
@[as_macro] 
pub fn rotate_pid(outputs u8, pwr i8, angle int, p u8, i u8, d u8) {
	C.RotateMotorPID(outputs, pwr, angle, p, i, d)
}