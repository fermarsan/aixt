// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Sensor module for NXT (NXC backend)

module sensor	


@[as_macro] pub const s1 = u8(0)
@[as_macro] pub const s2 = u8(1)
@[as_macro] pub const s3 = u8(2)
@[as_macro] pub const s4 = u8(3)

// Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call. 
@[as_macro] pub const touch   		= u16(C.SENSOR_TOUCH)
@[as_macro] pub const light   		= u16(C.SENSOR_LIGHT)
@[as_macro] pub const rotation   	= u16(C.SENSOR_ROTATION)
@[as_macro] pub const celsius   	= u16(C.SENSOR_CELSIUS)
@[as_macro] pub const fahrenheit   	= u16(C.SENSOR_FAHRENHEIT)
@[as_macro] pub const pulse   		= u16(C.SENSOR_PULSE)
@[as_macro] pub const edge    		= u16(C.SENSOR_EDGE)
@[as_macro] pub const nxt_light   	= u16(C.SENSOR_NXTLIGHT)
@[as_macro] pub const sound   		= u16(C.SENSOR_SOUND)
@[as_macro] pub const lows_peed_9v  = u16(C.SENSOR_LOWSPEED_9V)
@[as_macro] pub const lows_peed   	= u16(C.SENSOR_LOWSPEED)
@[as_macro] pub const color_full  	= u16(C.SENSOR_COLORFULL)
@[as_macro] pub const color_red  	= u16(C.SENSOR_COLORRED)
@[as_macro] pub const color_green  	= u16(C.SENSOR_COLORGREEN)
@[as_macro] pub const color_blue  	= u16(C.SENSOR_COLORBLUE)
@[as_macro] pub const color_none  	= u16(C.SENSOR_COLORNONE)


// Use sensor mode constants to configure an input port for the desired sensor mode.
// The constants are intended for use in NBC. 
@[as_macro] pub const mode_raw          	= C.IN_MODE_RAW
@[as_macro] pub const mode_bool         	= C.IN_MODE_BOOLEAN
@[as_macro] pub const mode_edge         	= C.IN_MODE_TRANSITIONCNT
@[as_macro] pub const mode_pulse        	= C.IN_MODE_PERIODCOUNTER
@[as_macro] pub const mode_percent      	= C.IN_MODE_PCTFULLSCALE
@[as_macro] pub const mode_celsius      	= C.IN_MODE_CELSIUS
@[as_macro] pub const mode_fahrenheit   	= C.IN_MODE_FAHRENHEIT
@[as_macro] pub const mode_rotation     	= C.IN_MODE_ANGLESTEP  
@[as_macro] pub const mode_slope_mask   	= C.IN_MODE_SLOPEMASK    
@[as_macro] pub const mode_mask     		= C.IN_MODE_MODEMASK    
@[as_macro] pub const mode_transition_cnt	= C.IN_MODE_TRANSITIONCNT
@[as_macro] pub const mode_period_counter	= C.IN_MODE_PERIODCOUNTER
@[as_macro] pub const mode_pct_full_scale 	= C.IN_MODE_PCTFULLSCALE 
@[as_macro] pub const mode_angle_step    	= C.IN_MODE_ANGLESTEP    

// Use sensor mode constants to configure an input port for the desired sensor mode.  


// Use sensor type constants to configure an input port for a specific type of sensor. 
@[as_macro] pub const type_none          	= C.IN_TYPE_NO_SENSOR
@[as_macro] pub const type_touch         	= C.IN_TYPE_SWITCH
@[as_macro] pub const type_temperature   	= C.IN_TYPE_TEMPERATURE
@[as_macro] pub const type_light         	= C.IN_TYPE_REFLECTION
@[as_macro] pub const type_rotation      	= C.IN_TYPE_ANGLE
@[as_macro] pub const type_light_active  	= C.IN_TYPE_LIGHT_ACTIVE
@[as_macro] pub const type_light_inactive	= C.IN_TYPE_LIGHT_INACTIVE
@[as_macro] pub const type_sound_db      	= C.IN_TYPE_SOUND_DB
@[as_macro] pub const type_sound_dba     	= C.IN_TYPE_SOUND_DBA
@[as_macro] pub const type_custom        	= C.IN_TYPE_CUSTOM
@[as_macro] pub const type_low_speed      	= C.IN_TYPE_LOWSPEED
@[as_macro] pub const type_low_speed_9v   	= C.IN_TYPE_LOWSPEED_9V
@[as_macro] pub const type_high_speed     	= C.IN_TYPE_HISPEED
@[as_macro] pub const type_color_full     	= C.IN_TYPE_COLORFULL
@[as_macro] pub const type_color_red      	= C.IN_TYPE_COLORRED
@[as_macro] pub const type_color_green    	= C.IN_TYPE_COLORGREEN
@[as_macro] pub const type_color_blue     	= C.IN_TYPE_COLORBLUE
@[as_macro] pub const type_color_none     	= C.IN_TYPE_COLORNONE   
@[as_macro] pub const type_color_exit     	= C.IN_TYPE_COLOREXIT 


