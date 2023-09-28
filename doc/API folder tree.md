# **_Aixt_** API folder tree
The _Aixt_ API for each microntroller port has to be located in the folder:
```
./ports/brand/microcontroler_or_board/api
```
for instance:
```
./port/Explorer-16/PIC24/api
```

All the API implementations have to follow this basic folder tree:
```
api
 ├── builtin.c
 ├── machine.c
 ├── machine/
 │    ├── pin.c
 │    ├── adc.c
 │    └── uart.c
 ├── time.c
 └── time/
      ├── sleep_ms.c
      └── sleep_us.c
```

<!-- Raspberry-Pi-Pico
 └── projects/
      └── blinking/
           ├── blinking.ino
           └── api/
               ├── builtin.c
               ├── machine/
               │    └── pin.c
               └── time/
                    └── sleep_ms.c

#include "api/builtin.c"
#include "api/machine/pin.c"
#include "api/time/sleep_ms.c" -->


starting from the _Aixt_ project main folder.

The _Aixt_ API is composed by several modules with certain microcontroller fuctionality. All the API functions refering to the abailable inner hardware or peripherals of each microcontroller are located in the module named `machine`. Other functions refering to generic functionalities are located in a respective module named according them. For example, all the functions refering to time or delying are located un the `time` module.

In order to follow the _V language_ syntactic rules, all the folder and file names inside the api folder must use **snake_case**.

## Modules
Each module in the API have to be implemented by means of a _C_'s header file and a folder. For example, the `time` module is implemented as `time.h` and `time/`: 
```
api
 ├── ...
 :
 ├── time.h
 └── time/
      ├── time__sleep_ms.h
      └── time__sleep_us.h
```
The `time/` folder also contains other header or source files.

The porpose of implementing this file-folder scheme is optimizing the amount of header or source files to be compiled by module. For instance, if the user only going to use the function `sleep_ms`, it can import it especificaly as:
```go
import time { sleep_ms }
``` 
Then the transpiled _C_ code will be:
```c
#include time/time__sleep_ms.h
``` 
In this case the _C_ compiler only will compile and include in binary output file, the `time__sleep_ms.h` file.

On the other hand, the user can import all the functions in `time` module like this:
```go
import time
``` 
Then the transpiled _C_ code will be:
```c
#include time.h
``` 
this will include the `time.h` file, which will include all the header files inside `time/`, in this case `time_sleep_ms.h` and `time_sleep_us.h`. 

## File names
All the module files have to be named with a prefix which indicates the module's name. For instance the file which contains the `pin` functions, belongs to the `machine` module, then it is named:
```
machine__pin.h
```
The prefix is the module's name plus a double underscore character.

## Optimization levels
_Aixt_ projects uses _C_ code optimization levels according to the way of describing each API fucntion on _C_ language. The optimization level is specified with the ending `_n`, where `n` is the optimization level starting from `0`. 

For example the regular version of the `pin` file will be:
```
machine__pin_0.h
```  

