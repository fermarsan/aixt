// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: write UART
//              (PIC18F452)
module uart
fn write(data rune){
    TXREG=data
}