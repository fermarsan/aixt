// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Sound module for NXT (NXC backend)

module sound
 

// Constants for use in the sound__play_tone() api function. 
@[as_macro] pub const tone_c3	= C.TONE_C3
@[as_macro] pub const tone_cs3	= C.TONE_CS3
@[as_macro] pub const tone_d3	= C.TONE_D3
@[as_macro] pub const tone_ds3	= C.TONE_DS3
@[as_macro] pub const tone_e3	= C.TONE_E3
@[as_macro] pub const tone_f3	= C.TONE_F3
@[as_macro] pub const tone_fs3	= C.TONE_FS3
@[as_macro] pub const tone_g3	= C.TONE_G3
@[as_macro] pub const tone_gs3	= C.TONE_GS3
@[as_macro] pub const tone_a3	= C.TONE_A3
@[as_macro] pub const tone_as3	= C.TONE_AS3
@[as_macro] pub const tone_b3	= C.TONE_B3
@[as_macro] pub const tone_c4	= C.TONE_C4
@[as_macro] pub const tone_cs4	= C.TONE_CS4
@[as_macro] pub const tone_d4	= C.TONE_D4
@[as_macro] pub const tone_ds4	= C.TONE_DS4
@[as_macro] pub const tone_e4	= C.TONE_E4
@[as_macro] pub const tone_f4	= C.TONE_F4
@[as_macro] pub const tone_fs4	= C.TONE_FS4
@[as_macro] pub const tone_g4	= C.TONE_G4
@[as_macro] pub const tone_gs4	= C.TONE_GS4
@[as_macro] pub const tone_a4	= C.TONE_A4
@[as_macro] pub const tone_as4	= C.TONE_AS4
@[as_macro] pub const tone_b4	= C.TONE_B4
@[as_macro] pub const tone_c5	= C.TONE_C5
@[as_macro] pub const tone_cs5	= C.TONE_CS5
@[as_macro] pub const tone_d5	= C.TONE_D5
@[as_macro] pub const tone_ds5	= C.TONE_DS5
@[as_macro] pub const tone_e5	= C.TONE_E5
@[as_macro] pub const tone_f5	= C.TONE_F5
@[as_macro] pub const tone_fs5	= C.TONE_FS5
@[as_macro] pub const tone_g5	= C.TONE_G5
@[as_macro] pub const tone_gs5	= C.TONE_GS5
@[as_macro] pub const tone_a5	= C.TONE_A5
@[as_macro] pub const tone_as5	= C.TONE_AS5
@[as_macro] pub const tone_b5	= C.TONE_B5
@[as_macro] pub const tone_c6	= C.TONE_C6
@[as_macro] pub const tone_cs6	= C.TONE_CS6
@[as_macro] pub const tone_d6	= C.TONE_D6
@[as_macro] pub const tone_ds6	= C.TONE_DS6
@[as_macro] pub const tone_e6	= C.TONE_E6
@[as_macro] pub const tone_f6	= C.TONE_F6
@[as_macro] pub const tone_fs6	= C.TONE_FS6
@[as_macro] pub const tone_g6	= C.TONE_G6
@[as_macro] pub const tone_gs6	= C.TONE_GS6
@[as_macro] pub const tone_a6	= C.TONE_A6
@[as_macro] pub const tone_as6	= C.TONE_AS6
@[as_macro] pub const tone_b6	= C.TONE_B6
@[as_macro] pub const tone_c7	= C.TONE_C7
@[as_macro] pub const tone_cs7	= C.TONE_CS7
@[as_macro] pub const tone_d7	= C.TONE_D7
@[as_macro] pub const tone_ds7	= C.TONE_DS7
@[as_macro] pub const tone_e7	= C.TONE_E7
@[as_macro] pub const tone_f7	= C.TONE_F7
@[as_macro] pub const tone_fs7	= C.TONE_FS7
@[as_macro] pub const tone_g7	= C.TONE_G7
@[as_macro] pub const tone_gs7	= C.TONE_GS7
@[as_macro] pub const tone_a7	= C.TONE_A7
@[as_macro] pub const tone_as7	= C.TONE_AS7
@[as_macro] pub const tone_b7	= C.TONE_B7

// Functions for accessing and modifying sound module features. 
@[as_macro]
pub fn play_file() {
	return C.PlayFile() 
}

@[as_macro]
pub fn play_file_ex() {
	return C.PlayFileEx() 
}

@[as_macro]
pub fn play_tone() {
	return C.PlayTone() 
}

@[as_macro]
pub fn play_tone_ex() {
	return C.PlayToneEx() 
}

@[as_macro]
pub fn state() {
	return C.SoundState() 
}

@[as_macro]
pub fn flags() {
	return C.SoundFlags() 
}

@[as_macro]
pub fn stop() {
	return C.StopSound() 
}

@[as_macro]
pub fn frequency() {
	return C.SoundFrequency() 
}

@[as_macro]
pub fn duration() {
	return C.SoundDuration() 
}

@[as_macro]
pub fn sample_rate() {
	return C.SoundSampleRate() 
}

@[as_macro]
pub fn mode() {
	return C.SoundMode() 
}

@[as_macro]
pub fn volume() {
	return C.SoundVolume() 
}

@[as_macro]
pub fn set_duration() {
	return C.SetSoundDuration() 
}

@[as_macro]
pub fn set_flags() {
	return C.SetSoundFlags() 
}

@[as_macro]
pub fn set_frequency() {
	return C.SetSoundFrequency() 
}

@[as_macro]
pub fn set_mode() {
	return C.SetSoundMode() 
}

@[as_macro]
pub fn set_module_state() {
	return C.SetSoundModuleState() 
}

@[as_macro]
pub fn set_sample_rate() {
	return C.SetSoundSampleRate() 
}

@[as_macro]
pub fn set_volume() {
	return C.SetSoundVolume() 
}

@[as_macro]
pub fn play() {
	return C.PlaySound() 
}

@[as_macro]
pub fn play_tones() {
	return C.PlayTones() 
}

