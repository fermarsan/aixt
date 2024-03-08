module motor	// NXC Output

// #################### NXC Output module ####################

// Constants for use with set_output                                              
#define     update_flags_field      UpdateFlagsField                   
#define     output_mode_field       OutputModeField                    
#define     power_field             PowerField                         
#define     actual_speed_field      ActualSpeedField                   
#define     tacho_count_field       TachoCountField                    
#define     tacho_limit_field       TachoLimitField                    
#define     run_state_field         RunStateField                      
#define     turn_ratio_field        TurnRatioField                     
#define     reg_mode_field          RegModeField                       
#define     overload_field          OverloadField                      
#define     reg_p_value_field       RegPValueField                     
#define     reg_i_value_field       RegIValueField                     
#define     reg_d_value_field       RegDValueField                     
#define     block_tacho_count_field BlockTachoCountField            
#define     rotation_count_field    RotationCountField              
#define     output_options_field    OutputOptionsField              
#define     max_speed_field         MaxSpeedField                   
#define     max_acceleration_field  MaxAccelerationField

// Constant offsets into the Output module IOMAP structure. 
#define     offset_tacho_count          OutputOffsetTachoCount        
#define     offset_block_tacho_count    OutputOffsetBlockTachoCount        
#define     offset_rotation_count       OutputOffsetRotationCount        
#define     offset_tacho_limit          OutputOffsetTachoLimit        
#define     offset_motor_rpm            OutputOffsetMotorRPM           
#define     offset_flags                OutputOffsetFlags                
#define     offset_mode                 OutputOffsetMode                
#define     offset_speed                OutputOffsetSpeed                
#define     offset_actual_speed         OutputOffsetActualSpeed                
#define     offset_reg_p_parameter      OutputOffsetRegPParameter        
#define     offset_reg_i_parameter      OutputOffsetRegIParameter        
#define     offset_reg_d_parameter      OutputOffsetRegDParameter        
#define     offset_run_state            OutputOffsetRunState           
#define     offset_reg_mode             OutputOffsetRegMode            
#define     offset_overloaded           OutputOffsetOverloaded        
#define     offset_sync_turn_parameter  OutputOffsetSyncTurnParameter        
#define     offset_options              OutputOffsetOptions           
#define     offset_max_speed            OutputOffsetMaxSpeed           
#define     offset_max_accel            OutputOffsetMaxAccel           
#define     offset_regulation_time      OutputOffsetRegulationTime            
#define     offset_regulation_options   OutputOffsetRegulationOptions

// Output port constants are used when calling motor control API functions. 
#define 	a	OUT_A  
#define 	b	OUT_B  
#define 	c	OUT_C  
#define 	ab	OUT_AB 
#define 	ac	OUT_AC 
#define 	bc	OUT_BC 
#define 	abc	OUT_ABC

// Use these constants to configure the desired mode for the specified motor                                              : coast, motoron, brake, or regulated.
// Mode constants can be combined with bitwise OR. 
#define     mode_coast      OUT_MODE_COAST       
#define     mode_motoron    OUT_MODE_MOTORON    
#define     mode_brake      OUT_MODE_BRAKE       
#define     mode_regulated  OUT_MODE_REGULATED   
#define     mode_regmethod  OUT_MODE_REGMETHOD

// Use these constants to configure the desired options for the specified motor                                              : hold at limit and ramp down to limit.
// Option constants can be combined with bitwise OR. 
#define 	option_holdatlimit    	OUT_OPTION_HOLDATLIMIT    
#define 	option_rampdowntolimit	OUT_OPTION_RAMPDOWNTOLIMIT

// Use these constants to configure the desired regulation mode for the specified motor                                              : none, speed regulation, 
// multi-motor synchronization, or position regulation                                               . 
#define 	regmode_idle    OUT_REGMODE_IDLE  
#define 	regmode_speed   OUT_REGMODE_SPEED 
#define 	regmode_sync    OUT_REGMODE_SYNC  
#define 	regmode_pos     OUT_REGMODE_POS 

