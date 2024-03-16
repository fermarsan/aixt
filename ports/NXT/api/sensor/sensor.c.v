module sensor	

// #################### NXC Input module ####################

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
#define 	i1	IN_1
#define 	i2	IN_2
#define 	i3	IN_3
#define 	i4	IN_4

// Use the combined sensor type and mode constants to configure both the sensor mode and type in a single function call. 
#define 	touch   		SENSOR_TOUCH
#define 	light   		SENSOR_LIGHT
#define 	rotation   		SENSOR_ROTATION
#define 	celsius   		SENSOR_CELSIUS
#define 	fahrenheit   	SENSOR_FAHRENHEIT
#define 	pulse   		SENSOR_PULSE
#define 	edge    		SENSOR_EDGE
#define 	nxtlight   		SENSOR_NXTLIGHT
#define 	sound   		SENSOR_SOUND
#define 	lowspeed_9v  	SENSOR_LOWSPEED_9V
#define 	lowspeed   		SENSOR_LOWSPEED
#define 	colorfull   	SENSOR_COLORFULL
#define 	colorred   		SENSOR_COLORRED
#define 	colorgreen   	SENSOR_COLORGREEN
#define 	colorblue   	SENSOR_COLORBLUE
#define 	colornone   	SENSOR_COLORNONE

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
#define		sensor__set_type(...)                		SetSensorType(__VA_ARGS__)                                                          
#define		sensor__set_mode(...)          				SetSensorMode(__VA_ARGS__)                                                          
#define		sensor__clear(...)            				ClearSensor(__VA_ARGS__)                                                          
#define		sensor__reset(...)            				ResetSensor(__VA_ARGS__)                                                          
#define		sensor__set(...)              				SetSensor(__VA_ARGS__)                                                          
#define		sensor__set_touch(...)         				SetSensorTouch(__VA_ARGS__)                                                          
#define		sensor__set_light(...)         				SetSensorLight(__VA_ARGS__)                                                          
#define		sensor__set_sound(...)         				SetSensorSound(__VA_ARGS__)                                                          
#define		sensor__set_lowspeed(...)      				SetSensorLowspeed(__VA_ARGS__)                                                          
#define		sensor__set_ultrasonic(...)    				SetSensorUltrasonic(__VA_ARGS__)                                                          
#define		sensor__set_e_meter(...)        			SetSensorEMeter(__VA_ARGS__)                                                          
#define		sensor__set_temperature(...)   				SetSensorTemperature(__VA_ARGS__)                                                          
#define		sensor__set_color_full(...)     			SetSensorColorFull(__VA_ARGS__)                                                          
#define		sensor__set_color_red(...)      			SetSensorColorRed(__VA_ARGS__)                                                          
#define		sensor__set_color_green(...)    			SetSensorColorGreen(__VA_ARGS__)                                                          
#define		sensor__set_color_blue(...)     			SetSensorColorBlue(__VA_ARGS__)                                                          
#define		sensor__set_color_none(...)     			SetSensorColorNone(__VA_ARGS__)                                                        
#define		sensor__read(...)		                	Sensor(__VA_ARGS__)                                                          
#define		sensor__boolean(...)            			SensorBoolean(__VA_ARGS__)                                                          
#define		sensor__digi_pins_direction(...)        	SensorDigiPinsDirection(__VA_ARGS__)                                                          
#define		sensor__digi_pins_output_level(...)      	SensorDigiPinsOutputLevel(__VA_ARGS__)                                                          
#define		sensor__digi_pins_status(...)           	SensorDigiPinsStatus(__VA_ARGS__)                                                          
#define		sensor__invalid(...)                  		SensorInvalid(__VA_ARGS__)                                                          
#define		sensor__mode(...)                     		SensorMode(__VA_ARGS__)                                                          
#define		sensor__normalized(...)               		SensorNormalized(__VA_ARGS__)                                                          
#define		sensor__raw(...)                      		SensorRaw(__VA_ARGS__)                                                          
#define		sensor__scaled(...)                   		SensorScaled(__VA_ARGS__)                                                          
#define		sensor__type(...)                     		SensorType(__VA_ARGS__)                                                          
#define		sensor__value(...)                    		SensorValue(__VA_ARGS__)                                                          
#define		sensor__value_bool(...)                		SensorValueBool(__VA_ARGS__)                                                          
#define		sensor__value_raw(...)                 		SensorValueRaw(__VA_ARGS__)                                                          
#define		sensor__custom_active_status(...)       	CustomSensorActiveStatus(__VA_ARGS__)                                                          
#define		sensor__custom_percent_full_scale(...)   	CustomSensorPercentFullScale(__VA_ARGS__)                                                          
#define		sensor__custom_zero_offset(...)         	CustomSensorZeroOffset(__VA_ARGS__)                                                          
#define		sensor__set_custom_active_status(...)    	SetCustomSensorActiveStatus(__VA_ARGS__)                                                          
#define		sensor__set_custom_percent_full_scale(...)	SetCustomSensorPercentFullScale(__VA_ARGS__)                                                          
#define		sensor__set_custom_zero_offset(...)      	SetCustomSensorZeroOffset(__VA_ARGS__)                                                          
#define		sensor__set_boolean(...)               		SetSensorBoolean(__VA_ARGS__)                                                          
#define		sensor__set_digi_pins_direction(...)     	SetSensorDigiPinsDirection(__VA_ARGS__)                                                          
#define		sensor__set_digi_pins_output_level(...)   	SetSensorDigiPinsOutputLevel(__VA_ARGS__)                                                          
#define		sensor__set_digi_pins_status(...)        	SetSensorDigiPinsStatus(__VA_ARGS__)                                                          
#define		sensor__sys_color_read(...)             	SysColorSensorRead(__VA_ARGS__)                                                          
#define		sensor__read_colors_ex(...)              	ReadSensorColorEx(__VA_ARGS__)                                                          
#define		sensor__read_colors_raw(...)             	ReadSensorColorRaw(__VA_ARGS__)                                                         
#define		sensor__read_color_raw(...)           		ColorSensorRaw(__VA_ARGS__)                                                          
#define		sensor__read_color_value(...)         		ColorSensorValue(__VA_ARGS__)    

