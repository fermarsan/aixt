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

fn C.SetMotorPwnFreq(args ...any)
fn C.SetMotorRegulationTime(args ...any)
fn C.SetMotorRegulationOptions(args ...any)
fn C.OnFwdSyncPID(args ...any)    
fn C.OnFwdSyncExPID(args ...any)         
fn C.OnFwdRegPID(args ...any)                 
fn C.OnFwdRegExPID(args ...any)
fn C.Off(args ...any)
fn C.Coast(args ...any)
fn C.OffEx(args ...any)                     
fn C.CoastEx(args ...any)
fn C.Float(args ...any)
fn C.OnFwd(args ...any)                     
fn C.OnFwdEx(args ...any)
fn C.OnFwdReg(args ...any)                  
fn C.OnFwdRegEx(args ...any)                 
fn C.OnFwdSync(args ...any)                 
fn C.OnFwdSyncEx(args ...any)                 
fn C.RotateMotor(args ...any)                
fn C.RotateMotorPID(args ...any)                
fn C.RotateMotorEx(args ...any)                
fn C.RotateMotorExPID(args ...any)                
fn C.ResetTachoCount(args ...any)                
fn C.ResetBlockTachoCount(args ...any)                
fn C.ResetRotationCount(args ...any)                
fn C.ResetAllTachoCounts(args ...any)              
fn C.MotorMode(args ...any) u8
fn C.MotorPower(args ...any) i8              
fn C.MotorActualSpeed(args ...any) i8                 
fn C.MotorTachoCount(args ...any) int             
fn C.MotorTachoLimit(args ...any) int             
fn C.MotorRunState(args ...any) u8                
fn C.MotorTurnRatio(args ...any) i8                
fn C.MotorRegulation(args ...any) u8                
fn C.MotorOverload(args ...any) bool                
fn C.MotorRegPValue(args ...any) u8                
fn C.MotorRegIValue(args ...any) u8                
fn C.MotorRegDValue(args ...any) u8                
fn C.MotorBlockTachoCount(args ...any) int                  
fn C.MotorRotationCount(args ...any) int                 
fn C.MotorOutputOptions(args ...any) u8                 
fn C.MotorMaxSpeed(args ...any) u8                 
fn C.MotorMaxAcceleration(args ...any) u8                 
fn C.MotorPwnFreq(args ...any) u8                 
fn C.MotorRegulationTime(args ...any) u8                 
fn C.MotorRegulationOptions(args ...any) u8
fn C.PosRegEnable(args ...any) 
fn C.PosRegSetAngle(args ...any) 
fn C.PosRegAddAngle(args ...any)
fn C.PosRegSetMax(args ...any)



@[as_macro] 
pub fn set_pwn_freq(args ...any) {
	C.SetMotorPwnFreq(...args)
}
                 
@[as_macro] 
pub fn set_regulation_time(args ...any) {
	C.SetMotorRegulationTime(...args)
}

@[as_macro] 
pub fn set_regulation_options(args ...any) {
	C.SetMotorRegulationOptions(...args)
}

@[as_macro] 
pub fn write_sync_pid(args ...any) {
	C.OnFwdSyncPID(...args)
	// 	C.OnRevSyncPID(...args)
}
    
@[as_macro] 
pub fn write_sync_ex_pid(args ...any) {
	C.OnFwdSyncExPID(...args)
	// C.OnRevSyncExPID(outputs, pwr, turnpct, reset, p, i, d)
}
         
@[as_macro] 
pub fn write_reg_pid(args ...any) {
	C.OnFwdRegPID(...args)
	// C.OnRevRegPID()
}
                 
@[as_macro] 
pub fn write_reg_ex_pid(args ...any) {
	C.OnFwdRegExPID(...args)
	// C.OnRevRegExPID()
}

@[as_macro] 
pub fn off(args ...any) {
	C.Off(...args)
}
                     
@[as_macro] 
pub fn coast(args ...any) {
	C.Coast(...args)
}

@[as_macro] 
pub fn off_ex(args ...any) {
	C.OffEx(...args)
}
                     
@[as_macro] 
pub fn coast_ex(args ...any) {
	C.CoastEx(...args)
}

@[as_macro] 
pub fn float(args ...any) {
	C.Float(...args)
}
                     
@[as_macro] 
pub fn write(args ...any) {
	C.OnFwd(...args)
	// C.OnRev()
}
                     
@[as_macro] 
pub fn write_ex(args ...any) {
	C.OnFwdEx(...args)
	// C.OnRevEx()
}

