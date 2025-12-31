// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2025
//
// ## Description
// Pin management functions (Exp16-PIC24 port)
module pin_fn


@[as_macro] pub const a0 =   0
@[as_macro] pub const a1 =   1
@[as_macro] pub const a2 =   2
@[as_macro] pub const a3 =   3
@[as_macro] pub const a4 =   4
@[as_macro] pub const a5 =   5
@[as_macro] pub const a6 =   6
@[as_macro] pub const a7 =   7    // pins a8, a11, a12, a13 not implemented
@[as_macro] pub const a9 =   9
@[as_macro] pub const a10 =  10
@[as_macro] pub const a14 =  14
@[as_macro] pub const a15 =  15

@[as_macro] pub const b0 =   16
@[as_macro] pub const b1 =   17
@[as_macro] pub const b2 =   18
@[as_macro] pub const b3 =   19
@[as_macro] pub const b4 =   20
@[as_macro] pub const b5 =   21
@[as_macro] pub const b6 =   22
@[as_macro] pub const b7 =   23
@[as_macro] pub const b8 =   24
@[as_macro] pub const b9 =   25
@[as_macro] pub const b10 =  26
@[as_macro] pub const b11 =  27
@[as_macro] pub const b12 =  28
@[as_macro] pub const b13 =  29
@[as_macro] pub const b14 =  30
@[as_macro] pub const b15 =  31

@[as_macro] pub const c0 =   32
@[as_macro] pub const c1 =   33
@[as_macro] pub const c2 =   34
@[as_macro] pub const c3 =   35
@[as_macro] pub const c4 =   36     // pins from c5 to c11 not implemented
@[as_macro] pub const c12 =  44
@[as_macro] pub const c13 =  45
@[as_macro] pub const c14 =  46
@[as_macro] pub const c15 =  47

@[as_macro] pub const d0 =   48
@[as_macro] pub const d1 =   49
@[as_macro] pub const d2 =   50
@[as_macro] pub const d3 =   51
@[as_macro] pub const d4 =   52
@[as_macro] pub const d5 =   53
@[as_macro] pub const d6 =   54
@[as_macro] pub const d7 =   55
@[as_macro] pub const d8 =   56
@[as_macro] pub const d9 =   57
@[as_macro] pub const d10 =  58
@[as_macro] pub const d11 =  59
@[as_macro] pub const d12 =  60
@[as_macro] pub const d13 =  61
@[as_macro] pub const d14 =  62
@[as_macro] pub const d15 =  63

@[as_macro] pub const e0 =   64
@[as_macro] pub const e1 =   65
@[as_macro] pub const e2 =   66
@[as_macro] pub const e3 =   67
@[as_macro] pub const e4 =   68
@[as_macro] pub const e5 =   69
@[as_macro] pub const e6 =   70
@[as_macro] pub const e7 =   71
@[as_macro] pub const e8 =   72
@[as_macro] pub const e9 =   73     // pins from e10 to e15 not implemented

@[as_macro] pub const f0 =   80
@[as_macro] pub const f1 =   81
@[as_macro] pub const f2 =   82
@[as_macro] pub const f3 =   83
@[as_macro] pub const f4 =   84
@[as_macro] pub const f5 =   85
@[as_macro] pub const f6 =   86
@[as_macro] pub const f7 =   87
@[as_macro] pub const f8 =   88     // pins f9, f10, f11, f14, f15 not implemented
@[as_macro] pub const f12 =  92
@[as_macro] pub const f13 =  93

@[as_macro] pub const g0 =   96
@[as_macro] pub const g1 =   97
@[as_macro] pub const g2 =   98
@[as_macro] pub const g3 =   99
@[as_macro] pub const g4 =   100
@[as_macro] pub const g5 =   101
@[as_macro] pub const g6 =   102
@[as_macro] pub const g7 =   103
@[as_macro] pub const g8 =   104
@[as_macro] pub const g9 =   105    // pins g10, g11 not implemented
@[as_macro] pub const g12 =  108
@[as_macro] pub const g13 =  119
@[as_macro] pub const g14 =  110
@[as_macro] pub const g15 =  111

@[as_macro] pub const led3  = 0   // Onboard LEDs
@[as_macro] pub const led4  = 1
@[as_macro] pub const led5  = 2
@[as_macro] pub const led6  = 3
@[as_macro] pub const led7  = 4
@[as_macro] pub const led8  = 5
@[as_macro] pub const led9  = 6
@[as_macro] pub const led10 = 7

@[as_macro] pub const sw3	= 54    // Onboard switchs
@[as_macro] pub const sw4   = 61
@[as_macro] pub const sw5   = 7
@[as_macro] pub const sw6   = 55
