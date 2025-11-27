# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] Implement `lock` and `rlock` keywords (initially for NXT port)
- [ ] Implement float formatting on string interpolations (`${x:.2}`)
- [ ] Implement an equivalent to Arduino's `millis()`
<!-- - [ ] Implement CH32V and CH5xx families on Arduino through PlatformIO -->
<!-- - [ ] Add a configuration file inside each project folder in order to make it easy to integrate Aixt to and IDE like PlatformIO -->
- [ ] Allow multi-arg functions
- [ ] Implements sub-modules with the syntax: `import main_module.submodule`
- [ ] Issue: Transpiler only works with V 0.4.10 or below (check if "-" in names affects it)
- [ ] Generate the C macros (`@[as_macro]`) before de rest of constants and functions definition
- [ ] ISSUE: D:\git-projects\aixt\targets\Microchip\Explorer16\PIC24\examples\Exp16-PIC24-Port_blink conflict
- [ ] Define if the default modules use functional or object oriented paradigms
  - [ ] Define a standard way of naming the modules (`module`, `module_fn`, `module_oop`)
- [ ]  Implement `#preinclude`


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
- [ ] Add documentation about installing by using `conda`/`pixi`


### Done ✓make

- [x] Issue solved: Arduino Mega and Nano `led0` was not public.
- [x] VSCode `tasks.json` updated to also support pixi environments
- [x] Change all occurrences of `@[as_macro] const` by `@[as_macro] pub const`
- [x] Delete `nbc` compiler binaries from the repository (Linux and Windows versions)
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
