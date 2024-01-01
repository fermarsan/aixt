<div align="center">
<h1>Aixt</h1>
<h2>Programming Framework for Microcontrollers</h2>
</div>

Aixt is a programming framework for microcontrollers which uses a modern language syntax based on [_V_](https://vlang.io/) and able to be used by low-resource devices. Aixt is composed by 3 main components:

- The **Aixt** programing language based on the [_V language_](https://vlang.io/) syntax.
- The **Aixt to C Transpiler**, which translate the **Aixt** source code to _C_, for a expecific _C_ compiler of each microcontroller.
- The **Aixt API**, which makes the programming easy by standardizing the setup and I/O functions.  

```mermaid
stateDiagram-v2

    Aixt: Aixt language
    state Aixt {
        source: Source code
        API
    }

    Aixt2C: Aixt to C Transpiler
    state Aixt2C {
        Transpiler: Transpiler (V)
        setup: setup file (TOML)
    }

    C: C language
    state C {
        Tr_Code: Transpiled code
        API_C: API in C
    }

    state Microcontroller {
        PICs: PIC
        ATM: AT
        ESP
        RP2040
        others2: ...
        NXT: NXT brick
    }

    C_Compiler: C Compiler
    state C_Compiler {
        others: ...
        XC8
        XC16
        ImageCraft
        GCC
        others
        nbc: nbc (NXC)
    }

    machine
    state machine {
        BF: Binary file
    }

    Aixt    --> Aixt2C
    Aixt2C  --> Tr_Code
    C       --> C_Compiler
    C_Compiler  --> machine
    Microcontroller --> API_C
```

Aixt is designed as modular as possible, to make it easy to append new devices and boards.


## Aixt to C Transpiler

The transpiler is written in [_V_](https://vlang.io/) using the _V's_ native self-compiler (a transpiler from _V_ to _C_). This is implemented in the folders `\aixt_build` and `\aixt_cgen`, and the main source code is the `aixt.v` file. It generates code for 3 different backends:
- **c**: for the microcontroller native C compiler
- **nxc**: for the NXC compiler (LEGO Mindstorms NXT)
- **arduino**: for the Arduino IDE **WIP**


## Aixt Language

**Aixt** programing language implements a subset of [_V language_](https://vlang.io/). The main differences are show as follows:

feature                 |V                                  | Aixt
------------------------|-----------------------------------|----------------------------------------
variables               |immutable by default               | mutable by default
strings                 |dynamic-sized                      | fixed-sized
arrays                  |dynamic-sized                      | fixed-sized
default integers size   |32 bits                            | depends on the device  
structs                 |allow functions (object-oriented)  | don't allow functions (only structured)


### Example with `main` function

```v
/* Turning ON the onboard LED 10 for the Explorer16 board
for the PIC24FJ microcontroller (XC16 compiler)*/

fn main() {
    pin_high(led10)    //turn ON the LED 10 (PORTA7)
}
```

### Example without `main` function (Script mode)

```v
/* Turning ON the onboard LED 10 for the Explorer16 board
for the PIC24FJ microcontroller (XC16 compiler)*/

for {   //infinite loop
    pin_high(led10)     // LED 10 blinking
    sleep_ms(500)
    pin_low(led10)
    sleep_ms(500)
}
```

## Aixt API

The **Aixt API** is inspired by the _Micropython_, _Arduino_ and _Tinygo_ projects. The API for all the ports includes at least functions for:

- Digital input/output
- Analog inputs (ADC)
- PWM outputs
- Serial port (UART)

## Using Aixt
First compile `aixt.v`: 
```
cd aixt
v aixt.v
```

run it in a Linux-based system as:
```
./aixt <command> <device_or_board> <source_file>
```
or in Windows:
```
aixt.exe <command> <device_or_board> <source_file>
```

### Running examples:
```
./aixt -t Emulator test.v
```
```
./aixt -b NXT ports/NXT/projects/1_motor_forward.v
```

### Project's name
The project's name is inspired in _Veasel_, the Weasel pet of _V Language_, and at the same time is a tribute to _Ticuna_ people who live in the Amazonic forest in the borders of _Colombia_, _Brasil_ and _Perú_. Weasels are _mustelids_ just like otters, so the name **Aixt** comes from _Aixtü_, which is a way to say otter in [_Ticuna_](https://www.sil.org/system/files/reapdata/90/20/51/90205190508691852389084667097660892450/tca_Ticuna_Dictionary_2016_web.pdf) language.
