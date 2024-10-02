# Aixt TODO

Tasks to do in Aixt 


### Todo

- [ ] Start a vscode extension for Aixt
- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] generates documentation from code
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Use $tmpl and template files for the different backends 
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] change "set" by "setup" in sensor module (NXT port)
- [ ] Issue: Ident names including module and function name or scope position (for all ports)
- [ ] Avoid macros in ports for functions implementation


### In Progress

- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] implement maps
- [ ] Change all API constants
- [ ] Change arrays to  pure V
- [ ] Standardize (with original V) the identifier names in the generated C code
- [ ] make groups of PIC microcontrollers families

### Done ✓

- [x] APIs for Arduino Nano, Uno and RP Pico updated
- [x] Generate C templates for most of the Aixt's V expression and statements
- [x] Migrate setup files from toml to json
- [x] Implement the `match` expression #feat @fermarsan