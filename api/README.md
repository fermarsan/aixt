---
page: index
title: API
index: API reference
---

# _Aixt_ API reference

## `pin` module (digital I/O)

requires:
```v
import pin { Pin }
```

### Pin setup

For configuring a pin it is necessary to create an instance of the struct `pin.Pin`.
```v
mut my_pin := Pin.new(id)
my_pin.setup(mode) 
```
- `id` could change depending on the microcontroller for instance `pin.b7`, `pin.gp7`, etc.

- `mode` must be `pin.input` or `pin.output`

### Pin output

Set a high level (logical `1`) to a pin.
```v
my_pin.high()
```

Set a low level (logical `0`) to a pin.
```v
my_pin.low()
```

Toggle the level of a pin.
```v
my_pin.toggle() // not available for all devices
```

Write a logical value to a pin.
```v
my_pin.write(value)
```
- `value` is an integer to be written in the pin (`0` or `1`).

### Pin input

Read the logical value of an input pin.
```v
x = my_pin.read()
```
`.read()` returns an integer (`0` or `1`)


## `pin_fn` module (digital I/O functional version)
requires:
```v
import pin_fn as pin
```

### Pin setup
```v
pin.setup(id, mode)
```
- `id` could change depending on the microcontroller for instance `pin.b7`, `pin.gp7`, etc.

- `mode` must be `pin.input` or `pin.output`

### Pin output

Set a high level (logical `1`) to a pin.
```v
pin.high(id)
```

Set a low level (logical `0`) to a pin.
```v
pin.low(id)
```

Toggle the level of a pin.
```v
pin.toggle(id)    
// not available for all devices
```

Write a logical value to a pin.
```v
pin.write(name, value)
```
- `value` is an integer to be written in the pin (`0` or `1`).

### Pin input

Read the logical value of an input pin.
```v
x = pin.read(id)
```
`pin.read()` returns an integer (`0` or `1`)


## Analog to Digital Converter (ADC inputs)
requires:
```v
import adc
```

### ADC setup
```v
adc.setup(setup_value_1, setup_value_2, ... )
```

### ADC reading
```v
x = adc.read(channel)
```
- `channel` is an identifying number of the ADC input, for instance `adc.ch3`


## Pulse Width Modulation (PWM outputs)
requires:
```v
import pwm
```

### PWM setup
```v
pwm.setup(setup_value_1, setup_value_2, ... )  //or just pwm.setup(...)
```

### PWM duty cycle
```v
pwm.write(channel, duty)  //or pwm1_duty(duty)
```

- `duty` is the duty cycle (8-bit number in most of devices)
- `channel` is th output or channel name, for instance `pwm.ch1`


## Serial communication (UART)
requires:
```v
import uart
```

The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx.function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart.setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configure the communication speed

### Serial receiving
```v
str1 = uart.input()     // read a string from the default UART
```
```v
str2 = uart2.input()    // read a string from UART2
```
```v
str2 = uart1.read()     // read a single Byte from UART1
```

### Serial transmitting
```v
uart.print(message)     // print a string to the default UART
```
```v
uart.println(message)   // print a string plus a line-new character to the default UART
```
```v
uart2.print(message)    // print a string to the UART2
```
```v
uart3.println(message)  // print a string plus a line-new character to the UART3
```
```v
uart2.write(message)    // send binary data (in Bytes) to UART2
```


## Delay
requires:
```v
import time
```


```v
time.sleep(s)         // delay in seconds
```

```v
time.sleep_ms(ms)    // delay in milliseconds
```

```v
time.sleep_us(us)    // delay in microseconds
```
