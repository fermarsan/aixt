module sensor	

// #################### NXC Input module ####################

// Constants for use with the color calibration functions. 
// #define 	cal_point_0 	INPUT_CAL_POINT_0    
// #define 	cal_point_1 	INPUT_CAL_POINT_1    
// #define 	cal_point_2 	INPUT_CAL_POINT_2    
// #define 	no_of_points	INPUT_NO_OF_POINTS   

// Constants for use with the color calibration state function. 
// #define 	sensorcal 	INPUT_SENSORCAL 
// #define 	sensoroff 	INPUT_SENSOROFF 
// #define 	runningcal	INPUT_RUNNINGCAL
// #define 	startcal  	INPUT_STARTCAL  
// #define 	resetcal  	INPUT_RESETCAL  

// Constants for use with color sensor value arrays to index RGB and blank return values. 
// #define 	red         	INPUT_RED         
// #define 	green       	INPUT_GREEN       
// #define 	blue        	INPUT_BLUE        
// #define 	blank       	INPUT_BLANK       
// #define 	no_of_colors	INPUT_NO_OF_COLORS

// Constants for use with the ColorValue returned by the color sensor in full color mode. 
// #define 	blackcolor 		INPUT_BLACKCOLOR 
// #define 	bluecolor  		INPUT_BLUECOLOR  
// #define 	greencolor 		INPUT_GREENCOLOR 
// #define 	yellowcolor		INPUT_YELLOWCOLOR
// #define 	redcolor   		INPUT_REDCOLOR   
// #define 	whitecolor 		INPUT_WHITECOLOR 

// Constants for use with the Input module's Pin function. 
// #define 	pincmd_dir   	INPUT_PINCMD_DIR   
// #define 	pincmd_set   	INPUT_PINCMD_SET   
// #define 	pincmd_clear 	INPUT_PINCMD_CLEAR 
// #define 	pincmd_read  	INPUT_PINCMD_READ  
// #define 	pincmd_mask  	INPUT_PINCMD_MASK  
// #define 	pincmd_wait  	INPUT_PINCMD_WAIT  
// #define 	pindir_output	INPUT_PINDIR_OUTPUT
// #define 	pindir_input 	INPUT_PINDIR_INPUT

// Constants for use with set_input                                                      
// #define 	type_field           	TypeField           
// #define 	input_mode_field      	InputModeField      
// #define 	raw_value_field       	RawValueField       
// #define 	normalized_value_field	NormalizedValueField
// #define 	scaled_value_field    	ScaledValueField    
// #define 	invalid_data_field    	InvalidDataField    

// Constant offsets into the Input module IOMAP structure. 
// #define 	offset_custom_zero_offset     	InputOffsetCustomZeroOffset                                                      
// #define 	offset_ad_raw                	InputOffsetADRaw                                                      
// #define 	offset_sensor_raw            	InputOffsetSensorRaw                                                      
// #define 	offset_sensor_value          	InputOffsetSensorValue                                                      
// #define 	offset_sensor_type           	InputOffsetSensorType                                                      
// #define 	offset_sensor_mode           	InputOffsetSensorMode                                                      
// #define 	offset_sensor_boolean        	InputOffsetSensorBoolean                                                      
// #define 	offset_digi_pins_dir          	InputOffsetDigiPinsDir                                                      
// #define 	offset_digi_pins_in           	InputOffsetDigiPinsIn                                                      
// #define 	offset_digi_pins_out          	InputOffsetDigiPinsOut                                                      
// #define 	offset_custom_pct_full_scale   	InputOffsetCustomPctFullScale                                                      
// #define 	offset_custom_active_status   	InputOffsetCustomActiveStatus                                                      
// #define 	offset_invalid_data          	InputOffsetInvalidData                                                      
// #define 	offset_color_calibration     	InputOffsetColorCalibration                                                      
// #define 	offset_color_cal_limits       	InputOffsetColorCalLimits                                                      
// #define 	offset_color_ad_raw           	InputOffsetColorADRaw                                                      
// #define 	offset_color_sensor_raw       	InputOffsetColorSensorRaw                                                      
// #define 	offset_color_sensor_value     	InputOffsetColorSensorValue                                                      
// #define 	offset_color_boolean         	InputOffsetColorBoolean                                                      
// #define 	offset_color_calibration_state	InputOffsetColorCalibrationState      

// Input port constants are used when calling NXC sensor control API functions. 
#define 	s1	S1
#define 	s2	S2
#define 	s3	S3
#define 	s4	S4

// Constants for use when directly controlling or reading a port's digital pin state. 
// #define 	digi0	INPUT_DIGI0
// #define 	digi1	INPUT_DIGI1

