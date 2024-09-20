module sensor	

enum Sensor_names {
	s1 = 0
	s2
	s3
	s4
}

// Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call. 
#define 	sensor__touch   		SENSOR_TOUCH
#define 	sensor__light   		SENSOR_LIGHT
#define 	sensor__rotation   		SENSOR_ROTATION
#define 	sensor__celsius   		SENSOR_CELSIUS
#define 	sensor__fahrenheit   	SENSOR_FAHRENHEIT
#define 	sensor__pulse   		SENSOR_PULSE
#define 	sensor__edge    		SENSOR_EDGE
#define 	sensor__nxtlight   		SENSOR_NXTLIGHT
#define 	sensor__sound   		SENSOR_SOUND
#define 	sensor__lowspeed_9v  	SENSOR_LOWSPEED_9V
#define 	sensor__lowspeed   		SENSOR_LOWSPEED
#define 	sensor__colorfull   	SENSOR_COLORFULL
#define 	sensor__colorred   		SENSOR_COLORRED
#define 	sensor__colorgreen   	SENSOR_COLORGREEN
#define 	sensor__colorblue   	SENSOR_COLORBLUE
#define 	sensor__colornone   	SENSOR_COLORNONE

// Use sensor mode constants to configure an input port for the desired sensor mode.
// The constants are intended for use in NBC. 
// #define 	mode_raw          	IN_MODE_RAW          
// #define 	mode_boolean      	IN_MODE_BOOLEAN      
// #define 	mode_transitioncnt	IN_MODE_TRANSITIONCNT
// #define 	mode_periodcounter	IN_MODE_PERIODCOUNTER
// #define 	mode_pctfullscale 	IN_MODE_PCTFULLSCALE 
// #define 	mode_celsius      	IN_MODE_CELSIUS      
// #define 	mode_fahrenheit   	IN_MODE_FAHRENHEIT   
// #define 	mode_anglestep    	IN_MODE_ANGLESTEP    
// #define 	mode_slopemask    	IN_MODE_SLOPEMASK    
// #define 	mode_modemask     	IN_MODE_MODEMASK     

// Use sensor type constants to configure an input port for a specific type of sensor.
// These constants are intended for use in NBC. 
// #define 	type_no_sensor     	IN_TYPE_NO_SENSOR     
// #define 	type_switch        	IN_TYPE_SWITCH        
// #define 	type_temperature   	IN_TYPE_TEMPERATURE   
// #define 	type_reflection    	IN_TYPE_REFLECTION    
// #define 	type_angle         	IN_TYPE_ANGLE         
// #define 	type_light_active  	IN_TYPE_LIGHT_ACTIVE  
// #define 	type_light_inactive	IN_TYPE_LIGHT_INACTIVE
// #define 	type_sound_db      	IN_TYPE_SOUND_DB      
// #define 	type_sound_dba     	IN_TYPE_SOUND_DBA     
// #define 	type_custom        	IN_TYPE_CUSTOM        
// #define 	type_lowspeed      	IN_TYPE_LOWSPEED      
// #define 	type_lowspeed_9v   	IN_TYPE_LOWSPEED_9V   
// #define 	type_hispeed       	IN_TYPE_HISPEED       
// #define 	type_colorfull     	IN_TYPE_COLORFULL     
// #define 	type_colorred      	IN_TYPE_COLORRED      
// #define 	type_colorgreen    	IN_TYPE_COLORGREEN    
// #define 	type_colorblue     	IN_TYPE_COLORBLUE     
// #define 	type_colornone     	IN_TYPE_COLORNONE     
// #define 	type_colorexit     	IN_TYPE_COLOREXIT    

// Use sensor mode constants to configure an input port for the desired sensor mode.  
// #define 	mode_raw          IN_MODE_RAW
// #define 	mode_bool         IN_MODE_BOOLEAN
// #define 	mode_edge         IN_MODE_TRANSITIONCNT
// #define 	mode_pulse        IN_MODE_PERIODCOUNTER
// #define 	mode_percent      IN_MODE_PCTFULLSCALE
// #define 	mode_celsius      IN_MODE_CELSIUS
// #define 	mode_fahrenheit   IN_MODE_FAHRENHEIT
// #define 	mode_rotation     IN_MODE_ANGLESTEP

