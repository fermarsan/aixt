# Quick reference for PC

## Delay
Use the `time` module:
```go
import time

sleep(2)            // sleep for 2 seconds
sleep_ms(50)        // sleep for 50 milliseconds
sleep_us(100)       // sleep for 100 microseconds
```
alternatively you can import only the needed function:
```go
import time { sleep_ms }

sleep_ms(200)       // sleep for 200 milliseconds
```

## Emulated pins
Use the `machine` module and the `{ pin }` submodule.
```go
import machine { pin }

pin_high(a)         // turn ON the "a" pin 
pin_low(y)          // turn OFF the "y" pin 
pin_write(d, 1)     // write 1 on "d" pin
pin_read(x)         // read "x" pin
```

### `pin` names
Functions to emulate input/output pins on the console. There are 8 emulated pins named: `a`, `b`, `c`, `d`, `w`, `x`, `y` and `z`, which are show in the console after any change, as follows:

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

#### Supported functions
name                    | description
------------------------|---------------------
`pin_high(pin)`         | Turn ON `pin`
`pin_low(pin)`          | Turn OFF `pin`
`pin_write(pin, val)`   | Write `val` in `pin`
`pin_read(pin)`         | Read `pin`

_Note: when using `pin_read()` the user has to write the value in the console manually._

## PWM
Use the `machine` module and the `{ pwm }` submodule.
```go
import machine { pwm }

pwm1_duty(40)       // set the duty cycle for PWM 1
pwm2_duty(60)       // set the duty cycle for PWM 2
```

Console output:
```
 Aixt virtual PWM outputs
                                    PWM 1 :  40 %
||||||||||||||||||||______________________________
                                    PWM 2 :  60 %
||||||||||||||||||||||||||||||____________________
```

## ADC
Use the `machine` module and the `{ adc }` submodule.
```go
import machine { adc }

val1, val2 := 0, 0
val1 = adc1_read()       // read de ADC 1
val2 = adc2_read()       // read de ADC 2
```

Console output:
```
Aixt virtual ADC input     ADC 1 : 23
```
```
Aixt virtual ADC input     ADC 2 : 56
```
_**NOTE:** you can use the whole set of functions if you import all the machine module, like this._
```go
import machine
```

  

## `machine/uart` module

### `input()` function
The input strings to be captured by the `input()` function having a fixed size of 30 characters.