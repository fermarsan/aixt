module sensor	// NXC Input

// Constants for use with the color calibration functions. 
#define 	cal_point_0 	INPUT_CAL_POINT_0    
#define 	cal_point_1 	INPUT_CAL_POINT_1    
#define 	cal_point_2 	INPUT_CAL_POINT_2    
#define 	no_of_points	INPUT_NO_OF_POINTS   

// Constants for use with the color calibration state function. 
#define 	sensorcal 	INPUT_SENSORCAL 
#define 	sensoroff 	INPUT_SENSOROFF 
#define 	runningcal	INPUT_RUNNINGCAL
#define 	startcal  	INPUT_STARTCAL  
#define 	resetcal  	INPUT_RESETCAL  

// Constants for use with color sensor value arrays to index RGB and blank return values. 
#define 	red         	INPUT_RED         
#define 	green       	INPUT_GREEN       
#define 	blue        	INPUT_BLUE        
#define 	blank       	INPUT_BLANK       
#define 	no_of_colors	INPUT_NO_OF_COLORS

// Constants for use with the ColorValue returned by the color sensor in full color mode. 
#define 	blackcolor 		INPUT_BLACKCOLOR 
#define 	bluecolor  		INPUT_BLUECOLOR  
#define 	greencolor 		INPUT_GREENCOLOR 
#define 	yellowcolor		INPUT_YELLOWCOLOR
#define 	redcolor   		INPUT_REDCOLOR   
#define 	whitecolor 		INPUT_WHITECOLOR 

// Constants for use with the Input module's Pin function. 
#define 	pincmd_dir   	INPUT_PINCMD_DIR   
#define 	pincmd_set   	INPUT_PINCMD_SET   
#define 	pincmd_clear 	INPUT_PINCMD_CLEAR 
#define 	pincmd_read  	INPUT_PINCMD_READ  
#define 	pincmd_mask  	INPUT_PINCMD_MASK  
#define 	pincmd_wait  	INPUT_PINCMD_WAIT  
#define 	pindir_output	INPUT_PINDIR_OUTPUT
#define 	pindir_input 	INPUT_PINDIR_INPUT

// Constants for use with set_input                                                      
#define 	type_field           	TypeField           
#define 	input_mode_field      	InputModeField      
#define 	raw_value_field       	RawValueField       
#define 	normalized_value_field	NormalizedValueField
#define 	scaled_value_field    	ScaledValueField    
#define 	invalid_data_field    	InvalidDataField    

// Constant offsets into the Input module IOMAP structure. 
#define 	offset_custom_zero_offset     	InputOffsetCustomZeroOffset                                                      
#define 	offset_ad_raw                	InputOffsetADRaw                                                      
#define 	offset_sensor_raw            	InputOffsetSensorRaw                                                      
#define 	offset_sensor_value          	InputOffsetSensorValue                                                      
#define 	offset_sensor_type           	InputOffsetSensorType                                                      
#define 	offset_sensor_mode           	InputOffsetSensorMode                                                      
#define 	offset_sensor_boolean        	InputOffsetSensorBoolean                                                      
#define 	offset_digi_pins_dir          	InputOffsetDigiPinsDir                                                      
#define 	offset_digi_pins_in           	InputOffsetDigiPinsIn                                                      
#define 	offset_digi_pins_out          	InputOffsetDigiPinsOut                                                      
#define 	offset_custom_pct_full_scale   	InputOffsetCustomPctFullScale                                                      
#define 	offset_custom_active_status   	InputOffsetCustomActiveStatus                                                      
#define 	offset_invalid_data          	InputOffsetInvalidData                                                      
#define 	offset_color_calibration     	InputOffsetColorCalibration                                                      
#define 	offset_color_cal_limits       	InputOffsetColorCalLimits                                                      
#define 	offset_color_ad_raw           	InputOffsetColorADRaw                                                      
#define 	offset_color_sensor_raw       	InputOffsetColorSensorRaw                                                      
#define 	offset_color_sensor_value     	InputOffsetColorSensorValue                                                      
#define 	offset_color_boolean         	InputOffsetColorBoolean                                                      
#define 	offset_color_calibration_state	InputOffsetColorCalibrationState      

// Input port constants are used when calling NXC sensor control API functions. 
#define 	s1	S1
#define 	s2	S2
#define 	s3	S3
#define 	s4	S4

// Constants for use when directly controlling or reading a port's digital pin state. 
#define 	digi0	INPUT_DIGI0
#define 	digi1	INPUT_DIGI1

// Input port constants are used when calling sensor control API functions.
// These constants are intended for use in NBC. 
#define 	in_1	IN_1
#define 	in_2	IN_2
#define 	in_3	IN_3
#define 	in_4	IN_4

// Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call. 
#define 	touch         _SENSOR_CFG                                                         
#define 	light         _SENSOR_CFG                                                         
#define 	rotation      _SENSOR_CFG                                                         
#define 	celsius       _SENSOR_CFG                                                         
#define 	fahrenheit    _SENSOR_CFG                                                         
#define 	pulse         _SENSOR_CFG                                                         
#define 	edge          _SENSOR_CFG                                                         
#define 	nxtlight      _SENSOR_CFG                                                         
#define 	sound         _SENSOR_CFG                                                         
#define 	lowspeed_9v   _SENSOR_CFG                                                         
#define 	lowspeed      _SENSOR_CFG                                                         
#define 	colorfull     _SENSOR_CFG                                                         
#define 	colorred      _SENSOR_CFG                                                         
#define 	colorgreen    _SENSOR_CFG                                                         
#define 	colorblue     _SENSOR_CFG                                                         
#define 	colornone     _SENSOR_CFG                                                         

// Use sensor mode constants to configure an input port for the desired sensor mode.
// The constants are intended for use in NBC. 
#define 	mode_raw          	IN_MODE_RAW          
#define 	mode_boolean      	IN_MODE_BOOLEAN      
#define 	mode_transitioncnt	IN_MODE_TRANSITIONCNT
#define 	mode_periodcounter	IN_MODE_PERIODCOUNTER
#define 	mode_pctfullscale 	IN_MODE_PCTFULLSCALE 
#define 	mode_celsius      	IN_MODE_CELSIUS      
#define 	mode_fahrenheit   	IN_MODE_FAHRENHEIT   
#define 	mode_anglestep    	IN_MODE_ANGLESTEP    
#define 	mode_slopemask    	IN_MODE_SLOPEMASK    
#define 	mode_modemask     	IN_MODE_MODEMASK     

// Use sensor type constants to configure an input port for a specific type of sensor.
// These constants are intended for use in NBC. 
#define 	type_no_sensor     	IN_TYPE_NO_SENSOR     
#define 	type_switch        	IN_TYPE_SWITCH        
#define 	type_temperature   	IN_TYPE_TEMPERATURE   
#define 	type_reflection    	IN_TYPE_REFLECTION    
#define 	type_angle         	IN_TYPE_ANGLE         
#define 	type_light_active  	IN_TYPE_LIGHT_ACTIVE  
#define 	type_light_inactive	IN_TYPE_LIGHT_INACTIVE
#define 	type_sound_db      	IN_TYPE_SOUND_DB      
#define 	type_sound_dba     	IN_TYPE_SOUND_DBA     
#define 	type_custom        	IN_TYPE_CUSTOM        
#define 	type_lowspeed      	IN_TYPE_LOWSPEED      
#define 	type_lowspeed_9v   	IN_TYPE_LOWSPEED_9V   
#define 	type_hispeed       	IN_TYPE_HISPEED       
#define 	type_colorfull     	IN_TYPE_COLORFULL     
#define 	type_colorred      	IN_TYPE_COLORRED      
#define 	type_colorgreen    	IN_TYPE_COLORGREEN    
#define 	type_colorblue     	IN_TYPE_COLORBLUE     
#define 	type_colornone     	IN_TYPE_COLORNONE     
#define 	type_colorexit     	IN_TYPE_COLOREXIT    

// Use sensor mode constants to configure an input port for the desired sensor mode.  
#define 	mode_raw          IN_MODE_RAW
#define 	mode_bool         IN_MODE_BOOLEAN
#define 	mode_edge         IN_MODE_TRANSITIONCNT
#define 	mode_pulse        IN_MODE_PERIODCOUNTER
#define 	mode_percent      IN_MODE_PCTFULLSCALE
#define 	mode_celsius      IN_MODE_CELSIUS
#define 	mode_fahrenheit   IN_MODE_FAHRENHEIT
#define 	mode_rotation     IN_MODE_ANGLESTEP

// Use sensor type constants to configure an input port for a specific type of sensor. 
#define 	type_none          	IN_TYPE_NO_SENSOR
#define 	type_touch         	IN_TYPE_SWITCH
#define 	type_temperature   	IN_TYPE_TEMPERATURE
#define 	type_light         	IN_TYPE_REFLECTION
#define 	type_rotation      	IN_TYPE_ANGLE
#define 	type_light_active  	IN_TYPE_LIGHT_ACTIVE
#define 	type_light_inactive	IN_TYPE_LIGHT_INACTIVE
#define 	type_sound_db      	IN_TYPE_SOUND_DB
#define 	type_sound_dba     	IN_TYPE_SOUND_DBA
#define 	type_custom        	IN_TYPE_CUSTOM
#define 	type_lowspeed      	IN_TYPE_LOWSPEED
#define 	type_lowspeed_9v   	IN_TYPE_LOWSPEED_9V
#define 	type_highspeed     	IN_TYPE_HISPEED
#define 	type_colorfull     	IN_TYPE_COLORFULL
#define 	type_colorred      	IN_TYPE_COLORRED
#define 	type_colorgreen    	IN_TYPE_COLORGREEN
#define 	type_colorblue     	IN_TYPE_COLORBLUE
#define 	type_colornone     	IN_TYPE_COLORNONE

