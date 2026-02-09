## v0.3
*9 Feb 2026*
This _Aixt_ version needs _Vlang_ *v0.5*.
#### Supported Devices
- Software emulator
- Mindstorms NXT
- PIC16F6xx-14p family
- PIC16F6xx-18p family
- PIC16F6xx-20p family
- PIC16F8x family
- PIC16F87x family
- PIC16F88x family
- Explorer16 (PIC24FJ128GA010)
- CY8CKIT-049-42xx (PSoC 4)
- CY8CKIT-145-40xx (PSoC 4)
- Arduino Uno
- Arduino Nano
- Arduino Mega
- Blue-Pill
- Nucleo-L031K6
- STM32G431Core
- STM32F411Core
- Raspberry Pi Pico
- XIAO-SAMD21
- XIAO-ESP32-xx (C3, C6, S3)
- ESP32-DevKitC
- ESP32-C3-CORE
- ESP32-C3FH4   
- M5Stack FIRE
- CH32V103R8T6-EVT-R1
Devices being updated:
- ESP32-CYD
- WCH families
  
#### Changes and new features
**Aixt CLI update**
- Migrate `aixt.v` file to an V's standard CLI app using `cli` module
- Aixt's `new` command has now an interactive mode (by flag)
- Implement the `init` command
- Interactive mode for `init` and `new`
- change `device` flag by `-target` (`-t`)
- make the Aixt executable receive `-c_compiler <cc_path>` (`-cc <cc_path>`) flag for the C compiler path
- make the Aixt executable receive `-flasher <flasher_path>` (`-f <flasher_path>`) flag for the flasher path
  
**Folder organization update**
- Split the examples from the API in all the targets creating `examples` folder
- Change `targets` folder name by `api`
- Change in all of the targets  `builtin.c.v` to `main/main.c.v`
- Change `/rp-pico/` by `/pico/`
- Change redundant names in `/examples/` folders
- Target names are case-insensitive now but the Aixt related files and folders are always lowercase 
- Add basic language test examples in `/test` folder
  - Create a folder by each test file including the project files
- Split the `docs` directory into `docs/api` and `docs/lib`
  
**API update**
- Object Oriented Programming enabled in the API for most of targets
- API and Aixt compiler now are number the same (0.3)
- Define as default the object oriented modules (`pin`, `motor`, etc) less in low memory devices like PICs
  - Define as standard module's name `module` for unique and OOP versions and `module_fn` for only-funcional ones
  - Update according the new names, the targets: NXT, Emulator and arduino devices (tested on Uno, Nano and Mega).
  - Create both functional and OOP version of modules `pin`, `adc`, `pwm`, `motor`, `sensor` and `button`  
  - Update all the Microchip targets to `pin_fn` 
  
**Editors update**
- VSCode `tasks.json` updated to also support Aixt as a Pixi workspace package
- Remove the fields `device` and `port` of `.vscode/settings.json`
- Modify `.vscode/tasks.json` according to the new `v.mod` file
- Modify `.zed/tasks.json` according to the new `v.mod` file
- Update `tasks.json` and `settings.json` according to the new `v.mod` file
  
**Solved issues**
- Arduino Mega and Nano `led0` is now public.
- Change all occurrences of `@[as_macro] const` by `@[as_macro] pub const`
- Aixt failed with V 0.4.12 or above ("-" in names affected it). Now it works on V 0.4.12 and 0.5
- Defining structs and use them in multiples files failed depending on the compiling order
  - Add to the `c_gen` struct the field `typedefs` 
- Global struct instances now work well
- Interrupts examples for `arduino` backend already work with `pin` y `pin_fn`
- Makefiles __device_name__ already works well
- Interrupts on PIC16F work back
- unknown PIC12 fuses solved
- `match` already works well with `C.variables`
- assignment using `match` already works
  
**README.md update**
- Add documentation about installing by using `conda`/`pixi`
  
**Configuration files update**
- Implement a new scheme for the `device.json` setup files
- Add a `v.mod` file inside each project folder in order including `device` and `port` fields
  - `transpile`, `c_compile` and `build` commands use the `v.mod` file if the flag `device` is not explicitly passed
  - `flash` command use the `v.mod` file if the flag `port` is not explicitly passed
