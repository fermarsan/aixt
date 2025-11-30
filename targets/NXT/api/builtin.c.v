module main

pub type Mutex = int

// #################### NXC Command module ####################


// Constant offsets into the Command module IOMAP structure. 
// #define 	offset_format_string  	CommandOffsetFormatString   
// #define 	offset_prc_handler    	CommandOffsetPRCHandler     
// #define 	offset_tick          	CommandOffsetTick           
// #define 	offset_offset_ds      	CommandOffsetOffsetDS       
// #define 	offset_offset_dva     	CommandOffsetOffsetDVA      
// #define 	offset_prog_status    	CommandOffsetProgStatus     
// #define 	offset_awake         	CommandOffsetAwake          
// #define 	offset_activate_flag  	CommandOffsetActivateFlag   
// #define 	offset_deactivate_flag	CommandOffsetDeactivateFlag 
// #define 	offset_file_name      	CommandOffsetFileName       
// #define 	offset_memory_pool    	CommandOffsetMemoryPool     
// #define 	offset_sync_time      	CommandOffsetSyncTime       
// #define 	offset_sync_tick      	CommandOffsetSyncTick          

// Constants defining communication error conditions. 
// #define 	err_comm_chan_not_ready	ERR_COMM_CHAN_NOT_READY   
// #define 	err_comm_chan_invalid  	ERR_COMM_CHAN_INVALID     
// #define 	err_comm_buffer_full   	ERR_COMM_BUFFER_FULL      
// #define 	err_comm_bus_err       	ERR_COMM_BUS_ERR         

// Constants defining various fatal error conditions. 
// #define 	err_arg            		ERR_ARG                
// #define 	err_instr          		ERR_INSTR              
// #define 	err_file           		ERR_FILE               
// #define 	err_ver            		ERR_VER                
// #define 	err_mem            		ERR_MEM                
// #define 	err_bad_ptr        		ERR_BAD_PTR            
// #define 	err_clump_count    		ERR_CLUMP_COUNT        
// #define 	err_no_code        		ERR_NO_CODE                 
// #define 	err_insane_offset  		ERR_INSANE_OFFSET      
// #define 	err_bad_pool_size  		ERR_BAD_POOL_SIZE      
// #define 	err_loader_err     		ERR_LOADER_ERR         
// #define 	err_spotcheck_fail 		ERR_SPOTCHECK_FAIL     
// #define 	err_no_active_clump		ERR_NO_ACTIVE_CLUMP    
// #define 	err_default_offsets		ERR_DEFAULT_OFFSETS    
// #define 	err_memmgr_fail    		ERR_MEMMGR_FAIL        
// #define 	err_non_fatal      		ERR_NON_FATAL          

// Constants defining general error conditions. 
// #define 	err_invalid_port 	ERR_INVALID_PORT 
// #define 	err_invalid_field	ERR_INVALID_FIELD
// #define 	err_invalid_queue	ERR_INVALID_QUEUE
// #define 	err_invalid_size 	ERR_INVALID_SIZE 
// #define 	err_no_prog      	ERR_NO_PROG      

// Constants defining various states of the command module virtual machine. 
// #define 	prog_idle   	PROG_IDLE   
// #define 	prog_ok     	PROG_OK     
// #define 	prog_running	PROG_RUNNING
// #define 	prog_error  	PROG_ERROR  
// #define 	prog_abort  	PROG_ABORT  
// #define 	prog_reset  	PROG_RESET  

// Constants defining errors that can occur during remote control 
// #define 	err_rc_illegal_val	ERR_RC_ILLEGAL_VAL
// #define 	err_rc_bad_packet 	ERR_RC_BAD_PACKET 
// #define 	err_rc_unknown_cmd	ERR_RC_UNKNOWN_CMD
// #define 	err_rc_failed     	ERR_RC_FAILED     

