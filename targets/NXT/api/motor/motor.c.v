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


// Motor struct
pub struct Motor {
mut:
	id	int
}

// global instances of Motor
__global (
	motor_a   = Motor { id: a }
	motor_b   = Motor { id: b }
	motor_c   = Motor { id: c }
	motor_ab  = Motor { id: ab }
	motor_ac  = Motor { id: ac }
	motor_bc  = Motor { id: bc }
	motor_abc = Motor { id: abc }
)

// NXC functions redeclaration
fn C.SetMotorPwnFreq(n u8)
fn C.SetMotorRegulationTime(n u8)
fn C.SetMotorRegulationOptions(n u8)
fn C.OnFwdSyncPID(outputs u8, pwr i8, turnpct i8, p u8, i u8, d u8)    
fn C.OnFwdSyncExPID(outputs u8, pwr i8, turnpct i8, reset u8, p u8, i u8, d u8)         
fn C.OnFwdRegPID(outputs u8, pwr i8, regmode u8, p u8, i u8, d u8)                 
fn C.OnFwdRegExPID(outputs u8, pwr i8, regmode u8, reset u8, p u8, i u8, d u8)
fn C.Off(outputs u8)
fn C.Coast(outputs u8)
fn C.OffEx(outputs u8, reset u8)                     
fn C.CoastEx(outputs u8, reset u8)
fn C.Float(outputs u8)
fn C.OnFwd(outputs u8, pwr i8)                     
fn C.OnFwdEx(outputs u8, pwr i8, reset u8)
fn C.OnFwdReg(outputs u8, pwr i8, regmode u8)                  
fn C.OnFwdRegEx(outputs u8, pwr i8, regmode u8, reset u8)                 
fn C.OnFwdSync(outputs u8, pwr i8, turnpct i8)                 
fn C.OnFwdSyncEx(outputs u8, pwr i8, turnpct i8, reset u8)                 
fn C.RotateMotor(outputs u8, pwr i8, angle int)                
fn C.RotateMotorPID(outputs u8, pwr i8, angle int, p u8, i u8, d u8)                
fn C.RotateMotorEx(outputs u8, pwr i8, angle int, turnpct i8, sync bool, stop bool)                
fn C.RotateMotorExPID(outputs u8, pwr i8, angle int, turnpct i8, sync bool, stop bool, p u8, i u8, d u8)                
fn C.ResetTachoCount(outputs u8)                
fn C.ResetBlockTachoCount(outputs u8)                
fn C.ResetRotationCount(outputs u8)                
fn C.ResetAllTachoCounts(outputs u8)              
fn C.MotorMode(output u8) u8
fn C.MotorPower(output u8) i8              
fn C.MotorActualSpeed(output u8) i8                 
fn C.MotorTachoCount(output u8) int             
fn C.MotorTachoLimit(output u8) int             
fn C.MotorRunState(output u8) u8                
fn C.MotorTurnRatio(output u8) i8                
fn C.MotorRegulation(output u8) u8                
fn C.MotorOverload(output u8) bool                
fn C.MotorRegPValue(output u8) u8                
fn C.MotorRegIValue(output u8) u8                
fn C.MotorRegDValue(output u8) u8                
fn C.MotorBlockTachoCount(output u8) int                  
fn C.MotorRotationCount(output u8) int                 
fn C.MotorOutputOptions(output u8) u8                 
fn C.MotorMaxSpeed(output u8) u8                 
fn C.MotorMaxAcceleration(output u8) u8                 
fn C.MotorPwnFreq() u8                 
fn C.MotorRegulationTime() u8                 
fn C.MotorRegulationOptions() u8
fn C.PosRegEnable(output u8, p u8, i u8, d u8) 
fn C.PosRegSetAngle(output u8, angle int) 
fn C.PosRegAddAngle(output u8, angle_add int)
fn C.PosRegSetMax(output u8, max_speed u8, max_acceleration u8)



//new returns a new Motor instance
@[inline]
pub fn Motor.new(id u8) Motor {
    return Motor {
		id: id
	}
}

@[as_macro] 
pub fn set_pwn_freq(n u8) {
	C.SetMotorPwnFreq(n)
}
                 
@[as_macro] 
pub fn set_regulation_time(n u8) {
	C.SetMotorRegulationTime(n)
}

@[as_macro] 
pub fn set_regulation_options(n u8) {
	C.SetMotorRegulationOptions(n)
}

@[inline] 
pub fn (mut m Motor) write_sync_pid(pwr i8, turnpct i8, p u8, i u8, d u8) {
	C.OnFwdSyncPID(m.id, pwr, turnpct, p, i, d)
	// 	C.OnRevSyncPID(...args)
}
    
@[inline] 
pub fn (mut m Motor) write_sync_ex_pid(pwr i8, turnpct i8, reset u8, p u8, i u8, d u8) {
	C.OnFwdSyncExPID(m.id, pwr, turnpct, reset, p, i, d)
	// C.OnRevSyncExPID(m.id, pwr, turnpct, reset, p, i, d)
}
         
@[inline] 
pub fn (mut m Motor) write_reg_pid(pwr i8, regmode u8, p u8, i u8, d u8) {
	C.OnFwdRegPID(m.id, pwr, regmode, p, i, d)
	// C.OnRevRegPID()
}
                 