- Update the `v.mod` file in all the Microchip targets
- Remove `aixt_linux` and `aixt_windows` from `settings.json`
- Change the fields `cc` and `flasher` of `setup/<target_name>.json` file, from `[windows_path]` `[linux_path]` to `[path]` and `[windows_path]` as optional
- Update all the setup files `*.json`to the new scheme
  - From `device.json` change `port:` by `target:`
- Change the fields `cc` and `flasher` of `setup.json` file, from `[flags]` to `[args]`
- Change `device:` by `target:` in the project's `v.mod` files
- Add the fields `cc:` and `flasher:` to the project's `v.mod` files
- Aixt executable now works using data from: direct flags, the `v.mod` file or default `setup/<target_name>.json` file, following this priority order.
- Change `aixt/AIXT` by `aixt_path/AIXT_PATH` in all the VSCode and Zed setup files.
  
**New features**
- Delete `nbc` compiler binaries from the repository (Linux and Windows versions)
- Enable conditional compilation based on `device.json` properties 
  - Include `$if c ? {}` syntax from `backend: c` of `device.json` 
  - Include `$if xc8 ? {}` syntax from `cc: { name: xc8 }` of `device.json` 
  - Change all the setup files name that contains '-' by '_'
  - Change all the setup files content that contains '-' by '_' in the fields: "target", "backend", "name" and "api_paths"
  - In the `api` folder change all the folders names that contains '-' by '_'
  - In the `api` folder change all the *.v file names that contains '-' by '_'
  - `PIC16F6xx_14p` ADC module modification by using conditional compilation: `$if PIC16F630 ? {`   
- Implement a `builtin` module similar to the _V's_ one
  - Implement `eprint()` function
- `#preinclude` command fully implemented and tested
- Generate the C macros (`@[as_macro]`) before de rest of constants and functions definition (functions and constants)
- Test and include in documentation the module `pin_fast` for PIC16 targets
- Update the PIC12Fxxx, PIC16F8x and PIC16F87x examples 
- generates documentation from code
  - Update the source files header to improve the visualization of the automatic documentation
  - Remove `/api/` from the end of targets implementation path  
  - Create 'dummy' modules as workspaces in API targets folders (Microchip and Arduino targets)
  - Change redundant targets API folders (Microchip and Arduino targets)
  - Change `/api/`,`/docs/`, `/setup/`, `examples/` and `/templates/project/` folders to lowercase
  - New script to generate `api/.../README.md` files, from `docs/.../quickref.md` and `api/.../header.md` 
  - Add the guide `Generate documentation from code.md`

#### Available Libraries
- disp7seg (7 Segments Arduino Shield)
- lcd (LCD Arduino Shield)
- For Arduino backend:
  - oled
  - random
  - tft_espi
  
## v0.2.3
*26 Oct 2025*
This _Aixt_ version needs _V_ *0.4.10*.
#### Supported Devices
Devices updated to API v0.2.0 (OOP enabled):
- Software emulator
- Mindstorms NXT
- PIC16F6xx-14p family
- PIC16F6xx-18p family
- PIC16F6xx-20p family
- PIC16F8x family
- PIC16F87x family
- PIC16F88x family
- Explorer16 (PIC24FJ128GA010)
- CY8CKIT-049-42xx (PSoC 4)
- CY8CKIT-145-40xx (PSoC 4)
- Arduino Uno
- Arduino Nano
- Arduino Mega
- Blue-Pill
- Nucleo-L031K6
- STM32G431Core
- STM32F411Core
- Raspberry Pi Pico
- XIAO-SAMD21
- XIAO-ESP32-xx (C3, C6, S3)
- ESP32-DevKitC
- ESP32-C3-CORE
- ESP32-C3FH4   
- M5Stack FIRE
- CH32V103R8T6-EVT-R1
Devices being updated:
- ESP32-CYD
- WCH families
#### Changes and new features
- Object Oriented Programming enabled (API v0.2.0)
  -  Issue solved: Structs can not be registered twice (due to the double parsing round). Solved clearing the symbol table between parsings
  -  Implement structs
    -  Implement structs declaring
    -  Implement struct instances declaring
    -  Implement struct fields access (`struct_name.struct_field`)
    -  Support struct methods (using the V standard)
  -  Add OOP features to the API (Emulator pin module, NXT motor module) 
  -  new 'pin_oop' object oriented pin module for Arduino backend (API v0.2.0)
  -  Issue solved: References to 'struct's fail generating C code
  -  In general API unify the name of the identification I/O parameter from 'name' to 'id', in all the targets for the modules `pin`, `adc` and `pwn` (along with their `_oop` version)
