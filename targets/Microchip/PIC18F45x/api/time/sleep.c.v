// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: seconds delay function
//              (PIC18F452)

module time

#define time.sleep(TIME)               delay_s(TIME*1000)