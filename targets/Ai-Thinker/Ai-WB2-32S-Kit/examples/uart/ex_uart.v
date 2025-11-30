// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: Serial Port UART functions (Ai-Thinker_Ai-WB2-32S-Kit)

import time {sleep_ms}
import pin
import uart


  uart.setup(115200)
  pin.setup(io4,output)
  pin.setup(io5,output)
  pin.setup(io12,output)

for {
  uart.println("\r\n Este programa realiza unas funciones establecidas:")
  uart.println("\r\n Oprimiendo la letra A, activa la salida  del pin GPIO4.")
  uart.println("\r\n Oprimiendo la letra B, activa la salida  del pin GPIO5.")
  uart.println("\r\n El piloto (led) Rojo indica que esta esperando instrucciones.")
  uart.println("\r\n Esperando instrucciones: \r\n")

  pin.high(io12)
  sleep_ms(500)

  pin.low(io12)
  sleep_ms(500)
  x:=0
  x=uart.any()
  if  x> 0 {
  command := ` ` 
	command = uart.read()

    if command==`A`  {
        uart.println("\r\n Comando A recibido. \r\n")
        uart.println("\r\n Realizando acción A. \r\n")
        pin.high(io4)
        sleep_ms(5000)

        pin.low(io4)
        sleep_ms(1000)
        uart.println("\r\n Proceso A finalizado. \r\n")
	}

      if command==`B`  {
        uart.println("\r\n Comando B recibido. \r\n")
        uart.println("\r\n Realizando acción B. \r\n")
        pin.high(io5)
        sleep_ms(5000)

        pin.low(io5)
        sleep_ms(1000)
        uart.println("\r\n Proceso B finalizado. \r\n")
	  }

      else {
        pin.high(io12)
        sleep_ms(1000)

        pin.low(io12)
        sleep_ms(1000)
      
    }
  }
}