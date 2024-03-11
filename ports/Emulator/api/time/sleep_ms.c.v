// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep_ms is a delay function in milliseconds for the Aixt PC port. 
#if defined(__linux) || defined(linux)
#define time__sleep_ms(TMS)		usleep(TMS*1000)
#else
#define time__sleep_ms(TMS)		Sleep(TMS)
#endif

// #define time__sleep_ms(TMS)  start_time = clock();  while (clock() < start_time + TMS*1000)