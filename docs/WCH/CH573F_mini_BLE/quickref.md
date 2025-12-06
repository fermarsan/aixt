# **Fast guide CH573F-mini-BLE**
This Aixt implementation that supports the card  CH573F-mini-BLE

# **ID card CH573F-mini-BLE**

## View
CH573F-mini-BLE, It's a card with Bluetooth 4.2 communication, featuring a total of 24 pins divided into two ports, A and B, with a speed of 60 MHz, 18 kB of RAM, 448 kB of ROM, with connection through USB type C. It includes output, input, PWM, ADC and UART functions.

![Alt text](Picture/CH573F-mini-BLE.jpg)

*Image taken from the device* [Image_CH573F-mini-BLE](https://github.com/WeActStudio/WeActStudio.WCH-BLE-Core/blob/master/Images/1.png)

## Datasheet
[CH573F-mini-BLE](https://github.com/WeActStudio/WeActStudio.WCH-BLE-Core/blob/master/Doc/CH573/en/CH573DS1.PDF)

## Port Identification
Below are the ports used and their proper designations for programming:

| Name | Alternate Funcion | Description                                   |
| ---- | :---------------: | --------------------------------------------- |
| G    |                   | Ground                                        |
| 5V   |                   | 5V Power supply                               |
| G    |                   | Ground                                        |
| 3V3  |                   | 3.3V Power supply                             |
| A4   |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       RXD3        | UART3 serial data input                       |
| A5   |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       TXD3        | UART3 serial data output                      |
| A8   |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       RXD1        | UART1 serial data input                       |
| A9   |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       TXD1        | UART1 serial data output                      |
| A10  |        I/0        | General purpose bidirectional digital I/0 pin |
| A11  |        I/0        | General purpose bidirectional digital I/0 pin |
| A12  |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       PWM4        | Pulse width modulation output channel 4       |
| A13  |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       PWM5        | Pulse width modulation output channel 5       |
| A14  |        I/0        | General purpose bidirectional digital I/0 pin |
| A15  |        I/0        | General purpose bidirectional digital I/0 pin |
| B4   |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       RXD0        | UART0 serial data input                       |
|      |       PWM7        | Pulse width modulation output channel 7       |
| B7   |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       TXD0        | UART0 serial data output                      |
|      |       PWM9        | Pulse width modulation output channel 9       |
| B10  |        I/0        | General purpose bidirectional digital I/0 pin |
| B11  |        I/0        | General purpose bidirectional digital I/0 pin |
| B12  |        I/0        | General purpose bidirectional digital I/0 pin |
| B13  |        I/0        | General purpose bidirectional digital I/0 pin |
| B14  |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       PWM10       | Pulse width modulation output channel 10      |
| B15  |        I/0        | General purpose bidirectional digital I/0 pin |
| B22  |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       RXD2        | UART2 serial data input                       |
| B23  |        I/0        | General purpose bidirectional digital I/0 pin |
|      |       TXD2        | UART2 serial data output                      |
|      |       PWM11       | Pulse width modulation output channel 11      |

## Programming in C/C++ language  
Programming of the CH573-mini-BLE card is done using the [MounRiver Studio](http://www.mounriver.com/download) program, which is developed based on the Eclipse GNU version. It is optimized for integrated development of C/C++ for ARM and RISC-V processor microcontrollers, with the latter being present in the CH573-mini-BLE card.  

## Programming in v language   
The distribution will be by modules within the API according to the functions to be implemented on the CH573F-miniBLE card. The modules will have a specific configuration in the internal file created with the name of each module with the extension .c.v and other configuration files within the module for proper configuration of each function. The modules for the CH573-mini-BLE card are as follows:

* Module adc
* Module pin
* Module port
* Module pwm
* Module time
* Module uart

### Setup pin configuration
To configure the pin usage mode.

```v
pin.setup(pin_name, mode)
```
* *Example: If you want to activate pin 11 of port A as an output;  `pin.setup(pin.a11, pin.output)`.*
* *Example: If you want to activate pin 11 of port A as an input.;  `pin.setup(pin.a11, pin.input)`.*

To activate the pin to use
```v
pin.high(PIN_NAME)
```
* *Example: If you want to activate pin 7 of port B;  `pin.high(pin.b7)`.*

To disable the pin being used
```v
pin.low(PIN_NAME)
```
* *Example: If you want to disable pin 7 of port B;  `pin.low(pin.b7)`.*

### Setup port configuration
To configure the mode of one or all pins of the specific port.
```v
port.setup(PORT, BITS, MODE)
```
* *Example: If you want to activate pin 4 of port A as an output;  `pin.setup(pin.a, pin.0x00000010, output)`.*
* *Example: If you want to activate all pins of port B as inputs;  `pin.setup(pin.b, pin.0xFFFFFFFF, input)`.*

State port detection

If you need to know what state an entry port is in:
```v
pin.read(PORT)
```
* *Example: If you want to detect the VALUE of port A; `port.read(port.a)`*

To activate one pin o all pin to use
```v
port.write(PORT, BITS)
```
* *Example: If you want to activate pin 15 of port B as an output;  `port.write(port.b, 0x00000080)`.*
* *Example: If you want to activate all pins of port B;  `port.write(port.a, 0xFFFFFFFF)`.*

### Pulse Width Modulation (PWM outputs)

There are 6 PWM channels on the CH573-mini-BLE card, each channel having its respective pin for output configuration. 

For PWM output configuration:
```v
pwm.write(channel, value)
```
* *Example: If you  want activate pwm the channel 4 with specific value between a cycle of 0 and 256;  `pwm.write(4, 50)`*

### Serial communication (UART)

For serial communication, the CH573-mini-BLE card has four UART ports, each port having two pins for sending and receiving data, TX and RX respectively. For serial communication, a USB-TTL cable with its respective driver must be used.

Because there are four UART serial communication ports, the configuration in the API is created for each UART, establishing UART, UART1, UART2, and UART3.

For configuring the UART serial communication speed: 
```
uart#.setup(baud_rate)
```
- `baud_rate` to configure the serial communication speed.
* *Example: If you want to establish a speed in UART0, you use `uart0.setup(115200)`*

### Serial transmitting

```v
uart#.print(message)      // print a string to the default UART
```
* *Example: If you want to use UART0 port `uart0.print(Uart for AIXT)`*
```v
uart#.println(message)    // print a string plus a line-new character to the default UART
```
* *Example: If you want to use UART1 port `uart1.println(Command received)`*
```v
uart#.write(message)    // send binary data (in Bytes) to the default UART
```
* *Example: If you want to use UART2 port `uart2.write()`*
```v
uart#.read // receives binary data (in Bytes) to the default UART 
```
* *Example: If you want to use UART3 port `uart3.read()`*

### Time 

* In each expression, the time VALUE is put inside the parentheses.
```v
time.sleep(s) //Seconds
```
* *Example: This is used as `time.sleep(2)`*
```v
time.sleep_ms(ms) //Milliseconds
```
* *Example: This is used as `time.sleep_ms(500)`*
```v
time.sleep_us(us) //Microseconds
```
 *Example: This is used as `time.sleep_us(5000)`*

## Implementation of the AIXT project

Below are some code in V language, examples of the main functions that are transcompiled to obtain the code in C/C++ language and perform the upload to the CH573F-mini-BLE card through the WCHISPTool extension of the MounRiver program. 

* Example flashing LED

```v
import time { sleep_ms }
import pin 

pin.setup(pin.a8, pin.output)

for {
    pin.high(pin.a8)    
    sleep_ms(150)
    pin.low(pin.a8)
    sleep_ms(150)
}
```

* Example flashing LED with toggle 

```v
import time { sleep_ms }
import pin 

pin.setup(pin.a8, pin.output)

for {
    pin.toggle(pin.a8)    
    sleep_ms(150)
}
```
* Example PORT 
```v
import port
import time {sleep_ms}

port.setup(port.a, pin.0x00000800, port.output)
port.setup(port.b, pin.0xFFFFFFFF, port.output)
for{
	port.write(port.a,0x00000800)
	time.sleep_ms(1000)
	port.write(port.b,0x00000800)
	time.sleep_ms(1000)
}
```
* Example PWM
```v
import time { sleep_ms }
import pin { setup }                         
import pwm                           

pin.setup(pin.a12, pin.output) 

value := 50

for {
    pwm.write(4, value)
    value = value + 50
    sleep_ms(300)
    if value > 250 {
        pwm.off(4)  
        sleep_ms(300)
        value = 50 
    }
}
```
* Example ADC
```v
import pin { setup }                         
import pwm      
import adc

pin.setup(pin.a4, pin.input) 

adc.setup(0)

for {
    adc.read(value)
	pwm.write(4, value)
    }
```
* Example UART0
```v
import time {sleep_ms}
import uart
import pin 

pin.high(pin.b7)
pin.setup(pin.b4, in_pullup) 
pin.setup(pin.b7, pin.output)

uart.setup(115200)

for {
    uart.write(TxBuff)
    sleep_ms(2000)
	uart.read()
}
```
