# **Fast guide AI-WB2-32S-KIT**
This Aixt implementation that supports the card  AI-WB2-32S-KIT

# **ID card AI-WB2-32S-KIT**

## View
* *Ai-WB2-32S-Kit, a total of 38 interfaces are connected, for example, the pin function definition table is the interface definition.*

![Alt text](Picture/AI-WBS-32S_FRONT.jpg)
*Image taken from the device datasheet*

## Datasheet
[AI-WB2-32S-KIT](http://www.ai-thinker.com/Uploads/file/20221008/20221008082356_37940.pdf)

## Port Identification
Below are the ports used and their proper designations for programming:

No.| Name     | Function 
-- |-----     |---
1  |3V3       |3.3V power supply; The output current of the external power supply is recommended to be above 500mA 
2  |EN        | By default, it is enabled as a chip, and the high level is effective 
3  |NC        | Empty feet 
4  |IO11      | GPIO11/SPI_SCLK/IIC_SDA/ADC_CH10/JTAG_TDI/TDO 
5  |NC        | Empty feet 
6  |Empty feet| Empty feet 
7  |IO14      | GPIO14/SPI_SS/IIC_SCL/PWM_CH4/ADC_CH2/JTAG_TCK/TMS 
8  |IO17      | GPIO17/SPI_MOSI/MISO/IIC_SDA/PWM_CH2/JTAG_TCK/TMS 
9  |IO3       | GPIO3/SPI_SCLK/IIC_SDA/PWM_CH3/JTAG_TDO/TDI 
10 |IO20/NC   | The default NC is unavailable 
11 |IO22/NC   | The default NC is unavailable 
12 |IO0/NC    | The default NC is unavailable 
13 |IO21/NC   | The default NC is unavailable 
14 |GND       | Ground 
15 |NC        | Empty feet 
16 |NC        | Empty feet 
17 |NC        | Empty feet 
18 |NC        | Empty feet 
19 |5V        | 5V power supply; External power supply output current is recommended to be above 500mA 
20 |NC        | Empty feet 
21 |NC        | Empty feet 
22 |NC        | Empty feet 
23 |NC        | Empty feet 
24 |NC        | Empty feet 
25 |IO8/NC    | The default NC is unavailable. 
26 |NC        | Empty feet 
27 |IO4       | GPIO4/SPI_MOSI/MISO/IIC_SCL/PWM_CH4/ADC_CH1 
28 |IO2/NC    | The default NC is unavailable
29 |NC        | Empty feet 
30 |IO1/NC    | The default NC is unavailable 
31 |IO5       | GPIO5/SPI_MOSI/MISO/IIC_SDA/PWM_CH0/ADC_CH4/JTAG_T MS/TCK 
32 |NC        | Empty feet 
33 |NC        | Empty feet 
34 |RX        | RXD/GPIO7/SPI_SCLK/IIC_SDA/PWM_CH2/JTAG_TDO/TDI 
35 |TX        | TXD/GPIO16/SPI_MOSI/MISO/IIC_SCL/PWM_CH1/JTAG_TMS/T CK 
36 |IO12      | GPIO12/SPI_MOSI/MISO/IIC_SCL/PWM_CH2/ADC_CH0/JTAG_T MS/TCK 
37 |NC        | Empty feet 
38 |GND       | Ground

## Programming in v language
For each of these modules, you will have a file in .c.v format with the same name of the module and in this you will have the text module followed by the name of the module, example:
* module pin
* module adc
* module pwm


### Output port configuration
To activate the port to use
```go
pin__setup(PIN_NAME, MODE)
```
To activate the port to use
```go
pin__high(PIN_NAME)
```
* *Example: If you want to activate the port 17;  `pin__high(17)`.*

To disable the port being used
```go
pin__low(PIN_NAME)
```
* *Example: If you want to disable the port 17;  `pin__low(17)`.*

To disable or enable the port to be used

```go
pin__write(PIN_NAME, VALUE)
```
* *Example: If you want to disable port 17 `pin__write(17, 1)`, and if you want to activate  `pin__write(17, 0)`.*

### Input port detection

If you need to know what state an entry port is in:
```go
x = pin__read(PIN_NAME)
```

* *Example: If you want to detect the VALUE of port 3; `x = pin__read(17)`, and `x` will take the VALUE of 0 or 1, depending on which port is active or disabled.*

### Analog to digital ports (ADC)

To configure one of the analog ports
```go
adc__setup(PIN_NAME, SETUP_VALUE, ... )
```
* *In PIN_NAME the name of the analog port is entered, in SETUP_VALUE the VALUE that will be given is said port.*

To detect the analog port VALUE
```go
x = adc__read(PIN_NAME)
```
* *In `PIN_NAME` the name of the analog port is entered, and `x` takes the VALUE of said port..*

## Pulse Width Modulation (PWM outputs)

To configure some PWM
```go
pwm__setup(SETUP_VALUE, setup_VALUE_1, ... )
```
* *In pwm you set the PWM to use, and in SETUP_VALUE the VALUE to which you want to configure said pwm.*


To configure the duty cycle of a modulator
```go
pwm__duty(duty)
```
* *In PWM the pwm to be used is set, and in `duty` the VALUE of the cycle (from 0 to 100) in percentage.*

## Serial communication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uart_function_name_x()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart__setup(BAUD_RATE)   // the same of uart__setup(BAUD_RATE)
```
For a second connection it is used as:
```v 
uart__setup_1(BAUD_RATE)   // the same of uart__setup_1(BAUD_RATE)
```
- `BAUD_RATE` configure the communication speed
### Serial transmitting

```v
uart__print(MESSAGE)      // print a string to the default UART
```
```v
uart__println(MESSAGE)    // print a string plus a line-new character to the default UART
```
```v
uart__ready() // get everything ready for to UART
```
```v
uart__read() // receives binary data (in Bytes) to UART
```
```v
uart__write(MESSAGE)    // send binary data (in Bytes) to second UART
```

### Retardos

* Use of times

    * In each expression, the time VALUE is put inside the parentheses.
```go
time__sleep(S) //Seconds
```
```go
time__sleep_ms(MS) //Milliseconds
```
```go
time__sleep_us(US) //Microseconds
```

* Example flashing LED

```go
import pin
import time {sleep_ms}

pin.setup(14, pin.out)

for {   //infinite loop
    pin.high(14)
    sleep_ms(500)
    pin.low(14)
    sleep_ms(500)
}
```
* Example PWM
```go
import time {sleep_ms}
import pin
import pwm

__global val = 0

pin.setup(17, pin.out)

for {
    pwm.write(17, val)
    sleep_ms(250)
    val=val+10
    if val==250{
		val=0  
    }
} 
```
