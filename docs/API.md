# **_Aixt_** Application Programming Interface v0.1.2

## Digital I/O (Pins)
requires:
```v
import pin
```

### Pin setup
```v
pin.setup(pin_name, mode)
```
- `pin_name` could change depending on the microcontroller for instance `pin.b7`, `pin.gp7`, etc.
- `mode`:
  - `pin.input`
  - `pin.output`

### Pin output
```v
pin.high(pin_name)
```
```v
pin.low(pin_name)
```
```v
pin.toggle(pin_name)    
// not available for all devices
```
```v
pin.write(pin_name, value)
```
- `value` is an integer to be written in the pin
  - `0`
  - `1`


### Pin input
```v
x = pin.read(pin_name)
```
`pin.read()` returns an integer (`0` or `1`)

## Analog to Digital Converter (ADC inputs)
requires:
```v
import adc
```


The syntax for all the ADC functions is: `adcx_function_name()`, being `x` the identifying number in case of multiple ADCs. You can omit the `x` for referring to the first ADC or in the case of having only one.

### ADC setup
```v
adc.setup(setup_value_1, setup_value_2, ... )   // equals to adc1_setup(...)
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

The syntax for all the PWM functions is: `pwm_function_name()`.

### PWM setup
```v
pwm_setup(setup_value_1, setup_value_2, ... )  //or just pwm.setup(...)
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

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart.setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configure the communication speed

### Serial receiving
```v
str1 = input()          // read a string from the default UART
```
```v
str2 = uart2_input()    // read a string from UART2
```
```v
str2 = uart1_read()    // read a single Byte from UART1
```

### Serial transmitting
```v
uart.print(message)      // print a string to the default UART
```
```v
uart.println(message)    // print a string plus a line-new character to the default UART
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


## Timming
requires:
```v
import time
```


```v
time.sleep(s)    // delay in seconds
```
```v
time.sleep_ms(ms)    // delay in milliseconds
```
```v
time.sleep_us(us)    // delay in microseconds
```