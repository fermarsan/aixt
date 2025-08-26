# Setup files

The **_Aixt_** project uses setup files for each supported microcontroller and compiler. These files configure the specific configuration parameters of the board or device such as: clock frequency, default hardware modules, header files etc., as well as other transpiler parameters such as variable type correspondence. The setup files are located in `setup` folder.

The setup files use the `.json` format due to its ubiquitous nature. The following sample code shows the content of `setup/PIC16F8x.json`:

```json
{
    "port":      "PIC16F8x",
    "board":     "---",
    "backend":   "c",

    "cc_linux":			"",             
    "cc_windows":		"",
    "cc_make_flags":	"PART=@{device}",

    "flasher_linux":    "arduino-cli",
    "flasher_windows":  "arduino-cli.exe",
	"flasher_flags":	"upload @{file_dir_name} -p @{port} -b esp32:esp32:esp32",

    "api_paths": [
        "Microchip/PIC16F8x",
        "Microchip/xc8-generic",
        "Microchip/PIC12F-16F-generic"
    ],
    "v_defines": [
    ],

    "default_cpu_freq": 4000000,
    "default_string_len": 20,

    "compiler_setup_path": "setup/xc8.json"
}
```

Each device's setup file `port_name.json` includes at the same time the correspondent compiler's setup file `compiler.json` in the parameter: `"compiler_setup_path":`. In this case `setup/xc8.json`, which has the followng content:

```json
{
    "main_ret_type": "void",
    "main_params":   "void",
    "compiler_types": {
        "void":     "void",
        "bool":     "bool",
        "i8":       "int8_t",
        "i16":      "int16_t",
        "int":      "int32_t",
        "i64":      "NOT SUPPORTED",
        "isize":    "int8_t",
        "int_literal": "int32_t",
        "u8":       "uint8_t",
        "u16":      "uint16_t",
        "u32":      "uint32_t",
        "u64":      "NOT SUPPORTED",
        "usize":    "uint8_t",
        "f32":      "float",
        "f64":      "NOT SUPPORTED",
        "float_literal": "float",
        "rune":     "char"
    }
}
```

The **_Aixt_** transpiler reads the `port_name.json` and  `compiler.json` and does the translation based on the parameters written on it, as well as adding the specific parameters of the microcontroller or board in the output `C` file. 


## Backend
 
**_Aixt_** can generated code for 3 different backends:

| Backend name | Target                                           |
| ------------ | ------------------------------------------------ |
| c            | for the native _C_ compiler of the device        |
| arduino      | for the ports that use _Arduino_ API             |
| nxc          | for LEGO Mindstorms NXT robots on _NXC_ language |


