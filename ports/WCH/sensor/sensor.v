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


//HiTechinc Angle Sensor Constants

#define     htangle_mode_normal                  HTANGLE_MODE_NORMAL             
#define     htangle_mode_calibrate               HTANGLE_MODE_CALIBRATE             
#define     htangle_mode_reset                   HTANGLE_MODE_RESET             
#define     htangle_reg_mode                     HTANGLE_REG_MODE             
#define     htangle_reg_dcdir                    HTANGLE_REG_DCDIR             
#define     htangle_reg_dc01                     HTANGLE_REG_DC01             
#define     htangle_reg_dc02                     HTANGLE_REG_DC02             
#define     htangle_reg_dc03                     HTANGLE_REG_DC03             
#define     htangle_reg_dc04                     HTANGLE_REG_DC04             
#define     htangle_reg_dc05                     HTANGLE_REG_DC05             
#define     htangle_reg_dcavg                    HTANGLE_REG_DCAVG             
#define     htangle_reg_acdir                    HTANGLE_REG_ACDIR             

//HiTechinc Barometic Sensor constants

#define     htbar_reg_command                    HTBAR_REG_COMMAND                                                                                    
#define     htbar_reg_temperature                HTBAR_REG_TEMPERATURE                                   
#define     htbar_reg_pressure                   HTBAR_REG_PRESSURE                                
#define     htbar_reg_calibration                HTBAR_REG_CALIBRATION                                   

//HiTechinc Color2 Constants

#define      ht_cmd_color2_active                HT_CMD_COLOR2_ACTIVE  
#define      ht_cmd_color2_passive               HT_CMD_COLOR2_PASSIVE  
#define      ht_cmd_color2_raw                   HT_CMD_COLOR2_RAW  
#define      ht_cmd_color2_50hz                  HT_CMD_COLOR2_50HZ  
#define      ht_cmd_color2_60hz                  HT_CMD_COLOR2_60HZ  
#define      ht_cmd_color2_blcal                 HT_CMD_COLOR2_BLCAL  
#define      ht_cmd_color2_wbcal                 HT_CMD_COLOR2_WBCAL  
#define      ht_cmd_color2_far                   HT_CMD_COLOR2_FAR  
#define      ht_cmd_color2_led_hi                HT_CMD_COLOR2_LED_HI  
#define      ht_cmd_color2_led_low               HT_CMD_COLOR2_LED_LOW  
#define      ht_cmd_color2_near                  HT_CMD_COLOR2_NEAR

//HiTechinc IRReceiver constants

#define      ht_cha1_A                           HT_CHA1_A 
#define      ht_cha1_B                           HT_CHA1_B
#define      ht_cha2_A                           HT_CHA2_A
#define      ht_cha2_B                           HT_CHA2_B
#define      ht_cha3_A                           HT_CHA3_A
#define      ht_cha3_B                           HT_CHA3_B 
#define      ht_cha4_A                           HT_CHA4_A
#define      ht_cha4_B                           HT_CHA4_B

//HiTechinc IRSeeeker2 constants

#define      htir2_mode_1200                     HTIR2_MODE_1200 
#define      htir2_mode_600                      HTIR2_MODE_600
#define      htir2_reg_mode                      HTIR2_REG_MODE
#define      htir2_reg_dcdir                     HTIR2_REG_DCDIR  
#define      htir2_reg_dc01                      HTIR2_REG_DC01
#define      htir2_reg_dc02                      HTIR2_REG_DC02 
#define      htir2_reg_dc03                      HTIR2_REG_DC03
#define      htir2_reg_dc04                      HTIR2_REG_DC04
#define      htir2_reg_dc05                      HTIR2_REG_DC05 
#define      htir2_reg_dcavr                     HTIR2_REG_DCAVG 
#define      htir2_reg_acdir                     HTIR2_REG_ACDIR 
#define      htir2_reg_ac01                      HTIR2_REG_AC01  
#define      htir2_reg_ac02                      HTIR2_REG_AC02
#define      htir2_reg_ac03                      HTIR2_REG_AC03
#define      htir2_reg_ac04                      HTIR2_REG_AC04 
#define      htir2_reg_ac04                      HTIR2_REG_AC05 

// HiTechinc PIR sensor Constants

#define      htpir_reg_deadband                  HTPIR_REG_DEADBAND 
#define      htpir_reg_reading                   HTPIR_REG_READING 

