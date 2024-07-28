module comm

// // Constants related to the bluetooth state. 
// #define 	bt_arm_off      	BT_ARM_OFF      
// #define 	bt_arm_cmd_mode 	BT_ARM_CMD_MODE  
// #define 	bt_arm_data_mode	BT_ARM_DATA_MODE  

// // Constants related to the bluetooth hardware status. 
// #define 	bt_enable 		BT_ENABLE   
// #define 	bt_disable		BT_DISABLE  

// // Constants related to the bluetooth state status. 
// #define 	bt_brick_visibility   	BT_BRICK_VISIBILITY     
// #define 	bt_brick_port_open    	BT_BRICK_PORT_OPEN     
// #define 	bt_connection_0_enable	BT_CONNECTION_0_ENABLE     
// #define 	bt_connection_1_enable	BT_CONNECTION_1_ENABLE     
// #define 	bt_connection_2_enable	BT_CONNECTION_2_ENABLE     
// #define 	bt_connection_3_enable	BT_CONNECTION_3_ENABLE    

// // Constant offsets into the Comm module IOMAP structure. 
// #define 	offset_p_func                            CommOffsetPFunc                      
// #define 	offset_p_func_two                        CommOffsetPFuncTwo                   
// #define 	offset_bt_device_table_name              CommOffsetBtDeviceTableName          
// #define 	offset_bt_device_table_class_of_device   CommOffsetBtDeviceTableClassOfDevice 
// #define 	offset_bt_device_table_bd_addr           CommOffsetBtDeviceTableBdAddr        
// #define 	offset_bt_device_table_device_status     CommOffsetBtDeviceTableDeviceStatus  
// #define 	offset_bt_connect_table_name             CommOffsetBtConnectTableName         
// #define 	offset_bt_connect_table_class_of_device  CommOffsetBtConnectTableClassOfDevice
// #define 	offset_bt_connect_table_pin_code         CommOffsetBtConnectTablePinCode      
// #define 	offset_bt_connect_table_bd_addr          CommOffsetBtConnectTableBdAddr       
// #define 	offset_bt_connect_table_handle_nr        CommOffsetBtConnectTableHandleNr     
// #define 	offset_bt_connect_table_stream_status    CommOffsetBtConnectTableStreamStatus 
// #define 	offset_bt_connect_table_link_quality     CommOffsetBtConnectTableLinkQuality  
// #define 	offset_brick_data_name                   CommOffsetBrickDataName              
// #define 	offset_brick_data_bluecore_version       CommOffsetBrickDataBluecoreVersion   
// #define 	offset_brick_data_bd_addr                CommOffsetBrickDataBdAddr            
// #define 	offset_brick_data_bt_state_status        CommOffsetBrickDataBtStateStatus     
// #define 	offset_brick_data_bt_hw_status           CommOffsetBrickDataBtHwStatus        
// #define 	offset_brick_data_time_out_value         CommOffsetBrickDataTimeOutValue      
// #define 	offset_bt_in_buf_buf                     CommOffsetBtInBufBuf                 
// #define 	offset_bt_in_buf_in_ptr                  CommOffsetBtInBufInPtr               
// #define 	offset_bt_in_buf_out_ptr                 CommOffsetBtInBufOutPtr              
// #define 	offset_bt_out_buf_buf                    CommOffsetBtOutBufBuf                
// #define 	offset_bt_out_buf_in_ptr                 CommOffsetBtOutBufInPtr              
// #define 	offset_bt_out_buf_out_ptr                CommOffsetBtOutBufOutPtr             
// #define 	offset_hs_in_buf_buf                     CommOffsetHsInBufBuf                 
// #define 	offset_hs_in_buf_in_ptr                  CommOffsetHsInBufInPtr               
// #define 	offset_hs_in_buf_out_ptr                 CommOffsetHsInBufOutPtr              
// #define 	offset_hs_out_buf_buf                    CommOffsetHsOutBufBuf                
// #define 	offset_hs_out_buf_in_ptr                 CommOffsetHsOutBufInPtr              
// #define 	offset_hs_out_buf_out_ptr                CommOffsetHsOutBufOutPtr             
// #define 	offset_usb_in_buf_buf                    CommOffsetUsbInBufBuf                
// #define 	offset_usb_in_buf_in_ptr                 CommOffsetUsbInBufInPtr              
// #define 	offset_usb_in_buf_out_ptr                CommOffsetUsbInBufOutPtr             
// #define 	offset_usb_out_buf_buf                   CommOffsetUsbOutBufBuf               
// #define 	offset_usb_out_buf_in_ptr                CommOffsetUsbOutBufInPtr             
// #define 	offset_usb_out_buf_out_ptr               CommOffsetUsbOutBufOutPtr            
// #define 	offset_usb_poll_buf_buf                  CommOffsetUsbPollBufBuf              
// #define 	offset_usb_poll_buf_in_ptr               CommOffsetUsbPollBufInPtr            
// #define 	offset_usb_poll_buf_out_ptr              CommOffsetUsbPollBufOutPtr           
// #define 	offset_bt_device_cnt                     CommOffsetBtDeviceCnt                
// #define 	offset_bt_device_name_cnt                CommOffsetBtDeviceNameCnt            
// #define 	offset_hs_flags                          CommOffsetHsFlags                    
// #define 	offset_hs_speed                          CommOffsetHsSpeed                    
// #define 	offset_hs_state                          CommOffsetHsState                    
// #define 	offset_usb_state                         CommOffsetUsbState                   
// #define 	offset_hs_address                        CommOffsetHsAddress                  
// #define 	offset_hs_mode                           CommOffsetHsMode                     
// #define 	offset_bt_data_mode                      CommOffsetBtDataMode                 
// #define 	offset_hs_data_mode                      CommOffsetHsDataMode                  

