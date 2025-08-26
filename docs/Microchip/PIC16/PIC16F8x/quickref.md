
Quick reference for the Microchip PIC16F8x devices:
- PIC16F83
- PIC16F84
- PIC16F84A

**NOTE:** This PIC16F8x microcontrollers only has digital outputs and digital inputs

## General $\mu C$ control

```v
// by default the CPU oscillation frequency is 10Mhz
@[as_macro] const cpu_freq = 4_000_000  // change it to 4Mhz
```

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

### Functions
| name                    | description               |
| ----------------------- | ------------------------- |
| `pin.setup(pin, mode)`  | Configure `pin` as `mode` |
| `pin.high(pin)`         | Turn On `pin`             |
| `pin.low(pin)`          | Turn Off `pin`            |
| `pin.toggle(pin)`       | Toggle the state of `pin` |
| `pin.write(pin, value)` | Write `value` in `pin`    |
| `pin.read(pin)`         | Return the state of `pin` |


### Digital pin names
The pin names are named with a letter indicating the port and a number indicating the pin. For example, `a6` indicates pin 6 of port A. All names in **Aixt** are written in lowercase, to follow [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Pin names for PIC16F8x
| Port  | 0    | 1    | 2    | 3    | 4    | 5     | 6     | 7     |
| :---: | ---- | ---- | ---- | ---- | ---- | ----- | ----- | ----- |
| **A** | `a0` | `a1` | `a2` | `a3` | `a4` | ----- | ----- | ----- |
| **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5`  | `b6`  | `b7`  |


## Pin ports
Use the `port` module:

```v
import port

port.setup(port.b, port.all_outputs)
port.setup(port.a, 0x00111111)  // port A bit 7 and 6 as outputs, the rest as inputs

val := port.read(port.a)
port.write(port.b, val) // port echo
```

### Functions
| name                      | description                |
| ------------------------- | -------------------------- |
| `port.setup(port, mode)`  | Configure `port` as `mode` |
| `port.read(port)`         | Return the value of `port` |
| `port.write(port, value)` | Write `value` to `port`    |

### Digital port names
The port names are named with a letter indicating the port. All names in **Aixt** are written in lowercase, to follow [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

### Pin names for PIC16F8x
| Port  | Aixt name |
| :---: | :-------: |
| **A** |    `a`    |
| **B** |    `b`    |


## Timer 0
Use the `timer0` module:

```v
import timer0

@[as_macro] const cpu_freq = 4_000_000  // 4Mhz

timer0.setup(10_000)    // setup a time of 10ms
.
.
.
t1 := timer0.read()
timer0.restart()
```

### Functions
| name                   | description                               |
| ---------------------- | ----------------------------------------- |
| `timer0.setup(period)` | Configure Timer0's `period`               |
| `timer0.read()`        | Return the value of Timer0                |
| `timer0.restart()`     | Restart the Timer0 from its initial value |
| `timer0.irq_enable()`  | Enable Timer0 overflow interrupt          |
| `timer0.irq_disable()` | Disable Timer0 overflow interrupt         |


## External Interrupt
Use the `ext` module:

```v
import ext

ext.setup(ext.falling)	// rising edge for external interrupt
ext.irq_enable()		// enable the interrupt
```

### Functions
| name                | description                         |
| ------------------- | ----------------------------------- |
| `ext.setup(edge)`   | Configure external interrupt `edge` |
| `ext.irq_enable()`  | Enable external interrupt           |
| `ext.irq_disable()` | Disable external interrupt          |