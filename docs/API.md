# **_Aixt_** Application Programming Interface v0.1.2

## Digital I/O (Pins)
requires:
```v
import pin
```

### Pin setup
```v
pin.setup(name, mode)
```
- `name` could change depending on the microcontroller for instance `pin.b7`, `pin.gp7`, etc.
- `mode`:
  - `pin.input`
  - `pin.output`

### Pin output
```v
pin.high(name)
```

```v
pin.low(name)
```

```v
pin.toggle(name)    
// not available for all devices
```

```v
pin.write(name, value)
```
- `value` is an integer to be written in the pin
  - `0`
  - `1`


### Pin input
```v
x = pin.read(name)
```
`pin.read()` returns an integer (`0` or `1`)

## Analog to Digital Converter (ADC inputs)
requires:
```v
import adc
```

The syntax for all the ADC functions is: `adc.function_name()`.


### ADC setup
```v
adc.setup(setup_value_1, setup_value_2, ... )   // equals to adc1_setup(...)
```

### ADC reading
```v
x = adc.read(channel)
```
- `channel` is an identifying number of the ADC input, for instance `adc.ch3`


## Pulse Width Modulation (PWM outputs)
requires:
```v
import pwm
```

The syntax for all the PWM functions is: `pwm_function_name()`.

### PWM setup
```v
pwm_setup(setup_value_1, setup_value_2, ... )  //or just pwm.setup(...)
```

### PWM duty cycle
```v
pwm.write(channel, duty)  //or pwm1_duty(duty)
```

- `duty` is the duty cycle (8-bit number in most of devices)
- `channel` is th output or channel name, for instance `pwm.ch1`


## Serial communication (UART)
requires:
```v
import uart
```

The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uartx.function_name()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart.setup(baud_rate)   // the same of uart1_setup(baud_rate)
```
- `baud_rate` configure the communication speed

### Serial receiving
```v
str1 = uart.input()          // read a string from the default UART
```
```v
str2 = uart2.input()    // read a string from UART2
```
```v
str2 = uart1.read()    // read a single Byte from UART1
```

### Serial transmitting
```v
uart.print(message)      // print a string to the default UART
```
```v
uart.println(message)    // print a string plus a line-new character to the default UART
```
```v
uart2.print(message)    // print a string to the UART2
```
```v
uart3.println(message)  // print a string plus a line-new character to the UART3
```
```v
uart2.write(message)    // send binary data (in Bytes) to UART2
```


## Delay
requires:
```v
import time
```


```v
time.sleep(s)    // delay in seconds
```
```v
time.sleep_ms(ms)    // delay in milliseconds
```
```v
time.sleep_us(us)    // delay in microseconds
```


# Creating a new API module

### File `function_name.c.v`.
All functions implemented in each **Aixt** module have a file named: 
`function_name.c.v` where it is done its implementation.

For instance the `setup` function of the `adc` module, which sets the resolution of the ADC, has to be described in `adc/setup.c.v`.

In devices using the **arduino** _backend_ most functionalities just have to be masked instead of implementing them from scratch. In this case the `setup` function in **V** masks the `analogReadResolution` function of **arduino**.

All functions have to be public (`pub`).

The `@[inline]` attribute is optional and defines the function created in C to be `inline`.


### File `module_name.c.v`.
All modules implemented in the `api` directory have a file with the same name as the module. For example the `pwm` module must have a `pwm.c.v` file where the basic definitions for the module are made.

In this case the functions to be invoked from C (arduino) are defined.

V allows the `any` data type which is practical if the return data type and/or parameters of the function to be masked are not known.

In this case the implementation can be left as is.

### File inclusion in C
API modules in **Aixt** can include `.c` or `.h` files with the `#include <lib.h>` or `#include “lib.h”` directive. Note that files enclosed in `"` will be searched in the same directory.


### Masking of arduino methods
In the case of the **arduino** _backend_, functions defined as methods can be redefined as macros in a `.c` file so that they can be `called` from V without problems.

Replacing the `.` with `_`.


And each function to be implemented or masked is described in a separate `.c.v` file, so that it can be called independently from V in order to use as little memory as possible if desired by the user.

In this case we must replace `Serial1` by just `Serial` in all functions.


We delete the unsupported modules
and that's it

Now let's compile the examples to corroborate the operation.

We rename the examples folders and the `.v` files.

it is advisable to open a different vscode session with only the example project file.

we must modify the `settings.json` file in the `.vscode` directory with the name of the new device.

In the case of the flicker example, the transcompilation generated the `.ino` file and the output binary file in the `build` folder.

now we test it in the **Wokwi** simulator
we can copy the generated code to the simulator

As we can see the example of the blinking works