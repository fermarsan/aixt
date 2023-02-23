# Aixt language
**Aixt** is bases on _The V programming language_.

# Diferences with V
- All the variables un **Aixt** are mutables by default

# Keywords
as
asm
assert
atomic
break
-const
continue
defer
-else
enum
-false
-fn
-for
go
goto
-if
-import
-in
interface
is
isreftype
lock
match
module
mut
none
or
pub
-return
rlock
select
shared
sizeof
spawn
static
struct
-true
type
typeof
union
unsafe
volatile
-__global
__offsetof




# Supported Aixt language features
    
- Inspired by the _V language_ grammar [https://vlang.io/](https://vlang.io/)
    - _Golang_ grammar was taken as reference [https://github.com/antlr/grammars-v4/tree/master/golang](https://github.com/antlr/grammars-v4/tree/master/golang)
    - as well as _Rust_ grammar [https://doc.rust-lang.org/stable/reference/](https://doc.rust-lang.org/stable/reference/)
- Integer literals in binary, octal, hexadecimal and decimal notation
- Floating point, rune, string and boolean literals
- Literals with '_'
- Declaration of signed and unsigned 8, 16, 32 and 64 bit integer variables (also isize and usize)
- Declaration of variables in floating point of 32 and 64 bits
- Single and multiple declaration and assignment
- Declaration by default type inference
- By default all variables are mutable, so `mut` keyword is not supported (give support at least dummy)
- line and block comments
- bitwise arithmetic and logical operations
- parentheses in expressions
- comparison operations
- compound operations '+=', etc.
- block expressions '{ Code_block }' (a tab is added to the block in the output file)
- - function declarations and return values
- if-else statements, infinity for , for as while