// Constants for use in the sys_call
// #define 	file_open_read          	FileOpenRead                                   
// #define 	file_open_write         	FileOpenWrite                                   
// #define 	file_open_append        	FileOpenAppend                                   
// #define 	file_read              		FileRead                                   
// #define 	file_write             		FileWrite                                   
// #define 	file_close             		FileClose                                   
// #define 	file_resolve_handle     	FileResolveHandle                                   
// #define 	file_rename            		FileRename                                   
// #define 	file_delete            		FileDelete                                   
// #define 	sound_play_file         	SoundPlayFile                                   
// #define 	sound_play_tone         	SoundPlayTone                                   
// #define 	sound_get_state         	SoundGetState                                   
// #define 	sound_set_state         	SoundSetState                                   
// #define 	draw_text              		DrawText                                   
// #define 	draw_point             		DrawPoint                                   
// #define 	draw_line              		DrawLine                                   
// #define 	draw_circle            		DrawCircle                                   
// #define 	draw_rect              		DrawRect                                   
// #define 	draw_graphic           		DrawGraphic                                   
// #define 	set_screen_mode         	SetScreenMode                                   
// #define 	read_button            		ReadButton                                   
// #define 	comm_ls_write           	CommLSWrite                                   
// #define 	comm_ls_read            	CommLSRead                                   
// #define 	comm_ls_check_status     	CommLSCheckStatus                                   
// #define 	random_number          		RandomNumber                                   
// #define 	get_start_tick          	GetStartTick                                   
// #define 	message_write          		MessageWrite                                   
// #define 	message_read           		MessageRead                                   
// #define 	comm_bt_check_status     	CommBTCheckStatus                                   
// #define 	comm_bt_write           	CommBTWrite                                   
// #define 	comm_bt_read            	CommBTRead                                   
// #define 	keep_alive             		KeepAlive                                   
// #define 	io_map_read             	IOMapRead                                   
// #define 	io_map_write            	IOMapWrite                                   
// #define 	color_sensor_read       	ColorSensorRead                                   
// #define 	comm_bt_on_off           	CommBTOnOff                                   
// #define 	comm_bt_connection      	CommBTConnection                                   
// #define 	comm_hs_write           	CommHSWrite                                   
// #define 	comm_hs_read            	CommHSRead                                   
// #define 	comm_hs_check_status     	CommHSCheckStatus                                   
// #define 	read_sem_data           	ReadSemData                                   
// #define 	write_sem_data          	WriteSemData                                   
// #define 	compute_calib_value     	ComputeCalibValue                                   
// #define 	update_calib_cache_info  	UpdateCalibCacheInfo                                   
// #define 	datalog_write          		DatalogWrite                                   
// #define 	datalog_get_times       	DatalogGetTimes                                   
// #define 	set_sleep_timeout_val    	SetSleepTimeoutVal                                   
// #define 	list_files             		ListFiles                                   
// #define 	input_pin_function      	InputPinFunction                                   
// #define 	io_map_read_by_id         	IOMapReadByID                                   
// #define 	io_map_write_by_id        	IOMapWriteByID                                   
// #define 	display_execute_function	DisplayExecuteFunction                                   
// #define 	comm_execute_function   	CommExecuteFunction                                   
// #define 	loader_execute_function 	LoaderExecuteFunction                                   
// #define 	file_find_first         	FileFindFirst                                   
// #define 	file_find_next          	FileFindNext                                   
// #define 	file_open_write_linear   	FileOpenWriteLinear                                   
// #define 	file_open_write_non_linear	FileOpenWriteNonLinear                                   
// #define 	file_open_read_linear    	FileOpenReadLinear                                   
// #define 	comm_hs_control         	CommHSControl                                   
// #define 	comm_ls_write_ex         	CommLSWriteEx                                   
// #define 	file_seek              		FileSeek                                   
// #define 	file_resize            		FileResize                                   
// #define 	draw_graphic_array      	DrawGraphicArray                                   
// #define 	draw_polygon           		DrawPolygon                                   
// #define 	draw_ellipse           		DrawEllipse                                   
// #define 	draw_font              		DrawFont                                   
// #define 	memory_manager         		MemoryManager                                   
// #define 	read_last_response      	ReadLastResponse                                   
// #define 	file_tell            	  	FileTell                                   
// #define 	random_ex              		RandomEx          

// Constants for use with the sleep
// #define 	ms_1  			MS_1                                      
// #define 	ms_2  			MS_2   
// #define 	ms_3  			MS_3   
// #define 	ms_4  			MS_4   
// #define 	ms_5  			MS_5   
// #define 	ms_6  			MS_6   
// #define 	ms_7  			MS_7   
// #define 	ms_8  			MS_8   
// #define 	ms_9  			MS_9   
// #define 	ms_10 			MS_10  
// #define 	ms_20 			MS_20  
// #define 	ms_30 			MS_30  
// #define 	ms_40 			MS_40  
// #define 	ms_50 			MS_50  
// #define 	ms_60 			MS_60  
// #define 	ms_70 			MS_70  
// #define 	ms_80 			MS_80  
// #define 	ms_90 			MS_90  
// #define 	ms_100			MS_100 
// #define 	ms_150			MS_150 
// #define 	ms_200			MS_200 
// #define 	ms_250			MS_250 
// #define 	ms_300			MS_300 
// #define 	ms_350			MS_350 
// #define 	ms_400			MS_400 
// #define 	ms_450			MS_450 
// #define 	ms_500			MS_500 
// #define 	ms_600			MS_600 
// #define 	ms_700			MS_700 
// #define 	ms_800			MS_800 
// #define 	ms_900			MS_900 
// #define 	sec_1 			SEC_1  
// #define 	sec_2 			SEC_2  
// #define 	sec_3 			SEC_3  
// #define 	sec_4 			SEC_4  
// #define 	sec_5 			SEC_5  
// #define 	sec_6 			SEC_6  
// #define 	sec_7 			SEC_7  
// #define 	sec_8 			SEC_8  
// #define 	sec_9 			SEC_9  
// #define 	sec_10			SEC_10 
// #define 	sec_15			SEC_15 
// #define 	sec_20			SEC_20 
// #define 	sec_30			SEC_30 
// #define 	min_1 			MIN_1  

