// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep_us is a delay function in microseconds for the Aixt PC port. 
#define time__sleep_us(TMS)  start_time = clock();  while (clock() < start_time + TMS)