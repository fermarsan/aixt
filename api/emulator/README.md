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

### Functions
| name                  | description           |
| --------------------- | --------------------- |
| `time.sleep(time)`    | delay in seconds      |
| `time.sleep_us(time)` | delay in microseconds |
| `time.sleep_ms(time)` | delay in milliseconds |


## Emulated pins
Use the `pin` module:

```v
import pin

pin.high(pin.x)
pin.low(pin.y)
pin.write(pin.z, pin.read(pin.a))   // pin echo
```

### Functions
| name                    | description               |
| ----------------------- | ------------------------- |
| `pin.high(pin)`         | Turn ON `pin`             |
| `pin.low(pin)`          | Turn OFF `pin`            |
| `pin.write(pin, value)` | Write `value` in `pin`    |
| `pin.read(pin)`         | Return the state of `pin` |

### Digital pin names
The functions to emulate input/output digital pins on the terminal use 8 emulated pins named: `a`, `b`, `c`, `d`, `w`, `x`, `y` and `z`, which are show in the terminal after any change, as follows:

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


## Emulated PWM (Pulse Width Modulation)
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

### Functions
| name                        | description                        |
| --------------------------- | ---------------------------------- |
| `pwm.write(channel, value)` | Write `value` in the PWM `channel` |

### PWM pin names
There are 2 emulated PWM channels named: `ch0` and `ch1`.


## Emulated ADC (Analog to Digital Converter)
Use the `adc` module:

```v
import adc

val1 := adc.read(ch0)       // read de ADC channel 0
val2 := adc.read(ch1)       // read de ADC channel 1
```

terminal output:
```
Aixt virtual ADC input     ADC 0 : 23
```
```
Aixt virtual ADC input     ADC 1 : 56
```

### Functions
| name                | description                       |
| ------------------- | --------------------------------- |
| `adc.read(channel)` | Return the ADC value in `channel` |

### Analog channels
There are 2 emulated ADC channels named: `ch0` and `ch1`.


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

### Functions
| name                     | description                                                                         |
| ------------------------ | ----------------------------------------------------------------------------------- |
| `uart.print(message)`    | Print the `message` in the virtual UART                                             |
| `uart.println(message)`  | Print the `message` plus a new line in the virtual UART                             |
| `uart.input(message)`    | Print the `message` and return the string entered by the user in the virtual UART   |
| `uart2.print(message)`   | Print the `message` in the virtual UART 2                                           |
| `uart2.println(message)` | Print the `message` plus a new line in the virtual UART 2                           |
| `uart2.input(message)`   | Print the `message` and return the string entered by the user in the virtual UART 2 |
| `uart3.print(message)`   | Print the `message` in the virtual UART 3                                           |
| `uart3.println(message)` | Print the `message` plus a new line in the virtual UART 3                           |
| `uart3.input(message)`   | Print the `message` and return the string entered by the user in the virtual UART 3 |

### Input function
The input strings to be captured by the `uart.input()` function having a fixed size of 30 characters.