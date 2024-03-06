// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep is a delay function in seconds for the Aixt PC port. 
#define time__sleep(TMS)  start_time = clock();  printf("\nt = %lu\n", start_time); while (clock() < start_time + TMS*1000000)