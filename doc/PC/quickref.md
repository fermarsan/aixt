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




## `machine` module
Machine module is created in order to emulate the pin an other microcontroller peipherals.

### `pin` functions
Functions to emulate input/output pins on the console. This emulation has 8 pins named: `A`, `B`, `C`, `D`, `w`, `x`, `y` and `z`, which are show in the console after any change, as follows:

_**Writing function**_
```
 Aixt virtual pins     [#] = ON   [ ] = OFF
 _____ _____ _____ _____ _____ _____ _____ _____
|  A  |  B  |  C  |  D  |  w  |  x  |  y  |  z  |
| [ ] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] |
'-----'-----'-----'-----'-----'-----'-----'-----'
```
_**Reading function**_
```
 Aixt virtual pins     Input z : _
```

Usage: 
```go
import machine { pin }
```
#### Functions
name                    | description
------------------------|---------------------
`pin_high(pin)`         | Set `pin`
`pin_low(pin)`          | Reset `pin`
`pin_write(pin, val)`   | Write `val` in `pin`
`pin_read(pin)`         | Read `pin`

_Note:_ when using `pin_read()` the user has to write the value in the console manually.  

## `os` module

### `input()` function
The input strings to be captured by the `input()` function having a fixed size of 30 characters.

## 