// // Constants for all the Comm module interface functions executable via SysCommExecuteFunction. 
// #define 	intf_sendfile     	INTF_SENDFILE     
// #define 	intf_search       	INTF_SEARCH       
// #define 	intf_stopsearch   	INTF_STOPSEARCH   
// #define 	intf_connect      	INTF_CONNECT      
// #define 	intf_disconnect   	INTF_DISCONNECT   
// #define 	intf_disconnectall	INTF_DISCONNECTALL
// #define 	intf_removedevice 	INTF_REMOVEDEVICE 
// #define 	intf_visibility   	INTF_VISIBILITY   
// #define 	intf_setcmdmode   	INTF_SETCMDMODE   
// #define 	intf_openstream   	INTF_OPENSTREAM   
// #define 	intf_senddata     	INTF_SENDDATA     
// #define 	intf_factoryreset 	INTF_FACTORYRESET 
// #define 	intf_bton         	INTF_BTON         
// #define 	intf_btoff        	INTF_BTOFF        
// #define 	intf_setbtname    	INTF_SETBTNAME    
// #define 	intf_extread      	INTF_EXTREAD      
// #define 	intf_pinreq       	INTF_PINREQ       
// #define 	intf_connectreq   	INTF_CONNECTREQ   
// #define 	intf_connectbyname	INTF_CONNECTBYNAME

// // Constants for Comm module status codes. 
// #define 	lr_success       		LR_SUCCESS       
// #define 	lr_could_not_save		LR_COULD_NOT_SAVE
// #define 	lr_store_is_full 		LR_STORE_IS_FULL 
// #define 	lr_entry_removed 		LR_ENTRY_REMOVED 
// #define 	lr_unknown_addr  		LR_UNKNOWN_ADDR  
// #define 	usb_cmd_ready    		USB_CMD_READY    
// #define 	bt_cmd_ready     		BT_CMD_READY     
// #define 	hs_cmd_ready     		HS_CMD_READY     

// // Constants related to the bluetooth and hi-speed data modes. 
// #define 	data_mode_nxt   	DATA_MODE_NXT   
// #define 	data_mode_gps   	DATA_MODE_GPS   
// #define 	data_mode_raw   	DATA_MODE_RAW   
// #define 	data_mode_mask  	DATA_MODE_MASK  
// #define 	data_mode_update	DATA_MODE_UPDATE

// // Constants refering to DeviceStatus within DeviceTable. 
// #define 	bt_device_empty  	BT_DEVICE_EMPTY  
// #define 	bt_device_unknown	BT_DEVICE_UNKNOWN
// #define 	bt_device_known  	BT_DEVICE_KNOWN  
// #define 	bt_device_name   	BT_DEVICE_NAME   
// #define 	bt_device_away   	BT_DEVICE_AWAY   

