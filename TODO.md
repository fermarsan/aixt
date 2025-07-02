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
- [ ] Add settings file `port_name.json` inside `/port_name` folder


### In Progress

- [ ] generates documentation from code
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] implement maps
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Issue: Calling function from string interpolations including casting
- [ ] Implements sub-modules
- [ ] `pin.<function>_fast` functions on `pin` module implemented
- [ ] Issue: `match` can not work with functions
- [ ] Issue: the Makefile for PIC12F6xx fails


### Done ✓make

- [x] Call Aixt directly from `.vscode/tasks.json` instead of running it through V compiler
- [x] New devices supported PIC16F62x-648 including `uart`
- [x] Issue solved: `module.c.v` is not parsed first when imported a module
- [x] Issue solved: comments inside conditional compiling fails inside `as_macro` functions
- [x] Issue solved: `as_macro` multiline functions fails when return a value
- [x] Change "Aixt: C compile" taks by "Aixt: C Compile" in all `tasks.json` files
- [x] Add snippets for `timer0` and `ext` modules for PIC16F family
- [x] Group PIC16F630-676 and PIC16F684 as PIC16F6xx-14p
- [x] Change PIC16F62x-648 to PIC16F6xx-18p
- [x] Change PIC16F68x-690 to PIC16F6xx-20p
- [x] Update snippets for PIC16F8x, PIC16F6xx-14p and PIC16F6xx-18p
- [x] PIC12F6xx port implementation (`time`, `timer0`, `pin` and `ext` modules)
- [x] Add template and "examples" folders for PIC12F6xx
- [x] Issue solved: "cc_make_flags" write mistake in some `.json` setup files
- [x] Snippets updated for PIC devices (including `time`, `timer0`, `pin`, `port` and `ext`)