// 
#define 	custominactive	INPUT_CUSTOMINACTIVE
#define 	custom9v      	INPUT_CUSTOM9V      
#define 	customactive  	INPUT_CUSTOMACTIVE  
#define 	invalid_data  	INPUT_INVALID_DATA  

// Functions for accessing and modifying input module features. 
#define		sensor__set_type                		SetSensorType                                                          
#define		sensor__set_mode          				SetSensorMode                                                          
#define		sensor__clear            				ClearSensor                                                          
#define		sensor__reset            				ResetSensor                                                          
#define		sensor__set              				SetSensor                                                          
#define		sensor__set_touch         				SetSensorTouch                                                          
#define		sensor__set_light         				SetSensorLight                                                          
#define		sensor__set_sound         				SetSensorSound                                                          
#define		sensor__set_lowspeed      				SetSensorLowspeed                                                          
#define		sensor__set_ultrasonic    				SetSensorUltrasonic                                                          
#define		sensor__set_e_meter        				SetSensorEMeter                                                          
#define		sensor__set_temperature   				SetSensorTemperature                                                          
#define		sensor__set_color_full     				SetSensorColorFull                                                          
#define		sensor__set_color_red      				SetSensorColorRed                                                          
#define		sensor__set_color_green    				SetSensorColorGreen                                                          
#define		sensor__set_color_blue     				SetSensorColorBlue                                                          
#define		sensor__set_color_none     				SetSensorColorNone                                                          
#define		get_input                   			GetInput                                                          
#define		set_input                   			SetInput                                                          
#define		sensorx                      			Sensor                                                          
#define		sensor__boolean            				SensorBoolean                                                          
#define		sensor__digi_pins_direction        		SensorDigiPinsDirection                                                          
#define		sensor__digi_pins_output_level      	SensorDigiPinsOutputLevel                                                          
#define		sensor__digi_pins_status           		SensorDigiPinsStatus                                                          
#define		sensor__invalid                  		SensorInvalid                                                          
#define		sensor__mode                     		SensorMode                                                          
#define		sensor__normalized               		SensorNormalized                                                          
#define		sensor__raw                      		SensorRaw                                                          
#define		sensor__scaled                   		SensorScaled                                                          
#define		sensor__type                     		SensorType                                                          
#define		sensor__value                    		SensorValue                                                          
#define		sensor__value_bool                		SensorValueBool                                                          
#define		sensor__value_raw                 		SensorValueRaw                                                          
#define		sensor__custom_active_status       		CustomSensorActiveStatus                                                          
#define		sensor__custom_percent_full_scale   	CustomSensorPercentFullScale                                                          
#define		sensor__custom_zero_offset         		CustomSensorZeroOffset                                                          
#define		sensor__set_custom_active_status    	SetCustomSensorActiveStatus                                                          
#define		sensor__set_custom_percent_full_scale	SetCustomSensorPercentFullScale                                                          
#define		sensor__set_custom_zero_offset      	SetCustomSensorZeroOffset                                                          
#define		sensor__set_boolean               		SetSensorBoolean                                                          
#define		sensor__set_digi_pins_direction     	SetSensorDigiPinsDirection                                                          
#define		sensor__set_digi_pins_output_level   	SetSensorDigiPinsOutputLevel                                                          
#define		sensor__set_digi_pins_status        	SetSensorDigiPinsStatus                                                          
#define		sensor__sys_color_read             		SysColorSensorRead                                                          
#define		sensor__read_color_ex              		ReadSensorColorEx                                                          
#define		sensor__read_color_raw             		ReadSensorColorRaw                                                          
#define		color_ad_raw                    		ColorADRaw                                                          
#define		color_boolean                   		ColorBoolean                                                          
#define		color_calibration               		ColorCalibration                                                          
#define		color_calibration_state         		ColorCalibrationState                                                          
#define		color_cal_limits                		ColorCalLimits                                                          
#define		color_raw                 				ColorSensorRaw                                                          
#define		color_value               				ColorSensorValue                                                          
#define		sys_input_pin_function          		SysInputPinFunction                                                          