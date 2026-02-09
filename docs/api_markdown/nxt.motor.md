# module nxt.motor


## Contents
- [Constants](#Constants)
- [pwn_freq](#pwn_freq)
- [regulation_options](#regulation_options)
- [regulation_time](#regulation_time)
- [set_pwn_freq](#set_pwn_freq)
- [set_regulation_options](#set_regulation_options)
- [set_regulation_time](#set_regulation_time)
- [Motor.new](#Motor.new)
- [Motor](#Motor)
  - [write_sync_pid](#write_sync_pid)
  - [write_sync_ex_pid](#write_sync_ex_pid)
  - [write_reg_pid](#write_reg_pid)
  - [write_reg_ex_pid](#write_reg_ex_pid)
  - [off](#off)
  - [coast](#coast)
  - [off_ex](#off_ex)
  - [coast_ex](#coast_ex)
  - [float](#float)
  - [write](#write)
  - [write_ex](#write_ex)
  - [write_reg](#write_reg)
  - [write_reg_ex](#write_reg_ex)
  - [write_sync](#write_sync)
  - [write_sync_ex](#write_sync_ex)
  - [rotate](#rotate)
  - [rotate_pid](#rotate_pid)
  - [rotate_ex](#rotate_ex)
  - [rotate_ex_pid](#rotate_ex_pid)
  - [reset_tacho_count](#reset_tacho_count)
  - [reset_block_tacho_count](#reset_block_tacho_count)
  - [reset_rotation_count](#reset_rotation_count)
  - [reset_all_tacho_counts](#reset_all_tacho_counts)
  - [mode](#mode)
  - [power](#power)
  - [actual_speed](#actual_speed)
  - [tacho_count](#tacho_count)
  - [tacho_limit](#tacho_limit)
  - [run_state](#run_state)
  - [turn_ratio](#turn_ratio)
  - [regulation](#regulation)
  - [overload](#overload)
  - [reg_p](#reg_p)
  - [read_reg_i](#read_reg_i)
  - [reg_d](#reg_d)
  - [block_tacho_count](#block_tacho_count)
  - [rotation_count](#rotation_count)
  - [output_options](#output_options)
  - [max_speed](#max_speed)
  - [max_acceleration](#max_acceleration)
  - [enable_pos_reg](#enable_pos_reg)
  - [set_angle_pos_reg](#set_angle_pos_reg)
  - [add_angle_pos_reg](#add_angle_pos_reg)
  - [set_max_pos_reg](#set_max_pos_reg)

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

## pwn_freq
```v
fn pwn_freq() u8
```

[[Return to contents]](#Contents)

## regulation_options
```v
fn regulation_options() u8
```

[[Return to contents]](#Contents)

## regulation_time
```v
fn regulation_time() u8
```

[[Return to contents]](#Contents)

## set_pwn_freq
```v
fn set_pwn_freq(n u8)
```

[[Return to contents]](#Contents)

## set_regulation_options
```v
fn set_regulation_options(n u8)
```

[[Return to contents]](#Contents)

## set_regulation_time
```v
fn set_regulation_time(n u8)
```

[[Return to contents]](#Contents)

## Motor.new
```v
fn Motor.new(id u8) Motor
```

new returns a new Motor instance

[[Return to contents]](#Contents)

## Motor
```v
struct Motor {
mut:
	id int
}
```

Motor struct

[[Return to contents]](#Contents)

## write_sync_pid
```v
fn (mut m Motor) write_sync_pid(pwr i8, turnpct i8, p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## write_sync_ex_pid
```v
fn (mut m Motor) write_sync_ex_pid(pwr i8, turnpct i8, reset u8, p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## write_reg_pid
```v
fn (mut m Motor) write_reg_pid(pwr i8, regmode u8, p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## write_reg_ex_pid
```v
fn (mut m Motor) write_reg_ex_pid(pwr i8, regmode u8, reset u8, p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## off
```v
fn (mut m Motor) off()
```

[[Return to contents]](#Contents)

## coast
```v
fn (mut m Motor) coast()
```

[[Return to contents]](#Contents)

## off_ex
```v
fn (mut m Motor) off_ex(reset u8)
```

[[Return to contents]](#Contents)

## coast_ex
```v
fn (mut m Motor) coast_ex(reset u8)
```

[[Return to contents]](#Contents)

## float
```v
fn (mut m Motor) float()
```

[[Return to contents]](#Contents)

## write
```v
fn (mut m Motor) write(pwr i8)
```

[[Return to contents]](#Contents)

## write_ex
```v
fn (mut m Motor) write_ex(pwr i8, reset u8)
```

[[Return to contents]](#Contents)

## write_reg
```v
fn (mut m Motor) write_reg(pwr i8, regmode u8)
```

[[Return to contents]](#Contents)

## write_reg_ex
```v
fn (mut m Motor) write_reg_ex(pwr i8, regmode u8, reset u8)
```

[[Return to contents]](#Contents)

## write_sync
```v
fn (mut m Motor) write_sync(pwr i8, turnpct i8)
```

[[Return to contents]](#Contents)

## write_sync_ex
```v
fn (mut m Motor) write_sync_ex(pwr i8, turnpct i8, reset u8)
```

[[Return to contents]](#Contents)

## rotate
```v
fn (mut m Motor) rotate(pwr i8, angle int)
```

[[Return to contents]](#Contents)

## rotate_pid
```v
fn (mut m Motor) rotate_pid(pwr i8, angle int, p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## rotate_ex
```v
fn (mut m Motor) rotate_ex(pwr i8, angle int, turnpct i8, sync bool, stop bool)
```

[[Return to contents]](#Contents)

## rotate_ex_pid
```v
fn (mut m Motor) rotate_ex_pid(pwr i8, angle int, turnpct i8, sync bool, stop bool, p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## reset_tacho_count
```v
fn (mut m Motor) reset_tacho_count()
```

[[Return to contents]](#Contents)

## reset_block_tacho_count
```v
fn (mut m Motor) reset_block_tacho_count()
```

[[Return to contents]](#Contents)

## reset_rotation_count
```v
fn (mut m Motor) reset_rotation_count()
```

[[Return to contents]](#Contents)

## reset_all_tacho_counts
```v
fn (mut m Motor) reset_all_tacho_counts()
```

[[Return to contents]](#Contents)

## mode
```v
fn (mut m Motor) mode() u8
```

[[Return to contents]](#Contents)

## power
```v
fn (mut m Motor) power() i8
```

[[Return to contents]](#Contents)

## actual_speed
```v
fn (mut m Motor) actual_speed() i8
```

[[Return to contents]](#Contents)

## tacho_count
```v
fn (mut m Motor) tacho_count() int
```

[[Return to contents]](#Contents)

## tacho_limit
```v
fn (mut m Motor) tacho_limit() int
```

[[Return to contents]](#Contents)

## run_state
```v
fn (mut m Motor) run_state() u8
```

[[Return to contents]](#Contents)

## turn_ratio
```v
fn (mut m Motor) turn_ratio() i8
```

[[Return to contents]](#Contents)

## regulation
```v
fn (mut m Motor) regulation() u8
```

[[Return to contents]](#Contents)

## overload
```v
fn (mut m Motor) overload() bool
```

[[Return to contents]](#Contents)

## reg_p
```v
fn (mut m Motor) reg_p() u8
```

[[Return to contents]](#Contents)

## read_reg_i
```v
fn (mut m Motor) read_reg_i() u8
```

[[Return to contents]](#Contents)

## reg_d
```v
fn (mut m Motor) reg_d() u8
```

[[Return to contents]](#Contents)

## block_tacho_count
```v
fn (mut m Motor) block_tacho_count() int
```

[[Return to contents]](#Contents)

## rotation_count
```v
fn (mut m Motor) rotation_count() int
```

[[Return to contents]](#Contents)

## output_options
```v
fn (mut m Motor) output_options() u8
```

[[Return to contents]](#Contents)

## max_speed
```v
fn (mut m Motor) max_speed() u8
```

[[Return to contents]](#Contents)

## max_acceleration
```v
fn (mut m Motor) max_acceleration() u8
```

[[Return to contents]](#Contents)

## enable_pos_reg
```v
fn (mut m Motor) enable_pos_reg(p u8, i u8, d u8)
```

[[Return to contents]](#Contents)

## set_angle_pos_reg
```v
fn (mut m Motor) set_angle_pos_reg(angle int)
```

[[Return to contents]](#Contents)

## add_angle_pos_reg
```v
fn (mut m Motor) add_angle_pos_reg(angle_add int)
```

[[Return to contents]](#Contents)

## set_max_pos_reg
```v
fn (mut m Motor) set_max_pos_reg(max_speed u8, max_acceleration u8)
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
