# module microchip.pic16f6xx_14p.adc


## Contents
- [Constants](#Constants)
- [read](#read)
- [read_byte](#read_byte)
- [setup](#setup)

## Constants
```v
const in0 = u8(0b11111110)
```

ADC analog pins (are negated by join them with &&)

[[Return to contents]](#Contents)

```v
const in1 = u8(0b11111101)
```

[[Return to contents]](#Contents)

```v
const in2 = u8(0b11111011)
```

[[Return to contents]](#Contents)

```v
const in3 = u8(0b11110111)
```

[[Return to contents]](#Contents)

```v
const in4 = u8(0b11101111)
```

[[Return to contents]](#Contents)

```v
const in5 = u8(0b11011111)
```

[[Return to contents]](#Contents)

```v
const in6 = u8(0b10111111)
```

[[Return to contents]](#Contents)

```v
const in7 = u8(0b01111111)
```

[[Return to contents]](#Contents)

```v
const all_analogs = u8(0b00000000)
```

[[Return to contents]](#Contents)

```v
const all_digitals = u8(0b11111111)
```

[[Return to contents]](#Contents)

```v
const bits_8 = 0
```

ADC conversion bits

[[Return to contents]](#Contents)

```v
const bits_10 = 1
```

[[Return to contents]](#Contents)

```v
const ch0 = 0
```

ADC input channels

[[Return to contents]](#Contents)

```v
const ch1 = 1
```

[[Return to contents]](#Contents)

```v
const ch2 = 2
```

[[Return to contents]](#Contents)

```v
const ch3 = 3
```

[[Return to contents]](#Contents)

```v
const ch4 = 4
```

[[Return to contents]](#Contents)

```v
const ch5 = 5
```

[[Return to contents]](#Contents)

```v
const ch6 = 6
```

[[Return to contents]](#Contents)

```v
const ch7 = 7
```

[[Return to contents]](#Contents)

## read
```v
fn read(channel u8) u16
```

[[Return to contents]](#Contents)

## read_byte
```v
fn read_byte(channel u8) u8
```

[[Return to contents]](#Contents)

## setup
```v
fn setup(pins u8, nbits u8)
```

setup function configures de analog pins, the number of bits and the frequency of the ADC.

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
