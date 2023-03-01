# **_Aixt_** API folder tree
The _Aixt_ API is composed by several modules with certain microcontroller fuctionality. All the API functions refering to the abailable inner hardware or peripherals of each microcontroller are located in the module named `machine`. Other functions refering to generic functionalities are located in a respective module named according them.  modules All the API implementations follow this basic folder tree:

```
API/
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

## File names
All the module files have to be named with a prefix which indicates the module's name. For instance the file which contains the `pin` functions, belongs to the `machine` module, then it is named:
```
machine__pin.h
```
The prefix is the module's name plus a double underscore character.
