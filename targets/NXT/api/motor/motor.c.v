// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Motor module for NXT (object oriented)

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

pub struct Motor {
mut:
	id	int
}

__global (
	motor_a   = Motor { id: a }
	motor_b   = Motor { id: b }
	motor_c   = Motor { id: c }
	motor_ab  = Motor { id: ab }
	motor_ac  = Motor { id: ac }
	motor_bc  = Motor { id: bc }
	motor_abc = Motor { id: abc }
)

fn C.SetMotorPwnFreq(n byte)
fn C.SetMotorRegulationTime(n byte)
fn C.SetMotorRegulationOptions(n byte)
fn C.OnFwdSyncPID(outputs byte, pwr char, turnpct char, p byte, i byte, d byte)    
fn C.OnFwdSyncExPID(outputs byte, pwr char, turnpct char, reset byte, p byte, i byte, d byte)         
fn C.OnFwdRegPID(outputs byte, pwr char, regmode byte, p byte, i byte, d byte)                 
fn C.OnFwdRegExPID(outputs byte, pwr char, regmode byte, reset byte, p byte, i byte, d byte)
fn C.Off(outputs byte)
fn C.Coast(outputs byte)
fn C.OffEx(outputs byte, reset byte)                     
fn C.CoastEx(outputs byte, reset byte)
fn C.Float(outputs byte)
fn C.OnFwd(outputs byte, pwr char)                     
fn C.OnFwdEx(outputs byte, pwr char, reset byte)
fn C.OnFwdReg(outputs byte, pwr char, regmode byte)                  
fn C.OnFwdRegEx(outputs byte, pwr char, regmode byte, reset byte)                 
fn C.OnFwdSync(outputs byte, pwr char, turnpct char)                 
fn C.OnFwdSyncEx(outputs byte, pwr char, turnpct char, reset byte)                 
fn C.RotateMotor(outputs byte, pwr char, angle long)                
fn C.RotateMotorPID(outputs byte, pwr char, angle long, p byte, i byte, d byte)                
fn C.RotateMotorEx(outputs byte, pwr char, angle long, turnpct char, sync bool, stop bool)                
fn C.RotateMotorExPID(outputs byte, pwr char, angle long, turnpct char, sync bool, stop bool, p byte, i byte, d byte)                
fn C.ResetTachoCount(outputs byte)                
fn C.ResetBlockTachoCount(outputs byte)                
fn C.ResetRotationCount(outputs byte)                
fn C.ResetAllTachoCounts(outputs byte)              
fn C.MotorMode(output byte) u8
fn C.MotorPower(output byte) i8              
fn C.MotorActualSpeed(output byte) i8                 
fn C.MotorTachoCount(output byte) int             
fn C.MotorTachoLimit(output byte) int             
fn C.MotorRunState(output byte) u8                
fn C.MotorTurnRatio(output byte) i8                
fn C.MotorRegulation(output byte) u8                
fn C.MotorOverload(output byte) bool                
fn C.MotorRegPValue(output byte) u8                
fn C.MotorRegIValue(output byte) u8                
fn C.MotorRegDValue(output byte) u8                
fn C.MotorBlockTachoCount(output byte) int                  
fn C.MotorRotationCount(output byte) int                 
fn C.MotorOutputOptions(output byte) u8                 
fn C.MotorMaxSpeed(output byte) u8                 
fn C.MotorMaxAcceleration(output byte) u8                 
fn C.MotorPwnFreq() u8                 
fn C.MotorRegulationTime() u8                 
fn C.MotorRegulationOptions() u8
fn C.PosRegEnable(output byte, p byte, i byte, d byte) 
fn C.PosRegSetAngle(output byte, angle long) 
fn C.PosRegAddAngle(output byte, angle_add long)
fn C.PosRegSetMax(output byte, max_speed byte, max_acceleration byte)



@[as_macro] 
pub fn (mut m Motor) set_pwn_freq(n byte) {
	C.SetMotorPwnFreq(n)
}
                 
@[as_macro] 
pub fn (mut m Motor) set_regulation_time(n byte) {
	C.SetMotorRegulationTime(n)
}

@[as_macro] 
pub fn (mut m Motor) set_regulation_options(n byte) {
	C.SetMotorRegulationOptions(n)
}

@[as_macro] 
pub fn (mut m Motor) write_sync_pid(outputs byte, pwr char, turnpct char, p byte, i byte, d byte) {
	C.OnFwdSyncPID(outputs, pwr, turnpct, p, i, d)
	// 	C.OnRevSyncPID(...args)
}
    
@[as_macro] 
pub fn (mut m Motor) write_sync_ex_pid(outputs byte, pwr char, turnpct char, reset byte, p byte, i byte, d byte) {
	C.OnFwdSyncExPID(outputs, pwr, turnpct, reset, p, i, d)
	// C.OnRevSyncExPID(outputs, pwr, turnpct, reset, p, i, d)
}
         
@[as_macro] 
pub fn (mut m Motor) write_reg_pid(outputs byte, pwr char, regmode byte, p byte, i byte, d byte) {
	C.OnFwdRegPID(outputs, pwr, regmode, p, i, d)
	// C.OnRevRegPID()
}
                 
@[as_macro] 
pub fn (mut m Motor) write_reg_ex_pid(outputs byte, pwr char, regmode byte, reset byte, p byte, i byte, d byte) {
	C.OnFwdRegExPID(outputs, pwr, regmode, reset, p, i, d)
	// C.OnRevRegExPID()
}

@[as_macro] 
pub fn (mut m Motor) off(outputs byte) {
	C.Off(outputs)
}
                     
@[as_macro] 
pub fn (mut m Motor) coast(outputs byte) {
	C.Coast(outputs)
}

