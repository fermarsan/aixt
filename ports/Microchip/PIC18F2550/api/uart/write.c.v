// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: write.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART management functions  (PIC18F2550 port)

module uart

fn write(data rune){
    TXREG=data
}