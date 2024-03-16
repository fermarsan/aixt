module sound

// #################### NXC Sound module ####################

// Constant offsets into the Sound module IOMAP structure. 
#define 	offset_freq         		SoundOffsetFreq           
#define 	offset_duration     		SoundOffsetDuration       
#define 	offset_sample_rate   		SoundOffsetSampleRate     
#define 	offset_sound_filename		SoundOffsetSoundFilename  
#define 	offset_flags        		SoundOffsetFlags          
#define 	offset_state        		SoundOffsetState          
#define 	offset_mode         		SoundOffsetMode           
#define 	offset_volume       		SoundOffsetVolume         

// Constants defining miscellaneous sound module aspects. 
#define 	frequency_min     	FREQUENCY_MIN     
#define 	frequency_max     	FREQUENCY_MAX     
#define 	samplerate_min    	SAMPLERATE_MIN    
#define 	samplerate_default	SAMPLERATE_DEFAULT
#define 	samplerate_max    	SAMPLERATE_MAX    


// Constants for use with the sound__flags() function. 
#define 	flags_idle   	SOUND_FLAGS_IDLE    
#define 	flags_update 	SOUND_FLAGS_UPDATE    
#define 	flags_running	SOUND_FLAGS_RUNNING    

// Constants for use with the sound__mode() function. 
#define 	mode_once		SOUND_MODE_ONCE    
#define 	mode_loop		SOUND_MODE_LOOP    
#define 	mode_tone		SOUND_MODE_TONE   

// Constants for use with the sound__state() function. 
#define 	state_idle	SOUND_STATE_IDLE    
#define 	state_file	SOUND_STATE_FILE    
#define 	state_tone	SOUND_STATE_TONE    
#define 	state_stop	SOUND_STATE_STOP   

// Constants for use in the sound__play_tone() api function. 
#define 	tone_c3		TONE_C3
#define 	tone_cs3	TONE_CS3
#define 	tone_d3		TONE_D3
#define 	tone_ds3	TONE_DS3
#define 	tone_e3		TONE_E3
#define 	tone_f3		TONE_F3
#define 	tone_fs3	TONE_FS3
#define 	tone_g3		TONE_G3
#define 	tone_gs3	TONE_GS3
#define 	tone_a3		TONE_A3
#define 	tone_as3	TONE_AS3
#define 	tone_b3		TONE_B3
#define 	tone_c4		TONE_C4
#define 	tone_cs4	TONE_CS4
#define 	tone_d4		TONE_D4
#define 	tone_ds4	TONE_DS4
#define 	tone_e4		TONE_E4
#define 	tone_f4		TONE_F4
#define 	tone_fs4	TONE_FS4
#define 	tone_g4		TONE_G4
#define 	tone_gs4	TONE_GS4
#define 	tone_a4		TONE_A4
#define 	tone_as4	TONE_AS4
#define 	tone_b4		TONE_B4
#define 	tone_c5		TONE_C5
#define 	tone_cs5	TONE_CS5
#define 	tone_d5		TONE_D5
#define 	tone_ds5	TONE_DS5
#define 	tone_e5		TONE_E5
#define 	tone_f5		TONE_F5
#define 	tone_fs5	TONE_FS5
#define 	tone_g5		TONE_G5
#define 	tone_gs5	TONE_GS5
#define 	tone_a5		TONE_A5
#define 	tone_as5	TONE_AS5
#define 	tone_b5		TONE_B5
#define 	tone_c6		TONE_C6
#define 	tone_cs6	TONE_CS6
#define 	tone_d6		TONE_D6
#define 	tone_ds6	TONE_DS6
#define 	tone_e6		TONE_E6
#define 	tone_f6		TONE_F6
#define 	tone_fs6	TONE_FS6
#define 	tone_g6		TONE_G6
#define 	tone_gs6	TONE_GS6
#define 	tone_a6		TONE_A6
#define 	tone_as6	TONE_AS6
#define 	tone_b6		TONE_B6
#define 	tone_c7		TONE_C7
#define 	tone_cs7	TONE_CS7
#define 	tone_d7		TONE_D7
#define 	tone_ds7	TONE_DS7
#define 	tone_e7		TONE_E7
#define 	tone_f7		TONE_F7
#define 	tone_fs7	TONE_FS7
#define 	tone_g7		TONE_G7
#define 	tone_gs7	TONE_GS7
#define 	tone_a7		TONE_A7
#define 	tone_as7	TONE_AS7
#define 	tone_b7		TONE_B7

// Functions for accessing and modifying sound module features. 
#define     sound__play_file(...)        PlayFile(__VA_ARGS__)
#define     sound__play_file_ex(...)     PlayFileEx(__VA_ARGS__)
#define     sound__play_tone(...)        PlayTone(__VA_ARGS__)
#define     sound__play_tone_ex(...)     PlayToneEx(__VA_ARGS__)
#define     sound__state(...)            SoundState(__VA_ARGS__)
#define     sound__flags(...)            SoundFlags(__VA_ARGS__)
#define     sound__stop(...)             StopSound(__VA_ARGS__)
#define     sound__frequency(...)        SoundFrequency(__VA_ARGS__)
#define     sound__duration(...)         SoundDuration(__VA_ARGS__)
#define     sound__sample_rate(...)      SoundSampleRate(__VA_ARGS__)
#define     sound__mode(...)             SoundMode(__VA_ARGS__)
#define     sound__volume(...)           SoundVolume(__VA_ARGS__)
#define     sound__set_duration(...)     SetSoundDuration(__VA_ARGS__)
#define     sound__set_flags(...)        SetSoundFlags(__VA_ARGS__)
#define     sound__set_frequency(...)    SetSoundFrequency(__VA_ARGS__)
#define     sound__set_mode(...)         SetSoundMode(__VA_ARGS__)
#define     sound__set_module_state(...) SetSoundModuleState(__VA_ARGS__)
#define     sound__set_sample_rate(...)  SetSoundSampleRate(__VA_ARGS__)
#define     sound__set_volume(...)       SetSoundVolume(__VA_ARGS__)
#define     sound__sys_play_file(...)    SysSoundPlayFile(__VA_ARGS__)
#define     sound__sys_play_tone(...)    SysSoundPlayTone(__VA_ARGS__)
#define     sound__sys_get_state(...)    SysSoundGetState(__VA_ARGS__)
#define     sound__sys_set_state(...)    SysSoundSetState(__VA_ARGS__)
#define     sound__play(...)             PlaySound(__VA_ARGS__)
#define     sound__play_tones(...)       PlayTones(__VA_ARGS__)


fn init() {

}
