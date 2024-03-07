module motor	// NXC Output

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
#define     motor__set_pwn_freq             SetMotorPwnFreq                 
#define     motor__set_regulation_time      SetMotorRegulationTime                 
#define     motor__set_regulation_options   SetMotorRegulationOptions                 
#define     motor__forward_sync_pid         OnFwdSyncPID                 
#define     motor__forward_sync_ex_pid      OnFwdSyncExPID                 
#define     motor__reverse_sync_pid         OnRevSyncPID                 
#define     motor__reverse_sync_ex_pid      OnRevSyncExPID                 
#define     motor__forward_reg_pid          OnFwdRegPID                 
#define     motor__forward_reg_ex_pid       OnFwdRegExPID                 
#define     motor__reverse_reg_pid          OnRevRegPID                 
#define     motor__reverse_reg_ex_pid       OnRevRegExPID                 
#define     motor__off                      Off                       
#define     motor__off_ex                   OffEx                     
#define     motor__coast                    Coast                     
#define     motor__coast_ex                 CoastEx                   
#define     motor__float                    Float                     
#define     motor__forward                  OnFwd                     
#define     motor__forward_ex               OnFwdEx                   
#define     motor__reverse                  OnRev                     
#define     motor__reverse_ex               OnRevEx                   
#define     motor__forward_reg              OnFwdReg                  
#define     motor__forward_reg_ex           OnFwdRegEx                 
#define     motor__reverse_reg              OnRevReg                  
#define     motor__reverse_reg_ex           OnRevRegEx                 
#define     motor__forward_sync             OnFwdSync                 
#define     motor__forward_sync_ex          OnFwdSyncEx                 
#define     motor__reverse_sync             OnRevSync                 
#define     motor__reverse_sync_ex          OnRevSyncEx                 
#define     motor__rotate                   RotateMotor                 
#define     motor__rotate_pid               RotateMotorPID                 
#define     motor__rotate_ex                RotateMotorEx                 
#define     motor__rotate_ex_pid            RotateMotorExPID                 
#define     motor__reset_tacho_count        ResetTachoCount                 
#define     motor__reset_block_tacho_count  ResetBlockTachoCount                 
#define     motor__reset_rotation_count     ResetRotationCount                 
#define     motor__reset_all_tacho_counts   ResetAllTachoCounts                 
#define     set_output               		SetOutput                 
#define     get_output               		GetOutput                 
#define     motor__mode                     MotorMode                 
#define     motor__power                    MotorPower                 
#define     motor__actual_speed             MotorActualSpeed                 
#define     motor__tacho_count              MotorTachoCount                 
#define     motor__tacho_limit              MotorTachoLimit                 
#define     motor__run_state                MotorRunState                 
#define     motor__turn_ratio               MotorTurnRatio                 
#define     motor__regulation               MotorRegulation                 
#define     motor__overload                 MotorOverload                 
#define     motor__reg_p_value              MotorRegPValue                 
#define     motor__reg_i_value              MotorRegIValue                 
#define     motor__reg_d_value              MotorRegDValue                 
#define     motor__block_tacho_count        MotorBlockTachoCount                 
#define     motor__rotation_count           MotorRotationCount                 
#define     motor__output_options           MotorOutputOptions                 
#define     motor__max_speed                MotorMaxSpeed                 
#define     motor__max_acceleration         MotorMaxAcceleration                 
#define     motor__pwn_freq                 MotorPwnFreq                 
#define     motor__regulation_time          MotorRegulationTime                 
#define     motor__regulation_options       MotorRegulationOptions                 
#define     pos_reg_enable           		PosRegEnable                 
#define     pos_reg_set_angle        		PosRegSetAngle                 
#define     pos_reg_add_angle        		PosRegAddAngle                 
#define     pos_reg_set_max          		PosRegSetMax


fn init() {

}