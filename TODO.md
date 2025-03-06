# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] Issue: Ident names including module and function name or scope position (for all ports)
- [ ] Implement `lock` and `rlock` keywords (initially for NXT port)
- [ ] Implement an equivalent to Arduino's `millis()`
- [ ] Implements sub-modules
- [ ] Implement CH32V and CH5xx families on Arduino through PlatformIO
- [ ] Add a configuration file inside each project folder in order to make it easy to integrate Aixt to and IDE like PlatformIO


### In Progress

- [ ] generates documentation from code
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] implement maps
- [ ] Change arrays to pure V
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Implement float formatting on string interpolations (`${x:.2}`)
- [ ] Issue: Calling function from array interpolations
- [ ] Issue: can not import a module from another module
- [ ] Standardize the member vars `api_mod_paths` and `api_lib_paths` as maps

### Done ✓make

- [x] Issue solved: `version` command only works running from aixt's main folder
- [x] Update Microchip XC8 devices to xc8-v3.00
- [x] New Timer0 example (PIC16F8x family)
- [x] Implement Timer0 functions
- [x] New type `Mutex` implemented in NXT port (`@[mutex]` attribute deprecated) 
- [x] New names for functions in NXT's `task` module
- [x] NXT snippets file updated
- [x] `port` options added to all `settings.json` project files
- [x] `flasher_linux`, `flasher_windows`, `flasher_flags` options added to all `setup.json` configuration files
- [x] Implement `flash` option, to download the binary file to the device
- [x] Help message updated
- [x] Create M5Stack port
- [x] `.aixt` extension is deprecated
- [x] `Aixt: Flash` and `Aixt: Build & Flash` vscode tasks added to arduino-backend devices 
- [x] Issue solved: Conditional assign already works on V v0.4.9
- [x] Issue solved: Conditional declare/assign statement already doesn't declare inner local variables
- [x] `random` module for arduino devices created
- [x] IMU module created for the `M5Stack` port 
- [x] 6 tested examples for the `M5Stack` port 
- [x] Implement the folder structure for libraries
- [x] Implement an example library
- [x] Issue solved: Array initialization fails the number of elements
- [x] Pass arrays as function parameters
- [x] Issue solved: `U16` type fails on Arduino backend
- [x] Update quickref.md files (Emulator, PIC16F8x, Arduino Nano) 
- [x] Move the `random` module from API to Libraries  
- [x] Implement External Interrupts on Arduino backend (AVR based)
- [x] Change the function attribute management
- [x] Change the External Interrupt for Arduino Nano using C maros with string concatenation
- [x] Add an external interrupt example for Arduino Nano
- [x] Unify the API of Arduino supported devices 
- [x] Add custom h/c, h/cpp and hpp/cpp files to the project folder (to use custom c external libraries)
- [x] Improve the `clean` command, removing the all .c, .cpp, .h and .hpp files
- [x] Update the ESP32-C3FH4 port (blinking led example tested) 
- [x] Standardize `pin.mode` on `pin.setup` for all arduino devices 
- [x] New port Luatos/ESP32-C3-CORE (blinking led example tested) 
- [x] Update the W801 port (2 blinking led examples tested) 