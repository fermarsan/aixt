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
- [ ] Update all of the project templates


### Done ✓

- [x] add a custom attribute for defining constants and functions as C macros in order to save memory in small devices
- [x] define API modules' parameters as constants
- [x] Divide the parsing files order in two rounds (the second one including the imported module's files)
- [x] Allow implementation of the same Module on multiple directories
- [x] make groups of PIC microcontrollers families
- [x] Standardize (with original V) the identifier names in the generated C code
- [x] Update ESP32-DevKitC to the API 0.1.2
- [x] Implement the basic structure of interrupts (attribute `@[XXXX_isr]`)
- [x] Implement external interrupts on PIC16F8x microcontroller family.
- [x] Implement the constant `cpu_freq` for changing the default cpu frequency defined on `.json` file
- [x] Change Raspberry-Pi-Pico port name by "RP-Pico"
- [x] Update the `Setup file.md` in `doc` folder. (`Setup files.md` )
- [x] Explorer 16 PIC24 setup files updated 
- [x] Change Exp16-PIC24 port name by "Exp16-PIC24"
- [x] Templates updated: Arduino-Nano, Arduino-Uno, Emulator, ESP32-DevkitC, Exp16-PIC24