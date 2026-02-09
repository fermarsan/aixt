# module nxt.motor_fn


## Contents
- [Constants](#Constants)
- [actual_speed](#actual_speed)
- [add_angle_pos_reg](#add_angle_pos_reg)
- [block_tacho_count](#block_tacho_count)
- [coast](#coast)
- [coast_ex](#coast_ex)
- [enable_pos_reg](#enable_pos_reg)
- [float](#float)
- [max_acceleration](#max_acceleration)
- [max_speed](#max_speed)
- [mode](#mode)
- [off](#off)
- [off_ex](#off_ex)
- [output_options](#output_options)
- [overload](#overload)
- [power](#power)
- [pwn_freq](#pwn_freq)
- [read_reg_i](#read_reg_i)
- [reg_d](#reg_d)
- [reg_p](#reg_p)
- [regulation](#regulation)
- [regulation_options](#regulation_options)
- [regulation_time](#regulation_time)
- [reset_all_tacho_counts](#reset_all_tacho_counts)
- [reset_block_tacho_count](#reset_block_tacho_count)
- [reset_rotation_count](#reset_rotation_count)
- [reset_tacho_count](#reset_tacho_count)
- [rotate](#rotate)
- [rotate_ex](#rotate_ex)
- [rotate_ex_pid](#rotate_ex_pid)
- [rotate_pid](#rotate_pid)
- [rotation_count](#rotation_count)
- [run_state](#run_state)
- [set_angle_pos_reg](#set_angle_pos_reg)
- [set_max_pos_reg](#set_max_pos_reg)
- [set_pwn_freq](#set_pwn_freq)
- [set_regulation_options](#set_regulation_options)
- [set_regulation_time](#set_regulation_time)
- [tacho_count](#tacho_count)
- [tacho_limit](#tacho_limit)
- [turn_ratio](#turn_ratio)
- [write](#write)
- [write_ex](#write_ex)
- [write_reg](#write_reg)
- [write_reg_ex](#write_reg_ex)
- [write_reg_ex_pid](#write_reg_ex_pid)
- [write_reg_pid](#write_reg_pid)
- [write_sync](#write_sync)
- [write_sync_ex](#write_sync_ex)
- [write_sync_ex_pid](#write_sync_ex_pid)
- [write_sync_pid](#write_sync_pid)

## Constants
```v
const a = 0x00
```

Output port constants are used when calling motor control API functions.

[[Return to contents]](#Contents)

```v
const b = 0x01
```

[[Return to contents]](#Contents)

```v
const c = 0x02
```

[[Return to contents]](#Contents)

```v
const ab = 0x03
```

[[Return to contents]](#Contents)

```v
const ac = 0x04
```

[[Return to contents]](#Contents)

```v
const bc = 0x05
```

[[Return to contents]](#Contents)

```v
const abc = 0x06
```

[[Return to contents]](#Contents)

```v
const regmode_idle = C.UT_REGMODE_IDLE
```

Use these constants to configure the desired regulation mode for the specified motor multi-motor synchronization, or position regulation

[[Return to contents]](#Contents)

```v
const regmode_speed = C.UT_REGMODE_SPEED
```

[[Return to contents]](#Contents)

```v
const regmode_sync = C.UT_REGMODE_SYNC
```

[[Return to contents]](#Contents)

```v
const regmode_pos = C.UT_REGMODE_POS
```

[[Return to contents]](#Contents)

## actual_speed
```v
fn actual_speed(args ...any) i8
```

[[Return to contents]](#Contents)

## add_angle_pos_reg
```v
fn add_angle_pos_reg(args ...any)
```

[[Return to contents]](#Contents)

## block_tacho_count
```v
fn block_tacho_count(args ...any) int
```

[[Return to contents]](#Contents)

## coast
```v
fn coast(args ...any)
```

[[Return to contents]](#Contents)

## coast_ex
```v
fn coast_ex(args ...any)
```

[[Return to contents]](#Contents)

## enable_pos_reg
```v
fn enable_pos_reg(args ...any)
```

[[Return to contents]](#Contents)

## float
```v
fn float(args ...any)
```

[[Return to contents]](#Contents)

## max_acceleration
```v
fn max_acceleration(args ...any) u8
```

[[Return to contents]](#Contents)

## max_speed
```v
fn max_speed(args ...any) u8
```

[[Return to contents]](#Contents)

## mode
```v
fn mode(args ...any) u8
```

[[Return to contents]](#Contents)

## off
```v
fn off(args ...any)
```

[[Return to contents]](#Contents)

## off_ex
```v
fn off_ex(args ...any)
```

[[Return to contents]](#Contents)

## output_options
```v
fn output_options(args ...any) u8
```

[[Return to contents]](#Contents)

## overload
```v
fn overload(args ...any) bool
```

[[Return to contents]](#Contents)

## power
```v
fn power(args ...any) i8
```

[[Return to contents]](#Contents)

## pwn_freq
```v
fn pwn_freq(args ...any) u8
```

[[Return to contents]](#Contents)

## read_reg_i
```v
fn read_reg_i(args ...any) u8
```

[[Return to contents]](#Contents)

## reg_d
```v
fn reg_d(args ...any) u8
```

[[Return to contents]](#Contents)

## reg_p
```v
fn reg_p(args ...any) u8
```

[[Return to contents]](#Contents)

## regulation
```v
fn regulation(args ...any) u8
```

[[Return to contents]](#Contents)

## regulation_options
```v
fn regulation_options(args ...any) u8
```

[[Return to contents]](#Contents)

## regulation_time
```v
fn regulation_time(args ...any) u8
```

[[Return to contents]](#Contents)

## reset_all_tacho_counts
```v
fn reset_all_tacho_counts(args ...any)
```

[[Return to contents]](#Contents)

## reset_block_tacho_count
```v
fn reset_block_tacho_count(args ...any)
```

[[Return to contents]](#Contents)

## reset_rotation_count
```v
fn reset_rotation_count(args ...any)
```

[[Return to contents]](#Contents)

## reset_tacho_count
```v
fn reset_tacho_count(args ...any)
```

[[Return to contents]](#Contents)

## rotate
```v
fn rotate(args ...any)
```

[[Return to contents]](#Contents)

## rotate_ex
```v
fn rotate_ex(args ...any)
```

[[Return to contents]](#Contents)

## rotate_ex_pid
```v
fn rotate_ex_pid(args ...any)
```

[[Return to contents]](#Contents)

## rotate_pid
```v
fn rotate_pid(args ...any)
```

[[Return to contents]](#Contents)

## rotation_count
```v
fn rotation_count(args ...any) int
```

[[Return to contents]](#Contents)

## run_state
```v
fn run_state(args ...any) u8
```

[[Return to contents]](#Contents)

## set_angle_pos_reg
```v
fn set_angle_pos_reg(args ...any)
```

[[Return to contents]](#Contents)

## set_max_pos_reg
```v
fn set_max_pos_reg(args ...any)
```

[[Return to contents]](#Contents)

## set_pwn_freq
```v
fn set_pwn_freq(args ...any)
```

[[Return to contents]](#Contents)

## set_regulation_options
```v
fn set_regulation_options(args ...any)
```

[[Return to contents]](#Contents)

## set_regulation_time
```v
fn set_regulation_time(args ...any)
```

[[Return to contents]](#Contents)

## tacho_count
```v
fn tacho_count(args ...any) int
```

[[Return to contents]](#Contents)

## tacho_limit
```v
fn tacho_limit(args ...any) int
```

[[Return to contents]](#Contents)

## turn_ratio
```v
fn turn_ratio(args ...any) i8
```

[[Return to contents]](#Contents)

## write
```v
fn write(args ...any)
```

[[Return to contents]](#Contents)

## write_ex
```v
fn write_ex(args ...any)
```

[[Return to contents]](#Contents)

## write_reg
```v
fn write_reg(args ...any)
```

[[Return to contents]](#Contents)

## write_reg_ex
```v
fn write_reg_ex(args ...any)
```

[[Return to contents]](#Contents)

## write_reg_ex_pid
```v
fn write_reg_ex_pid(args ...any)
```

[[Return to contents]](#Contents)

## write_reg_pid
```v
fn write_reg_pid(args ...any)
```

[[Return to contents]](#Contents)

## write_sync
```v
fn write_sync(args ...any)
```

[[Return to contents]](#Contents)

## write_sync_ex
```v
fn write_sync_ex(args ...any)
```

[[Return to contents]](#Contents)

## write_sync_ex_pid
```v
fn write_sync_ex_pid(args ...any)
```

[[Return to contents]](#Contents)

## write_sync_pid
```v
fn write_sync_pid(args ...any)
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
