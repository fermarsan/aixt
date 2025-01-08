// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Motor module for NXT (NXC backend)

module motor	// NXC Output

// Output port constants are used when calling motor control API functions. 
@[as_macro] pub const a   = 0x00
@[as_macro] pub const b   = 0x01	
@[as_macro] pub const c   = 0x02	
@[as_macro] pub const ab  = 0x03	
@[as_macro] pub const ac  = 0x04	
@[as_macro] pub const bc  = 0x05	
@[as_macro] pub const abc = 0x06

// Use these constants to configure the desired regulation mode for the specified motor          
// multi-motor synchronization, or position regulation                               
@[as_macro] pub const regmode_idle    = C.UT_REGMODE_IDLE  
@[as_macro] pub const regmode_speed   = C.UT_REGMODE_SPEED 
@[as_macro] pub const regmode_sync    = C.UT_REGMODE_SYNC  
@[as_macro] pub const regmode_pos     = C.UT_REGMODE_POS 

fn C.Off(args ...any)
fn C.Coast(args ...any)
fn C.Float(args ...any)
fn C.OnFwd(args ...any)
fn C.RotateMotor(args ...any)
fn C.RotateMotorPID(args ...any)

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
	C.OnFwd(outputs, pwr)
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