// // Constants for use with the SysCommHSControl API function. 
// #define 	hs_ctrl_init		HS_CTRL_INIT
// #define 	hs_ctrl_uart		HS_CTRL_UART
// #define 	hs_ctrl_exit		HS_CTRL_EXIT

// // Constants that combine data bits, parity, and stop bits into a single value. 
// #define 	hs_mode_8n1			HS_MODE_8N1
// #define 	hs_mode_7e1			HS_MODE_7E1

// // Constants referring to HsMode (number of data bits) 
// #define 	hs_mode_5_data		HS_MODE_5_DATA
// #define 	hs_mode_6_data		HS_MODE_6_DATA
// #define 	hs_mode_7_data		HS_MODE_7_DATA
// #define 	hs_mode_8_data		HS_MODE_8_DATA

// // Constants referring to HsMode (parity) 
// #define 	hs_mode_e_parity	HS_MODE_E_PARITY    
// #define 	hs_mode_o_parity	HS_MODE_O_PARITY    
// #define 	hs_mode_s_parity	HS_MODE_S_PARITY    
// #define 	hs_mode_m_parity	HS_MODE_M_PARITY    
// #define 	hs_mode_n_parity	HS_MODE_N_PARITY   

// // Constants referring to HsMode (number of stop bits) 
// #define 	hs_mode_10_stop		HS_MODE_10_STOP    
// #define 	hs_mode_15_stop		HS_MODE_15_STOP    
// #define 	hs_mode_20_stop		HS_MODE_20_STOP   

// // Constants referring to HsMode UART configuration settings. 
// #define 	hs_mode_uart_rs485	HS_MODE_UART_RS485    
// #define 	hs_mode_uart_rs232	HS_MODE_UART_RS232    
// #define 	hs_mode_mask      	HS_MODE_MASK      
// #define 	hs_uart_mask      	HS_UART_MASK      
// #define 	hs_mode_default   	HS_MODE_DEFAULT   

// // Constants for reading joystick information. 
// #define 	joy_btn_01			JOY_BTN_01 
// #define 	joy_btn_02			JOY_BTN_02 
// #define 	joy_btn_03			JOY_BTN_03 
// #define 	joy_btn_04			JOY_BTN_04 
// #define 	joy_btn_05			JOY_BTN_05 
// #define 	joy_btn_06			JOY_BTN_06 
// #define 	joy_btn_07			JOY_BTN_07 
// #define 	joy_btn_08			JOY_BTN_08 
// #define 	joy_btn_09			JOY_BTN_09 
// #define 	joy_btn_10			JOY_BTN_10 
// #define 	joy_btn_11			JOY_BTN_11 
// #define 	joy_btn_12			JOY_BTN_12 
// #define 	joy_btn_13			JOY_BTN_13 
// #define 	joy_btn_14			JOY_BTN_14 
// #define 	joy_btn_15			JOY_BTN_15 
// #define 	joy_btn_16			JOY_BTN_16 
// #define 	joy_btn_17			JOY_BTN_17 
// #define 	joy_btn_18			JOY_BTN_18 
// #define 	joy_btn_19			JOY_BTN_19 
// #define 	joy_btn_20			JOY_BTN_20 
// #define 	joy_btn_21			JOY_BTN_21 
// #define 	joy_btn_22			JOY_BTN_22 
// #define 	joy_btn_23			JOY_BTN_23 
// #define 	joy_btn_24			JOY_BTN_24 
// #define 	joy_btn_25			JOY_BTN_25 
// #define 	joy_btn_26			JOY_BTN_26 
// #define 	joy_btn_27			JOY_BTN_27 
// #define 	joy_btn_28			JOY_BTN_28 
// #define 	joy_btn_29			JOY_BTN_29 
// #define 	joy_btn_30			JOY_BTN_30 
// #define 	joy_btn_31			JOY_BTN_31 
// #define 	joy_btn_32			JOY_BTN_32 
// #define 	joy_pov_forward		JOY_POV_FORWARD 
// #define 	joy_pov_topright	JOY_POV_TOPRIGHT 
// #define 	joy_pov_right		JOY_POV_RIGHT 
// #define 	joy_pov_botright	JOY_POV_BOTRIGHT 
// #define 	joy_pov_backward	JOY_POV_BACKWARD 
// #define 	joy_pov_botleft		JOY_POV_BOTLEFT 
// #define 	joy_pov_left		JOY_POV_LEFT 
// #define 	joy_pov_topleft		JOY_POV_TOPLEFT 
// #define 	joy_pov_centered	JOY_POV_CENTERED

