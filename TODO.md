# Aixt TODO

Tasks to do in Aixt 

### Todo

- [ ] Fix the function attributes #bug @fermarsan
- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] Update the Aixt executable path #bug
- [ ] dynamic memory definition
- [ ] generates documentation from code
- [ ] Give support to transpile multi-file folders (`aixt.v`)
- [ ] API auto-import option

### In Progress

- [ ] Implement the `match` expression #feat @fermarsan
- [ ] Implement string interpolation
- [ ] Implement strings.Builder instead of regular strings in C Gen
    - [ ] use builder.write() and builder.writeln() instead of return strings
   
### Done ✓

- [x] Update the general diagram
- [x] support enum fields (`enum_name.enum_field`)
- [x] Add `void` type to C void functions 
- [x] Force to include `module_name.c.v` first
- [x] Implement automatic use of Makefiles in -c (compile) command
- [x] Change the vscode tasks to point the folder instead of `aixt.v`