# module nxt.button


## Contents
- [Constants](#Constants)
- [count](#count)
- [long_press_count](#long_press_count)
- [long_release_count](#long_release_count)
- [press_count](#press_count)
- [read](#read)
- [read_ex](#read_ex)
- [read_sys](#read_sys)
- [release_count](#release_count)
- [set_long_press_count](#set_long_press_count)
- [set_long_release_count](#set_long_release_count)
- [set_press_count](#set_press_count)
- [set_release_count](#set_release_count)
- [set_short_release_count](#set_short_release_count)
- [set_state](#set_state)
- [short_release_count](#short_release_count)
- [state](#state)

## Constants
```v
const btn1 = 0
```

Constants that are part of the NXT firmware's Button module.

[[Return to contents]](#Contents)

```v
const btn2 = 1
```

[[Return to contents]](#Contents)

```v
const btn3 = 2
```

[[Return to contents]](#Contents)

```v
const btn4 = 3
```

[[Return to contents]](#Contents)

```v
const no_btns = 4
```

[[Return to contents]](#Contents)

```v
const exit = 0
```

[[Return to contents]](#Contents)

```v
const right = 1
```

[[Return to contents]](#Contents)

```v
const left = 2
```

[[Return to contents]](#Contents)

```v
const center = 3
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

## count
```v
fn count(args ...any) u8
```

[[Return to contents]](#Contents)

## long_press_count
```v
fn long_press_count(args ...any) u8
```

[[Return to contents]](#Contents)

## long_release_count
```v
fn long_release_count(args ...any) u8
```

[[Return to contents]](#Contents)

## press_count
```v
fn press_count(args ...any) u8
```

[[Return to contents]](#Contents)

## read
```v
fn read(args ...any) bool
```

Functions for accessing and modifying Button module features.

[[Return to contents]](#Contents)

## read_ex
```v
fn read_ex(args ...any) i8
```

[[Return to contents]](#Contents)

## read_sys
```v
fn read_sys(args ...any)
```

[[Return to contents]](#Contents)

## release_count
```v
fn release_count(args ...any) u8
```

[[Return to contents]](#Contents)

## set_long_press_count
```v
fn set_long_press_count(args ...any)
```

[[Return to contents]](#Contents)

## set_long_release_count
```v
fn set_long_release_count(args ...any)
```

[[Return to contents]](#Contents)

## set_press_count
```v
fn set_press_count(args ...any)
```

[[Return to contents]](#Contents)

## set_release_count
```v
fn set_release_count(args ...any)
```

[[Return to contents]](#Contents)

## set_short_release_count
```v
fn set_short_release_count(args ...any)
```

[[Return to contents]](#Contents)

## set_state
```v
fn set_state(args ...any)
```

[[Return to contents]](#Contents)

## short_release_count
```v
fn short_release_count(args ...any) u8
```

[[Return to contents]](#Contents)

## state
```v
fn state(args ...any) u8
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
