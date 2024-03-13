// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024

module time

// sleep_ms is a delay function in seconds (aproximation) for the (WCH-CH582F)
 
#define time__sleep(TIME)    DelayMs(TIME*1000)

