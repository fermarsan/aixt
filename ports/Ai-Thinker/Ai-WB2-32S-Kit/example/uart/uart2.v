// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart.v
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: Serial Port UART functions (Ai-Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

import time {sleep_ms}
import pin
import uart
  
  uart.setup(115200);
  pin.out(4);
  
  if(uart.ready()){
    char a = uart.read();
    uart.println(a);

  }