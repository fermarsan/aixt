# module nxt.sound


## Contents
- [Constants](#Constants)
- [duration](#duration)
- [frequency](#frequency)
- [mode](#mode)
- [play](#play)
- [play_file](#play_file)
- [play_file_ex](#play_file_ex)
- [play_tone](#play_tone)
- [play_tone_ex](#play_tone_ex)
- [play_tones](#play_tones)
- [sample_rate](#sample_rate)
- [set_duration](#set_duration)
- [set_flags](#set_flags)
- [set_frequency](#set_frequency)
- [set_mode](#set_mode)
- [set_module_state](#set_module_state)
- [set_sample_rate](#set_sample_rate)
- [set_volume](#set_volume)
- [stop](#stop)
- [volume](#volume)

## Constants
```v
const tone_c3 = C.TONE_C3
```

Constants for use in the sound__play_tone() api function.

[[Return to contents]](#Contents)

```v
const tone_cs3 = C.TONE_CS3
```

[[Return to contents]](#Contents)

```v
const tone_d3 = C.TONE_D3
```

[[Return to contents]](#Contents)

```v
const tone_ds3 = C.TONE_DS3
```

[[Return to contents]](#Contents)

```v
const tone_e3 = C.TONE_E3
```

[[Return to contents]](#Contents)

```v
const tone_f3 = C.TONE_F3
```

[[Return to contents]](#Contents)

```v
const tone_fs3 = C.TONE_FS3
```

[[Return to contents]](#Contents)

```v
const tone_g3 = C.TONE_G3
```

[[Return to contents]](#Contents)

```v
const tone_gs3 = C.TONE_GS3
```

[[Return to contents]](#Contents)

```v
const tone_a3 = C.TONE_A3
```

[[Return to contents]](#Contents)

```v
const tone_as3 = C.TONE_AS3
```

[[Return to contents]](#Contents)

```v
const tone_b3 = C.TONE_B3
```

[[Return to contents]](#Contents)

```v
const tone_c4 = C.TONE_C4
```

[[Return to contents]](#Contents)

```v
const tone_cs4 = C.TONE_CS4
```

[[Return to contents]](#Contents)

```v
const tone_d4 = C.TONE_D4
```

[[Return to contents]](#Contents)

```v
const tone_ds4 = C.TONE_DS4
```

[[Return to contents]](#Contents)

```v
const tone_e4 = C.TONE_E4
```

[[Return to contents]](#Contents)

```v
const tone_f4 = C.TONE_F4
```

[[Return to contents]](#Contents)

```v
const tone_fs4 = C.TONE_FS4
```

[[Return to contents]](#Contents)

```v
const tone_g4 = C.TONE_G4
```

[[Return to contents]](#Contents)

```v
const tone_gs4 = C.TONE_GS4
```

[[Return to contents]](#Contents)

```v
const tone_a4 = C.TONE_A4
```

[[Return to contents]](#Contents)

```v
const tone_as4 = C.TONE_AS4
```

[[Return to contents]](#Contents)

```v
const tone_b4 = C.TONE_B4
```

[[Return to contents]](#Contents)

```v
const tone_c5 = C.TONE_C5
```

[[Return to contents]](#Contents)

```v
const tone_cs5 = C.TONE_CS5
```

[[Return to contents]](#Contents)

```v
const tone_d5 = C.TONE_D5
```

[[Return to contents]](#Contents)

```v
const tone_ds5 = C.TONE_DS5
```

[[Return to contents]](#Contents)

```v
const tone_e5 = C.TONE_E5
```

[[Return to contents]](#Contents)

```v
const tone_f5 = C.TONE_F5
```

[[Return to contents]](#Contents)

```v
const tone_fs5 = C.TONE_FS5
```

[[Return to contents]](#Contents)

```v
const tone_g5 = C.TONE_G5
```

[[Return to contents]](#Contents)

```v
const tone_gs5 = C.TONE_GS5
```

[[Return to contents]](#Contents)

```v
const tone_a5 = C.TONE_A5
```

[[Return to contents]](#Contents)

```v
const tone_as5 = C.TONE_AS5
```

[[Return to contents]](#Contents)

```v
const tone_b5 = C.TONE_B5
```

[[Return to contents]](#Contents)

```v
const tone_c6 = C.TONE_C6
```

[[Return to contents]](#Contents)

```v
const tone_cs6 = C.TONE_CS6
```

[[Return to contents]](#Contents)

```v
const tone_d6 = C.TONE_D6
```

[[Return to contents]](#Contents)

```v
const tone_ds6 = C.TONE_DS6
```

[[Return to contents]](#Contents)

```v
const tone_e6 = C.TONE_E6
```

[[Return to contents]](#Contents)

```v
const tone_f6 = C.TONE_F6
```

[[Return to contents]](#Contents)

```v
const tone_fs6 = C.TONE_FS6
```

[[Return to contents]](#Contents)

```v
const tone_g6 = C.TONE_G6
```

[[Return to contents]](#Contents)

```v
const tone_gs6 = C.TONE_GS6
```

[[Return to contents]](#Contents)

```v
const tone_a6 = C.TONE_A6
```

[[Return to contents]](#Contents)

```v
const tone_as6 = C.TONE_AS6
```

[[Return to contents]](#Contents)

```v
const tone_b6 = C.TONE_B6
```

[[Return to contents]](#Contents)

```v
const tone_c7 = C.TONE_C7
```

[[Return to contents]](#Contents)

```v
const tone_cs7 = C.TONE_CS7
```

[[Return to contents]](#Contents)

```v
const tone_d7 = C.TONE_D7
```

[[Return to contents]](#Contents)

```v
const tone_ds7 = C.TONE_DS7
```

[[Return to contents]](#Contents)

```v
const tone_e7 = C.TONE_E7
```

[[Return to contents]](#Contents)

```v
const tone_f7 = C.TONE_F7
```

[[Return to contents]](#Contents)

```v
const tone_fs7 = C.TONE_FS7
```

[[Return to contents]](#Contents)

```v
const tone_g7 = C.TONE_G7
```

[[Return to contents]](#Contents)

```v
const tone_gs7 = C.TONE_GS7
```

[[Return to contents]](#Contents)

```v
const tone_a7 = C.TONE_A7
```

[[Return to contents]](#Contents)

```v
const tone_as7 = C.TONE_AS7
```

[[Return to contents]](#Contents)

```v
const tone_b7 = C.TONE_B7
```

[[Return to contents]](#Contents)

## duration
```v
fn duration() u16
```

[[Return to contents]](#Contents)

## frequency
```v
fn frequency() u16
```

[[Return to contents]](#Contents)

## mode
```v
fn mode() u8
```

[[Return to contents]](#Contents)

## play
```v
fn play(args ...any)
```

[[Return to contents]](#Contents)

## play_file
```v
fn play_file(args ...any) i8
```

Functions for accessing and modifying sound module features.

[[Return to contents]](#Contents)

## play_file_ex
```v
fn play_file_ex(args ...any) i8
```

[[Return to contents]](#Contents)

## play_tone
```v
fn play_tone(args ...any) i8
```

[[Return to contents]](#Contents)

## play_tone_ex
```v
fn play_tone_ex(args ...any) i8
```

[[Return to contents]](#Contents)

## play_tones
```v
fn play_tones(args ...any)
```

[[Return to contents]](#Contents)

## sample_rate
```v
fn sample_rate() u16
```

[[Return to contents]](#Contents)

## set_duration
```v
fn set_duration(args ...any)
```

[[Return to contents]](#Contents)

## set_flags
```v
fn set_flags(args ...any)
```

[[Return to contents]](#Contents)

## set_frequency
```v
fn set_frequency(args ...any)
```

[[Return to contents]](#Contents)

## set_mode
```v
fn set_mode(args ...any)
```

[[Return to contents]](#Contents)

## set_module_state
```v
fn set_module_state(args ...any)
```

[[Return to contents]](#Contents)

## set_sample_rate
```v
fn set_sample_rate(args ...any)
```

[[Return to contents]](#Contents)

## set_volume
```v
fn set_volume(args ...any)
```

[[Return to contents]](#Contents)

## stop
```v
fn stop()
```

[[Return to contents]](#Contents)

## volume
```v
fn volume() u8
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