// #define 	note_whole  	NOTE_WHOLE  
// #define 	note_half   	NOTE_HALF      
// #define 	note_quarter	NOTE_QUARTER   
// #define 	note_eight  	NOTE_EIGHT     
// #define 	note_sixteen	NOTE_SIXTEEN   

// Constants defining possible VM states. 
// #define 	times_up     	TIMES_UP       
// #define 	rotate_queue 	ROTATE_QUEUE   
// #define 	stop_req     	STOP_REQ       
// #define 	breakout_req 	BREAKOUT_REQ   
// #define 	clump_suspend	CLUMP_SUSPEND  
// #define 	clump_done   	CLUMP_DONE     

// Constants that are part of the NXT firmware's Command module
// #define 	stat_msg_empty_mailbox	STAT_MSG_EMPTY_MAILBOX
// #define 	stat_comm_pending     	STAT_COMM_PENDING     
// #define 	pool_max_size         	POOL_MAX_SIZE         
// #define 	no_err                	NO_ERR      

// Logical comparison operators for use in BranchTest and BranchComp
// #define 	lt   	LT   	
// #define 	gt   	GT   	
// #define 	lteq   	LTEQ   	
// #define 	gteq   	GTEQ   	
// #define 	eq   	EQ   	
// #define 	neq   	NEQ   	


