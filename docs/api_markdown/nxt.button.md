# module nxt.button


## Contents
- [Constants](#Constants)
- [read_sys](#read_sys)
- [Button.new](#Button.new)
- [Button](#Button)
  - [read](#read)
  - [count](#count)
  - [read_ex](#read_ex)
  - [press_count](#press_count)
  - [long_press_count](#long_press_count)
  - [short_release_count](#short_release_count)
  - [long_release_count](#long_release_count)
  - [release_count](#release_count)
  - [state](#state)
  - [set_long_press_count](#set_long_press_count)
  - [set_long_release_count](#set_long_release_count)
  - [set_press_count](#set_press_count)
  - [set_release_count](#set_release_count)
  - [set_short_release_count](#set_short_release_count)
  - [set_state](#set_state)

## Constants
```v
const btn1 = u8(0)
```

Constants that are part of the NXT firmware's Button module.

[[Return to contents]](#Contents)

```v
const btn2 = u8(1)
```

[[Return to contents]](#Contents)

```v
const btn3 = u8(2)
```

[[Return to contents]](#Contents)

```v
const btn4 = u8(3)
```

[[Return to contents]](#Contents)

```v
const no_btns = u8(4)
```

[[Return to contents]](#Contents)

```v
const exit = u8(0)
```

[[Return to contents]](#Contents)

```v
const right = u8(1)
```

[[Return to contents]](#Contents)

```v
const left = u8(2)
```

[[Return to contents]](#Contents)

```v
const center = u8(3)
```

[[Return to contents]](#Contents)

```v
const pressed = 0x01
```

Constants for use with the ButtonState() function.

[[Return to contents]](#Contents)

```v
const short_released = 0x02
```

[[Return to contents]](#Contents)

```v
const long_pressed = 0x04
```

[[Return to contents]](#Contents)

```v
const long_released = 0x08
```

[[Return to contents]](#Contents)

```v
const pressed_state = 0x80
```

[[Return to contents]](#Contents)

```v
const _none = 0x10
```

[[Return to contents]](#Contents)

## read_sys
```v
fn read_sys(args ...any)
```

[[Return to contents]](#Contents)

## Button.new
```v
fn Button.new(id u8) Sensor
```

new returns a new Sensor instance

[[Return to contents]](#Contents)

## Button
```v
struct Button {
mut:
	id u8
}
```

Button struct

[[Return to contents]](#Contents)

## read
```v
fn (mut b Button) read(reset_count bool) bool
```

Functions for accessing and modifying Button module features.

[[Return to contents]](#Contents)

## count
```v
fn (mut b Button) count(reset_count bool) u8
```

[[Return to contents]](#Contents)

## read_ex
```v
fn (mut b Button) read_ex(reset bool, pressed &bool, count &u32) i8
```

[[Return to contents]](#Contents)

## press_count
```v
fn (mut b Button) press_count() u8
```

[[Return to contents]](#Contents)

## long_press_count
```v
fn (mut b Button) long_press_count() u8
```

[[Return to contents]](#Contents)

## short_release_count
```v
fn (mut b Button) short_release_count() u8
```

[[Return to contents]](#Contents)

## long_release_count
```v
fn (mut b Button) long_release_count() u8
```

[[Return to contents]](#Contents)

## release_count
```v
fn (mut b Button) release_count() u8
```

[[Return to contents]](#Contents)

## state
```v
fn (mut b Button) state() u8
```

[[Return to contents]](#Contents)

## set_long_press_count
```v
fn (mut b Button) set_long_press_count(n u8)
```

[[Return to contents]](#Contents)

## set_long_release_count
```v
fn (mut b Button) set_long_release_count(n u8)
```

[[Return to contents]](#Contents)

## set_press_count
```v
fn (mut b Button) set_press_count(n u8)
```

[[Return to contents]](#Contents)

## set_release_count
```v
fn (mut b Button) set_release_count(n u8)
```

[[Return to contents]](#Contents)

## set_short_release_count
```v
fn (mut b Button) set_short_release_count(n u8)
```

[[Return to contents]](#Contents)

## set_state
```v
fn (mut b Button) set_state(state u8)
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
