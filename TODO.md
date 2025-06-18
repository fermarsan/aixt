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
- [ ] Implement CH32V and CH5xx families on Arduino through PlatformIO
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
- [ ] Issue: External interrupts on Arduino backend fails if the pin is not defined as constant
- [ ] Implements sub-modules
- [ ] `pin.<function>_fast` functions on `pin` module implemented


### Done ✓make
- [x] Generate the `arduino-ARM32` subfolder 
- [x] Change aixt transpiler as a module with submodules
- [x] Remove the passing of the aixt-path among functions
- [x] Issue solved: C prototypes of `@[inline]` functions fail
- [x] Changes `compile` Aixt option to `c_compile` (including vscode and zed `tasks.json`) 
- [x] Generate a new transpiler script
- [x] Implement and test (16F83_blinking, ESP32-C3FH4-blinking and Nano-random_bits) a new transpiler scheme
- [x] New transpiler folder tree including submodules `builder`, `cgen`, `setup` and `util`
- [x] Builtin LED and SWITCH auto-setup (Arduino-AVR)
- [x] New external interrupt example for Blue Pill (non-tested) 
- [x] Change '/' linux path separator by `os.path_separator` constant
- [x] Enable input pulldown resistors in the API
- [x] Change pin definitions as macros in most of the ports
- [x] Change the interrupt service functions to be universal (not dependent of the backend)
- [x] Add `pin.toggle()` function on Arduino ports
