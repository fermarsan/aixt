# module microchip.pic24.pin_fn


## Contents
- [Constants](#Constants)
- [high](#high)
- [low](#low)
- [read](#read)
- [setup](#setup)
- [toggle](#toggle)
- [write](#write)

## Constants
```v
const input = u8(1)
```

pin modes

[[Return to contents]](#Contents)

```v
const output = u8(0)
```

[[Return to contents]](#Contents)

## high
```v
fn high(id u8)
```

high puts a logic 1 to a pin

[[Return to contents]](#Contents)

## low
```v
fn low(id u8)
```

low puts a logic 0 to a pin

[[Return to contents]](#Contents)

## read
```v
fn read(id u8) u8
```

read function reads the logic value of a pin

[[Return to contents]](#Contents)

## setup
```v
fn setup(id u8, mode u8)
```

setup configures the `mode` of a pin (by `id`)

[[Return to contents]](#Contents)

## toggle
```v
fn toggle(id u8)
```

toggle function toggles the logic value of a pin

[[Return to contents]](#Contents)

## write
```v
fn write(id u8, value u8)
```

write function writes a logical `value` to a pin by its `ìd`

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
