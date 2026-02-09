# module arduino.core.pin_fn


## Contents
- [Constants](#Constants)
- [high](#high)
- [low](#low)
- [read](#read)
- [setup](#setup)
- [write](#write)

## Constants
```v
const input = u8(C.INPUT)
```

pin modes

[[Return to contents]](#Contents)

```v
const output = u8(C.OUTPUT)
```

[[Return to contents]](#Contents)

```v
const in_pullup = u8(C.INPUT_PULLUP)
```

[[Return to contents]](#Contents)

```v
const in_pulldown = u8(C.INPUT_PULLDOWN)
```

[[Return to contents]](#Contents)

## high
```v
fn high(id u8)
```

high puts a high value (logic 1) to a specific pin

[[Return to contents]](#Contents)

## low
```v
fn low(id u8)
```

low puts a low value (logic 0) to a specific pin

[[Return to contents]](#Contents)

## read
```v
fn read(id u8) u8
```

read function reads the value from a specified digital pin, either HIGH or LOW

[[Return to contents]](#Contents)

## setup
```v
fn setup(id u8, mode u8)
```

setup configures a pin's input/output mode

[[Return to contents]](#Contents)

## write
```v
fn write(id u8, val u8)
```

write puts a logic value to a specific pin

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:30
