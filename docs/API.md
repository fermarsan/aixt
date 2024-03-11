# **_Aixt_** Application Programming Interface

## Digital I/O (Pins)
### Pin setup
```v
pin_setup(pin_name, mode)
```
- `pin_name` could change depending on the microcontroller.
- `mode`:
  - `in`
  - `out`

### Pin output
```v
pin_high(pin_name)
```
```v
pin_low(pin_name)
```
```v
pin_toggle(pin_name)    
// not available for all devices
```
```v
pin_write(pin_name, value)
```
- `value` is an integer to be written in the pin
  - `0` or `low` 
  - `1` or `high`


### Pin input
```v
x = pin_read(pin_name)
```
`pin_read` returns an integer (`0` or `1`)

## Analog to Digital Converter (ADC inputs)

The syntax for all the ADC functions is: `adcx_function_name()`, being `x` the identifying number in case of multiple ADCs. You can omit the `x` for referring to the first ADC or in the case of having only one.

### ADC setup
```v
adc_setup(setup_value_1, setup_value_2, ... )   // equals to adc1_setup(...)
```

### ADC reading
```v
x = adc_read(channel)
```
- `channel` is an identifying number of the ADC input
## Pulse Width Modulation (PWM outputs)

The syntax for all the PWM functions is: `pwmx_function_name()`, being `x` the identifying number in case of multiple PWM outputs. You can omit the `x` for referring to the first PWM output or in the case of having only one.

### PWM setup
```v
pwm1_setup(setup_value_1, setup_value_2, ... )  //or just pwm_setup(...)
```

### PWM duty cycle
```v
pwm_write(duty)  //or pwm1_duty(duty)
```

- `duty` is the duty cycle in percentage (0 - 100)

## Serial communication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart_setup(baud_rate)   // the same of uart1_setup(baud_rate)
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
print(message)      // print a string to the default UART
```
```v
println(message)    // print a string plus a line-new character to the default UART
```
```v
uart2_print(message)    // print a string to the UART2
```
```v
uart1_println(message)  // print a string plus a line-new character to the UART1
```
```v
uart2_write(message)    // send binary data (in Bytes) to UART2
```
## Timming
```v
sleep(s)    // delay in seconds
```
```v
sleep_ms(ms)    // delay in milliseconds
```
```v
sleep_us(us)    // delay in microseconds
```