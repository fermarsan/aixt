# Quick reference for the CH551 / CH552 boards

The original pin names can be found in the CH551/CH552
[Datasheet](https://akizukidenshi.com/goodsaffix/CH552.pdf).

> **Note**
>
> AIxt transpiles the source code into an Arduino `.ino` sketch.
>
> Currently, AIxt CH55x projects are compiled using the **CH55xDuino** core. Since the current workflow is not compatible with **Arduino CLI**, the generated `.ino` file must be opened in the **Arduino IDE** for compilation and uploading to the microcontroller.

---

## Delay and Timing

Use the `time` module:

```v
import time

time.sleep(2)         // sleep for 2 seconds
time.sleep_ms(50)     // sleep for 50 milliseconds
time.sleep_us(100)    // sleep for 100 microseconds
```

### Functions

| name | description |
|------|-------------|
| `time.sleep(time)` | Delay in seconds |
| `time.sleep_ms(time)` | Delay in milliseconds |
| `time.sleep_us(time)` | Delay in microseconds |

---

## Onboard Hardware

The onboard LED is named `led0`.

```v
import pin

pin.setup(pin.led0, pin.output)
pin.high(pin.led0)
```

The onboard LED is connected to **P3.0**.

---

## Pin module

Use the `pin` module:

```v
import pin

pin.setup(pin.p30, pin.output)

pin.high(pin.p30)
pin.low(pin.p30)

pin.write(pin.p30, pin.read(pin.p11))
```

### Functions

| name | description |
|------|-------------|
| `pin.setup(pin, mode)` | Configure `pin` as `mode` |
| `pin.high(pin)` | Set pin HIGH |
| `pin.low(pin)` | Set pin LOW |
| `pin.write(pin, value)` | Write `value` to `pin` |
| `pin.read(pin)` | Read the state of `pin` |

### Digital pin names

| name | CH551 |
|:----:|:----------:|
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

---

## Port module

Use the `port` module:

```v
import port

port.setup(port.b, port.all_outputs)
```

### Functions

| name | description |
|------|-------------|
| `port.setup(port, mode)` | Configure a port |
| `port.read(port)` | Read port value |
| `port.write(port, value)` | Write port value |

### Port names

| name | Port |
|:----:|:----:|
| `b` | Port B |
| `c` | Port C |
| `d` | Port D |

---

## PWM (Pulse Width Modulation)

Use the `pwm` module:

```v
import pwm

pwm.write(pwm.ch1_1, 128)
pwm.write(pwm.ch2_1, 64)
```

### Functions

| name | description |
|------|-------------|
| `pwm.write(channel, value)` | Write `value` to the PWM `channel` |

### PWM channel names

| name | CH551 |
|:----:|:----:|
| `ch1_1` | P1.5 |
| `ch1_2` | P3.0 |
| `ch2_1` | P3.1 |
| `ch2_2` | P3.4 |

---

## ADC (Analog-to-Digital Converter)

Use the `adc` module:

```v
import adc

value1 := adc.read(adc.ch0)
value2 := adc.read(adc.ch1)
```

### Functions

| name | description |
|------|-------------|
| `adc.read(channel)` | Return the ADC value |

### ADC channel names

| name | CH551 |
|:----:|:----:|
| `ch0` | P1.1 |
| `ch1` | P1.4 |
| `ch2` | P1.5 |
| `ch3` | P3.2 |

---

## UART (USB Serial)

The `uart` module uses the **USBSerial** interface provided by **CH55xDuino**.

### Functions

| name | description |
|------|-------------|
| `uart.setup(baud_rate)` | Initialize the USBSerial interface with the specified baud rate. |
| `uart.any()` | Return the number of bytes available for reading from USBSerial. |
| `uart.read()` | Read one byte from USBSerial. |
| `uart.write(character)` | Send one byte through USBSerial. |
| `uart.print(message)` | Send a string through USBSerial. |
| `uart.println(message)` | Send a string followed by CR/LF through USBSerial. |
### Note

The `uart` module uses the **USBSerial** interface provided by **CH55xDuino**.

Unlike standard Arduino boards, USB communication is **not** implemented through the `Serial` object.

---

## Examples

### Blinking (LED)

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
### INVERTER (LED)

```v
import time
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
import adc
import adc_fn
import pin_fn as pin

pin.setup(pin.led0, pin.output)

for {
    // Leer el canal ADC0 (P1.1)
    value := adc_fn.read(adc.ch0)

    // Comparar el valor leído
    if value > 127 {
        pin.high(pin.led0)
    } else {
        pin.low(pin.led0)
    }

    // Esperar 20 ms
    time.sleep_ms(20)
}

```
---

### BREATHING (PWM)

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

### ANALOG ECHO (ADC - PWM)

```v
## References

- CH551/CH552 Datasheet
- CH55xDuino
- CH55xDuino HardwareSerial (`USBSerial`)