@[as_macro] 
pub fn write_reg(args ...any) {
	C.OnFwdReg(...args)
	// C.OnRevReg()
}
                  
@[as_macro] 
pub fn write_reg_ex(args ...any) {
	C.OnFwdRegEx(...args)
	// C.OnRevRegEx()
}
                 
@[as_macro] 
pub fn write_sync(args ...any) {
	C.OnFwdSync(...args)
	// C.OnRevSync()
}
                 
@[as_macro] 
pub fn write_sync_ex(args ...any) {
	C.OnFwdSyncEx(...args)
	// C.OnRevSyncEx()
}
                 
@[as_macro] 
pub fn rotate(args ...any) {
	C.RotateMotor(...args)
}
                 
@[as_macro] 
pub fn rotate_pid(args ...any) {
	C.RotateMotorPID(...args)
}
                 
@[as_macro] 
pub fn rotate_ex(args ...any) {
	C.RotateMotorEx(...args)
}
                 
@[as_macro] 
pub fn rotate_ex_pid(args ...any) {
	C.RotateMotorExPID(...args)
}
                 
@[as_macro] 
pub fn reset_tacho_count(args ...any) {
	C.ResetTachoCount(...args)
}
                 
@[as_macro] 
pub fn reset_block_tacho_count(args ...any) {
	C.ResetBlockTachoCount(...args)
}
                 
@[as_macro] 
pub fn reset_rotation_count(args ...any) {
	C.ResetRotationCount(...args)
}
                 
@[as_macro] 
pub fn reset_all_tacho_counts(args ...any) {
	C.ResetAllTachoCounts(...args)
}
               
@[as_macro] 
pub fn mode(args ...any) u8 {
	return C.MotorMode(...args)
}
                 
@[as_macro] 
pub fn power(args ...any) i8 {
	return C.MotorPower(...args)
}
                 
@[as_macro] 
pub fn actual_speed(args ...any) i8 {
	return C.MotorActualSpeed(...args)
}
                 
@[as_macro] 
pub fn tacho_count(args ...any) int {
	return C.MotorTachoCount(...args)
}
                 
@[as_macro] 
pub fn tacho_limit(args ...any) int {
	return C.MotorTachoLimit(...args)
}
                 
@[as_macro] 
pub fn run_state(args ...any) u8 {
	return C.MotorRunState(...args)
}
                 
@[as_macro] 
pub fn turn_ratio(args ...any) i8 {
	return C.MotorTurnRatio(...args)
}
                 
@[as_macro] 
pub fn regulation(args ...any) u8 {
	return C.MotorRegulation(...args)
}
                 
@[as_macro] 
pub fn overload(args ...any) bool {
	return C.MotorOverload(...args)
}
                 
@[as_macro] 
pub fn reg_p(args ...any) u8 {
	return C.MotorRegPValue(...args)
}
                 
@[as_macro] 
pub fn read_reg_i(args ...any) u8 {
	return C.MotorRegIValue(...args)
}
                 
@[as_macro] 
pub fn reg_d(args ...any) u8 {
	return C.MotorRegDValue(...args)
}
                 
@[as_macro] 
pub fn block_tacho_count(args ...any) int {
	return C.MotorBlockTachoCount(...args)
}
                 
@[as_macro] 
pub fn rotation_count(args ...any) int {
	return C.MotorRotationCount(...args)
}
                 
@[as_macro] 
pub fn output_options(args ...any) u8 {
	return C.MotorOutputOptions(...args)
}
                 
@[as_macro] 
pub fn max_speed(args ...any) u8 {
	return C.MotorMaxSpeed(...args)
}
                 
@[as_macro] 
pub fn max_acceleration(args ...any) u8 {
	return C.MotorMaxAcceleration(...args)
}
                 
@[as_macro] 
pub fn pwn_freq(args ...any) u8 {
	return C.MotorPwnFreq()
}
                 
@[as_macro] 
pub fn regulation_time(args ...any) u8 {
	return C.MotorRegulationTime()
}
                 
@[as_macro] 
pub fn regulation_options(args ...any) u8 {
	return C.MotorRegulationOptions()
}

@[as_macro]
pub fn enable_pos_reg(args ...any) {
	C.PosRegEnable(...args)
}
 
@[as_macro]
pub fn set_angle_pos_reg(args ...any) {
	C.PosRegSetAngle(...args)
}
 
@[as_macro]
pub fn add_angle_pos_reg(args ...any) {
	C.PosRegAddAngle(...args)
}

@[as_macro]
pub fn set_max_pos_reg(args ...any) {
	C.PosRegSetMax(...args)
}