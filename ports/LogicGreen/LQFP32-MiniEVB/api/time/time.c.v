// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Time module (LQFP32 MiniEVB Nano - LGT8F328P port)
module time

//Pauses the program for the amount of time (in seconds) specified as parameter
#define time.sleep(TS)  delay(TS*1000)

//Pauses the program for the amount of time (in milliseconds) specified as parameter
#define time.sleep_ms(TMS)  delay(TMS)

//Pauses the program for the amount of time (in microseconds) specified by the parameter
#define time.sleep_us(TUS)  delayMicroseconds(TUS)