//HiTechinc Prototype board constants

#define      htproto_reg_a0                      HTPROTO_REG_A0  
#define      htproto_reg_a1                      HTPROTO_REG_A1 
#define      htproto_reg_a2                      HTPROTO_REG_A2
#define      htproto_reg_a3                      HTPROTO_REG_A3 
#define      htproto_reg_a4                      HTPROTO_REG_A4
#define      htproto_reg_din                     HTPROTO_REG_DIN 
#define      htproto_reg_dout                    HTPROTO_REG_DOUT 
#define      htproto_reg_dctrl                   HTPROTO_REG_DCTRL 
#define      htproto_reg_strate                  HTPROTO_REG_SRATE

//HiTechinc SuperPro analog input

#define      htspro_A0                           HTSPRO_A0          
#define      htspro_A1                           HTSPRO_A1
#define      htspro_A2                           HTSPRO_A2
#define      htspro_A3                           HTSPRO_A3

//HiTechinc SuperPro analog output

#define      htspro_dac0                         HTSPRO_DAC0
#define      htspro_dac1                         HTSPRO_DAC1 

//SuperPro LED control constants

#define      led_blue                            LED_BLUE
#define      led_red                             LED_RED
#define      led_none                            LED_NONE

//SuperPro Strobe control constants 
#define      strobe_s0                           STROBE_S0          
#define      strobe_s1                           STROBE_S1 
#define      strobe_s2                           STROBE_S2
#define      strobe_s3                           STROBE_S3
#define      strobe_read                         STROBE_READ
#define      strobe_write                        STROBE_WRITE

//SuperPro analog output mode constants

#define      dac_mode_dcout                            DAC_MODE_DCOUT
#define      dac_mode_sinewave                         DAC_MODE_SINEWAVE
#define      dac_mode_squarewave                       DAC_MODE_SQUAREWAVE
#define      dac_mode_sawposwave                       DAC_MODE_SAWPOSWAVE
#define      dac_mode_sawnegwave                       DAC_MODE_SAWNEGWAVE
#define      dac_mode_trianglewave                     DAC_MODE_TRIANGLEWAVE
#define      dac_mode_pwmvoltage                       DAC_MODE_PWMVOLTAGE
#define      dac_mode_restart_mask                     DAC_MODE_RESTART_MASK

//SuperPro digital pin constants

#define      digi_pin0                                 DIGI_PIN0
#define      digi_pin1                                 DIGI_PIN1
#define      digi_pin2                                 DIGI_PIN2
#define      digi_pin3                                 DIGI_PIN3
#define      digi_pin4                                 DIGI_PIN4
#define      digi_pin5                                 DIGI_PIN5
#define      digi_pin6                                 DIGI_PIN6
#define      digi_pin7                                 DIGI_PIN7



