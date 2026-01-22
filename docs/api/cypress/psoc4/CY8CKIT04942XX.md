# Quick Guide PSoC4
This Aixt implementation for PSoC 4 supports the CY8CKIT04942X board. 


# This Aixt implementation for PSoC 4 supports the CY8CKIT-049-42XX board.

## View

![CY8CKIT-049-42XX](Images-CY8CKIT04942XX/View-CY8CKIT04942XX.jpg)

## Datasheet
[Datasheet CY8CKIT-049-42XX](https://www.infineon.com/dgdl/Infineon-CY8CKIT-049-4xxx_PSoC_4_Prototyping_Kit_Guide-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d0d8da4017d0ef17bd002cb)


# General Configuration

The basic microcontroller functions are integrated to generate a general hardware structure, as follows:

- 4 PWMs
- 1 LEDs
- 1 push button
- 2 communication ports (UARTs)
- 11 digital inputs
- 11 digital outputs
- 4 analog inputs

*Visualization in PSoC Creator*

![General_Hardware_Structure.jpg](Images-CY8CKIT04942XX/General_Hardware_Structure_CY8CKIT04942XX.jpg)

## Port Identification

The following table shows the ports used and their assigned names for programming: 

| Port | name      | Type   |
| ---- | --------- | ------ |
| 1.6  | led1      | output |
| 0.7  | sw1       | input  |
| 0.0  | di0       | input  |
| 0.1  | di1       | input  |
| 0.2  | di2       | input  |
| 0.3  | di3       | input  |
| 0.4  | di4       | input  |
| 0.5  | di5       | input  |
| 0.6  | di6       | input  |
| 1.1  | di7       | input  |
| 1.3  | di8       | input  |
| 1.4  | di9       | input  |
| 1.5  | di10      | input  |
| 1.7  | do0       | output |
| 2.5  | do1       | output |
| 2.7  | do2       | output |
| 3.0  | do3       | output |
| 3.1  | do4       | output |
| 3.4  | do5       | output |
| 3.5  | do6       | output |
| 3.6  | do7       | output |
| 3.7  | do8       | output |
| 4.2  | do9       | output |
| 4.3  | do10      | output |
| 1.0  | out_pwm0  | output |
| 1.2  | out_pwm1  | output |
| 2.4  | out_pwm2  | output |
| 2.6  | out_pwm3  | output |
| 2.0  | in0_adc   | input  |
| 2.1  | in1_adc   | input  |
| 2.2  | in2_adc   | input  |
| 2.3  | in3_adc   | input  |
| 4.0  | \uart:rx\ | output |
| 4.1  | \uart:tx\ | output |

## Programming in V language

For each of these modules, you will have a file in .c.v format with the same name of the module and in this you will have the text module followed by the name of the module, example:

* module pin
* module pwm
* module uart
* module adc

For each of the following modules, a .c.v file will be generated with the same name as the module.


### Output port configuration

To activate an output port;
```v
pin.high(pin_name)
```
*Example: to activate the output port called led1; ` pin.high(led1)`*

To deactivate an output port;
```v
pin.low(pin_name)
```
*Example: to deactivate the output port called led1; `pin.low(led1)`*

To activate or deactivate an output port;

```v
pin.write(pin_name, value)
```
*Example: to deactivate led1;  `pin.write(led1, 1)`, and to activate it;  `pin.write(led1, 0)`.*

### Input Port Detection

To check the state of an input port:
```v
x = pin.read(pin_name)
```

*Example: to detect the value of port sw2;  `x = pin.read(sw2) `, The variable x will take a value of 0 or 1 depending on whether the port is active or inactive*

### PWM

To configure PWM on one of the ports;
```v
pwm.write(pwm.channel,duty)
```
*pwm.channel indicates the channel to control, and duty represents the duty cycle value (from 0 to 10000).*

*Example: to control channel 1 with a PWM signal with duty cycle = 10000, `pwm.write(pwm.ch1, 10000) `*



### Serial comunication (UART)

To configure a UART communication port;

```v

uart.setup(), // Initializes and configures the UART with basic parameters

```
## Serial Transmission

*Since the port is already defined as "uart:tx", this is the only available serial UART communication port. The value you place in "message" will be the data transmitted*

```v

uart.print(message) // Prints text (string or number converted to characters) and sends it to the UART TX register
```

```v

uart.println(message) // Prints text and appends a newline (\r\n)

```

```v

uart.read() // Receives data from the UART port (reads input on RX pin)

```

```v

uart.write() // Sends data through the UART port (writes directly to TX register)

```

### Analog-to-Digital Converter (ADC)

To initialize and configure the ADC module

```v

adc.setup()

```

To read the digital value converted by the ADC on a specific channel.

```v

adc.read()

```


### Delays

Using time functions;

* Seconds
```v
time.sleep(s)
```

* Milliseconds

```v
time.sleep_ms(ms)
```

* Microseconds

```v
time.sleep_us(us)
```

*In each expression, place the desired time value inside the parentheses*

* Example: Blinking LED (high/low functions)

```v

import time {sleep_ms}
import pin


for {
	pin.high(led1)
	time.sleep_ms(5000)
	pin.low(led1)
	time.sleep_ms(5000)
}

```
* Example: Blinking LED (write function)

```v
import time
import pin

for {
	pin.write(led_1, 0)
	time.sleep_ms(500)
	pin.write(led_1, 1)
	time.sleep_ms(500)
}

```
* Example: LED controlled by button (read function)

```v

import time {sleep_ms}
import pin


for {

    if pin.read(sw2) == 1 {     // If the button is pressed (logic high)
        pin.high(led1)           // Turn LED on
    } else {
        pin.low(led1)            // Turn LED off
    }

    time.sleep_ms(100)             // Small delay to avoid bouncing
}

```

* PWM example 

```v

import time {sleep_ms}
import pwm

for {
    pwm.write(pwm.ch1, 10000)
    sleep_ms(500)

    pwm.write(pwm.ch1, 5000)
    sleep_ms(500)

    pwm.write(pwm.ch1, 0)
    sleep_ms(500)
    
 }
 
  ```


* UART example 

```v

import time {sleep_ms}
import uart

uart.setup()
for {

uart.print("Sending for UART...\r\n")
time.sleep_ms(1000) 

}

```

* ADC example 

```v

import time
import uart
import adc

adc.setup()
uart.setup()

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}

```