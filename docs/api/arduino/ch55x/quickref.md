# Quick reference for the CH551 / CH552 board

The CH551 support in AIxt is based on the **CH55xDuino** core. AIxt transpiles V source code into an Arduino `.ino` sketch, which must be opened with the Arduino IDE for compilation and programming.

The original pin names can be found in the CH552/CH551 [Datasheet](https://akizukidenshi.com/goodsaffix/CH552.pdf) published by WCH.


## Delay and Timing

### Functions

| name                  | description           |
|-----------------------|-----------------------|
| `time.sleep(time)`    | Delay in seconds      |
| `time.sleep_ms(time)` | Delay in milliseconds |
| `time.sleep_us(time)` | Delay in microseconds |


## Onboard Hardware

The onboard LED is named `led0`.

```v
import pin_fn as pin

pin.setup(pin.led0, pin.output)
pin.high(pin.led0)
```
The onboard LED is connected to **P3.0**

## Pin module

### Functions

| name                    | description               |
|-------------------------|---------------------------|
| `pin.setup(pin, mode)`  | Configure `pin` as `mode` |
| `pin.high(pin)`         | Turn on `pin`             |
| `pin.low(pin)`          | Turn off `pin`            |
| `pin.write(pin, value)` | Write `value` to `pin`    |
| `pin.read(pin)`         | Return the state of `pin` |

### Modes

| name | description |
|------|-------------|
| `input` | Digital input |
| `output` | Digital output |
| `in_pullup` | Input with pull-up resistor |
| `in_pulldown` | Input with pull-down resistor (if supported) |

### Digital names

| name | pin CH55X |
|:----:|:------------:|
| `p11` | P1.1 |
| `p14` | P1.4 |
| `p15` | P1.5 |
| `p16` | P1.6 |
| `p17` | P1.7 |
| `p30` | P3.0 |
| `p31` | P3.1 |
| `p32` | P3.2 |
| `p33` | P3.3 |
| `p34` | P3.4 |
| `led0` | P3.0 (onboard LED) |


## PWM (Pulse Width Modulation)

### Functions

| name | description |
|------|-------------|
| `pwm.setup_pin(channel)` | Configure PWM output pin |
| `pwm.write(channel, value)` | Write PWM duty cycle |

### Channels

| name | pin CH55X |
|:----:|:------------:|
| `ch1_1` | P1.5 |
| `ch1_2` | P3.0 |
| `ch2_1` | P3.1 |
| `ch2_2` | P3.4 |


## ADC (Analog to Digital Converter)

### Functions

| name | description |
|------|-------------|
| `adc.read(channel)` | Read the ADC value from `channel` |

### channels

| name | pin CH55X |
|:----:|:------------:|
| `ch0` | P1.1 |
| `ch1` | P1.4 |
| `ch2` | P1.5 |
| `ch3` | P3.2 |

> **Note**
>
> The CH55xDuino implementation returns an 8-bit ADC value (0–255).


## UART (USB Serial)

### Functions

| name | description |
|------|-------------|
| `uart.setup(baud_rate)` | Initialize USB Serial |
| `uart.read()` | Read one received byte |
| `uart.write(character)` | Send one byte |
| `uart.print(message)` | Send a string |
| `uart.println(message)` | Send a string followed by CR (Carriage Return) /LF (Line Feed) |
| `uart.any()` | Return the number of received bytes |

> **Note**
>
> The `uart` module uses the **USBSerial** interface provided by the [**CH55xDuino**](https://github.com/DeqingSun/ch55xduino/blob/ch55xduino/ch55xduino/ch55x/cores/ch55xduino/HardwareSerial.h) core.

> Unlike standard Arduino boards, USB communication is **not** implemented through the `Serial` object.


## Examples

### LED Blinking

```v
import time
import pin_fn as pin

pin.setup(pin.p30, pin.output)

for {
    pin.high(pin.p30)
    time.sleep_ms(500)

    pin.low(pin.p30)
    time.sleep_ms(500)
}
```

---

### Inverter (Digital Input )

```v
import pin_fn as pin

pin.setup(pin.p14, pin.input)

for {
    if pin.read(pin.p14) == 1 {
        pin.low(pin.led0)
    } else {
        pin.high(pin.led0)
    }
}
```

---

### ADC

```v
import time
import adc_fn as adc
import pin_fn as pin

pin.setup(pin.led0, pin.output)

for {
    value := adc.read(adc.ch0)

    if value > 127 {
        pin.high(pin.led0)
    } else {
        pin.low(pin.led0)
    }

    time.sleep_ms(20)
}
```

---

### Analog Echo

```v
import time
import adc_fn as adc
import pwm_fn as pwm

pwm.setup_pin(pwm.ch2_2)

for {
    value := adc.read(adc.ch0)

    pwm.write(pwm.ch2_2, u8(value))

    time.sleep_ms(10)
}
```

---

### Breathing (PWM - LED)

```v
import time
import pin_fn as pin
import pwm_fn as pwm

pin.setup(pwm.ch1_1, pin.output)

for {
    for level in 0 .. 256 {
        pwm.write(pwm.ch1_1, level)
        time.sleep_ms(5)
    }

    for level in 0 .. 256 {
        pwm.write(pwm.ch1_1, 255 - level)
        time.sleep_ms(5)
    }

    time.sleep_ms(100)
}
```

---

### Message (USB Serial)

```v
import time
import uart

for {
    uart.println("ch551")
    time.sleep_ms(500)
}
```

## Notes

- AIxt transpiles V source files into an Arduino `.ino` sketch.
- The generated `.ino` file must be opened in the Arduino IDE.
- The current CH551 implementation is based on the **CH55xDuino** core.
- Compilation and programming are performed using the Arduino IDE with the CH55xDuino board package.
- USB serial communication is implemented through the **USBSerial** interface provided by CH55xDuino.

## References

- [CH551/CH552 Datasheet] (https://akizukidenshi.com/goodsaffix/CH552.pdf)
- [CH55xDuino] (https://github.com/DeqingSun/ch55xduino/blob/ch55xduino/README.md)
- [CH55xDuino HardwareSerial (`USBSerial`)](https://github.com/DeqingSun/ch55xduino/blob/ch55xduino/ch55xduino/ch55x/cores/ch55xduino/HardwareSerial.h)
