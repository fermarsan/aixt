# Setup file

The **_Aixt_** project uses a setup file for each supported microcontroller. This file configures the especific configuration paramenters of the board or device such as: clock frecuency, default hardware modules, header files etc., as well as other transpiler parameters such as variable type correspondence.

The setup file uses the `YAML` format due to its simplicity. The following sample code shows and extract of the `setup.yaml`:

```yaml
.
.
.
u8:     uint8_t
u16:    uint16_t
u32:    uint32_t
usize:  uint16_t

f32:    float
f64:    "long double"
.
.
.
headers:
  - <xc.h>
  - <stdint.h>
  - <stdbool.h>
  - <p24FJ128GA010.h>
  - <libpic30.h>

macros:
  - "FCY 4000000UL"
.
.
.
```

The **_Aixt_** transpiler reads the `setup.yaml` and does the traslation based on the parameters written on it, as well as it generates `settings.h` adding the specific parameters of the microcontroller or board.  