-  Issue solved: functions that returns pointers fail
-  Include casting on C generated code for 'return' commands
-  Change the C generation of commands: `import module { component }`, to reach it more to original V behavior (import all the `module` and enable a short pseudonym for `component`)
-  Generate the modules `arduino-generic-UARTx` instead of defining them for each target
-  Change the definition of builtin LEDs ans Switches from `builtin.c.v` to `pin.c.v` 
-  Unify most the ports implementation in only one file `module.c.v`
-  `pin_fast` module implemented for PIC16
-  Change the name of the devices/boards implementation folder from `ports` to `targets` 
-  NXT target API (motor, sensor and button modules) updated to v0.2.0 (OOP)
-  NXT test examples split in 'funcional' and 'struct-based' (object oriented approach)
-  Now the builtin inputs and outputs belong to `pin` module and require to be manual configured ans initialized
-  Issue solved: `/` characters produce errors on Windows. They were replaced by `os.path_separator` and `os.norm_path()`
-  Pass the definition of pin modes for all the Arduino backend devices to `arduino-generic/api/pin`
-  Folder `Test` deprecated
-  Update OLED examples
#### Available Libraries
- disp7seg (7 Segments Arduino Shield)
- lcd (LCD Arduino Shield)
- For Arduino backend:
  - oled
  - random
  - tft_espi
  
## v0.2.2
*22 Aug 2025*
#### Devices Supported
Devices updated to API v0.1.2:
- Software emulator
- Mindstorms NXT
- PIC16F6xx-14p family
- PIC16F6xx-18p family
- PIC16F6xx-20p family
- PIC16F8x family
- PIC16F87x family
- PIC16F88x family
- Arduino Uno
- Arduino Nano
- Arduino Mega
- Blue-Pill
- Nucleo-L031K6
- STM32G431Core
- STM32F411Core
- Raspberry Pi Pico
- XIAO-SAMD21
- XIAO-ESP32-xx (C3, C6, S3)
- ESP32-DevKitC
- ESP32-C3-CORE
- ESP32-C3FH4   
- M5Stack FIRE
Devices being updated:
- CY8CKIT-145
- CY8CKIT-049
- ESP32-CYD
- WCH families
#### Changes and new features
- Call Aixt directly from `.vscode/tasks.json` instead of running it through V compiler
- New devices supported PIC16F62x-648 including `uart`
- Issue solved: `module.c.v` is not parsed first when imported a module
- Issue solved: comments inside conditional compiling fails inside `as_macro` functions
- Issue solved: `as_macro` multiline functions fails when return a value
- Change "Aixt: C compile" taks by "Aixt: C Compile" in all `tasks.json` files
- Add snippets for `timer0` and `ext` modules for PIC16F family
- Group PIC16F630-676 and PIC16F684 as PIC16F6xx-14p
- Change PIC16F62x-648 to PIC16F6xx-18p
- Change PIC16F68x-690 to PIC16F6xx-20p
- Update snippets for PIC16F8x, PIC16F6xx-14p and PIC16F6xx-18p
- PIC12F6xx port implementation (`time`, `timer0`, `pin` and `ext` modules)
- Add template and "examples" folders for PIC12F6xx
- Issue solved: "flags" write mistake in some `.json` setup files
- Snippets updated for PIC devices (including `time`, `timer0`, `pin`, `port`, `adc`, `pwm` and `ext`)
- Update snippets for Arduino AVR
- Make `adc.setup()` automatically set the used pin channels as inputs on PIC devices
- Issue solved: change `as_macro` multiline functions due to the using of ({ ... }) fails in XC Microchip compilers
- Add the interrupts doc file.
- Block diagram updated
- Interrupts `timerX` and `ext` implemented for ST devices (Arduino backend)
#### Available Libraries
- disp7seg (7 Segments Arduino Shield)
- lcd (LCD Arduino Shield)
- For Arduino backend:
  - oled
  - random
  - tft_espi