@[as_macro] 
pub fn (mut m Motor) off_ex(outputs byte, reset byte) {
	C.OffEx(outputs, reset)
}
                     
@[as_macro] 
pub fn (mut m Motor) coast_ex(outputs byte, reset byte) {
	C.CoastEx(outputs, reset)
}

@[as_macro] 
pub fn (mut m Motor) float(outputs byte) {
	C.Float(outputs)
}
                     
@[as_macro] 
pub fn (mut m Motor) write(outputs byte, pwr char) {
	C.OnFwd(outputs, pwr)
	// C.OnRev()
}
                     
@[as_macro] 
pub fn (mut m Motor) write_ex(outputs byte, pwr char, reset byte) {
	C.OnFwdEx(outputs, pwr, reset)
	// C.OnRevEx()
}

@[as_macro] 
pub fn (mut m Motor) write_reg(outputs byte, pwr char, regmode byte) {
	C.OnFwdReg(outputs, pwr, regmode)
	// C.OnRevReg()
}
                  
@[as_macro] 
pub fn (mut m Motor) write_reg_ex(outputs byte, pwr char, regmode byte, reset byte) {
	C.OnFwdRegEx(outputs, pwr, regmode, reset)
	// C.OnRevRegEx()
}
                 
@[as_macro] 
pub fn (mut m Motor) write_sync(outputs byte, pwr char, turnpct char) {
	C.OnFwdSync(outputs, pwr, turnpct)
	// C.OnRevSync()
}
                 
@[as_macro] 
pub fn (mut m Motor) write_sync_ex(outputs byte, pwr char, turnpct char, reset byte) {
	C.OnFwdSyncEx(outputs, pwr, turnpct, reset)
	// C.OnRevSyncEx()
}
                 
@[as_macro] 
pub fn (mut m Motor) rotate(outputs byte, pwr char, angle long) {
	C.RotateMotor(outputs, pwr, angle)
}
                 
@[as_macro] 
pub fn (mut m Motor) rotate_pid(outputs byte, pwr char, angle long, p byte, i byte, d byte) {
	C.RotateMotorPID(outputs, pwr, angle, p, i, d)
}
                 
@[as_macro] 
pub fn (mut m Motor) rotate_ex(outputs byte, pwr char, angle long, turnpct char, sync bool, stop bool) {
	C.RotateMotorEx(outputs, pwr, angle, turnpct, sync, stop)
}
                 
@[as_macro] 
pub fn (mut m Motor) rotate_ex_pid(outputs byte, pwr char, angle long, turnpct char, sync bool, stop bool, p byte, i byte, d byte) {
	C.RotateMotorExPID(outputs, pwr, angle, turnpct, sync, stop, p, i, d)
}
                 
@[as_macro] 
pub fn (mut m Motor) reset_tacho_count(outputs byte) {
	C.ResetTachoCount(outputs)
}
                 
@[as_macro] 
pub fn (mut m Motor) reset_block_tacho_count(outputs byte) {
	C.ResetBlockTachoCount(outputs)
}
                 
@[as_macro] 
pub fn (mut m Motor) reset_rotation_count(outputs byte) {
	C.ResetRotationCount(outputs)
}
                 
@[as_macro] 
pub fn (mut m Motor) reset_all_tacho_counts(outputs byte) {
	C.ResetAllTachoCounts(outputs)
}
               
@[as_macro] 
pub fn (mut m Motor) mode(output byte) u8 {
	return C.MotorMode(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) power(output byte) i8 {
	return C.MotorPower(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) actual_speed(output byte) i8 {
	return C.MotorActualSpeed(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) tacho_count(output byte) int {
	return C.MotorTachoCount(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) tacho_limit(output byte) int {
	return C.MotorTachoLimit(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) run_state(output byte) u8 {
	return C.MotorRunState(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) turn_ratio(output byte) i8 {
	return C.MotorTurnRatio(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) regulation(output byte) u8 {
	return C.MotorRegulation(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) overload(output byte) bool {
	return C.MotorOverload(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) reg_p(output byte) u8 {
	return C.MotorRegPValue(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) read_reg_i(output byte) u8 {
	return C.MotorRegIValue(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) reg_d(output byte) u8 {
	return C.MotorRegDValue(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) block_tacho_count(output byte) int {
	return C.MotorBlockTachoCount(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) rotation_count(output byte) int {
	return C.MotorRotationCount(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) output_options(output byte) u8 {
	return C.MotorOutputOptions(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) max_speed(output byte) u8 {
	return C.MotorMaxSpeed(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) max_acceleration(output byte) u8 {
	return C.MotorMaxAcceleration(output)
}
                 
@[as_macro] 
pub fn (mut m Motor) pwn_freq() u8 {
	return C.MotorPwnFreq()
}
                 
@[as_macro] 
pub fn (mut m Motor) regulation_time() u8 {
	return C.MotorRegulationTime()
}
                 
@[as_macro] 
pub fn (mut m Motor) regulation_options() u8 {
	return C.MotorRegulationOptions()
}

@[as_macro]
pub fn (mut m Motor) enable_pos_reg(output byte, p byte, i byte, d byte) {
	C.PosRegEnable(output, p, i, d)
}
 
@[as_macro]
pub fn (mut m Motor) set_angle_pos_reg(output byte, angle long) {
	C.PosRegSetAngle(output, angle)
}
 
@[as_macro]
pub fn (mut m Motor) add_angle_pos_reg(output byte, angle_add long) {
	C.PosRegAddAngle(output, angle_add)
}

@[as_macro]
pub fn (mut m Motor) set_max_pos_reg(output byte, max_speed byte, max_acceleration byte) {
	C.PosRegSetMax(output, max_speed, max_acceleration)
}