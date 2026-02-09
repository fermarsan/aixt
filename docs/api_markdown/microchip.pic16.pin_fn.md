# module microchip.pic16.pin_fn


## Contents
- [high](#high)
- [low](#low)
- [read](#read)
- [setup](#setup)
- [toggle](#toggle)
- [write](#write)

## high
```v
fn high(id u8)
```

high function puts a logic `1` to a pin through its `id`

[[Return to contents]](#Contents)

## low
```v
fn low(id u8)
```

low function puts a logic `0` to a pin through its `id`

[[Return to contents]](#Contents)

## read
```v
fn read(id u8) u8
```

read function reads the logic value of a pin pin through its `id`

[[Return to contents]](#Contents)

## setup
```v
fn setup(id u8, mode u8)
```

setup function configures the mode of a pin. `id` is the pin id for example `pin.c7` and `mode` is the pin mode, `pin.input` or `pin.output`.

[[Return to contents]](#Contents)

## toggle
```v
fn toggle(id u8)
```

toggle function toggles the logic `value` of a pin through its `id`

[[Return to contents]](#Contents)

## write
```v
fn write(id u8, value u8)
```

write function writes a logic `value` to a pin through its `id`

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
