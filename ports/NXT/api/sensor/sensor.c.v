// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Sensor module for NXT (NXC backend)

module sensor	


@[as_macro] pub const s1 = 0
@[as_macro] pub const s2 = 1
@[as_macro] pub const s3 = 2
@[as_macro] pub const s4 = 3

// Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call. 
@[as_macro] pub const touch   		= C.SENSOR_TOUCH
@[as_macro] pub const light   		= C.SENSOR_LIGHT
@[as_macro] pub const rotation   	= C.SENSOR_ROTATION
@[as_macro] pub const celsius   	= C.SENSOR_CELSIUS
@[as_macro] pub const fahrenheit   	= C.SENSOR_FAHRENHEIT
@[as_macro] pub const pulse   		= C.SENSOR_PULSE
@[as_macro] pub const edge    		= C.SENSOR_EDGE
@[as_macro] pub const nxt_light   	= C.SENSOR_NXTLIGHT
@[as_macro] pub const sound   		= C.SENSOR_SOUND
@[as_macro] pub const lows_peed_9v  = C.SENSOR_LOWSPEED_9V
@[as_macro] pub const lows_peed   	= C.SENSOR_LOWSPEED
@[as_macro] pub const color_full  	= C.SENSOR_COLORFULL
@[as_macro] pub const color_red  	= C.SENSOR_COLORRED
@[as_macro] pub const color_green  	= C.SENSOR_COLORGREEN
@[as_macro] pub const color_blue  	= C.SENSOR_COLORBLUE
@[as_macro] pub const color_none  	= C.SENSOR_COLORNONE


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






fn C.SetSensor(args ...any)
fn C.SetSensorTouch(args ...any)
fn C.SetSensorLight(args ...any)
fn C.SetSensorSound(args ...any)
fn C.SetSensorLowspeed(args ...any)
fn C.SetSensorUltrasonic(args ...any)
fn C.SetSensorTemperature(args ...any)
fn C.SetSensorColorFull(args ...any)
fn C.Sensor(args ...any) u16
fn C.SensorBoolean(args ...any) bool
fn C.SensorUS(args ...any) u8
fn C.SensorUS0(args ...any) u8
fn C.SensorUSWait(args ...any) u8
fn C.ConfigureTemperatureSensor( args ...any)
fn C.SensorTemperature(args ...any) f32
fn C.SetSensorType(args ...any)
fn C.SetSensorMode(args ...any)
fn C.ClearSensor(args ...any) 
fn C.ResetSensor(args ...any)


@[as_macro]
pub fn setup(args ...any) {
	C.SetSensor(...args) 
}                                                          

@[as_macro]
pub fn as_touch(args ...any) {
	C.SetSensorTouch(...args) 
}                                                          

@[as_macro]
pub fn as_light(args ...any) {
	C.SetSensorLight(...args) 
}                                                          

@[as_macro]
pub fn as_sound(args ...any) {
	C.SetSensorSound(...args) 
}                                                          

@[as_macro]
pub fn as_lowspeed(args ...any) {
	C.SetSensorLowspeed(...args) 
}                                                          

@[as_macro]
pub fn as_ultrasonic(args ...any) {
	C.SetSensorUltrasonic(...args)
}                                                          
                                                    
@[as_macro]
pub fn as_temperature(args ...any) {
	C.SetSensorTemperature(...args) 
}                                                          

@[as_macro]
pub fn as_color_full(args ...any) {
	C.SetSensorColorFull(...args) 
}                                                          

@[as_macro]
pub fn read(args ...any) u16 {
	return C.Sensor(...args) 
}                                                          

@[as_macro]
pub fn read_bool(args ...any) bool {
	return C.SensorBoolean(...args) 
}       

@[as_macro]
pub fn read_us(args ...any) u8 {
	return C.SensorUS(...args) 
} 

@[as_macro]
pub fn read_us_now(args ...any) u8 {
	return C.SensorUS0(...args) 
} 

@[as_macro]
pub fn read_us_wait(args ...any) u8 {
	return C.SensorUSWait(...args) 
} 

@[as_macro]
pub fn setup_temperature(args ...any) {
	C.ConfigureTemperatureSensor(...args) 
} 

@[as_macro]
pub fn read_temperature(args ...any) f32 {
	return C.SensorTemperature(...args) 
}

@[as_macro]
pub fn set_type(args ...any) {
	C.SetSensorType(...args) 
}                                                          

@[as_macro]
pub fn write_mode(args ...any) {
	C.SetSensorMode(...args) 
}  

@[as_macro]
pub fn clear(args ...any) {
	C.ClearSensor(...args) 
}    

@[as_macro]
pub fn reset(args ...any) {
	C.ResetSensor(...args) 
}   