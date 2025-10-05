# Quick reference for the Arduino Nano board


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
| `time.sleep(time)`    | Delay in seconds      |
| `time.sleep_us(time)` | Delay in microseconds |
| `time.sleep_ms(time)` | Delay in milliseconds |


## Internal LEDs
The onboard LED is named `led0` 

```v
import pin

pin.setup(pin.led0, pin.output)
pin.high(pin.led0)
```


## Pins
Use the `pin` module:

```v
import pin

pin.setup(pin.d0, pin.input)
pin.high(pin.d13)
pin.low(pin.d3)
pin.write(pin.d8, pin.read(pin.d0)) // pin echo
```

### Functions
| name                    | description               |
| ----------------------- | ------------------------- |
| `pin.setup(pin, mode)`  | Configure `pin` as `mode` |
| `pin.high(pin)`         | Turn On `pin`             |
| `pin.low(pin)`          | Turn Off `pin`            |
| `pin.write(pin, value)` | Write `value` in `pin`    |
| `pin.read(pin)`         | Return the state of `pin` |


### Digital pin names
The digital pin names are named from `d0` to `d21`.

 
## PWM (Pulse Width Modulation)
Use the `pwm` module:

```v
import pwm

pwm.write(pin.gp7, 40)       // set the duty cycle for gp7 pin
pwm.write(pin.gp8, 60)       // set the duty cycle for gp8 pin
```

### Functions
| name                        | description                        |
| --------------------------- | ---------------------------------- |
| `pwm.write(channel, value)` | Write `value` in the PWM `channel` |

### PWM pin names
All the digital pins are able to be used as PWM channels.


## ADC (Analog to Digital Converter)
Use the `adc` module:

```v
import adc

val1 := adc.read(ch0)       // read de ADC channel 0
val2 := adc.read(ch1)       // read de ADC channel 1
```

### Functions
| name                | description                       |
| ------------------- | --------------------------------- |
| `adc.read(channel)` | Return the ADC value in `channel` |

### Analog channels
The PWM channels are named from `ch0` to `ch2`.


## UART (serial port)
Use the `uart` or `uart2` module:

```v
import uart

uart.print('Hello ')
uart.println('World...')
```

### Functions
| name                     | description                                                      |
| ------------------------ | ---------------------------------------------------------------- |
| `uart.setup(baud_rate)`  | Configure the `baud_rate` of the UART                            |
| `uart.read()`            | Return one character received by UART                            |
| `uart.input(message)`    | Send the `message` and then return the string received by UART   |
| `uart.write(character)`  | Send one character by UART                                       |
| `uart.print(message)`    | Send the `message` by UART                                       |
| `uart.println(message)`  | Send the `message` plus a new line by UART                       |
| `uart.any()`             | Return the number uf characters in the UART's buffer             |
| `uart2.setup(baud_rate)` | Configure the `baud_rate` of the UART 2                          |
| `uart2.read()`           | Return one character received by UART 2                          |
| `uart2.input(message)`   | Send the `message` and then return the string received by UART 2 |
| `uart2.write(character)` | Send one character by UART 2                                     |
| `uart2.print(message)`   | Send the `message` by UART 2                                     |
| `uart2.println(message)` | Send the `message` plus a new line by UART 2                     |
| `uart2.any()`            | Return the number uf characters in the UART2's buffer            |


## USB UART (serial port by USB)
Use the `usb_uart` module:

```v
import usb_uart

usb_uart.print('Hello ')
usb_uart.println('World...')
```

### Functions
| name                    | description                                                        |
| ----------------------- | ------------------------------------------------------------------ |
| `uart.read()`           | Return one character received by USB-UART                          |
| `uart.input(message)`   | Send the `message` and then return the string received by USB-UART |
| `uart.write(character)` | Send one character by USB-UART                                     |
| `uart.print(message)`   | Send the `message` by USB-UART                                     |
| `uart.println(message)` | Send the `message` plus a new line by USB-UART                     |
| `uart.any()`            | Return the number uf characters in the USB-UART's buffer           |

