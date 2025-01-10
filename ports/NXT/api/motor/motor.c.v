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
fn C.MotorPwnFreq() u8                 
fn C.MotorRegulationTime() u8                 
fn C.MotorRegulationOptions() u8
fn C.PosRegEnable(args ...any) 
fn C.PosRegSetAngle(args ...any) 
fn C.PosRegAddAngle(args ...any)
fn C.PosRegSetMax(args ...any)




@[as_macro] 
pub fn write_pwn_freq(args ...any) {
	C.SetMotorPwnFreq(...args)
}
                 
@[as_macro] 
pub fn write_reg_time(regu_time u8) {
	C.SetMotorRegulationTime(regu_time)
}

@[as_macro] 
pub fn write_reg_options(regu_options u8) {
	C.SetMotorRegulationOptions(regu_options)
}

@[as_macro] 
pub fn write_sync_pid(outputs u8, pwr i8, turnpct i8, p u8, i u8, d u8) {
	C.OnFwdSyncPID(outputs, pwr, turnpct, p, i, d)
	// 	C.OnRevSyncPID(outputs, pwr, turnpct, p, i, d)
}
    
@[as_macro] 
pub fn write_sync_ex_pid(outputs u8, pwr i8, turnpct i8, reset u8, p u8, i u8, d u8) {
	C.OnFwdSyncExPID(outputs, pwr, turnpct, reset, p, i, d)
	// C.OnRevSyncExPID(outputs, pwr, turnpct, reset, p, i, d)
}
         
@[as_macro] 
pub fn write_reg_pid(outputs u8, pwr i8, regmode u8, p u8, i u8, d u8) {
	C.OnFwdRegPID(outputs, pwr, regmode, p, i, d)
	// C.OnRevRegPID()
}
                 
@[as_macro] 
pub fn write_reg_ex_pid(outputs u8, pwr i8, regmode u8, reset u8, p u8, i u8, d u8) {
	C.OnFwdRegExPID(outputs, pwr, regmode, reset, p, i, d)
	// C.OnRevRegExPID()
}

@[as_macro] 
pub fn off(outputs u8) {
	C.Off(outputs)
}
                     
@[as_macro] 
pub fn coast(outputs u8) {
	C.Coast(outputs)
}

@[as_macro] 
pub fn off_ex(outputs u8, reset u8) {
	C.OffEx(outputs, reset)
}
                     
@[as_macro] 
pub fn coast_ex(outputs u8, reset u8) {
	C.CoastEx(outputs, reset)
}

@[as_macro] 
pub fn float(outputs u8) {
	C.Float(outputs)
}
                     
@[as_macro] 
pub fn write(outputs u8) {
	C.OnFwd(outputs)
	// C.OnRev()
}
                     
@[as_macro] 
pub fn write_ex(outputs u8, pwr i8, reset u8) {
	C.OnFwdEx(outputs, pwr, reset)
	// C.OnRevEx()
}

@[as_macro] 
pub fn write_reg(outputs u8, pwr i8, regmode u8) {
	C.OnFwdReg(outputs, pwr, regmode)
	// C.OnRevReg()
}
                  
@[as_macro] 
pub fn write_reg_ex(outputs u8, pwr i8, regmode u8, reset u8) {
	C.OnFwdRegEx(outputs, pwr, regmode, reset)
	// C.OnRevRegEx()
}
                 
@[as_macro] 
pub fn write_sync(outputs u8, pwr i8, turnpct i8) {
	C.OnFwdSync(outputs, pwr, turnpct)
	// C.OnRevSync()
}
                 
@[as_macro] 
pub fn write_sync_ex(outputs u8, pwr i8, turnpct i8, reset u8) {
	C.OnFwdSyncEx(outputs, pwr, turnpct, reset)
	// C.OnRevSyncEx()
}
                 
@[as_macro] 
pub fn rotate(outputs u8, pwr i8, angle int) {
	C.RotateMotor(outputs, pwr, angle)
}
                 
@[as_macro] 
pub fn rotate_pid(outputs u8, pwr i8, angle int, p u8, i u8, d u8) {
	C.RotateMotorPID(outputs, pwr, angle, p, i, d)
}
                 
