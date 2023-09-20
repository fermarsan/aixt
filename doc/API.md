# **_Aixt_** Application Programmimg Interface

## Digital I/O
### Pin setup `pin_mode()`
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
- `value` is an integer to be written in the pin (`0` or `1`)


### Pin input
```go
x = pin_read(pin_name)
```
`pin_read` returns an integer (`0` or `1`)

## Analog to Digital (ADC)
```go
adc_setup(channel, setup_value_1, ... )
```
```go
x = adc_read(channel)
```
## PWM
```go
pwm_setup(pwm_id, setup_value_1, ... )
```
```go
pwm_duty(pwm_id, duty)
```
- `pwm_id` is the integer ID of each PWM module
- `duty` is the duty cycle in percentage (0 - 100)

## Serial comunication (UART)
```go
uart_setup(uart_id, baud_rate)
```
```go
x = uart_input(uart_id)
```
```go
uart_println(uart_id, message)
```
```go
uart_print(uart_id, message)
```
## Timming
```go
sleep(s)
```
```go
sleep_ms(ms)
```
```go
sleep_us(us)



