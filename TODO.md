# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] Implement `lock` and `rlock` keywords (initially for NXT port)
- [ ] Implement float formatting on string interpolations (`${x:.2}`)
- [ ] Implement an equivalent to Arduino's `millis()`
<!-- - [ ] Implement CH32V and CH5xx families on Arduino through PlatformIO -->
<!-- - [ ] Add a configuration file inside each project folder in order to make it easy to integrate Aixt to and IDE like PlatformIO -->
- [ ] Allow multi-arg functions
- [ ] Check the convenience of the "generality" of each port implementation
- [ ] Implements sub-modules with the syntax: `import main_module.submodule`
- [ ] Issue: Transpiler only works with V 0.4.10 or below
- [ ] Generate the C macros (`@[as_macro]`) before de rest of constants and functions definition


### In Progress

- [ ] generates documentation from code
- [ ] implement maps
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Issue: Calling function from string interpolations including casting
- [ ] Issue: `match` can not work with functions
- [ ] Issue: the Makefile for PIC12F6xx fails
- [ ] Issue: assignment using `match` fails


### Done ✓make

- [x] Issue solved: Structs can not be registered twice (due to the double parsing round). Solved clearing the symbol table between parsings
- [x] Implement structs
  - [x] Implement structs declaring
  - [x] Implement struct instances declaring
  - [x] Implement struct fields access (`struct_name.struct_field`)
  - [x] Support struct methods (using the V standard)
- [x] Add OOP features to the API (Emulator pin module, NXT motor module) 
- [x] new 'pin_oop' object oriented pin module for Arduino backend (API v0.2.0)
- [x] Issue solved: References to 'struct's fail generating C code
- [x] Issue solved: functions that returns pointers fail
- [x] Include casting on C generated code for 'return' commands
- [x] Change the C generation of commands: `import module { component }`, to reach it more to original V behavior (import all the `module` and enable a short pseudonym for `component`)
- [x] Generate the modules `arduino-generic-UARTx` instead of defining them for each target
- [x] Change the definition of builtin LEDs ans Switches from `builtin.c.v` to `pin.c.v` 
- [x] Unify most the ports implementation in only one file `module.c.v`
- [x] `pin_fast` module implemented for PIC16
- [x] Change the name of the devices/boards implementation folder from `ports` to `targets` 
- [x] NXT target API (motor, sensor and button modules) updated to v0.2.0 (OOP)
- [x] NXT test examples split in 'funcional' and 'struct-based' (object oriented approach)
- [x] Now the builtin inputs and outputs belong to `pin` module and require to be manual configured ans initialized
- [x] Issue solved: `/` characters produce errors on Windows. They were replaced by `os.path_separator` and `os.norm_path()`
- [x] In general API unify the name of the identification I/O parameter from 'name' to 'id', in all the targets for the modules `pin`, `adc` and `pwn` (along with their `_oop` version)