@[as_macro] 
pub fn rotate_ex(outputs u8, pwr i8, angle int, turnpct i8, sync bool, stop bool) {
	C.RotateMotorEx(outputs, pwr, angle, turnpct, sync, stop)
}
                 
@[as_macro] 
pub fn rotate_ex_pid(outputs u8, pwr i8, angle int, turnpct i8, sync bool, stop bool, p u8, i u8, d u8) {
	C.RotateMotorExPID(outputs, pwr, angle, turnpct, sync, stop, p, i, d)
}
                 
@[as_macro] 
pub fn reset_tacho_count(outputs u8) {
	C.ResetTachoCount(outputs)
}
                 
@[as_macro] 
pub fn reset_block_tacho_count(outputs u8) {
	C.ResetBlockTachoCount(outputs)
}
                 
@[as_macro] 
pub fn reset_rotation_count(outputs u8) {
	C.ResetRotationCount(outputs)
}
                 
@[as_macro] 
pub fn reset_all_tacho_counts(outputs u8) {
	C.ResetAllTachoCounts(outputs)
}
               
@[as_macro] 
pub fn read_mode(output u8) u8 {
	return C.MotorMode(output)
}
                 
@[as_macro] 
pub fn read_power(output u8) i8 {
	return C.MotorPower(output)
}
                 
@[as_macro] 
pub fn read_actual_speed(output u8) u8 {
	return C.MotorActualSpeed(output)
}
                 
@[as_macro] 
pub fn read_tacho_count(output u8) int {
	return C.MotorTachoCount(output)
}
                 
@[as_macro] 
pub fn read_tacho_limit(output u8) int {
	return C.MotorTachoLimit(output)
}
                 
@[as_macro] 
pub fn read_run_state(output u8) u8 {
	return C.MotorRunState(output)
}
                 
@[as_macro] 
pub fn read_turn_ratio(output u8) i8 {
	return C.MotorTurnRatio(output)
}
                 
@[as_macro] 
pub fn read_regulation(output u8) u8 {
	return C.MotorRegulation(output)
}
                 
@[as_macro] 
pub fn overload(output u8) bool {
	return C.MotorOverload(output)
}
                 
@[as_macro] 
pub fn read_reg_p(output u8) u8 {
	return C.MotorRegPValue(output)
}
                 
@[as_macro] 
pub fn read_reg_i(output u8) u8 {
	return C.MotorRegIValue(output)
}
                 
@[as_macro] 
pub fn read_reg_d(output u8) u8 {
	return C.MotorRegDValue(output)
}
                 
@[as_macro] 
pub fn read_block_tacho_count(output u8) int {
	return C.MotorBlockTachoCount(output)
}
                 
@[as_macro] 
pub fn read_rotation_count(output u8) int {
	return C.MotorRotationCount(output)
}
                 
@[as_macro] 
pub fn read_output_options(output u8) u8 {
	return C.MotorOutputOptions(output)
}
                 
@[as_macro] 
pub fn read_max_speed(output u8) u8 {
	return C.MotorMaxSpeed(output)
}
                 
@[as_macro] 
pub fn read_max_accel(output u8) u8 {
	return C.MotorMaxAcceleration(output)
}
                 
@[as_macro] 
pub fn read_pwn_freq() u8 {
	return C.MotorPwnFreq()
}
                 
@[as_macro] 
pub fn read_reg_time() u8 {
	return C.MotorRegulationTime()
}
                 
@[as_macro] 
pub fn read_reg_options() u8 {
	return C.MotorRegulationOptions()
}

@[as_macro]
pub fn enable_pos_reg(args ...any) {
	C.PosRegEnable(...args)
}
 
@[as_macro]
pub fn write_angle_pos_reg(args ...any) {
	C.PosRegSetAngle(...args)
}
 
@[as_macro]
pub fn add_angle_pos_reg(args ...any) {
	C.PosRegAddAngle(...args)
}

@[as_macro]
pub fn write_max_pos_reg(args ...any) {
	C.PosRegSetMax(...args)
}