// Functions for accessing and modifying Command module features. 
// @[inline] current_tick() { return C.CurrentTick() } 
// @[inline] first_tick() { return C.FirstTick() } 
// @[inline] reset_sleep_timer() { C.ResetSleepTimer() } 
// @[inline] sys_call() { return C.SysCall() } 
// @[inline] sys_get_start_tick() { return C.SysGetStartTick() } 
// @[inline] sys_keep_alive() { return C.SysKeepAlive() } 
// @[inline] sys_io_map_read() { return C.SysIOMapRead() } 
// @[inline] sys_io_map_write() { return C.SysIOMapWrite() } 
// @[inline] sys_io_map_read_by_id() { return C.SysIOMapReadByID() } 
// @[inline] sys_io_map_write_by_id() { return C.SysIOMapWriteByID() } 
// @[inline] sys_datalog_write() { return C.SysDatalogWrite() } 
// @[inline] sys_datalog_get_times() { return C.SysDatalogGetTimes() } 
// @[inline] sys_read_sem_data() { return C.SysReadSemData() } 
// @[inline] sys_write_sem_data() { return C.SysWriteSemData() } 
// @[inline] sys_update_calib_cache_info() { return C.SysUpdateCalibCacheInfo() } 
// @[inline] sys_compute_calib_value() { return C.SysComputeCalibValue() } 
// @[inline] get_memory_info() { return C.GetMemoryInfo() } 
// @[inline] sys_memory_manager() { return C.SysMemoryManager() } 
// @[inline] get_last_response_info() { return C.GetLastResponseInfo() } 
// @[inline] sys_read_last_response() { return C.SysReadLastResponse() } 
// @[inline] sleep_ms(ms u32) { C.Wait(ms) }					//custom 
// @[inline] yield() { C.Yield() } 
// @[inline] stop_all_tasks() { C.StopAllTasks() } 
// @[inline] stop_program(val bool) { C.Stop(val) } 
// @[inline] exit_to(new_task fn) { C.ExitTo(new_task) } 
// @[inline] precedes() { return C.Precedes() } 
// @[inline] follows() { return C.Follows() } 
// @[inline] acquire() { return C.Acquire() } 
// @[inline] release() { return C.Release() } 
// @[inline] start_task() { return C.StartTask() } 
// @[inline] stop_task() { return C.StopTask() } 
// @[inline] branch_test() { return C.BranchTest() } 
// @[inline] branch_comp() { return C.BranchComp() } 
// @[inline] set_io_map_bytes() { return C.SetIOMapBytes() } 
// @[inline] set_io_map_value() { return C.SetIOMapValue() } 
// @[inline] get_io_map_bytes() { return C.GetIOMapBytes() } 
// @[inline] get_io_map_value() { return C.GetIOMapValue() } 
// @[inline] get_low_speed_module_bytes() { return C.GetLowSpeedModuleBytes() } 
// @[inline] get_display_module_bytes() { return C.GetDisplayModuleBytes() } 
// @[inline] get_comm_module_bytes() { return C.GetCommModuleBytes() } 
// @[inline] get_command_module_bytes() { return C.GetCommandModuleBytes() } 
// @[inline] set_command_module_bytes() { return C.SetCommandModuleBytes() } 
// @[inline] set_low_speed_module_bytes() { return C.SetLowSpeedModuleBytes() } 
// @[inline] set_display_module_bytes() { return C.SetDisplayModuleBytes() } 
// @[inline] set_comm_module_bytes() { return C.SetCommModuleBytes() } 
// @[inline] set_sound_module_bytes() { return C.SetSoundModuleBytes() } 
// @[inline] set_io_map_bytes_by_id() { return C.SetIOMapBytesByID() } 
// @[inline] set_io_map_value_by_id() { return C.SetIOMapValueByID() } 
// @[inline] get_io_map_bytes_by_id() { return C.GetIOMapBytesByID() } 
// @[inline] get_io_map_value_by_id() { return C.GetIOMapValueByID() } 
// @[inline] set_command_module_value() { return C.SetCommandModuleValue() } 
// @[inline] set_io_ctrl_module_value() { return C.SetIOCtrlModuleValue() } 
// @[inline] set_loader_module_value() { return C.SetLoaderModuleValue() } 
// @[inline] set_ui_module_value() { return C.SetUIModuleValue() } 
// @[inline] set_sound_module_value() { return C.SetSoundModuleValue() } 
// @[inline] set_button_module_value() { return C.SetButtonModuleValue() } 
// @[inline] set_input_module_value() { return C.SetInputModuleValue() } 
// @[inline] set_output_module_value() { return C.SetOutputModuleValue() } 
// @[inline] set_low_speed_module_value() { return C.SetLowSpeedModuleValue() } 
// @[inline] set_display_module_value() { return C.SetDisplayModuleValue() } 
// @[inline] set_comm_module_value() { return C.SetCommModuleValue() } 
// @[inline] get_command_module_value() { return C.GetCommandModuleValue() } 
// @[inline] get_loader_module_value() { return C.GetLoaderModuleValue() } 
// @[inline] get_sound_module_value() { return C.GetSoundModuleValue() } 
// @[inline] get_button_module_value() { return C.GetButtonModuleValue() } 
// @[inline] get_ui_module_value() { return C.GetUIModuleValue() } 
// @[inline] get_input_module_value() { return C.GetInputModuleValue() } 
// @[inline] get_output_module_value() { return C.GetOutputModuleValue() } 
// @[inline] get_low_speed_module_value() { return C.GetLowSpeedModuleValue() } 
// @[inline] get_display_module_value() { return C.GetDisplayModuleValue() } 
// @[inline] get_comm_module_value() { return C.GetCommModuleValue() }

// @[inline] sleep(ts) { C.Wait(ts*1000) }		//custom

// cstdlib.c
// @[inline] abort() { return C.abort() }
// @[inline] atoi() { return C.atoi() }
// @[inline] atol() { return C.atol() }
// @[inline] atof() { return C.atof() }
// @[inline] strtod() { return C.strtod() }
// @[inline] strtol() { return C.strtol() }
// @[inline] strtoul() { return C.strtoul() }


// #################### NXC IOCtrl module ####################

// Constant offsets into the IOCtrl module IOMAP structure. 
// #define 	io_ctrl_offset_power_on		IOCtrlOffsetPowerOn

// Use these constants to power down the NXT or boot it into SAMBA (aka firmware download) mode. 
// #define 	io_ctrl_powerdown	IOCTRL_POWERDOWN       
// #define 	io_ctrl_boot     	IOCTRL_BOOT      

// Functions for accessing and modifying IOCtrl module features. 
// @[inline] power_down() { return C.PowerDown() }
// @[inline] sleep_now() { return C.SleepNow() }
// @[inline] reboot_in_firmware_mode() { return C.RebootInFirmwareMode() }
