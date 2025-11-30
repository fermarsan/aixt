# Aixt's V language
**Aixt** _V_ language is based on [The V programming language](https://vlang.io/).

The _V_ grammar was taken from these sources (ordered by importance):
- Abstract Syntax Tree V's documentation: [https://modules.vlang.io/v.ast.html](https://modules.vlang.io/v.ast.html)
- _V_ grammar definition in Antlr-v4:     [https://github.com/antlr/grammars-v4/blob/master/v/V.g4](https://github.com/antlr/grammars-v4/blob/master/v/V.g4)
- _V_ grammar definition in lark:         [(https://github.com/Itay2805/Vork/blob/master/v.lark](https://github.com/Itay2805/Vork/blob/master/v.lark)

#  Diferences between Aixt's V and standard V
As _V_, **Aixt** support function attributes like `@[inline]`, but it also include others like `@[task]`  which gives support to multitasking in the transpiling to _NXC_ language and `@[as_macro]` for implementing them as C macro (for low-memory devices).

The main differences between **Aixt** and **V**are show as follows:

| feature              | V                             | Aixt's V                                                              |
| -------------------- | ----------------------------- | --------------------------------------------------------------------- |
| strings              | fixed-sized and dynamic-sized | fixed-sized (for now)                                                 |
| arrays               | fixed-sized and dynamic-sized | fixed-sized (for now)                                                 |
| structs              | allow functions               | allow functions. Can not declared as reference                        |
| functions            | multiple return values        | only one return value                                                 |
| text macros          | not allowed                   | allowed by using '@[as_macro]' attribute, for functions and constants |
| `C` variables access | not allowed                   | allowed by using 'C.var_name' syntax                                  |
| global variables     | disabled by default           | enabled by default                                                    |


#  V's supported keywords
The V's supported keywords are listed in bold text as follows.
- **as**
- asm
- assert
- atomic
- **break**
- **const**
- defer
- **else**
- **enum**
- **false**
- **fn**
- **for**
- go
- goto
- **if**
- **import**
- **in**
- interface
- **is**
- isreftype
- lock
- **match**
- **module**
- **mut**
- none
- or
- **pub**
- **return**
- rlock
- select
- shared
- sizeof
- spawn
- static
- **struct**
- **true**
- **type**
- typeof
- union
- **unsafe**
- volatile
- **__global**
- __offsetof

#  Aixt's V language features
- All variables are local by default
- `__global`  keyword in case of needing global variables
- Integer literals in binary, octal, hexadecimal and decimal notation
- Floating point, `rune`, `string`  and _boolean_ literals
- Numeric literals can include `_`  for better readability
- Declaration of signed and unsigned 8, 16, 32 and 64 bit integer variables (also `isize` and `usize` )
- Declaration floating point variables of 32 and 64 bits including scientific notation
- Multiple declaration and assignment in a single line
- Declaration by default type inference for scalar and array variables
- Variable casting in case of need to specify the variable type of number of bits
- Function attributes using the syntax: 
  
``` v
@[attribute] 
fn <name>(<params>) {
    <statements>
}```

- Loops with `for` through arrays and integer ranges:

``` v
arr := [3,5,7,9]
for a in arr {
    a = 0
}
```    
``` v
for i in 1..11 {
    x += i
}
``` 