// Use these constants to configure the desired run state for the specified motor                                              : 
// idle, rampup, running, rampdown, or hold. 
#define 	runstate_idle       OUT_RUNSTATE_IDLE       
#define 	runstate_rampup     OUT_RUNSTATE_RAMPUP     
#define 	runstate_running    OUT_RUNSTATE_RUNNING    
#define 	runstate_rampdown   OUT_RUNSTATE_RAMPDOWN   
#define 	runstate_hold       OUT_RUNSTATE_HOLD

// Use these constants to specify which motor values need to be updated.
// Update flag constants can be combined with bitwise OR. 
#define 	uf_update_mode                  UF_UPDATE_MODE                   
#define 	uf_update_speed                 UF_UPDATE_SPEED                  
#define 	uf_update_tacho_limit           UF_UPDATE_TACHO_LIMIT            
#define 	uf_update_reset_count           UF_UPDATE_RESET_COUNT            
#define 	uf_update_pid_values            UF_UPDATE_PID_VALUES             
#define 	uf_update_reset_block_count     UF_UPDATE_RESET_BLOCK_COUNT      
#define 	uf_update_reset_rotation_count  UF_UPDATE_RESET_ROTATION_COUNT   
#define 	uf_pending_updates              UF_PENDING_UPDATES  

// Use these constants to configure the desired options for position regulation. 
#define 	regoption_no_saturation		OUT_REGOPTION_NO_SATURATION 

// PID constants are for adjusting the Proportional, Integral, and Derivative motor controller parameters. 
#define 	pid_0   PID_0   
#define 	pid_1   PID_1   
#define 	pid_2   PID_2   
#define 	pid_3   PID_3   
#define 	pid_4   PID_4   
#define 	pid_5   PID_5   
#define 	pid_6   PID_6   
#define 	pid_7   PID_7   

// Use these constants to specify which of the three tachometer counters should be reset.
// Reset constants can be combined with bitwise OR. 
#define 	reset_none              RESET_NONE              
#define 	reset_count             RESET_COUNT             
#define 	reset_block_count       RESET_BLOCK_COUNT       
#define 	reset_rotation_count    RESET_ROTATION_COUNT    
#define 	reset_blockandtacho     RESET_BLOCKANDTACHO     
#define 	reset_all               RESET_ALL    