## v0.2.1
*21 Jun 2025*
#### Devices Supported
Devices updated to API v0.1.2:
- Software emulator
- Mindstorms NXT
- PIC16F8x family
- PIC16F87x family
- PIC16F88x family
- Arduino Uno
- Arduino Nano
- Arduino Mega
- Raspberry Pi Pico
- ESP32-DevkitC
- Blue-Pill
- XIAO-SAMD21
- Nucleo-L031K6
- XIAO-ESP32-xx (C3, C6, S3)
- CY8CKIT-145
- CY8CKIT-049
- ESP32-DevKitC
- M5Stack FIRE
- STM32G431Core
Devices being updated:
- ESP32-CYD
- PIC16F6xx family
- WCH families
- Black-Pill
#### Changes and new features
- Generate the `arduino-ARM32` subfolder 
- Change aixt transpiler as a module with submodules
- Remove the passing of the aixt-path among functions
- Issue solved: C prototypes of `@[inline]` functions fail
- Changes `compile` Aixt option to `c_compile` (including vscode and zed `tasks.json`) 
- Generate a new transpiler script
- Implement and test (16F83_blinking, ESP32-C3FH4-blinking and Nano-random_bits) a new transpiler scheme
- New transpiler folder tree including submodules `builder`, `cgen`, `setup` and `util`
- Builtin LED and SWITCH auto-setup (Arduino-AVR)
- New external interrupt example for Blue Pill (non-tested) 
- For external interrupts on Arduino backend the pin has to be defined as constant
- Change '/' linux path separator by `os.path_separator` constant
- Enable input pulldown resistors in the API
- Change pin definitions as macros in most of the ports
- Change the interrupt service functions to be universal (not dependent of the backend)
- Add `pin.toggle()` function on Arduino ports
- Standardize the API component names containing numbers by `'<name><number>'` instead of `'<name>_<number>'`
- Update examples and the main diagram on `README.md`
- update the supported device list and link it to `README.md`
- update Emulator and NXT examples

## v0.2.0
*15 May 2025*
#### Devices Supported
Devices updated to API v0.1.2:
- Software emulator
- Mindstorms NXT
- PIC16F8x family
- PIC16F87x family
- Arduino Uno
- Arduino Nano
- Raspberry Pi Pico
- ESP32-DevkitC
- Blue-Pill
- XIAO-SAMD21
- Nucleo-L031K6
- XIAO-ESP32-xx (C3, C6, S3)
Devices being updated:
- Arduino Mega
- CY8CKIT-145
- CY8CKIT-049
- ESP32-CYD
- ESP32-DevKitC
- M5Stack FIRE
- PIC16F6xx and 16F88x families
- WCH families
- STM32G431Core
- Black-Pill
#### New features
- Implement `for in` commands on strings.
- Add custom `h/c`, `h/cpp` and `hpp/cpp` files to the project folder (to use custom c external libraries)
- New Timer0 functions and examples (PIC16F8x family) including interrupts
- Update Microchip XC8 devices to xc8-v3.00
- New type `Mutex` implemented in NXT port (`@[mutex]` attribute deprecated)
- New names for functions in NXT's `task` module
- NXT snippets file updated 
- `port` options added to all `settings.json` project files
- `flasher_linux`, `windows_path`, `flags` options added to all `setup.json` configuration files
- Implement `flash` option, to download the binary file to the device
- Help message updated
- Create M5Stack port
- `.aixt` extension is deprecated
- `Aixt: Flash` and `Aixt: Build & Flash` vscode tasks added to arduino-backend devices
- `random` module for arduino devices created
- IMU module created for the `M5Stack` port
- 6 tested examples for the `M5Stack` port
- Implement the folder structure for libraries
- Implement an example library
- Pass arrays as function parameters
- Update quickref.md files (Emulator, PIC16F8x, Arduino Nano)
- Move the `random` module from API to Libraries
- Implement External Interrupts on Arduino backend (AVR based)
- Change the function attribute management
- Change the External Interrupt for Arduino Nano using C macros with string concatenation
- Add an external interrupt example for Arduino Nano
- Unify the API of Arduino supported devices
- Improve the `clean` command, removing the all `.c`, `.cpp`, `.h` and `.hpp` files
- Update the ESP32-C3FH4 port (blinking led example tested)
- Standardize `pin.mode` on `pin.setup` for all arduino devicesSTM32G431Core
- New port Luatos/ESP32-C3-CORE (blinking led example tested)
- Update the W801 port (2 blinking led examples tested)
- Standardize the member vars `api_mod_paths` and `api_lib_paths` as maps
- Enable interrupts functions for Arduino devices in addition to the external interrupts
- create ESP32-CYD port and "tft_espi" library
- Support for Zed editor implemented
- Implement the PortB change interruption and pull-ups for PIC16F family
- Issue solved: `version` command only works running from aixt's main folder
- Issue solved: Array initialization fails the number of elements
- Issue solved: Conditional assign already works on V v0.4.9
- Issue solved: Conditional declare/assign statement already doesn't declare inner local variables
- Issue solved: `U16` type fails on Arduino backend
- Issue solved: Library modules are not 
- Issue solved: can not import a module from another module
- Issue solved: Constant array transpiling fails

