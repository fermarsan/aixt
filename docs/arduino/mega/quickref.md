# Quick reference for the Arduino Mega board

The original pin names can be shown in the [Arduino Mega Pinout](https://docs.arduino.cc/resources/pinouts/A000067-full-pinout.pdf).


## Delay and Timing
Use the `time` module:

```v
import time

time.sleep(2)            // sleep for 2 seconds
time.sleep_ms(50)        // sleep for 50 milliseconds
time.sleep_us(100)       // sleep for 100 microseconds
```

### Functions
| name                  | description           |
|-----------------------|-----------------------|
| `time.sleep(time)`    | Delay in seconds      |
| `time.sleep_us(time)` | Delay in microseconds |
| `time.sleep_ms(time)` | Delay in milliseconds |


## Onboard Hardware
The onboard LED is named `led0`:

```v
import pin

pin.setup(pin.led0, pin.output)
pin.high(pin.led0)
```


## Pin module
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
|-------------------------|---------------------------|
| `pin.setup(pin, mode)`  | Configure `pin` as `mode` |
| `pin.high(pin)`         | Turn On `pin`             |
| `pin.low(pin)`          | Turn Off `pin`            |
| `pin.write(pin, value)` | Write `value` in `pin`    |
| `pin.read(pin)`         | Return the state of `pin` |


### Digital pin names
The digital pin names are named from `d0` to `d69`.

| name  | original name |
|:-----:|:-------------:|
| `d0`  |      D0       |
| `d1`  |      D1       |
|  ...  |      ...      |
| `d68` |      D68      |
| `d69` |      D69      |


## Pin port module
Use the `port` module:

```v
import port

port.setup(port.b, port.all_outputs)
port.setup(port.c, port.all_inputs)  // port A bit 7 and 6 as outputs, the rest as inputs

val := port.read(port.c)
port.write(port.b, val) // port echo
```

### Functions
| name                      | description                |
|---------------------------|----------------------------|
| `port.setup(port, mode)`  | Configure `port` as `mode` |
| `port.read(port)`         | Return the value of `port` |
| `port.write(port, value)` | Write `value` to `port`    |

### Digital port names
| name | original name |
|:----:|:-------------:|
| `b`  |       B       |
| `c`  |       C       |
| `d`  |       D       |
| `e`  |       E       |
| `f`  |       F       |
| `g`  |       G       |
| `h`  |       H       |
| `i`  |       I       |
| `j`  |       J       |
| `k`  |       K       |


## PWM (Pulse Width Modulation)
Use the `pwm` module:

```v
import pwm

pwm.write(pwm.ch0, 40)       // set the duty cycle for PWM channel 0
pwm.write(pwm.ch1, 60)       // set the duty cycle for PWM channel 1
```

### Functions

| name                        | description                        |
|-----------------------------|------------------------------------|
| `pwm.write(channel, value)` | Write `value` in the PWM `channel` |

### PWM pin names
The PWM channels are named from `ch0` to `ch13`.

|  name  | original name |
|:------:|:-------------:|
| `ch0`  |      D0       |
| `ch1`  |      D1       |
| `ch2`  |      D2       |
| `ch3`  |      D3       |
| `ch4`  |      D4       |
| `ch5`  |      D5       |
| `ch6`  |      D6       |
| `ch7`  |      D7       |
| `ch8`  |      D8       |
| `ch9`  |      D9       |
| `ch10` |      D10      |
| `ch11` |      D11      |
| `ch12` |      D12      |
| `ch13` |      D13      |


## ADC (Analog to Digital Converter)
Use the `adc` module:

```v
import adc

val1 := adc.read(adc.ch0)       // read de ADC channel 0
val2 := adc.read(adc.ch1)       // read de ADC channel 1
```

### Functions
| name                | description                       |
|---------------------|-----------------------------------|
| `adc.read(channel)` | Return the ADC value in `channel` |

### Analog channels
The PWM channels are named from `ch0` to `ch7`.

|  name  | original name |
|:------:|:-------------:|
| `ch0`  |    A0/D54     |
| `ch1`  |    A1/D55     |
| `ch2`  |    A2/D56     |
| `ch3`  |    A3/D57     |
| `ch4`  |    A4/D58     |
| `ch5`  |    A5/D59     |
| `ch6`  |    A6/D60     |
| `ch7`  |    A7/D61     |
| `ch8`  |    A8/D62     |
| `ch9`  |    A9/D63     |
| `ch10` |    A10/D64    |
| `ch11` |    A11/D65    |
| `ch12` |    A12/D66    |
| `ch13` |    A13/D67    |
| `ch14` |    A14/D68    |
| `ch15` |    A15/D69    |


## UART (serial port)
Use the `uart` module:

```v
import uart

uart.print('Hello ')
uart.println('World...')
```

### Functions
| name                    | description                                                    |
|-------------------------|----------------------------------------------------------------|
| `uart.setup(baud_rate)` | Configure the `baud_rate` of the UART                          |
| `uart.read()`           | Return one character received by UART                          |
| `uart.input(message)`   | Send the `message` and then return the string received by UART |
| `uart.write(character)` | Send one character by UART                                     |
| `uart.print(message)`   | Send the `message` by UART                                     |
| `uart.println(message)` | Send the `message` plus a new line by UART                     |
| `uart.any()`            | Return the number uf characters in the UART's buffer           |


## Examples

### LED Blinking
```v
import time
import pin

pin.low(pin.led0)	// turn off the on-board LED

for {
	pin.toggle(pin.led0)    // LED toggle 
	time.sleep_ms(500)  // delay
}

```

### ADC value sent by UART
```v
import time
import uart
import adc

uart.setup(9600)	// set the baudrate

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}
```

### LED Blinking by Interrupt
```v
import pin
import ext

@[ext_isr:'pin.d2']	// interrupt service routine
fn blink() {
	pin.toggle(pin.led0)
}

pin.setup(pin.d2, pin.input)
pin.low(pin.led0)

ext.irq_enable(pin.d2, ext.change)	// interrupt request enabled

for {
	// Empty infinite loop
}
```
