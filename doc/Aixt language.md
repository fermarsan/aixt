# Aixt language
**Aixt** is based on [The V programming language](https://vlang.io/).

The _V_ grammar was taken from these sources (ordered by importance):
- Abstract Syntax Tree V's documentation: [https://modules.vlang.io/v.ast.html](https://modules.vlang.io/v.ast.html)
- _V_ grammar definition in Antlr-v4:     [https://github.com/antlr/grammars-v4/blob/master/v/V.g4](https://github.com/antlr/grammars-v4/blob/master/v/V.g4)
- _V_ grammar definition in lark:         [(https://github.com/Itay2805/Vork/blob/master/v.lark](https://github.com/Itay2805/Vork/blob/master/v.lark)

# Diferences between Aixt and V
- By default all variables in **Aixt** are mutable, so `mut` keyword is not supported
- **Aixt** supports the semicolon `;` by separating statements in the same line
- As _V_, **Aixt** support function attributes like `[inline]`, but these attributes include others like `[task]` which gives support to multitasking in the transpiling to _NXC_ language
- `mutex` variables for giving support to multitasking in _NXC_ transcompiling

# V's supported keywords
The V's supported keywors are in bold.
- as
- asm
- assert
- atomic
- **break**
- **const**
- defer
- **else**
- enum
- **false**
- **fn**
- **for**
- go
- goto
- **if**
- **import**
- **in**
- interface
- is
- isreftype
- lock
- match
- module
- mut
- none
- or
- pub
- **return**
- rlock
- select
- shared
- sizeof
- spawn
- static
- struct
- **true**
- type
- typeof
- union
- unsafe
- volatile
- **__global**
- __offsetof

# Aixt language features
- Mutable variables by default
- All variables are local by default
- `__global` keyword in case of needing global variables
- Integer literals in binary, octal, hexadecimal and decimal notation
- Floating point, `rune`, `string` and _boolean_ literals
- Numeric literals include `_` for better readability
- Declaration of signed and unsigned 8, 16, 32 and 64 bit integer variables (also `isize` and `usize`)
- Declaration floating point variables of 32 and 64 bits including scientific notation
- Multiple declaration and assignment in a single line
- Declaration by default type inference for scalar and array variables
- Variable casting in case of need to specify the variable type of number of bits
- Function attributes using the syntax: 
    ```go
    [attribute] 
    fn <name>(<params>) {
        <statements>
    }```
- Loops with `for` through arrays and integer ranges:
    ```go
    arr := [3,5,7,9]
    for a in arr {
        a = 0
    }
    ```   
    ```go
    for i in 1..11 {
        x += i
    }
    ```
