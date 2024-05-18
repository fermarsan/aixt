// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module uart

#define uart__print(MESSAGE)		printf("\033[1;32m");	printf("%s", MESSAGE)	// in green