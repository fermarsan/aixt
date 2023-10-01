# **_Aixt_** Application Programmimg Interface

## Digital I/O (Pins)
### Pin setup
```go
pin_mode(pin_name, mode)
```
- `pin_name` could change depending on the microcontroller.
- `mode`:
  - `in`
  - `out`

### Pin output
```go
pin_high(pin_name)
```
```go
pin_low(pin_name)
```
```go
pin_write(pin_name, value)
```
- `value` is an integer to be written in the pin
  - `0` or `low` 
  - `1` or `high`


### Pin input
```go
x = pin_read(pin_name)
```
`pin_read` returns an integer (`0` or `1`)

## Analog to Digital Converter (ADC inputs)

The syntax for all the ADC functions is: `adcx_function_name()`, being `x` the identifing number in case of multiple ADCs. You can ommit the `x` for refering to the first ADC or in the case of having only one.

### ADC setup
```go
adc_setup(setup_value_1, setup_value_2, ... )   // equals to adc1_setup(...)
```

### ADC reading
```go
x = adc_read(channel)
```
- `channel` is an identifing number of the ADC input
## Pulse Width Modulation (PWM outputs)

The syntax for all the PWM functions is: `pwmx_function_name()`, being `x` the identifing number in case of multiple PWM outputs. You can ommit the `x` for refering to the first PWM output or in the case of having only one.

### PWM setup
```go
pwm1_setup(setup_value_1, setup_value_2, ... )  //or just pwm_setup(...)
```

### PWM duty cycle
```go
pwm_duty(duty)  //or pwm1_duty(duty)
```

- `duty` is the duty cycle in percentage (0 - 100)

## Serial comunication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the especific dom¿cumentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifing number in case of multiple UARTs. You can ommit the `x` for refering to the first UART or in the case of having only one.  

### UART setup

```go
uart_setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configurate the comunication speed

### Serial receiving
```go
str1 = input()          // read a string from the default UART
```
```go
str2 = uart2_input()    // read a string from UART2
```

### Serial transmitting
```go
print(message)      // print a string to the default UART
```
```go
println(message)    // print a string plus a line-new character to the default UART
```
```go
uart2_print(message)    // print a string to the UART2
```
```go
uart1_println(message)  // print a string plus a line-new character to the UART1
```
## Timming
```go
sleep(s)    // delay in seconds
```
```go
sleep_ms(ms)    // delay in milliseconds
```
```go
sleep_us(us)    // delay in microseconds
```