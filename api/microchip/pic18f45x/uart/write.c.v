// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
//
// ## Description
// write UART
//              (PIC18F452)
module uart
fn write(data rune){
    TXREG=data
}