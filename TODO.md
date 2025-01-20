# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] Issue: Ident names including module and function name or scope position (for all ports)
- [ ] Implement `lock` and `rlock` keywords (initially for NXT port)
- [ ] Implement an equivalent to Arduino's `millis()`
- [ ] Implements sub-modules


### In Progress

- [ ] generates documentation from code
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] implement maps
- [ ] Change arrays to pure V
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Implement a Libraries folder


### Done ✓make

- [x] Issue solved: `version` command only works running from aixt's main folder
- [x] Update Microchip XC8 devices to xc8-v3.00
- [x] New Timer0 example (PIC16F8x family)
- [x] Implement Timer0 functions
- [x] New type `Mutex` implemented in NXT port (`@[mutex]` attribute deprecated) 
- [x] New names for functions in NXT's `task` module
- [x] NXT snippets file updated