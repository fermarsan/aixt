# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside `for` statement
- [ ] Implement `lock` and `rlock` keywords (initially for NXT port)
- [ ] Implement float formatting on string interpolations (`${x:.2}`)
- [ ] Implement an equivalent to Arduino's `millis()`
- [ ] Allow multi-arg functions
- [ ] Implements sub-modules with the syntax: `import main_module.submodule`
- [ ] ISSUE: D:\git-projects\aixt\targets\Microchip\Explorer16\PIC24\examples\Exp16-PIC24-Port_blink conflict


### In Progress

- [ ] implement maps
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Issue: Calling function from string interpolations including casting
- [ ] Issue: `match` can not work with functions
- [ ] Issue: the Makefile for PIC12F6xx fails
- [ ] Update the Explorer16 target
- [ ] Clone Aixt without targets/../examples and docs to make it lightweight for the Conda package (include src/v.mod)


### Done ✓make

- [x] Issue solved: Arduino Mega and Nano `led0` was not public.
- [x] VSCode `tasks.json` updated to also support pixi environments
- [x] Change all occurrences of `@[as_macro] const` by `@[as_macro] pub const`
- [x] Delete `nbc` compiler binaries from the repository (Linux and Windows versions)
- [x] Add documentation about installing by using `conda`/`pixi`
- [x] Implement a new scheme for the `device.json` setup files
- [x] Update all the setup files `*.json`to the new scheme
  - [x] From `device.json` change `port:` by `target:`
- [x] Add basic language test examples
  - [x] Create a folder by each test file including the project files
- [x] Enable conditional compilation based on `device.json` properties 
  - [x] Include `$if c ? {}` syntax from `backend: c` of `device.json` 
  - [x] Include `$if xc8 ? {}` syntax from `cc: { name: xc8 }` of `device.json` 
  - [x] Change all the setup files name that contains '-' by '-_'
  - [x] Change all the setup files content that contains '-' by '_' in the fields: "target", "backend", "name" and "api_paths"
  - [x] In the `targets` folder change all the folders names that contains '-' by '_'
  - [x] In the `targets` folder change all the *.v file names that contains '-' by '_'
  - [x] `PIC16F6xx_14p` ADC module modification by using conditional compilation: `$if PIC16F630 ? {`   
- [x] Implement a `builtin` module similar to the _V's_ one
  - [x] Implement `eprint()` function
- [x] Migrate `aixt.v` file to an V's standard CLI app using `cli` module
- [x] Aixt's `new` command has now an interactive mode (by flag)
- [x] Issue solved: Transpiler only works with V 0.4.10 or below (check if "-" in names affects it). Fully tested on v 0.4.12.
- [x] Add a `v.mod` file inside each project folder in order including `device` and `port` fields
  - [x] `transpile`, `c_compile` and `build` commands use the `v.mod` file if the flag `device` is not explicitly passed
  - [x] `flash` command use the `v.mod` file if the flag `port` is not explicitly passed
- [x] Remove the fields `device` and `port` of `.vscode/settings.json`
- [x] Modify `.vscode/tasks.json` according to the new `v.mod` file
- [x] Modify `.zed/tasks.json` according to the new `v.mod` file
- [x] Implement the `init` command
- [x] Interactive mode for `init` and `new`
- [x] change `device` flag by `target` 
- [x] `#preinclude` command fully implemented and tested
- [x] Issue solved: defining structs and use them in multiples files fails depending on the compiling order
  - [x] Add to the `c_gen` struct the field `typedefs` 
- [x] Issue solved: Global struct instances fails
- [x] Generate the C macros (`@[as_macro]`) before de rest of constants and functions definition (functions and constants)
- [x] Define as default the object oriented modules (`pin`, `motor`, etc) less in low memory devices like PICs
  - [x] Define as standard module's name `module` for unique and OOP versions and `module_fn` for only-funcional ones
  - [x] Update according the new names, the targets: NXT, Emulator and arduino devices (tested on Uno, Nano and Mega).
  - [x] Create both functional and OOP version of modules `pin`, `adc`, `pwm`, `motor`, `sensor` and `button`  
  - [x] Update all the Microchip targets to `pin_fn` 
- [x] Issue solved: interrupts examples for arduino backend already work  with `pin` y `pin_fn`
- [x] Update the `v.mod` file in all the Microchip targets
- [x] Issue solved: Makefiles __device_name__ already works well
- [x] Update `tasks.json` and `settings.json` according to the new `v.mod` file
- [x] Change `aixt_linux` and `aixt_windows` by a single `aixt` in `settings.json`
- [x] Issue solved: Interrupts on PIC16F work back.
- [x] Issue solved: unknown PIC12 fuses
- [x] Test and include in documentation the module `pin_fast` for PIC16 targets
- [x] Update the PIC12Fxxx, PIC16F8x and PIC16F87x examples
- [x] Issue solved: `match` already works well with `C.variables`
- [x] Issue solved: assignment using `match` already works
- [ ] generates documentation from code
  - [x] Update the source files header to improve the visualization of the automatic documentation
- [x] Split the examples from the API in all the targets
