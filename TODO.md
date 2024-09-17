# Aixt TODO

Tasks to do in Aixt 


### Todo

- [ ] Start a vscode extension for Aixt
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] generates documentation from code
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Use $tmpl and template files for the different backends 
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] make groups of PIC microcontrollers families 
- [ ] change "set" by "setup" in sensor module (NXT port)
- [ ] Issue: Ident names including module and function name or scope position (for all ports)
- [ ] implements maps
- [ ] Avoid macros in ports for functions implementation


### In Progress

- [ ] Implement the `match` expression #feat @fermarsan
- [ ] Change all API constants
- [ ] Change arrays to  pure V
- [ ] Standardize (with original V) the identifier names in the generated C code
- [ ] Compile option turned into more universal by using pseudo variables inside .toml files.

### Done ✓

- [x] Complete Arduino Nano API update
- [x] UART arduino example 
- [x] Remove module's name from pin names
- [x] Issue: after changing name functions in Emulator port (SOLVED)