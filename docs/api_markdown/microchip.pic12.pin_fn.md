# module microchip.pic12.pin_fn


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
const io0 = 0 // pin `id`s as macros
```

[[Return to contents]](#Contents)

```v
const io1 = 1
```

[[Return to contents]](#Contents)

```v
const io2 = 2
```

[[Return to contents]](#Contents)

```v
const io3 = 3
```

[[Return to contents]](#Contents)

```v
const io4 = 4
```

[[Return to contents]](#Contents)

```v
const io5 = 5
```

[[Return to contents]](#Contents)

```v
const irq = 2 // IRQ (INT) pin
```

[[Return to contents]](#Contents)

```v
const output = 0 // pin `mode`s as macros
```

[[Return to contents]](#Contents)

```v
const input = 1
```

[[Return to contents]](#Contents)

## high
```v
fn high(id u8)
```

high function puts a logical `1` to a pin by its `id`

[[Return to contents]](#Contents)

## low
```v
fn low(id u8)
```

low function puts a logical `0` to a pin by its `id`

[[Return to contents]](#Contents)

## read
```v
fn read(id u8) u8
```

read function reads the logic `value` of a pin by its `id`

[[Return to contents]](#Contents)

## setup
```v
fn setup(id u8, mode u8)
```

setup fucntion configures the `mode` of a pin (by `id`)

[[Return to contents]](#Contents)

## toggle
```v
fn toggle(id u8)
```

toggle function toggles the logic value of a pin by its `id`

[[Return to contents]](#Contents)

## write
```v
fn write(id u8, value u8)
```

write function writes a logical `value` to a pin by its `ìd`

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
