# module microchip.pic24.port


## Contents
- [Constants](#Constants)
- [read](#read)
- [setup](#setup)
- [write](#write)

## Constants
```v
const all_inputs = 0b1111111111111111
```

port common modes

[[Return to contents]](#Contents)

```v
const all_outputs = 0b0000000000000000
```

[[Return to contents]](#Contents)

## read
```v
fn read(id u8) u16
```

read function reads an 8 bit value from a ports

[[Return to contents]](#Contents)

## setup
```v
fn setup(id u8, mode u16)
```

setup configures bit by bit the pin mode of a 8 bit port

[[Return to contents]](#Contents)

## write
```v
fn write(id u8, value u16)
```

write function writes an 8 bit value on a port

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
