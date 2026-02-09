# module m5stack.core.button


## Contents
- [Constants](#Constants)
- [is_pressed](#is_pressed)
- [is_released](#is_released)
- [last_change](#last_change)
- [pressed_for](#pressed_for)
- [pressed_for_ctime](#pressed_for_ctime)
- [read](#read)
- [released_for](#released_for)
- [was_pressed](#was_pressed)
- [was_released](#was_released)
- [was_released_for](#was_released_for)

## Constants
```v
const a_pin = u8(39)
```

[[Return to contents]](#Contents)

```v
const b_pin = u8(38)
```

[[Return to contents]](#Contents)

```v
const c_pin = u8(37)
```

[[Return to contents]](#Contents)

```v
const a = u8(0)
```

[[Return to contents]](#Contents)

```v
const b = u8(1)
```

[[Return to contents]](#Contents)

```v
const c = u8(2)
```

[[Return to contents]](#Contents)

## is_pressed
```v
fn is_pressed(btn u8) bool
```

[[Return to contents]](#Contents)

## is_released
```v
fn is_released(btn u8) bool
```

[[Return to contents]](#Contents)

## last_change
```v
fn last_change(btn u8)
```

[[Return to contents]](#Contents)

## pressed_for
```v
fn pressed_for(btn u8, ms u32) bool
```

[[Return to contents]](#Contents)

## pressed_for_ctime
```v
fn pressed_for_ctime(btn u8, ms u32, continuous_time u32) bool
```

[[Return to contents]](#Contents)

## read
```v
fn read(btn u8)
```

[[Return to contents]](#Contents)

## released_for
```v
fn released_for(btn u8, ms u32) bool
```

[[Return to contents]](#Contents)

## was_pressed
```v
fn was_pressed(btn u8) bool
```

[[Return to contents]](#Contents)

## was_released
```v
fn was_released(btn u8) bool
```

[[Return to contents]](#Contents)

## was_released_for
```v
fn was_released_for(btn u8, ms u32) bool
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:30
