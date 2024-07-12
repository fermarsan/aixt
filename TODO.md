# Aixt TODO

Tasks to do in Aixt 


### Todo

- [ ] Start a vscode extension for Aixt
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] generates documentation from code
- [ ] API auto-import option
- [ ] Implement inline assembly
- [ ] Implement uart.input()
- [ ] Use $tmpl and template files for the different backends 
- [ ] Auto-detection of function return value (for assignments)
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] enum declaration issue
- [ ] make groups of PIC microcontrollers families 
- [ ] change "set" by "setup" in sensor module (NXT port)
- [ ] Issue: Ident names including module and function name or scope position (for all ports)
- [ ] implements maps


### In Progress

- [ ] Implement the `match` expression #feat @fermarsan
- [ ] Change all API constants
- [ ] Issue: remove the module's name from the function parameters

### Done ✓

- [x] Issue: duplicated function definition on output file (module functions)
- [x] Format output file
- [x] Allow by default mutable variables
- [x] Change preprocessor commands and C including code
- [x] Split parse and code generation in two rounds
- [x] Issue: out from single string to string array. Needs to change all files
- [x] Issue: for-in on const array
- [x] Interrupt request functions
- [x] Implement adc.setup() in Explorer16-PIC24
- [x] Issue: path in windows
