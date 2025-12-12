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

- [ ] generates documentation from code
- [ ] implement maps
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference
- [ ] Issue: Calling function from string interpolations including casting
- [ ] Issue: `match` can not work with functions
- [ ] Issue: the Makefile for PIC12F6xx fails
- [ ] Issue: assignment using `match` fails
- [ ] Update the Explorer16 target
- [ ] Clone Aixt without targets/../examples and docs to make it lightweight for the Conda package (include src/v.mod)
- [ ] Implement `#preinclude`
- [ ] Issue: defining structs and use them in multiples files fails depending on the compiling order
- [ ] Generate the C macros (`@[as_macro]`) before de rest of constants and functions definition
  


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
- [x] Implement the `init` command
- [x] Interactive mode for `init` and `new`
- [x] change `device` flag by `target` 
- [x] Define as default the object oriented modules (`pin`, `motor`, etc) less in low memory devices like PICs
  - [x] Define as standard module's name `module` for unique and OOP versions and `module_fn` for only-funcional ones
  - [x] Update according the new names, the targets: Emulator, (arduino backend devices)