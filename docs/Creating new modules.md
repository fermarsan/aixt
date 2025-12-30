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
