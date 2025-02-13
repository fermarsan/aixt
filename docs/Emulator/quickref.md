# Quick reference for the Software Emulator port

This software emulation works on _Linux_, _Windows_ and _Android (Termux)_.

## Delay
Use the `time` module:
```v
time.sleep(2)            // sleep for 2 seconds
time.sleep_ms(50)        // sleep for 50 milliseconds
time.sleep_us(100)       // sleep for 100 microseconds
```

## Emulated pins
```v
pin.high(pin.a)         // turn ON the "a" pin 
pin.low(pin.y)          // turn OFF the "y" pin 
pin.write(pin.d, 1)     // write 1 on "d" pin
pin.read(pin.x)         // read "x" pin
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

#### Supported functions
name                    | description
------------------------|---------------------
`pin.high(pin)`         | Turn ON `pin`
`pin.low(pin)`          | Turn OFF `pin`
`pin.write(pin, val)`   | Write `val` in `pin`
`pin.read(pin)`         | Read `pin`

_Note: when using `pin.read()` the user has to write the value in the terminal manually._

## PWM
```v
pwm.write(pwm.ch0, 40)       // set the duty cycle for PWM channel 0
pwm.write(pwm.ch1, 60)       // set the duty cycle for PWM channel 1
```

terminal output:
```
 Aixt virtual PWM outputs
                                    PWM 1 :  40 %
||||||||||||||||||||______________________________
                                    PWM 2 :  60 %
||||||||||||||||||||||||||||||____________________
```

## ADC
```v
val1, val2 := 0, 0
val1 = adc.read(ch0)       // read de ADC channel 0
val2 = adc.read(ch1)       // read de ADC channel 1
```

terminal output:
```
Aixt virtual ADC input     ADC 1 : 23
```
```
Aixt virtual ADC input     ADC 2 : 56
```


### `input()` function
The input strings to be captured by the `input()` function having a fixed size of 30 characters.