## v0.1.9
*17 Jan 2025*
#### Devices Supported
Devices updated to API v0.1.2:
- Software emulator
- Mindstorms NXT
- PIC16F8x family
- Arduino Uno
- Arduino Nano
- Raspberry Pi Pico
- ESP32-DevkitC
- PIC16F8x
- Blue-Pill
- XIAO-SAMD21
New Devices:
- Nucleo-L031K6
- XIAO-ESP32-xx (C3, C6, S3)
#### New features:
- Implement the basic structure of interrupts (attribute `@[XXXX_isr]`)
- Implement external interrupts on PIC16F8x microcontroller family.
- Implement the constant `cpu_freq` for changing the default cpu frequency defined on `.json` file
- Basic implementation of the "ArrayDecompose" expression
- Functions `@[as_macro]` now allow variable number of arguments
- Arrays and fixed-arrays now supports initialization by `{init: value}` syntax
- Empty array declaring now allowed
#### Changes
- Change Raspberry-Pi-Pico port name by "RP-Pico"
- Update the `Setup file.md` in `doc` folder. (`Setup files.md` )
- Explorer 16 PIC24 setup files updated 
- Change Exp16-PIC24 port name by "Exp16-PIC24"
- Nucleo-L031K6 project template created
- Issue solved: Unpacking type layout (symbol table)
- NXT port updated to API v0.1.2
- NXT snippets updated
- Change builtin LED name to `led0`
- Issue solved: main constants and globals can be invoked omitting `main.` now.
- Issue solved: array_init for non-fixed arrays fails
- Blue-Pill port updated to API v0.1.2
- XIAO-SAMD21 port updated to API v0.1.2
- XIAO-ESP-xx port created
- Templates updated: Arduino-Nano, Arduino-Uno, Emulator, ESP32-DevkitC, Exp16-PIC24, PIC16F8x, PIC16F88x, RP-Pico, W801, Blue-Pill, Nucleo-L031K6, XIAO-ESP32-xx, XIAO-SAMD21, NXT
- Add `symlink` option to help command 


## v0.1.8
*03 Dic 2024*
#### Devices Supported
Devices updated to API v0.1.2
- Software emulator
- PIC16F8x family
- Arduino Uno
- Arduino Nano
- Raspberry Pi Pico
- ESP32-DevKitC


## v0.1.7
*21 Nov 2024*
#### Devices Supported
Devices updated to API v0.1.2
- Software emulator
- PIC16F8x family
- Arduino Uno
- Arduino Nano
- Raspberry Pi Pico


## v0.1.6
*15 Nov 2024*
#### New features:
- Standardize the basic data types as V
- Add a typedef declaration for each compiler type in .json file (remove the necessity to do code replacements)
- Give support to "type" aliassing
- Add a custom attribute for defining constants and functions as C macros in order to save memory in small devices
- Define API modules' parameters as constants
- Allow implementation of the same Module on multiple directories


## v0.1.5
*8 Oct 2024*
#### Changes
- Give support to `in` and `!in` operands on arrays
- Solve the issue of `else` statements shown from V v0.4.7 onwards


## v0.1.4
*2 Oct 2024*
#### New features
Differente versions of `match` statement were implemented:
- regular `match`;
  - With one or multiple identifiers or literas
  - With one or multiple *Infix* expressions (comparisons)
  - With one or multiple ranges
- assignment by `match`:
  - With one or multiple identifiers or literas
  - With one or multiple *Infix* expressions (comparisons)
  - With one or multiple ranges
The `match` statements for *enums* are not allowed yet.


## v0.1.3
*28 Sep 2024*
#### New features
All the setup files were migrated from `.toml` to `.json`


