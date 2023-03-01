# **_Aixt_** API folder tree
The _Aixt_ API for each microntroller implementation has to be located in the folder:
```
./platforms/microcontroler_or_board/api
```
for instance:
```
./platforms/Explorer-16-PIC24/api
```

 All the API implementations have to follow this basic folder tree:
```
api
 ├── setup.h
 ├── machine.h
 ├── machine/
 │    ├── machine__pin.h
 │    ├── machine__adc.h
 │    └── machine__uart.h
 ├── time.h
 └── time/
      ├── time__sleep_ms.h
      └── time__sleep_us.h
```

starting from the _Aixt_ project main folder.

The _Aixt_ API is composed by several modules with certain microcontroller fuctionality. All the API functions refering to the abailable inner hardware or peripherals of each microcontroller are located in the module named `machine`. Other functions refering to generic functionalities are located in a respective module named according them. For example, all the functions refering to time or delying are located un the `time` module.

In order to follow the _V language_ syntactic rules, all the folder and file names inside the api folder must be lowercased.

## Modules
Each module in the API have to be implemented by means of a C's header file and a folder. For example, the `time` module is implemented as `time.h` and `time/`: 
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
Then the transpiled C code will be:
```c
#include time/time__sleep_ms.h
``` 
In this case the C compiler only will compile and include in binary output file, the `time__sleep_ms.h` file.

On the other hand, the user can import all the functions in `time` module like this:
```go
import time
``` 
Then the transpiled C code will be:
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
