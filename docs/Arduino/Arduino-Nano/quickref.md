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
name                  | description
----------------------|----------------------
`time.sleep(time)`    | Delay in seconds
`time.sleep_us(time)` | Delay in microseconds
`time.sleep_ms(time)` | Delay in milliseconds


## Internal LEDs
The onboard LED is named `led_0` 

```v
import pin

pin.setup(led_0, pin.output)
pin.high(led_0)
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
name                    | description
------------------------|--------------------------
`pin.setup(pin, mode)`  | Configure `pin` as `mode`
`pin.high(pin)`         | Turn On `pin`
`pin.low(pin)`          | Turn Off `pin`
`pin.write(pin, value)` | Write `value` in `pin`
`pin.read(pin)`         | Return the state of `pin`


### Digital pin names
The digital pin names are named from `d0` to `d21`.