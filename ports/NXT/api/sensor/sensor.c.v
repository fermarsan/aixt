// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Sensor module for NXT (NXC backend)

module sensor	


@[as_macro] const s1 = 0
@[as_macro] const s2 = 1
@[as_macro] const s3 = 2
@[as_macro] const s4 = 3

// Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call. 
@[as_macro] const touch   		= C.SENSOR_TOUCH
@[as_macro] const light   		= C.SENSOR_LIGHT
@[as_macro] const rotation   	= C.SENSOR_ROTATION
@[as_macro] const celsius   	= C.SENSOR_CELSIUS
@[as_macro] const fahrenheit   	= C.SENSOR_FAHRENHEIT
@[as_macro] const pulse   		= C.SENSOR_PULSE
@[as_macro] const edge    		= C.SENSOR_EDGE
@[as_macro] const nxtlight   	= C.SENSOR_NXTLIGHT
@[as_macro] const sound   		= C.SENSOR_SOUND
@[as_macro] const lowspeed_9v  	= C.SENSOR_LOWSPEED_9V
@[as_macro] const lowspeed   	= C.SENSOR_LOWSPEED
@[as_macro] const colorfull   	= C.SENSOR_COLORFULL
@[as_macro] const colorred   	= C.SENSOR_COLORRED
@[as_macro] const colorgreen   	= C.SENSOR_COLORGREEN
@[as_macro] const colorblue   	= C.SENSOR_COLORBLUE
@[as_macro] const colornone   	= C.SENSOR_COLORNONE

// Use sensor type constants to configure an input port for a specific type of sensor.
// These constants are intended for use in NBC. 
@[as_macro] const type_no_sensor     	= C.IN_TYPE_NO_SENSOR     
@[as_macro] const type_switch        	= C.IN_TYPE_SWITCH        
@[as_macro] const type_temperature   	= C.IN_TYPE_TEMPERATURE   
@[as_macro] const type_reflection    	= C.IN_TYPE_REFLECTION    
@[as_macro] const type_angle         	= C.IN_TYPE_ANGLE         
@[as_macro] const type_light_active  	= C.IN_TYPE_LIGHT_ACTIVE  
@[as_macro] const type_light_inactive	= C.IN_TYPE_LIGHT_INACTIVE
@[as_macro] const type_sound_db      	= C.IN_TYPE_SOUND_DB      
@[as_macro] const type_sound_dba     	= C.IN_TYPE_SOUND_DBA     
@[as_macro] const type_custom        	= C.IN_TYPE_CUSTOM        
@[as_macro] const type_lowspeed      	= C.IN_TYPE_LOWSPEED      
@[as_macro] const type_lowspeed_9v   	= C.IN_TYPE_LOWSPEED_9V   
@[as_macro] const type_hispeed       	= C.IN_TYPE_HISPEED       
@[as_macro] const type_colorfull     	= C.IN_TYPE_COLORFULL     
@[as_macro] const type_colorred      	= C.IN_TYPE_COLORRED      
@[as_macro] const type_colorgreen    	= C.IN_TYPE_COLORGREEN    
@[as_macro] const type_colorblue     	= C.IN_TYPE_COLORBLUE     
@[as_macro] const type_colornone     	= C.IN_TYPE_COLORNONE     
@[as_macro] const type_colorexit     	= C.IN_TYPE_COLOREXIT    


// Use sensor mode constants to configure an input port for the desired sensor mode.
// The constants are intended for use in NBC. 
@[as_macro] const mode_raw          	= C.IN_MODE_RAW          
@[as_macro] const mode_boolean      	= C.IN_MODE_BOOLEAN      
@[as_macro] const mode_transitioncnt	= C.IN_MODE_TRANSITIONCNT
@[as_macro] const mode_periodcounter	= C.IN_MODE_PERIODCOUNTER
@[as_macro] const mode_pctfullscale 	= C.IN_MODE_PCTFULLSCALE 
@[as_macro] const mode_celsius      	= C.IN_MODE_CELSIUS      
@[as_macro] const mode_fahrenheit   	= C.IN_MODE_FAHRENHEIT   
@[as_macro] const mode_anglestep    	= C.IN_MODE_ANGLESTEP    
@[as_macro] const mode_slopemask    	= C.IN_MODE_SLOPEMASK    
@[as_macro] const mode_modemask     	= C.IN_MODE_MODEMASK    

