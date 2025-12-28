// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo Duarte and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// UART management functions  (PIC18F2550 port)

module uart

fn write(data rune){
    TXREG=data
}