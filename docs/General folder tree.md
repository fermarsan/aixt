# Project's folder tree
Aixt project has the follow general folder tree:
    
    
aixt    
    ├── aixt_build
    ├── aixt_cgen
    ├── aixt.v
    ├── assets
    ├── common_test
    ├── CONTRIBUTING.md
    ├── docs
    ├── LICENSE
    ├── ports
    ├── prerequisites.md
    ├── README.md
    ├── TODO.md
    └── v.mod
    
    6 directories, 7 files
    fercho@V14-ADA:~/aixt$ tree -L 2
    .
    ├── aixt_build
    │   └── builder.v
    ├── aixt_cgen
    │   ├── assign.v
    │   ├── call.v
    │   ├── cgen.v
    │   ├── const.v
    │   ├── enum.v
    │   ├── expr.v
    │   ├── file.v
    │   ├── fn.v
    │   ├── for.v
    │   ├── global.v
    │   ├── if.v
    │   ├── infix.v
    │   ├── match.v
    │   ├── node.v
    │   ├── stmt.v
    │   └── utils.v
    ├── aixt.v
    ├── assets
    │   ├── Aixtu-ru.jpeg
    │   ├── Aixtu-ru-wide.png
    │   ├── Aixtü-ru.xcf
    │   ├── README.md
    │   ├── tasks.png
    │   ├── text-logo-bg.png
    │   ├── text-logo-bg.svg
    │   ├── text-logo.png
    │   ├── text-logo-sh.png
    │   ├── text-logo-sh.svg
    │   └── text-logo.svg
    ├── common_test
    │   ├── 00_one_line
    │   ├── 00_one_line.v
    │   ├── 01_declaring_and_types.v
    │   ├── 02_casting.v
    │   ├── 03_numeric_bases.v
    │   ├── 04_underscore_literal.v
    │   ├── 05_assign_operators.v
    │   ├── 06_comparing_operators.v
    │   ├── 07_binary_operators.v
    │   ├── 08_unary_operators.v
    │   ├── 09_inc_dec_operators.v
    │   ├── 10_explicit_main.v
    │   ├── 11_arithmetic_and_logic.v
    │   ├── 12_if_else.v
    │   ├── 13_function_def_and_call.v
    │   ├── 14_bare_for.v
    │   ├── 15_for_as_while.v
    │   ├── 16_for_c_style.v
    │   ├── 17_for_in_range.v
    │   ├── 18_arrays.v
    │   ├── 19_for_in_array.v
    │   ├── 20_multiple_assign.v
    │   ├── 21_constants.v
    │   ├── 22_global_variables.v
    │   ├── 23_attributes.v
    │   ├── 24_import.v
    │   ├── 25_C_preprocessor.v
    │   ├── 26_strings.v
    │   ├── 27_cond_assign.c
    │   ├── 27_cond_assign.v
    │   ├── 28_enum_declaration.v
    │   ├── 29_types.v
    │   ├── README.md
    │   └── xxx.v
    ├── CONTRIBUTING.md
    ├── docs
    │   ├── Aixt language.md
    │   ├── API folder tree.md
    │   ├── API.md
    │   ├── Atmel
    │   ├── Cypress
    │   ├── Devices and Boards.md
    │   ├── Emulator
    │   ├── Espressif
    │   ├── General folder tree.md
    │   ├── How to use.md
    │   ├── LogicGreen
    │   ├── Microchip
    │   ├── NXT
    │   ├── Raspberry-Pi
    │   ├── Setup file.md
    │   ├── ST
    │   └── WCH
    ├── LICENSE
    ├── ports
    │   ├── Atmel
    │   ├── Cypress
    │   ├── Emulator
    │   ├── Espressif
    │   ├── LogicGreen
    │   ├── M0sense
    │   ├── Microchip
    │   ├── NXT
    │   ├── Raspberry-Pi
    │   ├── setup
    │   ├── ST
    │   └── WCH
    ├── prerequisites.md
    ├── README.md
    ├── TODO.md
    └── v.mod