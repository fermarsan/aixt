// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// write UART
//              (PIC18F452)
module uart
fn write(data rune){
    TXREG=data
}