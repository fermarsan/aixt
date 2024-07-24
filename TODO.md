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
- [ ] Change the C generation using V text templates

### Done ✓

- [x] conditional $if and $else implemented
- [x] enum declaration issue
- [X] Auto-detection of function return value (for assignments)
- [x] API auto-import option (DISCARDED)
- [x] "29_types.v" fails
- [x] Issue: inline declaration in prototypes 
- [x] "19_for_in_array.v" fails
- [x] Mutable indexes on for_in statements
- [x] "21_constants.v" fails
- [x] "23_attributes.v" fails
- [x] "26_strings.v" fails
- [x] "28_enum_declaration.v" fails
- [x] "31_globals_and_constants.v" fails
- [x] "30_println.v" fails
- [x] "33_series_for_array.v" fails
- [x] "34_nested_for_array.v" fails
- [x] "36_println.v" fails
- [x] "39_string_interp.v" fails
- [x] Issue: remove the module's name from the function parameters
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
