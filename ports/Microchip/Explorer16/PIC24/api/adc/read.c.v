// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc


#include <libpic30.h>

fn C.read(channel u8) u16 