// Input port constants are used when calling sensor control API functions.
// These constants are intended for use in NBC. 
#define 	i1	IN_1
#define 	i2	IN_2
#define 	i3	IN_3
#define 	i4	IN_4

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
@[inline] set_type() { return C.SetSensorType() }                                                          
@[inline] set_mode() { return C.SetSensorMode() }                                                          
@[inline] clear() { return C.ClearSensor() }                                                          
@[inline] reset() { return C.ResetSensor() }                                                          
@[inline] set() { return C.SetSensor() }                                                          
@[inline] set_touch() { return C.SetSensorTouch() }                                                          
@[inline] set_light() { return C.SetSensorLight() }                                                          
@[inline] set_sound() { return C.SetSensorSound() }                                                          
@[inline] set_lowspeed() { return C.SetSensorLowspeed() }                                                          
@[inline] set_ultrasonic() { return C.SetSensorUltrasonic() }                                                          
@[inline] set_e_meter() { return C.SetSensorEMeter() }                                                          
@[inline] set_temperature() { return C.SetSensorTemperature() }                                                          
@[inline] set_color_full() { return C.SetSensorColorFull() }                                                          
@[inline] set_color_red() { return C.SetSensorColorRed() }                                                          
@[inline] set_color_green() { return C.SetSensorColorGreen() }                                                          
@[inline] set_color_blue() { return C.SetSensorColorBlue() }                                                          
@[inline] set_color_none() { return C.SetSensorColorNone() }                                                        
@[inline] read() { return C.Sensor() }                                                          
@[inline] boolean() { return C.SensorBoolean() }                                                          
@[inline] digi_pins_direction() { return C.SensorDigiPinsDirection() }                                                          
@[inline] digi_pins_output_level() { return C.SensorDigiPinsOutputLevel() }                                                          
@[inline] digi_pins_status() { return C.SensorDigiPinsStatus() }                                                          
@[inline] invalid() { return C.SensorInvalid() }                                                          
@[inline] mode() { return C.SensorMode() }                                                          
@[inline] normalized() { return C.SensorNormalized() }                                                          
@[inline] raw() { return C.SensorRaw() }                                                          
@[inline] scaled() { return C.SensorScaled() }                                                          
@[inline] type() { return C.SensorType() }                                                          
@[inline] value() { return C.SensorValue() }                                                          
@[inline] value_bool() { return C.SensorValueBool() }                                                          
@[inline] value_raw() { return C.SensorValueRaw() }                                                          
@[inline] custom_active_status() { return C.CustomSensorActiveStatus() }                                                          
@[inline] custom_percent_full_scale() { return C.CustomSensorPercentFullScale() }                                                          
@[inline] custom_zero_offset() { return C.CustomSensorZeroOffset() }                                                          
@[inline] set_custom_active_status() { return C.SetCustomSensorActiveStatus() }                                                          
@[inline] set_custom_percent_full_scale() { return C.SetCustomSensorPercentFullScale() }                                                          
@[inline] set_custom_zero_offset() { return C.SetCustomSensorZeroOffset() }                                                          
@[inline] set_boolean() { return C.SetSensorBoolean() }                                                          
@[inline] set_digi_pins_direction() { return C.SetSensorDigiPinsDirection() }                                                          
@[inline] set_digi_pins_output_level() { return C.SetSensorDigiPinsOutputLevel() }                                                          
@[inline] set_digi_pins_status() { return C.SetSensorDigiPinsStatus() }                                                          
@[inline] sys_color_read() { return C.SysColorSensorRead() }                                                          
@[inline] read_colors_ex() { return C.ReadSensorColorEx() }                                                          
@[inline] read_colors_raw() { return C.ReadSensorColorRaw() }                                                         
@[inline] read_color_raw() { return C.ColorSensorRaw() }                                                          
@[inline] read_color_value() { return C.ColorSensorValue() }    

// @[inline] get_input() { return C.GetInput() }       
// @[inline] set_input() { return C.SetInput() }       
// @[inline] color_ad_raw() { return C.ColorAdRaw() }       
// @[inline] color_boolean() { return C.ColorBoolean() }       
// @[inline] color_calibration() { return C.ColorCalibration() }       
// @[inline] color_calibration_state() { return C.ColorCalibrationState() }       
// @[inline] color_cal_limits() { return C.ColorCalLimits() }
// @[inline] sys_input_pin_function() { return C.SysInputPinFunction() } 

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
@[inline] sensor__read_ultrasonic() { return C.SensorUS() } 
@[inline] sensor__read_ultrasonic0() { return C.SensorUS0() } 
@[inline] sensor__us_wait() { return C.SensorUSWait() } 
@[inline] sensor__read_ultrasonic_ex() { return C.ReadSensorUSEx() } 
@[inline] sensor__read_ultrasonic_ex0() { return C.ReadSensorUSEx0() } 
@[inline] sensor__read_ultrasonic_ex_wait() { return C.ReadSensorUSExWait() } 
@[inline] sensor__read_e_meter() { return C.ReadSensorEMeter() } 
@[inline] sensor__configure_temperature() { return C.ConfigureTemperatureSensor() } 
@[inline] sensor__read_temperature() { return C.SensorTemperature() }