// Use sensor mode constants to configure an input port for the desired sensor mode.  
@[as_macro] const mode_raw            = C.IN_MODE_RAW
@[as_macro] const mode_bool           = C.IN_MODE_BOOLEAN
@[as_macro] const mode_edge           = C.IN_MODE_TRANSITIONCNT
@[as_macro] const mode_pulse          = C.IN_MODE_PERIODCOUNTER
@[as_macro] const mode_percent        = C.IN_MODE_PCTFULLSCALE
@[as_macro] const mode_celsius        = C.IN_MODE_CELSIUS
@[as_macro] const mode_fahrenheit     = C.IN_MODE_FAHRENHEIT
@[as_macro] const mode_rotation       = C.IN_MODE_ANGLESTEP

// Use sensor type constants to configure an input port for a specific type of sensor. 
@[as_macro] const type_none          	= C.IN_TYPE_NO_SENSOR
@[as_macro] const type_touch         	= C.IN_TYPE_SWITCH
@[as_macro] const type_temperature   	= C.IN_TYPE_TEMPERATURE
@[as_macro] const type_light         	= C.IN_TYPE_REFLECTION
@[as_macro] const type_rotation      	= C.IN_TYPE_ANGLE
@[as_macro] const type_light_active  	= C.IN_TYPE_LIGHT_ACTIVE
@[as_macro] const type_light_inactive	= C.IN_TYPE_LIGHT_INACTIVE
@[as_macro] const type_sound_db      	= C.IN_TYPE_SOUND_DB
@[as_macro] const type_sound_dba     	= C.IN_TYPE_SOUND_DBA
@[as_macro] const type_custom        	= C.IN_TYPE_CUSTOM
@[as_macro] const type_lowspeed      	= C.IN_TYPE_LOWSPEED
@[as_macro] const type_lowspeed_9v   	= C.IN_TYPE_LOWSPEED_9V
@[as_macro] const type_highspeed     	= C.IN_TYPE_HISPEED
@[as_macro] const type_colorfull     	= C.IN_TYPE_COLORFULL
@[as_macro] const type_colorred      	= C.IN_TYPE_COLORRED
@[as_macro] const type_colorgreen    	= C.IN_TYPE_COLORGREEN
@[as_macro] const type_colorblue     	= C.IN_TYPE_COLORBLUE
@[as_macro] const type_colornone     	= C.IN_TYPE_COLORNONE

@[as_macro]
pub fn setup(port u8, config u32) {
	C.SetSensor(port, config) 
}                                                          

@[as_macro]
pub fn as_touch(port u8) {
	C.SetSensorTouch(port) 
}                                                          

@[as_macro]
pub fn as_light(port u8, b_active bool) {
	C.SetSensorLight(port, b_active) 
}                                                          

@[as_macro]
pub fn as_sound(port u8, bd_b_scaling bool ) {
	C.SetSensorSound(port, bd_b_scaling) 
}                                                          

@[as_macro]
pub fn as_lowspeed(port u8, bis_powered bool) {
	C.SetSensorLowspeed(port, bis_powered) 
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
pub fn read(port u8) u32 {
	return C.Sensor(port) 
}                                                          

@[as_macro]
pub fn boolean(port u8) bool {
	return C.SensorBoolean(port) 
}       

@[as_macro]
pub fn read_us(port u8) u8 {
	return C.SensorUS(port u8) 
} 

@[as_macro]
pub fn read_us_now(port u8) u8 {
	return C.SensorUS0(port u8) 
} 

@[as_macro]
pub fn read_us_wait(port u8, wait u8) {
	return C.SensorUSWait(port, wait) 
} 

@[as_macro]
pub fn setup_temperature(port u8, config u8) {
	return C.ConfigureTemperatureSensor(port, config) 
} 

@[as_macro]
pub fn read_temperature(port u8) {
	return C.SensorTemperature(port) 
}

@[as_macro]
pub fn setup_type(port u8, typ u8) {
	C.SetSensorType(port, typ) 
}                                                          

@[as_macro]
pub fn setup_mode(port u8, mode u8) {
	C.SetSensorMode(port, mode) 
}  

@[as_macro]
pub fn reset(port u8) {
	C.ResetSensor(port) 
}   