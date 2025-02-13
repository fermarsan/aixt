# Quick reference for the Software Emulator
Software CLI emulator that works on _Linux_, _Windows_ and _Android (Termux)_.


## Delay
Use the `time` module:

```v
import time

time.sleep(2)            // sleep for 2 seconds
time.sleep_ms(50)        // sleep for 50 milliseconds
time.sleep_us(100)       // sleep for 100 microseconds
```


## Emulated pins
Use the `pin` module:

```v
import pin

pin.high(pin.x)
pin.low(pin.y)
pin.write(pin.z, pin.read(pin.a))   // pin echo
```

### `pin` names
Functions to emulate input/output pins on the terminal. There are 8 emulated pins named: `a`, `b`, `c`, `d`, `w`, `x`, `y` and `z`, which are show in the terminal after any change, as follows:

_**After calling a writing function**_
```
 Aixt virtual pins     [#] = ON   [ ] = OFF
 _____ _____ _____ _____ _____ _____ _____ _____
|  a  |  b  |  c  |  d  |  w  |  x  |  y  |  z  |
| [#] | [ ] | [ ] | [ ] | [ ] | [#] | [ ] | [ ] |
'-----'-----'-----'-----'-----'-----'-----'-----'
```
_**After calling a reading function**_
```
 Aixt virtual pins     Input z : 1
```

_Note: when using `pin.read()` the user has to write the value in the terminal manually._


## Emulated PWM
Use the `pwm` module:

```v
import pwm

pwm.write(pwm.ch0, 40)       // set the duty cycle for PWM channel 0
pwm.write(pwm.ch1, 60)       // set the duty cycle for PWM channel 1
```

terminal output:
```
 Aixt virtual PWM outputs
                                    PWM 0 :  40 %
||||||||||||||||||||______________________________
                                    PWM 1 :  60 %
||||||||||||||||||||||||||||||____________________
```


## Emulated ADC
Use the `adc` module:

```v
import adc

val1, val2 := 0, 0
val1 = adc.read(ch0)       // read de ADC channel 0
val2 = adc.read(ch1)       // read de ADC channel 1
```

terminal output:
```
Aixt virtual ADC input     ADC 0 : 23
```
```
Aixt virtual ADC input     ADC 1 : 56
```


## Emulated UART (serial port)
This software emulator has 3 virtual UARTs named `UART`, `UART2` and `UART3`.

Use the `uart` or `uartx` module:

```v
import uart

uart.print('Hello ')
uart.println('World...')
```

terminal output:
```
 Aixt virtual UART
Hello world!
```

### `uart.input()` function
The input strings to be captured by the `input()` function having a fixed size of 30 characters.


## Supported functions
name                        | description
----------------------------|----------------------------------------------------------------
`time.sleep(time)`          | delay in seconds
`time.sleep_us(time)`       | delay in microseconds
`time.sleep_ms(time)`       | delay in milliseconds
`pin.high(pin)`             | Turn ON `pin`
`pin.low(pin)`              | Turn OFF `pin`
`pin.write(pin, val)`       | Write `val` in `pin`
`pin.read(pin)`             | Read `pin`
`pwm.write(channel, val)`   | Write `val` in the PWM `channel` (in the terminal)
`adc.read(channel)`         | Read the ADC (by terminal) in `channel` and return that value 
`uart.print(message)`       | Print the `message` in the terminal
`uart.println(message)`     | Print the `message` plus a new line in the terminal
`uart.input(message)`       | Print the `message` and return the string entered by the user
`uart2.print(message)`      | Print the `message` in the terminal
`uart2.println(message)`    | Print the `message` plus a new line in the terminal
`uart2.input(message)`      | Print the `message` and return the string entered by the user 
`uart3.print(message)`      | Print the `message` in the terminal
`uart3.println(message)`    | Print the `message` plus a new line in the terminal
`uart3.input(message)`      | Print the `message` and return the string entered by the user  