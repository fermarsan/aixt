# **Fast guide M0sense**
This Aixt implementation that supports the card  M0sense

# **ID card M0sense**

## View
* *M0sense, a total of 38 interfaces are connected, for example, the pin function definition table is the interface definition.*

![Alt text](Picture/M0sense.jpg)

## Datasheet
[M0sense](https://dl.sipeed.com/shareURL/Maix-Zero/M0sense/1_Specification)

## Port Identification
Below are the ports used and their proper designations for programming:

No.| Name     | Function 
-- |-----     |---
1  |IO28      | GPIO28 
2  |3V3       | 3.3V power supply; The output current of the external power supply is recommended to be above 500mA  
3  |GND       | Ground 
4  |VSYS      | REF System 
5  |I02       | GPI02/BOOT Button
6  |IO0       | GPIO0 
7  |IO1       | GPIO1_LCD_CS
8  |IO9       | GPIO9 
9  |IO27      | GPIO27_SDA
10 |IO26      | GPIO26_SCL 
11 |IO25      | GPIO25_LEDR_LCD_DC 
12 |IO24      | GPIO25_LEDG_LCD_MOSI 
13 |IO23      | GPIO25_LEDB_LCD_SCLK
14 |IO15      | GPIO15 
15 |IO14      | GPIO14 
16 |GND       | Ground

## Programming in v language

### Output port configuration

To activate the port to use
```go
pin_high(pin_name)
```
* *Example: If you want to activate the port IO17;  `pin_high(IO17)`.*

To disable the port being used
```go
pin_low(pin_name)
```
* *Example: If you want to disable the port IO17;  `pin_low(IO17)`.*

To disable or enable the port to be used

```go
pin_write(pin_name, value)
```
* *Example: If you want to disable port IO17 `pin_write(IO17, 1)`, and if you want to activate  `pin_write(IO17, 0)`.*

### Input port detection

If you need to know what state an entry port is in:
```go
x = pin_read(pin_name)
```

* *Example: If you want to detect the value of port IO3; `x = pin_read(IO17)`, and `x` will take the value of 0 or 1, depending on which port is active or disabled.*

### Analog to digital ports (ADC)

To configure one of the analog ports
```go
adc_setup(channel, setup_value_1, ... )
```
* *In channel the name of the analog port is entered, in setup_value_1 the value that will be given is said port.*

To detect the analog port value
```go
x = adc_read(channel)
```
* *In `channel` the name of the analog port is entered, and `x` takes the value of said port..*

## Pulse Width Modulation (PWM outputs)

To configure some PWM
```go
pwm_setup(setup_value_1, setup_value_2, ... )
```
* *In pwm you set the PWM to use, and in setup_value_1 the value to which you want to configure said pwm.*


To configure the duty cycle of a modulator
```go
pwm_duty(duty)
```
* *In PWM the pwm to be used is set, and in `duty` the value of the cycle (from 0 to 100) in percentage.*

## Serial communication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx_function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart_setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configure the communication speed

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

### Retardos

* Use of times

    * In each expression, the time value is put inside the parentheses.
```go
sleep(s) //Seconds
```
```go
sleep_ms(ms) //Milliseconds
```
```go
sleep_us(us) //Microseconds
```

* Example flashing LED

```go
import machine { pin }
import time { sleep_ms }

pin_mode(IO14, out)

for {   //infinite loop
    pin_high(IO14)
    sleep_ms(500)
    pin_low(IO14)
    sleep_ms(500)
}
```