// Sensor struct
pub struct Sensor {
mut:
	id	u8
}

// NXC functions redeclaration
fn C.SetSensor(port u8, config u16)
fn C.SetSensorTouch(port u8)
fn C.SetSensorLight(port u8, b_active bool)
fn C.SetSensorSound(port u8, b_db_scaling bool)
fn C.SetSensorLowspeed(port u8, b_is_powered bool)
fn C.SetSensorUltrasonic(port u8)
fn C.SetSensorTemperature(port u8)
fn C.SetSensorColorFull(port u8)
fn C.Sensor(port u8) u16
fn C.SensorBoolean(port u8) bool
fn C.SensorUS(port u8) u8
fn C.SensorUS0(port u8) u8
fn C.SensorUSWait(port u8, wait u8) u8
fn C.ConfigureTemperatureSensor(port u8, config u8)
fn C.SensorTemperature(port u8) f32
fn C.SetSensorType(port u8, typ u8)
fn C.SetSensorMode(port u8, mode u8)
fn C.ClearSensor(port u8)
fn C.ResetSensor(port u8)

//new returns a new Sensor instance
@[inline]
pub fn Sensor.new(id u8) Sensor {
    return Sensor {
		id: id
	}
}

@[inline]
pub fn (mut s Sensor) setup(config u16) {
	C.SetSensor(s.id, config) 
}                                                          

@[inline]
pub fn (mut s Sensor) as_touch() {
	C.SetSensorTouch(s.id) 
}                                                          

@[inline]
pub fn (mut s Sensor) as_light(b_active bool) {
	C.SetSensorLight(s.id, b_active) 
}                                                          

@[inline]
pub fn (mut s Sensor) as_sound(b_db_scaling bool) {
	C.SetSensorSound(s.id, b_db_scaling) 
}                                                          

@[inline]
pub fn (mut s Sensor) as_lowspeed(b_is_powered bool) {
	C.SetSensorLowspeed(s.id, b_is_powered) 
}                                                          

@[inline]
pub fn (mut s Sensor) as_ultrasonic() {
	C.SetSensorUltrasonic(s.id)
}                                                          
                                                    
@[inline]
pub fn (mut s Sensor) as_temperature() {
	C.SetSensorTemperature(s.id) 
}                                                          

@[inline]
pub fn (mut s Sensor) as_color_full() {
	C.SetSensorColorFull(s.id) 
}                                                          

@[inline]
pub fn (mut s Sensor) read() u16 {
	return C.Sensor(s.id) 
}                                                          

@[inline]
pub fn (mut s Sensor) read_bool() bool {
	return C.SensorBoolean(s.id) 
}       

@[inline]
pub fn (mut s Sensor) read_us() u8 {
	return C.SensorUS(s.id) 
} 

@[inline]
pub fn (mut s Sensor) read_us_now() u8 {
	return C.SensorUS0(s.id) 
} 

@[inline]
pub fn (mut s Sensor) read_us_wait(wait u8) u8 {
	return C.SensorUSWait(s.id, wait) 
} 

@[inline]
pub fn (mut s Sensor) setup_temperature(config u8) {
	C.ConfigureTemperatureSensor(s.id, config) 
} 

@[inline]
pub fn (mut s Sensor) read_temperature() f32 {
	return C.SensorTemperature(s.id) 
}

@[inline]
pub fn (mut s Sensor) set_type(typ u8) {
	C.SetSensorType(s.id, typ) 
}                                                          

@[inline]
pub fn (mut s Sensor) write_mode(mode u8) {
	C.SetSensorMode(s.id, mode) 
}  

@[inline]
pub fn (mut s Sensor) clear() {
	C.ClearSensor(s.id) 
}    

@[inline]
pub fn (mut s Sensor) reset() {
	C.ResetSensor(s.id) 
}   