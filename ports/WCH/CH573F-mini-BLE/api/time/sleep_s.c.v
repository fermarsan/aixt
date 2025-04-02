// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: TIME functions (WCH-CH573F)

module time

// sleep_ms is a delay function in seconds (aproximation) for the (WCH-CH573F)
 
#define time.sleep(TIME)    DelayMs(TIME*1000)

