module lowspeed

// Constants for the low speed module LSChannelState function. 
#define 	ls_idle         	LOWSPEED_IDLE         
#define 	ls_init         	LOWSPEED_INIT         
#define 	ls_load_buffer  	LOWSPEED_LOAD_BUFFER  
#define 	ls_communicating	LOWSPEED_COMMUNICATING
#define 	ls_error        	LOWSPEED_ERROR        
#define 	ls_done         	LOWSPEED_DONE      

// Constants for the low speed module LSErrorType function. 
#define 	ls_no_error    		LOWSPEED_NO_ERROR    
#define 	ls_ch_not_ready		LOWSPEED_CH_NOT_READY
#define 	ls_tx_error    		LOWSPEED_TX_ERROR    
#define 	ls_rx_error    		LOWSPEED_RX_ERROR    

// Constants for the low speed module LSMode function. 
#define 	ls_transmitting 	LOWSPEED_TRANSMITTING   
#define 	ls_receiving    	LOWSPEED_RECEIVING     
#define 	ls_data_received	LOWSPEED_DATA_RECEIVED  

// Constant offsets into the low speed module IOMAP structure. 
#define 	ls_offset_in_buf_buf			LowSpeedOffsetInBufBuf
#define 	ls_offset_in_buf_in_ptr		    LowSpeedOffsetInBufInPtr
#define 	ls_offset_in_buf_out_ptr		LowSpeedOffsetInBufOutPtr
#define 	ls_offset_in_buf_bytes_to_rx	LowSpeedOffsetInBufBytesToRx
#define 	ls_offset_out_buf_buf			LowSpeedOffsetOutBufBuf
#define 	ls_offset_out_buf_in_ptr		LowSpeedOffsetOutBufInPtr
#define 	ls_offset_out_buf_out_ptr		LowSpeedOffsetOutBufOutPtr
#define 	ls_offset_out_buf_bytes_to_rx	LowSpeedOffsetOutBufBytesToRx
#define 	ls_offset_mode					LowSpeedOffsetMode
#define 	ls_offset_channel_state			LowSpeedOffsetChannelState
#define 	ls_offset_error_type			LowSpeedOffsetErrorType
#define 	ls_offset_state   				LowSpeedOffsetState   
#define 	ls_offset_speed   				LowSpeedOffsetSpeed   
#define 	ls_offset_no_restart_on_read	LowSpeedOffsetNoRestartOnRead

// Constants for the low speed module LSNoRestartOnRead and SetLSNoRestartOnRead functions.
// These values are combined with a bitwise OR operation. 
#define 	lsread_restart_all    	LSREAD_RESTART_ALL    
#define 	lsread_no_restart_1   	LSREAD_NO_RESTART_1   
#define 	lsread_no_restart_2   	LSREAD_NO_RESTART_2   
#define 	lsread_no_restart_3   	LSREAD_NO_RESTART_3   
#define 	lsread_no_restart_4   	LSREAD_NO_RESTART_4   
#define 	lsread_restart_none   	LSREAD_RESTART_NONE   
#define 	lsread_no_restart_mask	LSREAD_NO_RESTART_MASK

// Constants for the low speed module LSState function.
// These values are combined together using a bitwise OR operation. 
#define 	com_channel_none_active 	COM_CHANNEL_NONE_ACTIVE 
#define 	com_channel_one_active  	COM_CHANNEL_ONE_ACTIVE  
#define 	com_channel_two_active  	COM_CHANNEL_TWO_ACTIVE  
#define 	com_channel_three_active	COM_CHANNEL_THREE_ACTIVE
#define 	com_channel_four_active 	COM_CHANNEL_FOUR_ACTIVE 

// Functions for accessing and modifying low speed module features. 
#define		lowspeed__status(...) 		LowspeedStatus(__VA_ARGS__) 
#define		lowspeed__check_status(...) LowspeedCheckStatus(__VA_ARGS__) 
#define		lowspeed__bytes_ready(...) 	LowspeedBytesReady(__VA_ARGS__) 
#define		lowspeed__write(...) 		LowspeedWrite(__VA_ARGS__) 
#define		lowspeed__read(...)			LowspeedRead(__VA_ARGS__)

// Low level functions for accessing low speed module features. 
#define		lowspeed__get_input_buffer(...)				GetLSInputBuffer(__VA_ARGS__)
#define		lowspeed__get_output_buffer(...)			GetLSOutputBuffer(__VA_ARGS__)
#define		lowspeed__input_buffer_in_ptr(...)			LSInputBufferInPtr(__VA_ARGS__)
#define		lowspeed__input_buffer_out_ptr(...)			LSInputBufferOutPtr(__VA_ARGS__)
#define		lowspeed__input_buffer_bytes_to_rx(...)		LSInputBufferBytesToRx(__VA_ARGS__)
#define		lowspeed__output_buffer_in_ptr(...)			LSOutputBufferInPtr(__VA_ARGS__)
#define		lowspeed__output_buffer_out_ptr(...)		LSOutputBufferOutPtr(__VA_ARGS__)
#define		lowspeed__output_buffer_bytes_to_rx(...)	LSOutputBufferBytesToRx(__VA_ARGS__)
#define		lowspeed__mode(...)							LSMode(__VA_ARGS__)
#define		lowspeed__channel_state(...)				LSChannelState(__VA_ARGS__)
#define		lowspeed__error_type(...)					LSErrorType(__VA_ARGS__)
#define		lowspeed__state(...)						LSState(__VA_ARGS__)
#define		lowspeed__speed(...)						LSSpeed(__VA_ARGS__)
#define		lowspeed__no_restart_on_read(...)			LSNoRestartOnRead(__VA_ARGS__)
#define		set_i2c_options(...)						SetI2COptions(__VA_ARGS__)

// System call functions for accessing low speed module features. 
#define		sys_comm_ls_write(...) 			SysCommLSWrite(__VA_ARGS__) 
#define		sys_comm_ls_read(...) 			SysCommLSRead(__VA_ARGS__) 
#define		sys_comm_ls_check_status(...) 	SysCommLSCheckStatus(__VA_ARGS__) 
#define		sys_comm_ls_write_ex(...)		SysCommLSWriteEx(__VA_ARGS__)


fn init() {

}