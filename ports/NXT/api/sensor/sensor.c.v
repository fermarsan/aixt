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
@[as_macro] pub const touch   		= u16(C.SENSOR_TOUCH)
@[as_macro] pub const light   		= u16(C.SENSOR_LIGHT)
@[as_macro] pub const rotation   	= u16(C.SENSOR_ROTATION)
@[as_macro] pub const celsius   	= u16(C.SENSOR_CELSIUS)
@[as_macro] pub const fahrenheit   	= u16(C.SENSOR_FAHRENHEIT)
@[as_macro] pub const pulse   		= u16(C.SENSOR_PULSE)
@[as_macro] pub const edge    		= u16(C.SENSOR_EDGE)
@[as_macro] pub const nxtlight   	= u16(C.SENSOR_NXTLIGHT)
@[as_macro] pub const sound   		= u16(C.SENSOR_SOUND)
@[as_macro] pub const lowspeed_9v  	= u16(C.SENSOR_LOWSPEED_9V)
@[as_macro] pub const lowspeed   	= u16(C.SENSOR_LOWSPEED)
@[as_macro] pub const colorfull   	= u16(C.SENSOR_COLORFULL)
@[as_macro] pub const colorred   	= u16(C.SENSOR_COLORRED)
@[as_macro] pub const colorgreen   	= u16(C.SENSOR_COLORGREEN)
@[as_macro] pub const colorblue   	= u16(C.SENSOR_COLORBLUE)
@[as_macro] pub const colornone   	= u16(C.SENSOR_COLORNONE)


// Use sensor mode constants to configure an input port for the desired sensor mode.
// The constants are intended for use in NBC. 
@[as_macro] pub const mode_raw          = C.IN_MODE_RAW
@[as_macro] pub const mode_bool         = C.IN_MODE_BOOLEAN
@[as_macro] pub const mode_edge         = C.IN_MODE_TRANSITIONCNT
@[as_macro] pub const mode_pulse        = C.IN_MODE_PERIODCOUNTER
@[as_macro] pub const mode_percent      = C.IN_MODE_PCTFULLSCALE
@[as_macro] pub const mode_celsius      = C.IN_MODE_CELSIUS
@[as_macro] pub const mode_fahrenheit   = C.IN_MODE_FAHRENHEIT
@[as_macro] pub const mode_rotation     = C.IN_MODE_ANGLESTEP  
@[as_macro] pub const mode_slopemask    = C.IN_MODE_SLOPEMASK    
@[as_macro] pub const mode_modemask     = C.IN_MODE_MODEMASK    

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
@[as_macro] pub const type_lowspeed      	= C.IN_TYPE_LOWSPEED
@[as_macro] pub const type_lowspeed_9v   	= C.IN_TYPE_LOWSPEED_9V
@[as_macro] pub const type_highspeed     	= C.IN_TYPE_HISPEED
@[as_macro] pub const type_colorfull     	= C.IN_TYPE_COLORFULL
@[as_macro] pub const type_colorred      	= C.IN_TYPE_COLORRED
@[as_macro] pub const type_colorgreen    	= C.IN_TYPE_COLORGREEN
@[as_macro] pub const type_colorblue     	= C.IN_TYPE_COLORBLUE
@[as_macro] pub const type_colornone     	= C.IN_TYPE_COLORNONE   
@[as_macro] pub const type_colorexit     	= C.IN_TYPE_COLOREXIT 


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
fn C.ResetSensor(args ...any)


@[as_macro]
pub fn setup(port u8, config u16) {
	C.SetSensor(port, config) 
}                                                          

@[as_macro]
pub fn as_touch(port u8) {
	C.SetSensorTouch(port) 
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
pub fn as_ultrasonic(port u8) {
	C.SetSensorUltrasonic(port)
}                                                          

                                                        

@[as_macro]
pub fn as_temperature(port u8) {
	C.SetSensorTemperature(port) 
}                                                          

@[as_macro]
pub fn as_color_full(port u8) {
	C.SetSensorColorFull(port) 
}                                                          


@[as_macro]
pub fn read(port u8) u16 {
	return C.Sensor(port) 
}                                                          

@[as_macro]
pub fn read_bool(port u8) bool {
	return C.SensorBoolean(port) 
}       

@[as_macro]
pub fn read_us(port u8) u8 {
	return C.SensorUS(port) 
} 

@[as_macro]
pub fn read_us_now(port u8) u8 {
	return C.SensorUS0(port) 
} 

@[as_macro]
pub fn read_us_wait(port u8, wait u8) u8 {
	return C.SensorUSWait(port, wait) 
} 

@[as_macro]
pub fn setup_temperature(port u8, config u8) {
	C.ConfigureTemperatureSensor(port, config) 
} 

@[as_macro]
pub fn read_temperature(port u8) f32 {
	return C.SensorTemperature(port) 
}

@[as_macro]
pub fn write_type(port u8, typ u8) {
	C.SetSensorType(port, typ) 
}                                                          

@[as_macro]
pub fn write_mode(port u8, mode u8) {
	C.SetSensorMode(port, mode) 
}  

@[as_macro]
pub fn reset(port u8) {
	C.ResetSensor(port) 
}   