@[inline] 
pub fn (mut m Motor) write_reg_ex_pid(pwr i8, regmode u8, reset u8, p u8, i u8, d u8) {
	C.OnFwdRegExPID(m.id, pwr, regmode, reset, p, i, d)
	// C.OnRevRegExPID()
}

@[inline] 
pub fn (mut m Motor) off() {
	C.Off(m.id)
}
                     
@[inline] 
pub fn (mut m Motor) coast() {
	C.Coast(m.id)
}

@[inline] 
pub fn (mut m Motor) off_ex(reset u8) {
	C.OffEx(m.id, reset)
}
                     
@[inline] 
pub fn (mut m Motor) coast_ex(reset u8) {
	C.CoastEx(m.id, reset)
}

@[inline] 
pub fn (mut m Motor) float() {
	C.Float(m.id)
}
                     
@[inline] 
pub fn (mut m Motor) write(pwr i8) {
	C.OnFwd(m.id, pwr)
	// C.OnRev()
}
                     
@[inline] 
pub fn (mut m Motor) write_ex(pwr i8, reset u8) {
	C.OnFwdEx(m.id, pwr, reset)
	// C.OnRevEx()
}

@[inline] 
pub fn (mut m Motor) write_reg(pwr i8, regmode u8) {
	C.OnFwdReg(m.id, pwr, regmode)
	// C.OnRevReg()
}
                  
@[inline] 
pub fn (mut m Motor) write_reg_ex(pwr i8, regmode u8, reset u8) {
	C.OnFwdRegEx(m.id, pwr, regmode, reset)
	// C.OnRevRegEx()
}
                 
@[inline] 
pub fn (mut m Motor) write_sync(pwr i8, turnpct i8) {
	C.OnFwdSync(m.id, pwr, turnpct)
	// C.OnRevSync()
}
                 
@[inline] 
pub fn (mut m Motor) write_sync_ex(pwr i8, turnpct i8, reset u8) {
	C.OnFwdSyncEx(m.id, pwr, turnpct, reset)
	// C.OnRevSyncEx()
}
                 
@[inline] 
pub fn (mut m Motor) rotate(pwr i8, angle int) {
	C.RotateMotor(m.id, pwr, angle)
}
                 
@[inline] 
pub fn (mut m Motor) rotate_pid(pwr i8, angle int, p u8, i u8, d u8) {
	C.RotateMotorPID(m.id, pwr, angle, p, i, d)
}
                 
@[inline] 
pub fn (mut m Motor) rotate_ex(pwr i8, angle int, turnpct i8, sync bool, stop bool) {
	C.RotateMotorEx(m.id, pwr, angle, turnpct, sync, stop)
}
                 
@[inline] 
pub fn (mut m Motor) rotate_ex_pid(pwr i8, angle int, turnpct i8, sync bool, stop bool, p u8, i u8, d u8) {
	C.RotateMotorExPID(m.id, pwr, angle, turnpct, sync, stop, p, i, d)
}
                 
@[inline] 
pub fn (mut m Motor) reset_tacho_count() {
	C.ResetTachoCount(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) reset_block_tacho_count() {
	C.ResetBlockTachoCount(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) reset_rotation_count() {
	C.ResetRotationCount(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) reset_all_tacho_counts() {
	C.ResetAllTachoCounts(m.id)
}
               
@[inline] 
pub fn (mut m Motor) mode() u8 {
	return C.MotorMode(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) power() i8 {
	return C.MotorPower(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) actual_speed() i8 {
	return C.MotorActualSpeed(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) tacho_count() int {
	return C.MotorTachoCount(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) tacho_limit() int {
	return C.MotorTachoLimit(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) run_state() u8 {
	return C.MotorRunState(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) turn_ratio() i8 {
	return C.MotorTurnRatio(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) regulation() u8 {
	return C.MotorRegulation(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) overload() bool {
	return C.MotorOverload(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) reg_p() u8 {
	return C.MotorRegPValue(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) read_reg_i() u8 {
	return C.MotorRegIValue(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) reg_d() u8 {
	return C.MotorRegDValue(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) block_tacho_count() int {
	return C.MotorBlockTachoCount(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) rotation_count() int {
	return C.MotorRotationCount(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) output_options() u8 {
	return C.MotorOutputOptions(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) max_speed() u8 {
	return C.MotorMaxSpeed(m.id)
}
                 
@[inline] 
pub fn (mut m Motor) max_acceleration() u8 {
	return C.MotorMaxAcceleration(m.id)
}
                 
@[as_macro] 
pub fn pwn_freq() u8 {
	return C.MotorPwnFreq()
}
                 
@[as_macro] 
pub fn regulation_time() u8 {
	return C.MotorRegulationTime()
}
                 
@[as_macro] 
pub fn regulation_options() u8 {
	return C.MotorRegulationOptions()
}

@[inline]
pub fn (mut m Motor) enable_pos_reg(p u8, i u8, d u8) {
	C.PosRegEnable(m.id, p, i, d)
}
 
@[inline]
pub fn (mut m Motor) set_angle_pos_reg(angle int) {
	C.PosRegSetAngle(m.id, angle)
}
 
@[inline]
pub fn (mut m Motor) add_angle_pos_reg(angle_add int) {
	C.PosRegAddAngle(m.id, angle_add)
}

@[inline]
pub fn (mut m Motor) set_max_pos_reg(max_speed u8, max_acceleration u8) {
	C.PosRegSetMax(m.id, max_speed, max_acceleration)
}