// // Mailbox number constants should be used to avoid confusing NXT-G users. 
// #define 	mailbox1 		MAILBOX1 
// #define 	mailbox2 		MAILBOX2 
// #define 	mailbox3 		MAILBOX3 
// #define 	mailbox4 		MAILBOX4 
// #define 	mailbox5 		MAILBOX5 
// #define 	mailbox6 		MAILBOX6 
// #define 	mailbox7 		MAILBOX7 
// #define 	mailbox8 		MAILBOX8 
// #define 	mailbox9 		MAILBOX9 
// #define 	mailbox10		MAILBOX10

// // Miscellaneous constants related to the Comm module. 
// #define 	size_of_usbbuf               	SIZE_OF_USBBUF                   
// #define 	usb_protocol_overhead        	USB_PROTOCOL_OVERHEAD                   
// #define 	size_of_usbdata              	SIZE_OF_USBDATA                   
// #define 	size_of_hsbuf                	SIZE_OF_HSBUF                   
// #define 	size_of_btbuf                	SIZE_OF_BTBUF                   
// #define 	bt_cmd_byte                  	BT_CMD_BYTE                   
// #define 	size_of_bt_device_table      	SIZE_OF_BT_DEVICE_TABLE                   
// #define 	size_of_bt_connect_table     	SIZE_OF_BT_CONNECT_TABLE                   
// #define 	size_of_bt_name              	SIZE_OF_BT_NAME                   
// #define 	size_of_brick_name           	SIZE_OF_BRICK_NAME                   
// #define 	size_of_class_of_device      	SIZE_OF_CLASS_OF_DEVICE                   
// #define 	size_of_bt_pincode           	SIZE_OF_BT_PINCODE                   
// #define 	size_of_bdaddr               	SIZE_OF_BDADDR                   
// #define 	max_bt_msg_size              	MAX_BT_MSG_SIZE                   
// #define 	bt_default_inquiry_max       	BT_DEFAULT_INQUIRY_MAX                   
// #define 	bt_default_inquiry_timeout_lo	BT_DEFAULT_INQUIRY_TIMEOUT_LO                  

// // Constants for specifying remote connection slots. 
// #define 	conn_bt0		CONN_BT0    
// #define 	conn_bt1		CONN_BT1    
// #define 	conn_bt2		CONN_BT2    
// #define 	conn_bt3		CONN_BT3    
// #define 	conn_hs4		CONN_HS4    
// #define 	conn_hs_all		CONN_HS_ALL    
// #define 	conn_hs_1		CONN_HS_1    
// #define 	conn_hs_2		CONN_HS_2    
// #define 	conn_hs_3		CONN_HS_3    
// #define 	conn_hs_4		CONN_HS_4    
// #define 	conn_hs_5		CONN_HS_5    
// #define 	conn_hs_6		CONN_HS_6    
// #define 	conn_hs_7		CONN_HS_7    
// #define 	conn_hs_8		CONN_HS_8   

// Functions for sending direct commands to another NXT. 
@[inline] remote_keep_alive() { return C.RemoteKeepAlive() }
@[inline] remote_message_read() { return C.RemoteMessageRead() }
@[inline] remote_message_write() { return C.RemoteMessageWrite() }
@[inline] remote_play_sound_file() { return C.RemotePlaySoundFile() }
@[inline] remote_play_tone() { return C.RemotePlayTone() }
@[inline] remote_reset_motor_position() { return C.RemoteResetMotorPosition() }
@[inline] remote_reset_scaled_value() { return C.RemoteResetScaledValue() }
@[inline] remote_set_input_mode() { return C.RemoteSetInputMode() }
@[inline] remote_set_output_state() { return C.RemoteSetOutputState() }
@[inline] remote_start_program() { return C.RemoteStartProgram() }
@[inline] remote_stop_program() { return C.RemoteStopProgram() }
@[inline] remote_stop_sound() { return C.RemoteStopSound() }
@[inline] remote_get_output_state() { return C.RemoteGetOutputState() }
@[inline] remote_get_input_values() { return C.RemoteGetInputValues() }
@[inline] remote_get_battery_level() { return C.RemoteGetBatteryLevel() }
@[inline] remote_lowspeed_get_status() { return C.RemoteLowspeedGetStatus() }
@[inline] remote_lowspeed_read() { return C.RemoteLowspeedRead() }
@[inline] remote_get_current_program_name() { return C.RemoteGetCurrentProgramName() }
@[inline] remote_datalog_read() { return C.RemoteDatalogRead() }
@[inline] remote_get_contact_count() { return C.RemoteGetContactCount() }
@[inline] remote_get_contact_name() { return C.RemoteGetContactName() }
@[inline] remote_get_connection_count() { return C.RemoteGetConnectionCount() }
@[inline] remote_get_connection_name() { return C.RemoteGetConnectionName() }
@[inline] remote_get_property() { return C.RemoteGetProperty() }
@[inline] remote_reset_tacho_count() { return C.RemoteResetTachoCount() }
@[inline] remote_datalog_set_times() { return C.RemoteDatalogSetTimes() }
@[inline] remote_set_property() { return C.RemoteSetProperty() }
@[inline] remote_lowspeed_write() { return C.RemoteLowspeedWrite() }

