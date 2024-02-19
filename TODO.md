# Aixt TODO

Tasks to do in Aixt 

### Todo

- [ ] Fix the function attributes #bug @fermarsan
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] Update the Aixt executable path #bug
- [ ] dynamic memory definition
- [ ] implement string interpolation
- [ ] generates documentation from code
- [ ] Give support to transpile multi-file folders (`aixt.v`)
- [ ] API auto-import option

### In Progress

- [ ] Implement the `match` expression #feat @fermarsan
- [ ] Force to include `module_name.c.v` first
   
### Done ✓

- [x] Implement automatic use of Makefiles in -c (compile) command
- [x] Change the vscode tasks to point the folder instead of `aixt.v`
- [x] pass default config from `<port>.toml` to `builtin.c.v`
- [x] Manually parse used API files
- [x] change API to once file by function
- [x] Manually parse used module files
- [x] Implement Custom Module code generation
- [x] Multiple source files support