## v0.1.2
*27 Sep 2024*
#### Devices Supported
Devices updated to API v0.1.1
- Software emulator
- PIC16F8x family
- Arduino Uno
- Arduino Nano
- ESP32-DevKitC
- Raspberry Pi Pico
#### New features
- Compile option was turned into more universal behavior by using pseudo variables inside `.toml` files
- API modules can be written in both `module` and `module_complement` folders
- API implementations can be reused by similar ports or devices calling them from the `.toml`
- Generate C templates for most of the Aixt's V expression and statements using `$tmpl`


## v0.1.1
*12 Sep 2024*
Issue solved.


## v0.1.0
*11 Sep 2024*
#### Aixt V language
Now Aixt V is closer to original V due to:
- All the variables are immutable by default. The `mut` reserved word is fully supported.
- Only a few C pre-processor directives are supported (#include)
- C macros are avoided
- The Aixt API is implemented mainly in V
- Reference variables are supported
- Interoperability with C is improved by allowing the calling of C functions, constants and variables by using the syntax: `C.function()` or `C.identifier`, previous including the correspondent C header file
- declaration/initialization by function calling directly
##### Changes:
- The pin names and modes don´t include the module's name so `pin.setup(pin.d5, pin.output)` changes to `pin.high(d5, output)`, this change is for been less redundant.
- All the variables are immutable by default. If a mutable variable is needed, the use of mut reserved word is imperative.
- Variables can be declared/initialized by calling a function directly, so this two lines: `a := u16(0)` `a = adc.read(an5)` can be replaced by: `a := adc.read(an5)`
#### API standardization
(v0.1.0)
The function names were standardized for these modules:
- `pin`: individual pins
- `port`: pin ports
- `adc`: analog to digital converter
- `pwm`: pulse width modulation
- `uart`: serial port
- `time`: delaying functions
#### Configuration `.toml` files
Now the configuration files are split by device-settings and compiler-settings in different `.toml` files, in order to reuse and make it easy to include similar devices.
#### Supported devices
##### Emulator
Software emulator on Linux, Android (Termux) and Windows (x64-based or AArch64-based device: x64 or AArch64), using GCC or TCC compilers.
##### Microchip
- PIC16F8x family
  - PIC16F83
  - PIC16F83A
  - PIC16F84
  - PIC16F84A
##### Arduino boards
- Arduino Uno
- Arduino Nano
*The rest of devices or boards have to be migrated from API v0.0.1*


## v0.0.1
*03 Jul 2024*
#### Supported Modules:
(API v0.0.1)
- ADC
- PWM
- GPIO
- UART
#### Supported Devices:
- Emulator on Linux, Android (Termux) and Windows (x64-based or AArch64-based device: x64 or AArch64)
- LEGO Mindstorms NXT (NXT Intelligent Brick: AT91SAM7S256 (ARM7TDMI) "nxc backend")
- Microchip
    - PIC16F84A (Delay, GPIO)
    - PIC16F676 (Delay, GPIO, ADC)
    - PIC16F873A
    - PIC16F886
    - PIC18F452
    - PIC18F2550
    - Explorer 16: (PIC24FJ128GA010 )
- Atmel
    - MH-Tiny: ATtiny88 "arduino backend"
    - Arduino nano: ATmega328p "arduino backend"
- Seeed Studio
    - Seeed Studio XIAO SAMD21: ATSAMD21G18 (Cortex-M0+) "arduino backend"
- LogicGreen
    - LQFP32 MiniEVB: lgt8f328p "arduino backend"
- Espressif
    - NodeMCU V3 Lua: ESP8266 (LX106) "arduino backend"
    - ESP32-C3FH4 Core Board (WeAct Studio): ESP32-C3 (RV32) "arduino backend"
- ST
    - Blue Pill: STM32F103C6 (Cortex-M3) "arduino backend"
- LuatOS
    - CORE-Air32F103CBT6: air32f103 (Cortex-M3) "arduino backend"
- Raspberry Pi
    - Raspberry Pi Pico: RP2040 (Dual Cortex-M0+) "arduino backend"
    - Raspberry Pi Pico W: RP2040 (Dual Cortex-M0+) "arduino backend"
- Ai-Thinker
    - Ai-WB2-32S-Kit: BL602 "arduino backend" (Delay, GPIO, PWM, UART)
#### Backends:
- c
- arduino
- nxc
#### V language features not supported yet:
- OOP (functions associated to structures)
- match keyword
- inmutable variables by default (mut keyword unsupported)
- declaration/initialization by function calling
- dynamic memory