// Functions for sending system commands to another NXT. 
@[inline] remote_open_read() { return C.RemoteOpenRead() }             
@[inline] remote_open_append_data() { return C.RemoteOpenAppendData() }       
@[inline] remote_delete_file() { return C.RemoteDeleteFile() }           
@[inline] remote_find_first_file() { return C.RemoteFindFirstFile() }        
@[inline] remote_get_firmware_version() { return C.RemoteGetFirmwareVersion() }   
@[inline] remote_get_bluetooth_address() { return C.RemoteGetBluetoothAddress() }  
@[inline] remote_get_device_info() { return C.RemoteGetDeviceInfo() }        
@[inline] remote_delete_user_flash() { return C.RemoteDeleteUserFlash() }      
@[inline] remote_open_write() { return C.RemoteOpenWrite() }            
@[inline] remote_open_write_linear() { return C.RemoteOpenWriteLinear() }      
@[inline] remote_open_write_data() { return C.RemoteOpenWriteData() }        
@[inline] remote_close_file() { return C.RemoteCloseFile() }            
@[inline] remote_find_next_file() { return C.RemoteFindNextFile() }         
@[inline] remote_poll_command_length() { return C.RemotePollCommandLength() }    
@[inline] remote_write() { return C.RemoteWrite() }                
@[inline] remote_read() { return C.RemoteRead() }                 
@[inline] remote_io_map_read() { return C.RemoteIOMapRead() }            
@[inline] remote_poll_command() { return C.RemotePollCommand() }          
@[inline] remote_rename_file() { return C.RemoteRenameFile() }           
@[inline] remote_bluetooth_factory_reset() { return C.RemoteBluetoothFactoryReset() }
@[inline] remote_io_map_write_value() { return C.RemoteIOMapWriteValue() }      
@[inline] remote_io_map_write_bytes() { return C.RemoteIOMapWriteBytes() }      
@[inline] remote_set_brick_name() { return C.RemoteSetBrickName() }         

