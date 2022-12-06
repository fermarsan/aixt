
--------------------
# Supported Aixt language features

- Inspired by the _V language_ grammar [https://vlang.io/](https://vlang.io/)
    - _Golang_ grammar was taken as reference [https://github.com/antlr/grammars-v4/tree/master/golang](https://github.com/antlr/grammars-v4/tree/master/golang)
    - as well as _Rust_ grammar [https://doc.rust-lang.org/stable/reference/](https://doc.rust-lang.org/stable/reference/)
- Integer literals in binary, octal, hexadecimal and decimal notation
- Floating point, rune, string and boolean literals
- Literals with '_'
- Declaration of signed and unsigned 8, 16, 32 and 64 bit integer variables (also isize and usize)
- Declaration of variables in floating point of 32 and 64 bits
- Single and multiple declaration and assignment
- Declaration by default type inference
- By default all variables are mutable, so `mut` keyword is not supported 
- line and block comments
- bitwise arithmetic and logical operations
- parentheses in expressions
- comparison operations
<!-- - of compound operations '+=', etc. -->
- block expressions '{ Code_block }' (a tab is added to the block in the uotput file)
<!-- - function declarations and return values
- if-else statements, infinity for , for as while -->

# Other features

- YAML setup file support

----------------------------
# Supported devices and boards

## Microchip
- **8-bit 16F**
    - PIC16F84A
    - PIC16F628A
    - PIC16F676
    - PIC16F873A
    - PIC16F886
- **8-bit 18F**
    - PIC18F452
    - PIC18F2550
- **16-bit**
    - _Explorer 16_: PIC24FJ128GA010
    - _Explorer 16_: dsPIC33FJ256GP710A

## AVR
- _MH-Tiny_: ATtiny88 **_soon....._** 
- _Arduino nano_: ATmega328p

## LogicGreen 
- _LQFP32 MiniEVB_: lgt8f328p **_soon....._**

## Cypress

- **PSoC 1**
    - Cy8c2744324pxi

## Espressif
- ESP8266 **_soon....._**
- ESP32 **_soon....._**
- _CORE-ESP32_: ESP32-C3 **_soon....._**

## ST
- STM32F103C6 **_soon....._**

## LuatOS
- _CORE-Air32F103CBT6_: air32f103 **_soon....._**

## Raspberry Pi
- _Raspberry Pi Pico_: RP2040 **_soon....._**
- _Raspberry Pi Pico W_: RP2040 **_soon....._**

## WCH
- _CH552 Core Board_: CH552 **_soon....._**

## WinnerMicro
- W801-C400 **_soon....._**