#define		get_input(...)                   GetInput(__VA_ARGS__)       
#define		set_input(...)                   SetInput(__VA_ARGS__)       
#define		color_ad_raw(...)                ColorAdRaw(__VA_ARGS__)       
#define		color_boolean(...)               ColorBoolean(__VA_ARGS__)       
#define		color_calibration(...)           ColorCalibration(__VA_ARGS__)       
#define		color_calibration_state(...)     ColorCalibrationState(__VA_ARGS__)       
#define		color_cal_limits(...)            ColorCalLimits(__VA_ARGS__)
#define		sys_input_pin_function(...)      SysInputPinFunction(__VA_ARGS__) 

// #################### NXC LowSpeed module ####################

// Constants for use with the e-meter sensor. 
#define 	emeter_reg_vin   	EMETER_REG_VIN   
#define 	emeter_reg_ain   	EMETER_REG_AIN   
#define 	emeter_reg_vout  	EMETER_REG_VOUT  
#define 	emeter_reg_aout  	EMETER_REG_AOUT  
#define 	emeter_reg_joules	EMETER_REG_JOULES
#define 	emeter_reg_win   	EMETER_REG_WIN   
#define 	emeter_reg_wout  	EMETER_REG_WOUT  

// Constants for use with the ultrasonic sensor. 
#define 	us_cmd_off                  	US_CMD_OFF                  
#define 	us_cmd_singleshot           	US_CMD_SINGLESHOT           
#define 	us_cmd_continuous           	US_CMD_CONTINUOUS           
#define 	us_cmd_eventcapture         	US_CMD_EVENTCAPTURE         
#define 	us_cmd_warmreset            	US_CMD_WARMRESET            
#define 	us_reg_cm_interval          	US_REG_CM_INTERVAL          
#define 	us_reg_actual_zero          	US_REG_ACTUAL_ZERO          
#define 	us_reg_scale_factor         	US_REG_SCALE_FACTOR         
#define 	us_reg_scale_divisor        	US_REG_SCALE_DIVISOR        
#define 	us_reg_factory_actual_zero  	US_REG_FACTORY_ACTUAL_ZERO  
#define 	us_reg_factory_scale_factor 	US_REG_FACTORY_SCALE_FACTOR 
#define 	us_reg_factory_scale_divisor	US_REG_FACTORY_SCALE_DIVISOR
#define 	us_reg_measurement_units    	US_REG_MEASUREMENT_UNITS  

// Constants for use with the LEGO temperature sensor. 
#define 	temp_res_9bit     	TEMP_RES_9BIT     
#define 	temp_res_10bit    	TEMP_RES_10BIT    
#define 	temp_res_11bit    	TEMP_RES_11BIT    
#define 	temp_res_12bit    	TEMP_RES_12BIT    
#define 	temp_sd_continuous	TEMP_SD_CONTINUOUS
#define 	temp_sd_shutdown  	TEMP_SD_SHUTDOWN  
#define 	temp_tm_comparator	TEMP_TM_COMPARATOR
#define 	temp_tm_interrupt 	TEMP_TM_INTERRUPT 
#define 	temp_os_oneshot   	TEMP_OS_ONESHOT   
#define 	temp_fq_1         	TEMP_FQ_1         
#define 	temp_fq_2         	TEMP_FQ_2         
#define 	temp_fq_4         	TEMP_FQ_4         
#define 	temp_fq_6         	TEMP_FQ_6         
#define 	temp_pol_low      	TEMP_POL_LOW      
#define 	temp_pol_high     	TEMP_POL_HIGH     
#define 	temp_reg_temp     	TEMP_REG_TEMP     
#define 	temp_reg_config   	TEMP_REG_CONFIG   
#define 	temp_reg_tlow     	TEMP_REG_TLOW     
#define 	temp_reg_thigh    	TEMP_REG_THIGH   

// Functions for accessing and modifying low speed module features. 
#define		sensor__read_us(...) 				SensorUS(__VA_ARGS__) 
#define		sensor__read_us0(...) 				SensorUS0(__VA_ARGS__) 
#define		sensor__us_wait(...) 				SensorUSWait(__VA_ARGS__) 
#define		sensor__read_us_ex(...) 			ReadSensorUSEx(__VA_ARGS__) 
#define		sensor__read_us_ex0(...) 			ReadSensorUSEx0(__VA_ARGS__) 
#define		sensor__read_us_ex_wait(...) 		ReadSensorUSExWait(__VA_ARGS__) 
#define		sensor__read_e_meter(...) 			ReadSensorEMeter(__VA_ARGS__) 
#define		sensor__configure_temperature(...) 	ConfigureTemperatureSensor(__VA_ARGS__) 
#define		sensor__read_temperature(...)		SensorTemperature(__VA_ARGS__)


fn init() {

}