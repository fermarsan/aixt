# Aixt language
**Aixt** is bases on [The V programming language](https://vlang.io/).

# Diferences with V
Based on the _V_ grammar taken from these sources (ordered by importance):
- Abstract Syntax Tree V's documentation: [https://modules.vlang.io/v.ast.html](https://modules.vlang.io/v.ast.html)
- _V_ grammar definition in Antlr-v4:     [https://github.com/antlr/grammars-v4/blob/master/v/V.g4](https://github.com/antlr/grammars-v4/blob/master/v/V.g4)
- _V_ grammar definition in lark:         [(https://github.com/Itay2805/Vork/blob/master/v.lark](https://github.com/Itay2805/Vork/blob/master/v.lark)

# Supported Keywords
- as
- asm
- assert
- atomic
- break
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


# Supported Aixt language features
    
Inspired by the _V language_ grammar [https://vlang.io/](https://vlang.io/)
- _Golang_ grammar was taken as reference [https://github.com/antlr/grammars-v4/tree/master/golang](https://github.com/antlr/grammars-v4/tree/master/golang)
- as well as _Rust_ grammar [https://doc.rust-lang.org/stable/reference/](https://doc.rust-lang.org/stable/reference/)
- Integer literals in binary, octal, hexadecimal and decimal notation
- Floating point, `rune`, `string` and _boolean_ literals
- Literals with `_`
- Declaration of signed and unsigned 8, 16, 32 and 64 bit integer variables (also `isize` and `usize`)
- Declaration of variables in floating point of 32 and 64 bits
- Single and multiple declaration and assignment
- Declaration by default type inference
- By default all variables are mutable, so `mut` keyword is not supported (give support at least dummy)