## aixt0.1.9
*17 Jan 2025*

#### Devices Supported
Devices updated to API aixt0.1.2:
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
- Change builtin LED name to `led_0`
- Issue solved: main constants and globals can be invoked omitting `main.` now.
- Issue solved: array_init for non-fixed arrays fails
- Blue-Pill port updated to API v0.1.2
- XIAO-SAMD21 port updated to API v0.1.2
- XIAO-ESP-xx port created
- Templates updated: Arduino-Nano, Arduino-Uno, Emulator, ESP32-DevkitC, Exp16-PIC24, PIC16F8x, PIC16F88x, RP-Pico, W801, Blue-Pill, Nucleo-L031K6, XIAO-ESP32-xx, XIAO-SAMD21, NXT


## aixt0.1.8
*03 Dic 2024*
#### Devices Supported
Devices updated to API aixt0.1.2
- Software emulator
- PIC16F8x family
- Arduino Uno
- Arduino Nano
- Raspberry Pi Pico
- ESP32-DevKitC


## aixt0.1.7
*21 Nov 2024*
#### Devices Supported
Devices updated to API aixt0.1.2
- Software emulator
- PIC16F8x family
- Arduino Uno
- Arduino Nano
- Raspberry Pi Pico


## aixt0.1.6
*15 Nov 2024*
#### New features:
- Standardize the basic data types as V
- Add a typedef declaration for each compiler type in .json file (remove the necessity to do code replacements)
- Give support to "type" aliassing
- Add a custom attribute for defining constants and functions as C macros in order to save memory in small devices
- Define API modules' parameters as constants
- Allow implementation of the same Module on multiple directories


## aixt0.1.5
*8 Oct 2024*
#### Changes
- Give support to `in` and `!in` operands on arrays
- Solve the issue of `else` statements shown from V aixt0.4.7 onwards


## aixt0.1.4
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


## aixt0.1.3
*28 Sep 2024*
#### New features
All the setup files were migrated from `.toml` to `.json`


## aixt0.1.2
*27 Sep 2024*
#### Devices Supported
Devices updated to API aixt0.1.1
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


## aixt0.1.1
*12 Sep 2024*
Issue solved.


## aixt0.1.0
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
(aixt0.1.0)
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
*The rest of devices or boards have to be migrated from API aixt0.0.1*


## aixt0.0.1
*03 Jul 2024*
#### Supported Modules:
(API aixt0.0.1)
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