// Use sensor type constants to configure an input port for a specific type of sensor. 
// #define 	type_none          	IN_TYPE_NO_SENSOR
// #define 	type_touch         	IN_TYPE_SWITCH
// #define 	type_temperature   	IN_TYPE_TEMPERATURE
// #define 	type_light         	IN_TYPE_REFLECTION
// #define 	type_rotation      	IN_TYPE_ANGLE
// #define 	type_light_active  	IN_TYPE_LIGHT_ACTIVE
// #define 	type_light_inactive	IN_TYPE_LIGHT_INACTIVE
// #define 	type_sound_db      	IN_TYPE_SOUND_DB
// #define 	type_sound_dba     	IN_TYPE_SOUND_DBA
// #define 	type_custom        	IN_TYPE_CUSTOM
// #define 	type_lowspeed      	IN_TYPE_LOWSPEED
// #define 	type_lowspeed_9v   	IN_TYPE_LOWSPEED_9V
// #define 	type_highspeed     	IN_TYPE_HISPEED
// #define 	type_colorfull     	IN_TYPE_COLORFULL
// #define 	type_colorred      	IN_TYPE_COLORRED
// #define 	type_colorgreen    	IN_TYPE_COLORGREEN
// #define 	type_colorblue     	IN_TYPE_COLORBLUE
// #define 	type_colornone     	IN_TYPE_COLORNONE

// 
// #define 	custominactive	INPUT_CUSTOMINACTIVE
// #define 	custom9v      	INPUT_CUSTOM9V      
// #define 	customactive  	INPUT_CUSTOMACTIVE  
// #define 	invalid_data  	INPUT_INVALID_DATA 

// Functions for accessing and modifying input module features. 

// @[inline]
// pub fn set_type(port u8, typ u8) {
// 	return C.SetSensorType(port, typ) 
// }                                                          

// @[inline]
// pub fn set_mode() {
// 	return C.SetSensorMode() 
// }                                                          

// @[inline]
// pub fn clear() {
// 	return C.ClearSensor() 
// }                                                          

// @[inline]
// pub fn reset() {
// 	return C.ResetSensor() 
// }                                                          

@[inline]
pub fn setup() {
	return C.SetSensor() 
}                                                          

@[inline]
pub fn set_touch() {
	return C.SetSensorTouch() 
}                                                          

@[inline]
pub fn set_light() {
	return C.SetSensorLight() 
}                                                          

@[inline]
pub fn set_sound() {
	return C.SetSensorSound() 
}                                                          

@[inline]
pub fn set_lowspeed() {
	return C.SetSensorLowspeed() 
}                                                          

@[inline]
pub fn set_ultrasonic() {
	return C.SetSensorUltrasonic() 
}                                                          

@[inline]
pub fn set_e_meter() {
	return C.SetSensorEMeter() 
}                                                          

@[inline]
pub fn set_temperature() {
	return C.SetSensorTemperature() 
}                                                          

@[inline]
pub fn set_color_full() {
	return C.SetSensorColorFull() 
}                                                          

@[inline]
pub fn set_color_red() {
	return C.SetSensorColorRed() 
}                                                          

@[inline]
pub fn set_color_green() {
	return C.SetSensorColorGreen() 
}                                                          

@[inline]
pub fn set_color_blue() {
	return C.SetSensorColorBlue() 
}                                                          

@[inline]
pub fn set_color_none() {
	return C.SetSensorColorNone() 
}                                                        

@[inline]
pub fn read() {
	return C.Sensor() 
}                                                          

@[inline]
pub fn boolean() {
	return C.SensorBoolean() 
}                                                          

