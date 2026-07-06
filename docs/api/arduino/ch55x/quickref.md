# Quick reference for the CH551 / CH552 boards

The original pin names can be found in the CH551/CH552 [Datasheet](https://akizukidenshi.com/goodsaffix/CH552.pdf)

---

## Delay and Timing

Use the `time` module:

```v
import time

time.sleep(2)            // sleep for 2 seconds
time.sleep_ms(50)        // sleep for 50 milliseconds
time.sleep_us(100)       // sleep for 100 microseconds
```

### Functions

| name | description |
|-----------------------|-----------------------|
| `time.sleep(time)` | Delay in seconds |
| `time.sleep_us(time)` | Delay in microseconds |
| `time.sleep_ms(time)` | Delay in milliseconds |

---

## Onboard Hardware

The onboard LED is named `led0`.

```v
import pin

pin.setup(pin.led0, pin.output)
pin.high(pin.led0)
```

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
|-------------------------|---------------------------|
| `pin.setup(pin, mode)` | Configure `pin` as `mode` |
| `pin.high(pin)` | Turn On `pin` |
| `pin.low(pin)` | Turn Off `pin` |
| `pin.toggle(pin)` | Toggle `pin` |
| `pin.write(pin, value)` | Write `value` in `pin` |
| `pin.read(pin)` | Return the state of `pin` |

### Digital pin names

The digital GPIO supported by Aixt are:

| name | CH551 Pin |
|:----:|:---------:|
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

## PWM (Pulse Width Modulation)

Use the `pwm` module:

```v
import pwm_fn as pwm

pwm.write(pwm.ch1_1,128)
pwm.write(pwm.ch2_1,64)
```

### Functions

| name | description |
|-----------------------------|------------------------------------|
| `pwm.write(channel,value)` | Write `value` to the PWM `channel` |

### PWM channel names

| name | GPIO |
|:----:|:----:|
| `ch1_1` | P1.5 |
| `ch1_2` | P3.0 |
| `ch2_1` | P3.1 |
| `ch2_2` | P3.4 |

---

## ADC (Analog to Digital Converter)

Use the `adc` module:

```v
import adc_fn as adc

val1:=adc.read(adc.ch0)
val2:=adc.read(adc.ch1)
```

### Functions

| name | description |
|---------------------|-----------------------------------|
| `adc.read(channel)` | Return the ADC value |

### Analog channels

| name | GPIO |
|:----:|:----:|
| `ch0` | P1.1 |
| `ch1` | P1.4 |
| `ch2` | P1.5 |
| `ch3` | P3.2 |

---

## UART (Serial Port)

Use the `uart` module:

```v
import uart

uart.setup(115200)

uart.println('Hello CH551')
```

### Functions

| name | description |
|-------------------------|----------------------------------------------------------------|
| `uart.setup(baud)` | Configure UART baud rate |
| `uart.read()` | Read one byte |
| `uart.write(ch)` | Send one character |
| `uart.print(msg)` | Send string |
| `uart.println(msg)` | Send string plus newline |
| `uart.available()` | Return bytes available |

---

## Timer

Use the `timer` module:

```v
import timer

timer.delay_ms(500)
timer.delay_us(100)
```

### Functions

| name | description |
|-----------------------------|---------------------------|
| `timer.init()` | Initialize timer |
| `timer.start()` | Start timer |
| `timer.stop()` | Stop timer |
| `timer.reset()` | Reset timer |
| `timer.delay_ms()` | Delay in milliseconds |
| `timer.delay_us()` | Delay in microseconds |

---

## Examples

### LED Blinking

```v
import time
import pin

pin.setup(pin.led0,pin.output)

for{
    pin.toggle(pin.led0)
    time.sleep_ms(500)
}
```

---

### ADC value sent by UART

```v
import time
import uart
import adc_fn as adc

uart.setup(9600)

for{
    value:=adc.read(adc.ch0)
    uart.println('ADC channel 0: ${value}')
    time.sleep_ms(1000)
}
```

---

### UART Echo

```v
import uart

uart.setup(115200)

for{
    if uart.available()>0{
        c:=uart.read()
        uart.write(c)
    }
}
```

---

### PWM Example

```v
import pwm_fn as pwm

pwm.write(pwm.ch1_1,128)
```

---

### Timer Example

```v
import pin
import timer

pin.setup(pin.led0,pin.output)

for{
    pin.toggle(pin.led0)
    timer.delay_ms(500)
}
```