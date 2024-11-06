# Aixt TODO

Tasks to do in Aixt


### Todo

- [ ] Implement variable swapping (by using temporal vars) #feat
- [ ] dynamic memory definition
- [ ] generates documentation from code
- [ ] Implement inline assembly
- [ ] "40_inline_asm.v" inline asm implementation
- [ ] Implement uart.input()
- [ ] Support for arrays and strings initialized inside "for" statement
- [ ] change "set" by "setup" in sensor module (NXT port)
- [ ] Issue: Ident names including module and function name or scope position (for all ports)


### In Progress

- [ ] Implement structs #feat
    - [ ] support struct fields (`struct_name.struct_field`)
- [ ] implement maps
- [ ] Change arrays to pure V
- [ ] Standardize (with original V) the identifier names in the generated C code
- [ ] make groups of PIC microcontrollers families
- [ ] Start a vscode extension for Aixt
- [ ] Give support to reference and dereference 

### Done ✓

- [x] Migrate setup files from `.toml` to `.json`
- [x] Implement the `match` expression #feat @fermarsan
- [x] Give support to `in` and `!in` operands on arrays
- [x] Issue: `else` statements fail from V 0.4.7. SOLVED: defining else branch condition as `ast.NodeError`
- [x] Standardize the basic data types as V
- [x] Add a typedef declaration for each compiler type in `.json` file (remove the necesity to do code replacements)
- [x] Give support to "type" aliassing