@[inline]
pub fn digi_pins_direction() {
	return C.SensorDigiPinsDirection() 
}                                                          

@[inline]
pub fn digi_pins_output_level() {
	return C.SensorDigiPinsOutputLevel() 
}                                                          

@[inline]
pub fn digi_pins_status() {
	return C.SensorDigiPinsStatus() 
}                                                          

@[inline]
pub fn invalid() {
	return C.SensorInvalid() 
}                                                          

@[inline]
pub fn mode() {
	return C.SensorMode() 
}                                                          

@[inline]
pub fn normalized() {
	return C.SensorNormalized() 
}                                                          

@[inline]
pub fn raw() {
	return C.SensorRaw() 
}                                                          

@[inline]
pub fn scaled() {
	return C.SensorScaled() 
}                                                          

@[inline]
pub fn type() {
	return C.SensorType() 
}                                                          

@[inline]
pub fn value() {
	return C.SensorValue() 
}                                                          

@[inline]
pub fn value_bool() {
	return C.SensorValueBool() 
}                                                          

@[inline]
pub fn value_raw() {
	return C.SensorValueRaw() 
}                                                          

@[inline]
pub fn custom_active_status() {
	return C.CustomSensorActiveStatus() 
}                                                          

@[inline]
pub fn custom_percent_full_scale() {
	return C.CustomSensorPercentFullScale() 
}                                                          

@[inline]
pub fn custom_zero_offset() {
	return C.CustomSensorZeroOffset() 
}                                                          

@[inline]
pub fn set_custom_active_status() {
	return C.SetCustomSensorActiveStatus() 
}                                                          

@[inline]
pub fn set_custom_percent_full_scale() {
	return C.SetCustomSensorPercentFullScale() 
}                                                          

@[inline]
pub fn set_custom_zero_offset() {
	return C.SetCustomSensorZeroOffset() 
}                                                          

@[inline]
pub fn set_boolean() {
	return C.SetSensorBoolean() 
}                                                          

@[inline]
pub fn set_digi_pins_direction() {
	return C.SetSensorDigiPinsDirection() 
}                                                          

@[inline]
pub fn set_digi_pins_output_level() {
	return C.SetSensorDigiPinsOutputLevel() 
}                                                          

@[inline]
pub fn set_digi_pins_status() {
	return C.SetSensorDigiPinsStatus() 
}                                                          

@[inline]
pub fn sys_color_read() {
	return C.SysColorSensorRead() 
}                                                          

@[inline]
pub fn read_colors_ex() {
	return C.ReadSensorColorEx() 
}                                                          

@[inline]
pub fn read_colors_raw() {
	return C.ReadSensorColorRaw() 
}                                                         

@[inline]
pub fn read_color_raw() {
	return C.ColorSensorRaw() 
}                                                          

@[inline]
pub fn read_color_value() {
	return C.ColorSensorValue() 
}    

// 
@[inline]
pub fn get_input() {
	return C.GetInput() 
}       
// 
@[inline]
pub fn set_input() {
	return C.SetInput() 
}       
// 
@[inline]
pub fn color_ad_raw() {
	return C.ColorAdRaw() 
}       
// 
@[inline]
pub fn color_boolean() {
	return C.ColorBoolean() 
}       
// 
@[inline]
pub fn color_calibration() {
	return C.ColorCalibration() 
}       
// 
@[inline]
pub fn color_calibration_state() {
	return C.ColorCalibrationState() 
}       
// 
@[inline]
pub fn color_cal_limits() {
	return C.ColorCalLimits() 
}
// 
@[inline]
pub fn sys_input_pin_function() {
	return C.SysInputPinFunction() 
} 

// #################### NXC LowSpeed module ####################

// Constants for use with the e-meter sensor. 
// #define 	emeter_reg_vin   	EMETER_REG_VIN   
// #define 	emeter_reg_ain   	EMETER_REG_AIN   
// #define 	emeter_reg_vout  	EMETER_REG_VOUT  
// #define 	emeter_reg_aout  	EMETER_REG_AOUT  
// #define 	emeter_reg_joules	EMETER_REG_JOULES
// #define 	emeter_reg_win   	EMETER_REG_WIN   
// #define 	emeter_reg_wout  	EMETER_REG_WOUT  

