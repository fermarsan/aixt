# module microchip.pic12.port


## Contents
- [Constants](#Constants)
- [read](#read)
- [setup](#setup)
- [write](#write)

## Constants
```v
const all_inputs = 0b11111111 // port common modes
```

[[Return to contents]](#Contents)

```v
const all_outputs = 0b00000000
```

[[Return to contents]](#Contents)

## read
```v
fn read() u8
```

read function reads an 8 bit value from a port

[[Return to contents]](#Contents)

## setup
```v
fn setup(mode u8)
```

setup configures bit by bit the pin mode of a 8 bit port

[[Return to contents]](#Contents)

## write
```v
fn write(value u8)
```

write function writes an 8 bit value on a port

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
