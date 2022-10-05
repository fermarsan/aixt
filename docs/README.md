
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
# Supported Microcontrollers

## PIC

- **16-bit**
    - PIC24FJ128GA010
    - dsPIC33FJ256GP710A

- **8-bit**
    - PIC18F4550
    - PIC18F452
    - PIC16F866
    - PIC16F873A
    - PIC16F628A
    - PIC16F84A
    - PIC12F1822

## AVR
- ATmega328p

## Cypress

- **PSoC 1**
    - Cy8c2744324pxi

## Espressif
- ESP8266

## Raspberry Pi
- RP2040


