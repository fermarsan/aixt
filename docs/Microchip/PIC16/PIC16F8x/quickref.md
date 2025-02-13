# Quick reference for the PIC16F8x family

## Reference for the Microchip PIC16F8x devices
- PIC16F83
- PIC16F84
- PIC16F84A

**NOTE:** This PIC16F8x microcontrollers only has digital outputs and digital inputs


## Delay
Use the `time` module:

```v
import time

time.sleep(2)            // sleep for 2 seconds
time.sleep_ms(50)        // sleep for 50 milliseconds
time.sleep_us(100)       // sleep for 100 microseconds
```


## Pins
Use the `pin` module:

```v
import pin

pin.setup(pin.a1, pin.input)
pin.high(pin.b0)
pin.low(pin.a3)
pin.toggle(pin.b7)
pin.write(pin.b2, pin.read(pin.a1)) // pin echo
```


### `pin` names
The pin names are named with a letter indicating the port and a number indicating the pin. For example, `a6` indicates pin 6 of port A. All names in **Aixt** are written in lowercase, to follow [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Pin names for PIC16F8x
| Port | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
|:----:|-----|-----|-----|-----|-----|-----|-----|-----|
| **A**| `a0`| `a1`| `a2`| `a3`| `a4`|-----|-----|-----|
| **B**| `b0`| `b1`| `b2`| `b3`| `b4`| `b5`| `b6`| `b7`|


## Pin port
Use the `port` module:

```v
import port

port.setup(port.b, port.all_outputs)
port.setup(port.a, 0x00111111)  // port A bit 7 and 6 as outputs, the rest as inputs

val := port.read(port.a)
port.write(port.b, val) // port echo
```


### `port` names
The port names are named with a letter indicating the port. All names in **Aixt** are written in lowercase, to follow [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Pin names for PIC16F8x
| Port | Aixt name |
|:----:|:---------:|
| **A**| `a`       |
| **B**| `b`       |


## Timer 0
Use the `timer0` module:

```v
import port

port.setup(port.b, port.all_outputs)
port.setup(port.a, 0x00111111)  // port A bit 7 and 6 as outputs, the rest as inputs

val := port.read(port.a)
port.write(port.b, val) // port echo
```



## Examples

### Time
```v
time.sleep(5)	// Time of 5 seconds
time.sleep_us(10)	// Time of 10 microseconds
time.sleep_ms(500)	// Time of 500 milliseconds
```

### Pin Configuration
```v
pin.setup(pin.a4, pin.output)      // Function to configure the pin as output
pin.setup(pin.b2, pin.output)      // Function to configure the pin as output
pin.setup(pin.a2, pin.input)    // Function to configure the pin as input
pin.setup(pin.b4, pin.input)    // Function to configure the pin as input

pin.high(pin.a4)    // Function to turn on the pin
pin.low(pin.a4)     // Function to turn off the pin

pin.write(pin.a2, 0)  // Function to write to the pin
pin.write(pin.a2, 1)  // Function to write to the pin

pin.read(pin.a1)  // Function to read the pin
pin.read(pin.a1)  // Function to read the pin
```

### Example of turning an LED on and off:
```v
for {
    pin.high(pin.b1);
    time.sleep_us(500);
    pin.low(pin.b1);
    time.sleep_us(500);
}
```

### Example of turning a LED On and Off using a digital input:
```v
for {
    if pin.read(pin.b2) == 1 {        // Condition if it finds a 1 in b2
        pin.high(pin.b1);
    } else if pin.read(pin.b4) == 1 {   // Condition if it finds a 1 in b4
        pin.low(pin.b1);
    }
}

```

### Port Configuration
```v
port.setup(port.a, 0b00000000)      // Function to configure the port as output
```

### Example of turning on and off a port of the microcontroller:
```v
for {
    port.write(port.a,0b00110101);
    time.sleep_ms(500);
    port.write(port.a,0b00001010);
    time.sleep_ms(500);
}
```

## Supported Functions
The functions contained in the API are digital inputs or outputs.

name                                  | description
----------------------------------------|------------------------------
`pin.setup(pin_name, mode)`           | configures `pin_name` in `pin_mode`
`pin.high(pin_name)`                  | turn on `pin_name`
`pin.low(pin_name)`                   | turn off `pin_name`
`pin.toggle(pin_name)`                | toggle the state of `pin_name`
`pin.write(pin_name,val)`             | write `val` to `pin_name`
`pin.read(pin_name)`                  | read `pin_name`
`pin (pin)`                           | configure `pin_output` or `pin_input`
`port`                                | initialize `port`
`port.read(port_name)`                | read `port_name`
`port.setup(port_name, value)`        | configure `port_name` assign value `value`
`port.write(port_name, value)`        | write `port_name` to `value`
`time.sleep(time)`                    | delay in `sec`
`time.sleep_us(time)`                 | delay in `microsec`
`time.sleep_ms(time)`                 | delay in `millisec`

