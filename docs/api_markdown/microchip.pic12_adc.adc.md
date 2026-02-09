# module microchip.pic12_adc.adc


## Contents
- [Constants](#Constants)
- [read](#read)
- [read_byte](#read_byte)
- [setup](#setup)

## Constants
```v
const all_analogs = u8(0b0000) // ADC analog pins
```

[[Return to contents]](#Contents)

```v
const all_analogs_rp = u8(0b0001)
```

[[Return to contents]](#Contents)

```v
const in0_to_in4 = u8(0b0010)
```

[[Return to contents]](#Contents)

```v
const in0_to_in4_rp = u8(0b0011)
```

[[Return to contents]](#Contents)

```v
const in0_in1_in3 = u8(0b0100)
```

[[Return to contents]](#Contents)

```v
const in0_in1_rp = u8(0b0101)
```

[[Return to contents]](#Contents)

```v
const all_digitals = u8(0b0110)
```

[[Return to contents]](#Contents)

```v
const all_analogs_rp_rn = u8(0b1000)
```

[[Return to contents]](#Contents)

```v
const in0_to_in5 = u8(0b1001)
```

[[Return to contents]](#Contents)

```v
const in0_to_in5_rp = u8(0b1010)
```

[[Return to contents]](#Contents)

```v
const in0_to_in5_rp_rn = u8(0b1011)
```

[[Return to contents]](#Contents)

```v
const in0_to_in4_rp_rn = u8(0b1100)
```

[[Return to contents]](#Contents)

```v
const in0_in1_rp_rn = u8(0b1101)
```

[[Return to contents]](#Contents)

```v
const in0 = u8(0b1110)
```

[[Return to contents]](#Contents)

```v
const in0_rp_rn = u8(0b1111)
```

[[Return to contents]](#Contents)

```v
const bits_8 = u8(0) // ADC conversion bits
```

[[Return to contents]](#Contents)

```v
const bits_10 = u8(1)
```

[[Return to contents]](#Contents)

```v
const ch0 = 0 // ADC input channels
```

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

read function reads the full-bit ADC conversion in `channel`

[[Return to contents]](#Contents)

## read_byte
```v
fn read_byte(channel u8) u8
```

read_byte function reads a byte from the ADC conversion in `channel`

[[Return to contents]](#Contents)

## setup
```v
fn setup(pins u8, n_bits u8)
```

setup function configures the ADC. `pins` configures the analog pins and `n_bits` sets the 8-bit or 10-bit modes

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:31