// Constants for use with the ultrasonic sensor. 
// #define 	us_cmd_off                  	US_CMD_OFF                  
// #define 	us_cmd_singleshot           	US_CMD_SINGLESHOT           
// #define 	us_cmd_continuous           	US_CMD_CONTINUOUS           
// #define 	us_cmd_eventcapture         	US_CMD_EVENTCAPTURE         
// #define 	us_cmd_warmreset            	US_CMD_WARMRESET            
// #define 	us_reg_cm_interval          	US_REG_CM_INTERVAL          
// #define 	us_reg_actual_zero          	US_REG_ACTUAL_ZERO          
// #define 	us_reg_scale_factor         	US_REG_SCALE_FACTOR         
// #define 	us_reg_scale_divisor        	US_REG_SCALE_DIVISOR        
// #define 	us_reg_factory_actual_zero  	US_REG_FACTORY_ACTUAL_ZERO  
// #define 	us_reg_factory_scale_factor 	US_REG_FACTORY_SCALE_FACTOR 
// #define 	us_reg_factory_scale_divisor	US_REG_FACTORY_SCALE_DIVISOR
// #define 	us_reg_measurement_units    	US_REG_MEASUREMENT_UNITS  

// Constants for use with the LEGO temperature sensor. 
// #define 	temp_res_9bit     	TEMP_RES_9BIT     
// #define 	temp_res_10bit    	TEMP_RES_10BIT    
// #define 	temp_res_11bit    	TEMP_RES_11BIT    
// #define 	temp_res_12bit    	TEMP_RES_12BIT    
// #define 	temp_sd_continuous	TEMP_SD_CONTINUOUS
// #define 	temp_sd_shutdown  	TEMP_SD_SHUTDOWN  
// #define 	temp_tm_comparator	TEMP_TM_COMPARATOR
// #define 	temp_tm_interrupt 	TEMP_TM_INTERRUPT 
// #define 	temp_os_oneshot   	TEMP_OS_ONESHOT   
// #define 	temp_fq_1         	TEMP_FQ_1         
// #define 	temp_fq_2         	TEMP_FQ_2         
// #define 	temp_fq_4         	TEMP_FQ_4         
// #define 	temp_fq_6         	TEMP_FQ_6         
// #define 	temp_pol_low      	TEMP_POL_LOW      
// #define 	temp_pol_high     	TEMP_POL_HIGH     
// #define 	temp_reg_temp     	TEMP_REG_TEMP     
// #define 	temp_reg_config   	TEMP_REG_CONFIG   
// #define 	temp_reg_tlow     	TEMP_REG_TLOW     
// #define 	temp_reg_thigh    	TEMP_REG_THIGH   

// Functions for accessing and modifying low speed module features. 

@[inline]
pub fn sensor__read_ultrasonic() {
	return C.SensorUS() 
} 

@[inline]
pub fn sensor__read_ultrasonic0() {
	return C.SensorUS0() 
} 

@[inline]
pub fn sensor__us_wait() {
	return C.SensorUSWait() 
} 

@[inline]
pub fn sensor__read_ultrasonic_ex() {
	return C.ReadSensorUSEx() 
} 

@[inline]
pub fn sensor__read_ultrasonic_ex0() {
	return C.ReadSensorUSEx0() 
} 

@[inline]
pub fn sensor__read_ultrasonic_ex_wait() {
	return C.ReadSensorUSExWait() 
} 

@[inline]
pub fn sensor__read_e_meter() {
	return C.ReadSensorEMeter() 
} 

@[inline]
pub fn sensor__configure_temperature() {
	return C.ConfigureTemperatureSensor() 
} 

@[inline]
pub fn sensor__read_temperature() {
	return C.SensorTemperature() 
}
