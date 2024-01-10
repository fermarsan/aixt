# **_Aixt_** API folder tree
The _Aixt_ API for each microntroller port has to be located in the folder:
```
./ports/brand/microcontroller_or_board/api
```
for instance:
```
./ports/Microchip/Explorer-16/PIC24/api
```

All the API implementations have to follow this basic folder tree:

```
ports/Microchip/Explorer-16/PIC24/api/
├── builtin.c
├── machine
│   ├── adc.c
│   ├── pin.c
│   ├── pwm.c
│   └── uart.c
└── time
    ├── sleep.c
    ├── sleep_ms.c
    └── sleep_us.c
```

starting from the _Aixt_ project main folder.

The _Aixt_ API is composed by several modules with certain microcontroller fuctionality. All the API functions refering to the available inner hardware or peripherals of each microcontroller are located in the module named `machine`. Other functions refering to generic functionalities are located in a respective module named according them. For example, all the functions refering to time or delying are located in the `time` module.

In order to follow the _V language_ syntactic rules, all the folder and file names inside the api folder must use **snake_case**.

## Modules
Each module in the API have to be implemented by means of a _C_'s files in the module_name/ folder. For example, the `time` module is implemented in `time/` as follows: 
```
api
 ├── ...
 :
 └── time/
      ├── sleep_ms.c
      └── sleep_us.c
```

## Optimization levels
_Aixt_ projects uses _C_ code optimization levels according to the way of describing each API fucntion on _C_ language. The optimization level is specified with the ending `_n`, where `n` is the optimization level starting from `0` (**WIP**). 

