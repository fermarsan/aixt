# Quick reference for the Software Emulator port

This software emulation works on _Linux_, _Windows_ and _Android (Termux)_.

## Delay
Use the `time` module:
```v
sleep(2)            // sleep for 2 seconds
sleep_ms(50)        // sleep for 50 milliseconds
sleep_us(100)       // sleep for 100 microseconds
```

## Emulated pins
```v
pin.high(a)         // turn ON the "a" pin 
pin.low(y)          // turn OFF the "y" pin 
pin.write(d, 1)     // write 1 on "d" pin
pin.read(x)         // read "x" pin
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
pwm1_duty(40)       // set the duty cycle for PWM 1
pwm2_duty(60)       // set the duty cycle for PWM 2
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
val1 = adc1_read()       // read de ADC 1
val2 = adc2_read()       // read de ADC 2
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