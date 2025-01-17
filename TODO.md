# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] change "set" by "setup" in sensor module (NXT port)
- [ ] Issue: Ident names including module and function name or scope position (for all ports)


### In Progress

- [ ] generates documentation from code
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] implement maps
- [ ] Change arrays to pure V
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Implement Timer0 functions


### Done ✓

- [x] Implement the basic structure of interrupts (attribute `@[XXXX_isr]`)
- [x] Implement external interrupts on PIC16F8x microcontroller family.
- [x] Implement the constant `cpu_freq` for changing the default cpu frequency defined on `.json` file
- [x] Change Raspberry-Pi-Pico port name by "RP-Pico"
- [x] Update the `Setup file.md` in `doc` folder. (`Setup files.md` )
- [x] Explorer 16 PIC24 setup files updated 
- [x] Change Exp16-PIC24 port name by "Exp16-PIC24"
- [x] Nucleo-L031K6 project template created
- [x] Issue solved: Unpacking type layout (symbol table)
- [x] Basic implementation of the "ArrayDecompose" expression
- [x] Functions `@[as_macro]` now allow variable number of arguments
- [x] Arrays and fixed-arrays now supports initialization by `{init: value}` syntax
- [x] Empty array declaring now allowed
- [x] NXT port updated to API v0.1.2
- [x] NXT examples transpiled successfully  
- [x] NXT button and LCD modules updated
- [x] NXT snippets updated
- [x] Change builtin LED name to `led_0`
- [x] Issue: main constants and globals can be invoked omitting `main.` now.
- [x] Issue: array_init for non-fixed arrays fails
- [x] Blue-Pill config updated
- [x] Nucleo-L031K6 examples transpiled successfully
- [x] Blue-Pill port updated to API v0.1.2
- [x] Blue-Pill examples transpiled successfully
- [x] XIAO-SAMD21 port updated to API v0.1.2
- [x] XIAO-SAMD21 examples transpiled successfully
- [x] XIAO-ESP-xx port created
- [x] Templates updated: Arduino-Nano, Arduino-Uno, Emulator, ESP32-DevkitC, Exp16-PIC24, PIC16F8x, PIC16F88x, RP-Pico, W801, Blue-Pill, Nucleo-L031K6, XIAO-ESP32-xx, XIAO-SAMD21, NXT