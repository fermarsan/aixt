# module port


## Contents
- [b_pullups](#b_pullups)
- [read](#read)
- [setup](#setup)
- [write](#write)

## b_pullups
```v
fn b_pullups(enable bool)
```

b_pullups function enable or disable the pull up resistors of PORTB `enable` must be `false` or `true`

[[Return to contents]](#Contents)

## read
```v
fn read(id u8) u8
```

read function reads an 8-bit `value` from a port. `id` is the port id, for example `port.c`.

[[Return to contents]](#Contents)

## setup
```v
fn setup(id u8, mode u8)
```

setup function configures bit by bit the pin mode of a 8-bit port. `id` is the port id, for example `port.c`, `mode` is a byte that defines which pin is input (`1`) or output (`0`), for example `0b00001111` configures the 4 MSBs as outputs and the rest as inputs.

[[Return to contents]](#Contents)

## write
```v
fn write(id u8, value u8)
```

write function writes an 8-bit `value` on a port. `id` is the port id, for example `port.c`.

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 28 Dec 2025 16:52:38
