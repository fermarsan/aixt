# module microchip.pic12f6xx.pwm


## Contents
- [Constants](#Constants)
- [setup](#setup)
- [write](#write)

## Constants
```v
const ch1 = 0b11111_01_1
```

PWM channels

[[Return to contents]](#Contents)

```v
const ch2 = 0b11111_10_1
```

[[Return to contents]](#Contents)

```v
const f_high = 0b000000_00
```

PWM frecuency

[[Return to contents]](#Contents)

```v
const f_med = 0b000000_01 // div by 4
```

[[Return to contents]](#Contents)

```v
const f_low = 0b000000_10 // div by 16
```

[[Return to contents]](#Contents)

## setup
```v
fn setup(channel u8, res u8, freq u8)
```

setup function configures the PWM

for a resolution of 100 steps by period (res = 100):

| fosc   | f_high   | f_med     | f_low    |
|--------|----------|-----------|----------|
| 20 Mhz | 50 khz   | 12.5 khz  | 3125 hz  |
| 16 Mhz | 40 khz   | 10 khz    | 2500 hz  |
| 12 Mhz | 30 khz   | 7.5 khz   | 1875 hz  |
| 10 Mhz | 25 khz   | 6.25 khz  | 1563 hz  |
| 8 Mhz  | 20 khz   | 5 khz     | 1250 hz  |
| 4 Mhz  | 10 khz   | 2.5 khz   | 625 hz   |

for a resolution of 100 steps by period (res = 250):

| fosc   | f_high   | f_med     | f_low    |
|--------|----------|-----------|----------|
| 20 Mhz | 20 khz   | 5 khz     | 1.25 khz |
| 16 Mhz | 16 khz   | 4 khz     | 1 khz    |
| 12 Mhz | 12 khz   | 3 khz     | 750 hz   |
| 10 Mhz | 10 khz   | 2.5 khz   | 625 hz   |
| 8 Mhz  | 8 khz    | 2 khz     | 500 hz   |
| 4 Mhz  | 4 khz    | 1 khz     | 250 hz   |


[[Return to contents]](#Contents)

## write
```v
fn write(channel u8, duty u8)
```

write function sets the 8-bit duty cycle to a PWM channel

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
