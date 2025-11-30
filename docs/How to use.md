# Using **Aixt** project

## Run **Aixt**
In a terminal inside the **_Aixt_** folder compile and execute `aixt.v` file:

```
v run aixt.v <command> <device_or_board> <source_file>
```
Examples:
```
v run aixt.v -t Emulator targets/Emulator/projects/blinking/blinking.v
```
```
v run aixt.v -c Exp16-PIC24 common_test/17_for_in_range.v
```

## Compile **Aixt**
For improving the transcompilation from _Aixt_ to _C_ ou can compile first `aixt.v`: 
```
v aixt.v
```
and the execute:
```
./aixt <command> <device_or_board> <source_file>
```
Examples:
```
./aixt -t Emulator common_test/02_casting.v
```
```
./aixt -b NXT targets/NXT/projects/1_motor.write.v
```

## Aixt commands
_**Aixt**_ supports the following commands:

| Command          | working                                             |
| ---------------- | --------------------------------------------------- |
| transpile, -t    | Transpile to C an Aixt program.                     |
| compile, -c      | Compile the previously generated C file.            |
| run, -r          | Run the previously generated executable file.       |
| build, -b        | Build (transpile, compile and run) an Aixt program. |
| clean, -cl       | Clean all the generated file (C and executables).   |
| help, --help, -h | Call this help'                                     |
| version          | Print the Aixt version number                       |