// Functions for accessing and modifying Comm module features. 
@[inline] joystick_message_read() { return C.JoystickMessageRead() }      
@[inline] joystick_ex_message_read() { return C.JoystickExMessageRead() }    
@[inline] send_message() { return C.SendMessage() }              
@[inline] receive_message() { return C.ReceiveMessage() }           
@[inline] bluetooth_status() { return C.BluetoothStatus() }          
@[inline] bluetooth_write() { return C.BluetoothWrite() }           
@[inline] remote_connection_write() { return C.RemoteConnectionWrite() }    
@[inline] remote_connection_idle() { return C.RemoteConnectionIdle() }     
@[inline] send_remote_bool() { return C.SendRemoteBool() }           
@[inline] send_remote_number() { return C.SendRemoteNumber() }         
@[inline] send_remote_string() { return C.SendRemoteString() }         
@[inline] send_response_bool() { return C.SendResponseBool() }         
@[inline] send_response_number() { return C.SendResponseNumber() }       
@[inline] send_response_string() { return C.SendResponseString() }       
@[inline] receive_remote_bool() { return C.ReceiveRemoteBool() }        
@[inline] receive_remote_message_ex() { return C.ReceiveRemoteMessageEx() }   
@[inline] receive_remote_number() { return C.ReceiveRemoteNumber() }      
@[inline] receive_remote_string() { return C.ReceiveRemoteString() }      
@[inline] use_rs485() { return C.UseRS485() }                 
@[inline] rs485_control() { return C.RS485Control() }             
@[inline] rs485_data_available() { return C.RS485DataAvailable() }       
@[inline] rs485_initialize() { return C.RS485Initialize() }          
@[inline] rs485_disable() { return C.RS485Disable() }             
@[inline] rs485_enable() { return C.RS485Enable() }              
@[inline] rs485_read() { return C.RS485Read() }                
@[inline] rs485_read_ex() { return C.RS485ReadEx() }              
@[inline] rs485_sending_data() { return C.RS485SendingData() }         
@[inline] rs485_status() { return C.RS485Status() }              
@[inline] rs485_uart() { return C.RS485Uart() }                
@[inline] rs485_write() { return C.RS485Write() }               
@[inline] send_rs485_bool() { return C.SendRS485Bool() }            
@[inline] send_rs485_number() { return C.SendRS485Number() }          
@[inline] send_rs485_string() { return C.SendRS485String() }          
@[inline] get_bt_input_buffer() { return C.GetBTInputBuffer() }         
@[inline] get_bt_output_buffer() { return C.GetBTOutputBuffer() }        
@[inline] get_hs_input_buffer() { return C.GetHSInputBuffer() }         
@[inline] get_hs_output_buffer() { return C.GetHSOutputBuffer() }        
@[inline] get_usb_input_buffer() { return C.GetUSBInputBuffer() }        
@[inline] get_usb_output_buffer() { return C.GetUSBOutputBuffer() }       
@[inline] get_usb_poll_buffer() { return C.GetUSBPollBuffer() }         
@[inline] bt_device_name() { return C.BTDeviceName() }             
@[inline] bt_connection_name() { return C.BTConnectionName() }         
@[inline] bt_connection_pin_code() { return C.BTConnectionPinCode() }      
@[inline] brick_data_name() { return C.BrickDataName() }            
@[inline] get_bt_device_address() { return C.GetBTDeviceAddress() }       
@[inline] get_bt_connection_address() { return C.GetBTConnectionAddress() }   
@[inline] get_brick_data_address() { return C.GetBrickDataAddress() }      
@[inline] bt_device_class() { return C.BTDeviceClass() }            
@[inline] bt_device_status() { return C.BTDeviceStatus() }           
@[inline] bt_connection_class() { return C.BTConnectionClass() }        
@[inline] bt_connection_handle_num() { return C.BTConnectionHandleNum() }    
@[inline] bt_connection_stream_status() { return C.BTConnectionStreamStatus() } 
@[inline] bt_connection_link_quality() { return C.BTConnectionLinkQuality() }  
@[inline] brick_data_bluecore_version() { return C.BrickDataBluecoreVersion() } 
@[inline] brick_data_bt_state_status() { return C.BrickDataBtStateStatus() }   
@[inline] brick_data_bt_hardware_status() { return C.BrickDataBtHardwareStatus() }
@[inline] brick_data_timeout_value() { return C.BrickDataTimeoutValue() }    
@[inline] bt_input_buffer_in_ptr() { return C.BTInputBufferInPtr() }       
@[inline] bt_input_buffer_out_ptr() { return C.BTInputBufferOutPtr() }      
@[inline] bt_output_buffer_in_ptr() { return C.BTOutputBufferInPtr() }      
@[inline] bt_output_buffer_out_ptr() { return C.BTOutputBufferOutPtr() }     
@[inline] hs_input_buffer_in_ptr() { return C.HSInputBufferInPtr() }       
@[inline] hs_input_buffer_out_ptr() { return C.HSInputBufferOutPtr() }      
@[inline] hs_output_buffer_in_ptr() { return C.HSOutputBufferInPtr() }      
@[inline] hs_output_buffer_out_ptr() { return C.HSOutputBufferOutPtr() }     
@[inline] usb_input_buffer_in_ptr() { return C.USBInputBufferInPtr() }      
@[inline] usb_input_buffer_out_ptr() { return C.USBInputBufferOutPtr() }     
@[inline] usb_output_buffer_in_ptr() { return C.USBOutputBufferInPtr() }     
@[inline] usb_output_buffer_out_ptr() { return C.USBOutputBufferOutPtr() }    
@[inline] usb_poll_buffer_in_ptr() { return C.USBPollBufferInPtr() }       
@[inline] usb_poll_buffer_out_ptr() { return C.USBPollBufferOutPtr() }      
@[inline] bt_device_count() { return C.BTDeviceCount() }            
@[inline] bt_device_name_count() { return C.BTDeviceNameCount() }        
@[inline] hs_flags() { return C.HSFlags() }                  
@[inline] hs_speed() { return C.HSSpeed() }                  
@[inline] hs_state() { return C.HSState() }                  
@[inline] hs_address() { return C.HSAddress() }                
@[inline] hs_mode() { return C.HSMode() }                   
@[inline] bt_data_mode() { return C.BTDataMode() }               
@[inline] hs_data_mode() { return C.HSDataMode() }               
@[inline] usb_state() { return C.USBState() }                 
@[inline] set_bt_input_buffer() { return C.SetBTInputBuffer() }         
@[inline] set_bt_input_buffer_in_ptr() { return C.SetBTInputBufferInPtr() }    
@[inline] set_bt_input_buffer_out_ptr() { return C.SetBTInputBufferOutPtr() }   
@[inline] set_bt_output_buffer() { return C.SetBTOutputBuffer() }        
@[inline] set_bt_output_buffer_in_ptr() { return C.SetBTOutputBufferInPtr() }   
@[inline] set_bt_output_buffer_out_ptr() { return C.SetBTOutputBufferOutPtr() }  
@[inline] set_hs_input_buffer() { return C.SetHSInputBuffer() }         
@[inline] set_hs_input_buffer_in_ptr() { return C.SetHSInputBufferInPtr() }    
@[inline] set_hs_input_buffer_out_ptr() { return C.SetHSInputBufferOutPtr() }   
@[inline] set_hs_output_buffer() { return C.SetHSOutputBuffer() }        
@[inline] set_hs_output_buffer_in_ptr() { return C.SetHSOutputBufferInPtr() }   
@[inline] set_hs_output_buffer_out_ptr() { return C.SetHSOutputBufferOutPtr() }  
@[inline] set_usb_input_buffer() { return C.SetUSBInputBuffer() }        
@[inline] set_usb_input_buffer_in_ptr() { return C.SetUSBInputBufferInPtr() }   
@[inline] set_usb_input_buffer_out_ptr() { return C.SetUSBInputBufferOutPtr() }  
@[inline] set_usb_output_buffer() { return C.SetUSBOutputBuffer() }       
@[inline] set_usb_output_buffer_in_ptr() { return C.SetUSBOutputBufferInPtr() }  
@[inline] set_usb_output_buffer_out_ptr() { return C.SetUSBOutputBufferOutPtr() } 
@[inline] set_usb_poll_buffer() { return C.etUSBPollBuffer() }         
@[inline] set_usb_poll_buffer_in_ptr() { return C.SetUSBPollBufferInPtr() }    
@[inline] set_usb_poll_buffer_out_ptr() { return C.SetUSBPollBufferOutPtr() }   
@[inline] set_hs_flags() { return C.SetHSFlags() }               
@[inline] set_hs_speed() { return C.SetHSSpeed() }               
@[inline] set_hs_state() { return C.SetHSState() }               
@[inline] set_hs_address() { return C.SetHSAddress() }             
@[inline] set_hs_mode() { return C.SetHSMode() }                
@[inline] set_bt_data_mode() { return C.SetBTDataMode() }            
@[inline] set_hs_data_mode() { return C.SetHSDataMode() }            
@[inline] set_usb_state() { return C.SetUSBState() }              
@[inline] sys_message_write() { return C.SysMessageWrite() }          
@[inline] sys_message_read() { return C.SysMessageRead() }           
@[inline] sys_comm_bt_write() { return C.SysCommBTWrite() }           
@[inline] sys_comm_bt_check_status() { return C.SysCommBTCheckStatus() }     
@[inline] sys_comm_execute_function() { return C.SysCommExecuteFunction() }   
@[inline] sys_comm_hs_control() { return C.SysCommHSControl() }         
@[inline] sys_comm_hs_check_status() { return C.SysCommHSCheckStatus() }     
@[inline] sys_comm_hs_read() { return C.SysCommHSRead() }            
@[inline] sys_comm_hs_write() { return C.SysCommHSWrite() }           
@[inline] sys_comm_bt_on_off() { return C.SysCommBTOnOff() }           
@[inline] sys_comm_bt_connection() { return C.SysCommBTConnection() }      