// Functions for accessing and modifying output module features. 
#define     motor__set_pwn_freq(...)             SetMotorPwnFreq(__VA_ARGS__)                 
#define     motor__set_regulation_time(...)      SetMotorRegulationTime(__VA_ARGS__)                 
#define     motor__set_regulation_options(...)   SetMotorRegulationOptions(__VA_ARGS__)                 
#define     motor__forward_sync_pid(...)         OnFwdSyncPID(__VA_ARGS__)                 
#define     motor__forward_sync_ex_pid(...)      OnFwdSyncExPID(__VA_ARGS__)                 
#define     motor__reverse_sync_pid(...)         OnRevSyncPID(__VA_ARGS__)                 
#define     motor__reverse_sync_ex_pid(...)      OnRevSyncExPID(__VA_ARGS__)                 
#define     motor__forward_reg_pid(...)          OnFwdRegPID(__VA_ARGS__)                 
#define     motor__forward_reg_ex_pid(...)       OnFwdRegExPID(__VA_ARGS__)                 
#define     motor__reverse_reg_pid(...)          OnRevRegPID(__VA_ARGS__)                 
#define     motor__reverse_reg_ex_pid(...)       OnRevRegExPID(__VA_ARGS__)                 
#define     motor__off(...)                      Off(__VA_ARGS__)                       
#define     motor__off_ex(...)                   OffEx(__VA_ARGS__)                     
#define     motor__coast(...)                    Coast(__VA_ARGS__)                     
#define     motor__coast_ex(...)                 CoastEx(__VA_ARGS__)                   
#define     motor__float(...)                    Float(__VA_ARGS__)                     
#define     motor__forward(...)             	 OnFwd(__VA_ARGS__)                     
#define     motor__forward_ex(...)               OnFwdEx(__VA_ARGS__)                   
#define     motor__reverse(...)                  OnRev(__VA_ARGS__)                     
#define     motor__reverse_ex(...)               OnRevEx(__VA_ARGS__)                   
#define     motor__forward_reg(...)              OnFwdReg(__VA_ARGS__)                  
#define     motor__forward_reg_ex(...)           OnFwdRegEx(__VA_ARGS__)                 
#define     motor__reverse_reg(...)              OnRevReg(__VA_ARGS__)                  
#define     motor__reverse_reg_ex(...)           OnRevRegEx(__VA_ARGS__)                 
#define     motor__forward_sync(...)             OnFwdSync(__VA_ARGS__)                 
#define     motor__forward_sync_ex(...)          OnFwdSyncEx(__VA_ARGS__)                 
#define     motor__reverse_sync(...)             OnRevSync(__VA_ARGS__)                 
#define     motor__reverse_sync_ex(...)          OnRevSyncEx(__VA_ARGS__)                 
#define     motor__rotate(...)                   RotateMotor(__VA_ARGS__)                 
#define     motor__rotate_pid(...)               RotateMotorPID(__VA_ARGS__)                 
#define     motor__rotate_ex(...)                RotateMotorEx(__VA_ARGS__)                 
#define     motor__rotate_ex_pid(...)            RotateMotorExPID(__VA_ARGS__)                 
#define     motor__reset_tacho_count(...)        ResetTachoCount(__VA_ARGS__)                 
#define     motor__reset_block_tacho_count(...)  ResetBlockTachoCount(__VA_ARGS__)                 
#define     motor__reset_rotation_count(...)     ResetRotationCount(__VA_ARGS__)                 
#define     motor__reset_all_tacho_counts(...)   ResetAllTachoCounts(__VA_ARGS__)               
#define     motor__mode(...)                     MotorMode(__VA_ARGS__)                 
#define     motor__power(...)                    MotorPower(__VA_ARGS__)                 
#define     motor__actual_speed(...)             MotorActualSpeed(__VA_ARGS__)                 
#define     motor__tacho_count(...)              MotorTachoCount(__VA_ARGS__)                 
#define     motor__tacho_limit(...)              MotorTachoLimit(__VA_ARGS__)                 
#define     motor__run_state(...)                MotorRunState(__VA_ARGS__)                 
#define     motor__turn_ratio(...)               MotorTurnRatio(__VA_ARGS__)                 
#define     motor__regulation(...)               MotorRegulation(__VA_ARGS__)                 
#define     motor__overload(...)                 MotorOverload(__VA_ARGS__)                 
#define     motor__reg_p_value(...)              MotorRegPValue(__VA_ARGS__)                 
#define     motor__reg_i_value(...)              MotorRegIValue(__VA_ARGS__)                 
#define     motor__reg_d_value(...)              MotorRegDValue(__VA_ARGS__)                 
#define     motor__block_tacho_count(...)        MotorBlockTachoCount(__VA_ARGS__)                 
#define     motor__rotation_count(...)           MotorRotationCount(__VA_ARGS__)                 
#define     motor__output_options(...)           MotorOutputOptions(__VA_ARGS__)                 
#define     motor__max_speed(...)                MotorMaxSpeed(__VA_ARGS__)                 
#define     motor__max_acceleration(...)         MotorMaxAcceleration(__VA_ARGS__)                 
#define     motor__pwn_freq(...)                 MotorPwnFreq(__VA_ARGS__)                 
#define     motor__regulation_time(...)          MotorRegulationTime(__VA_ARGS__)                 
#define     motor__regulation_options(...)       MotorRegulationOptions(__VA_ARGS__)

#define     set_output(...)               	     SetOutput(__VA_ARGS__)    
#define     get_output(...)               	     GetOutput(__VA_ARGS__)      
#define     pos_reg_enable(...)           	     PosRegEnable(__VA_ARGS__)            
#define     pos_reg_set_angle(...)        	     PosRegSetAngle(__VA_ARGS__)             
#define     pos_reg_add_angle(...)        	     PosRegAddAngle(__VA_ARGS__)                
#define     pos_reg_set_max(...)          	     PosRegSetMax(__VA_ARGS__)             

fn init() {

}