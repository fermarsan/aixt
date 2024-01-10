# Setup file

The **_Aixt_** project uses a setup file for each supported microcontroller. This file configures the specific configuration parameters of the board or device such as: clock frequency, default hardware modules, header files etc., as well as other transpiler parameters such as variable type correspondence.

The setup file uses the `.toml` format due to its simplicity. The following sample code shows and extract of the `Explorer16-PIC24.toml`:

```toml
.
.
.
u8 =    "uint8_t"
u16 =   "uint16_t"
u32 =   "uint32_t"
usize = "uint16_t"

f32 =   "float"
f64 =   "long double"
.
.
.
headers = [
  "<xc.h>",
  "<stdint.h>",
  "<stdbool.h>",
  "<p24FJ128GA010.h>",
  "<libpic30.h>"
  ]

macros = [
  "FCY 4000000UL",
.
.
.
```

The **_Aixt_** transpiler reads the `port_name.toml` and does the translation based on the parameters written on it, as well as adding the specific parameters of the microcontroller or board in the output `C` file. 

## Backend
 
**_Aixt_** can generated code for 3 different backends:

Backend name    | Target
----------------|-------------------------------------------------
c               | for the native _C_ compiler of the device
arduino         | for the ports that use _Arduino_ API
nxc             | for LEGO Mindstorms NXT robots on _NXC_ language  