// Functions HiTechnic API Functions 
#define     sensor__set_ht_gyro(...)                       SetSensorHTGyro(__VA_ARGS__)
#define     sensor__set_ht_magnet(...)                     SetSensorHTMagnet(__VA_ARGS__)
#define     sensor__set_ht_eo_pd(...)                      SetSensorHTEOPD(__VA_ARGS__)
#define     sensor__set_ht_force(...)                      SetSensorHTForce(__VA_ARGS__)
#define     sensor__ht_gyro(...)                           SensorHTGyro(__VA_ARGS__)
#define     sensor__ht_magnet(...)                         SensorHTMagnet(__VA_ARGS__)
#define     sensor__ht_eo_pd(...)                          SensorHTEOPD(__VA_ARGS__)
#define     sensor__ht_force(...)                          SensorHTForce(__VA_ARGS__)
#define     sensor__ht_color_num(...)                      SensorHTColorNum(__VA_ARGS__)
#define     sensor__ht_compass(...)                        SensorHTCompass(__VA_ARGS__)
#define     sensor__ht_ir_seeker_dir(...)                  SensorHTIRSeekerDir(__VA_ARGS__)
#define     sensor__ht_ir_seeker_2_addr(...)               SensorHTIRSeeker2Addr(__VA_ARGS__)
#define     sensor__ht_ir_seeker_2_dcd_ir(...)             SensorHTIRSeeker2ACDir(__VA_ARGS__)
#define     sensor__set_ht_color_2_mode(...)               SetHTColor2Mode(__VA_ARGS__)
#define     sensor__set_ht_ir_seeker_2_mode(...)           SetHTIRSeeker2Mode(__VA_ARGS__)
#define     sensor__read_ht_accel(...)                     ReadSensorHTAceel(__VA_ARGS__)
#define     sensor__read_ht_color(...)                     ReadSensorHTColor(__VA_ARGS__)
#define     sensor__read_ht_ir_seeker(...)                 ReadSensorHTIRSeeker(__VA_ARGS__)
#define     sensor__read_ht_normalized_color(...)          ReadSensorHTNormalizedColor(__VA_ARGS__)
#define     sensor__read_ht_raw_color(...)                 ReadSensorHTRawColor(__VA_ARGS__)
#define     sensor__read_ht_color_2_active(...)            ReadSensorHTColor2Active(__VA_ARGS__)
#define     sensor__read_ht_normalized_color_2_active(...) ReadSensorHTNormalizedColor2Active(__VA_ARGS__)
#define     sensor__read_ht_raw_color_2(...)               ReadSensorHTRawColor2(__VA_ARGS__)
#define     sensor__read_ht_ir_receiver(...)               ReadSensorHTIRReceiver(__VA_ARGS__)
#define     sensor__read_ht_ir_receiver_ex(...)            ReadSensorHTIRReceiverEX(__VA_ARGS__)        
#define     sensor__read_ht_ir_seeker_2_ac(...)            ReadSensorHTIRSeeker2AC(__VA_ARGS__)
#define     sensor__read_ht_ir_seeker_2_dc(...)            ReadSensorHTIRSeeker2DC(__VA_ARGS__)
#define     sensor__reset_ht_angle(...)                    ResetSensorHTAngle(__VA_ARGS__)
#define     sensor__read_ht_angle(...)                     ReadSensorHTAngle(__VA_ARGS__)
#define     reset__ht_barometic_calibration(...)           ResetHTBarometicCalibration(__VA_ARGS__)
#define     set__ht_barometic_calibration(...)             SetHTBarometicCalibration(__VA_ARGS__)
#define     sensor__read_ht_barometric(...)                ReadSensorHTBarometric(__VA_ARGS__)
#define     sensor__ht_proto_analog(...)                   SensorHTProtoAnalog(__VA_ARGS__)   
#define     sensor__read_ht_proto_all_analog(...)          ReadSensorHTProtoAllAnalog(__VA_ARGS__)
#define     sensor__set_ht_proto_digital_control(...)      SetSensorHTProtoDigitalControl(__VA_ARGS__)
#define     sensor__ht_proto_digital_control(...)          SensorHTProtoDigitalControl(__VA_ARGS__)
#define     sensor__set_ht_proto_digital(...)              SetSensorHTEOProtoDigital(__VA_ARGS__)
#define     sensor__ht_proto_digital(...)                  SensorHTProtoDigital(__VA_ARGS__) 
#define     sensor__ht_super_pro_analog(...)               SensorHTSuperProAnalog(__VA_ARGS__)
#define     sensor__read_ht_super_pro_all_analog(...)      ReadSensorHTSuperProAllAnalog(__VA_ARGS__)
#define     sensor__set_ht_super_pro_digital_control(...)  SetSensorHTSuperProDigitalControl(__VA_ARGS__)
#define     sensor__ht_super_pro_digital_control(...)      SensorHTSuperProDIgitalControl(__VA_ARGS__)
#define     sensor__set_ht_super_pro_digital(...)          SetSensorHTSuperProDigital(__VA_ARGS__)
#define     sensor__ht_super_pro_digital(...)              SensorHTSuperProDigital(__VA_ARGS__)
#define     sensor__set_ht_super_pro_led(...)              SetSensorHTSuperProLed(__VA_ARGS__)
#define     sensor__ht_super_pro_led(...)                  SensorHTSuperProLed(__VA_ARGS__)
#define     sensor__set_ht_super_pro_strobe(...)           SetSensorHTSuperProStrobe(__VA_ARGS__)
#define     sensor__ht_super_pro_strobe(...)               SensorHTSuperProStrobe(__VA_ARGS__)
#define     sensor__set_ht_super_pro_program_control(...)  SetSensorHTSuperProProgramControl(__VA_ARGS__) 
#define     sensor__ht_super_pro_program_control(...)      SensorHTSuperProProgramControl(__VA_ARGS__)
#define     sensor__set_ht_super_pro_analog_out(...)       SetSensorHTSuperProAnalogOut(__VA_ARGS__)
#define     sensor__read_ht_super_pro_analog_out(...)      ReadSensorHTSuperProAnalogOut(__VA_ARGS__)
#define     sensor__set_ht_ir_deadband(...)                SetSensorHTPIRDeadband(__VA_ARGS__)
#define     sensor__ht_pir(...)                            SensorHTPIR(__VA_ARGS__)
#define     sensor__read_ht_touch_multiplexer(...)         ReadSensorHTTouchMultiplexer(__VA_ARGS__)
#define     ht__ir_train(...)                              HTIRTrain(__VA_ARGS__)
#define     ht__pf_combo_direct(...)                       HTPFComboDirect(__VA_ARGS__)
#define     ht__pf_combo_p_w_m(...)                        HTPFComboPWM(__VA_ARGS__)
#define     ht__pf_raw_output(...)                         HTPFRawnOutput(__VA_ARGS__)
#define     ht__pd_repeat(...)                             HTPFRepeat(__VA_ARGS__)
#define     ht__pf_single_output_c_s_t(...)                HTPFSingleOutputCST(__VA_ARGS__)
#define     ht__pf_single_output_p_w_m(...)                HTPFSingleOutputPWM(__VA_ARGS__)    
#define     ht__pf_single_pin(...)                         HTPFSinglePin(__VA_ARGS__)
#define     ht__pf_train(...)                              HTPFTrain(__VA_ARGS__)
#define     ht__rcx_setl_r_link_port(...)                  HTRCXSetlRLinkPort(__VA_ARGS__)
#define     ht__rcx_battery_level()                        HTRCXBatteryLevel()
#define     ht__rcx_poll(...)                              HTRCXPoll(__VA_ARGS__)
#define     ht__rcx_poll_memory(...)                       HTRCXPollMemory(__VA_ARGS__)
#define     ht__rcx_add_to_datalog(...)                    HTRCXAddToDatalog(__VA_ARGS__)
#define     ht__rcx_clear_all_events()                     HTRCXClearAllEvents()
#define     ht__rcx_clear_counter(...)                     HTRCXClearCounter(__VA_ARGS__)
#define     ht__rcx_clear_msg()                            HTRCXClearMsg()  
#define     ht__rcx_clear_sensor(...)                      HTRCXClearSensor(__VA_ARGS__)
#define     ht__rcx_clear_sound()                          HTRCXClearSound()            
#define     ht__rcx_clear_timer(...)                       HTRCXClearTimer(__VA_ARGS__)
#define     ht__rcx_create_datalog(...)                    HTRCXCreateDatalog(__VA_ARGS__)
#define     ht__rcx_dec_counter(...)                       HTRCXDecCounter(__VA_ARGS__)
#define     ht__rcx_delete_sub(...)                        HTRCXDeleteSub(__VA_ARGS__)
#define     ht__rcx_delete_subs()                          HTRCXDeleteSubs()
#define     ht__rcx_delete_task(...)                       HTRCXDeleteTask(__VA_ARGS__)
#define     ht__rcx_delete_tasks()                         HTRCXDeleteTasks()
#define     ht__rcx_disable_output(...)                    HTRCXDisableOutput(__VA_ARGS__)
#define     ht__rcx_enable_output(...)                     HTRCXEnableOutput(__VA_ARGS__)
#define     ht__rcx_event(...)                             HTRCXEvent(__VA_ARGS__)
#define     ht__rcx_float(...)                             HTRCXFloat(__VA_ARGS__)
#define     ht__rcx_fwd(...)                               HTRCXFwd(__VA_ARGS__)
#define     ht__rcx_inc_counter(...)                       HTRCXIncCounter(__VA_ARGS__)
#define     ht__rcx_invert_output(...)                     HTRCXInvertOutput(__VA_ARGS__)
#define     ht__rcx_mute_sound()                           HTRCXMuteSound()
#define     ht__rcx_obvert_output(...)                     HTRCXObvertOutput(__VA_ARGS__)
#define     ht__rcx_off(...)                               HTRCXOff(__VA_ARGS__)
#define     ht__rcx_on(...)                                HTRCXOn(__VA_ARGS__)
#define     ht__rcx_on_for(...)                            HTRCXOnFor(__VA_ARGS__)
#define     ht__rcx_on_fwd(...)                            HTRCXOnFwd(__VA_ARGS__)
#define     ht__rcx_on_rev(...)                            HTRCXOnRev(__VA_ARGS__)
#define     ht__rcx_pb_turn_off()                          HTRCXPBTurnOff()
#define     ht__rcx_ping()                                 HTRCXPing()
#define     ht__rcx_play_sound(...)                        HTRCXPlaySound(__VA_ARGS__)
#define     ht__rcx_play_tone(...)                         HTRCXPlayTone(__VA_ARGS__)
#define     ht__rcx_play_tone_var(...)                     HTRCXPlayToneVar(__VA_ARGS__)
#define     ht__rcx_remote(...)                            HTRCXRemote(__VA_ARGS__)
#define     ht__rcx_rev(...)                               HTRCXRev(__VA_ARGS__)
#define     ht__rcx_select_display(...)                    HTRCXSelectDisplay(__VA_ARGS__)
#define     ht__rcx_select_program(...)                    HTRCXSelectProgram(__VA_ARGS__)
#define     ht__rcx_send_serial(...)                       HTRCXSendSerial(__VA_ARGS__)
#define     ht__rcx_set_direction(...)                     HTRCXSetDirection(__VA_ARGS__)
#define     ht__rcx_set_event(...)                         HTRCXSetEvent(__VA_ARGS__)
#define     ht__rcx_set_global_direction(...)              HTRCXSetGlobalDirection(__VA_ARGS__)
#define     ht__rcx_set_global_output(...)                 HTRCXSetGlobalOutput(__VA_ARGS__)
#define     ht__rcx_set_max_power(...)                     HTRCXSetMaxPower(__VA_ARGS__)
#define     ht__rcx_set_message(...)                       HTRCXSetMessage(__VA_ARGS__)
#define     ht__rcx_set_output(...)                        HTRCXSetOutput(__VA_ARGS__)
#define     ht__rcx_set_power(...)                         HTRCXSetPower(__VA_ARGS__)
#define     ht__rcx_set_priority(...)                      HTRCXSetPriority(__VA_ARGS__)
#define     ht__rcx_set_sensor_mode(...)                   HTRCXSetSensorMode(__VA_ARGS__)
#define     ht__rcx_set_sensor_type(...)                   HTRCXSetSensorType(__VA_ARGS__)
#define     ht__rcx_set_sleep_time(...)                    HTRCXSetSleepTime(__VA_ARGS__)
#define     ht__rcx_set_tx_power(...)                      HTRCXSetTxPower(__VA_ARGS__)
#define     ht__rcx_set_watch(...)                         HTRCXSetWatch(__VA_ARGS__)
#define     ht__rcx_start_task(...)                        HTRCXStartTask(__VA_ARGS__)
#define     ht__rcx_stop_all_taks()                        HTRCXStopAllTasks()
#define     ht__rcx_stop_task(...)                         HTRCXStopTask(__VA_ARGS__)
#define     ht__rcx_toggle(..)                             HTRCXToggle(__VA_ARGS__)
#define     ht__rcx_unmute_sound()                         HTRCXUnmuteSound()
#define     ht__scout_calibrate_sensor()                   HTScoutCalibrateSensor()
#define     ht__scout_mute_sound()                         HTScoutMuteSound()
#define     ht__scout_select_sounds(...)                   HTScoutSelectSounds(__VA_ARGS__)                         
#define     ht__scout_send_V_L_L(...)                      HTScoutSendVLL(__VA_ARGS__)
#define     ht__scout_set_event_feed_back(...)             HTScoutSetEventFeedback(__VA_ARGS__)
#define     ht__scout_set_light(...)                       HTScoutSetLight(__VA_ARGS__)
#define     ht__scout_set_scout_mode(...)                  HTScoutSetScoutMode(__VA_ARGS__)
#define     ht__scout_set_sensor_click_time(...)           HTScoutSetSensorClickTime(__VA_ARGS__)
#define     ht__scout_set_sensor_hysteresis(...)           HTScoutSetSensorHysteresis(__VA_ARGS__)
#define     ht__scout_set_sensor_lower_limit(...)          HTScourSetSensorLowerLimit(__VA_ARGS__)
#define     ht__scout_set_sensor_upper_limit(...)          HTScourSetSensorUpperLimit(__VA_ARGS__)
#define     ht__scout_unmute_sound()                       HTScourUnmuteSound()


