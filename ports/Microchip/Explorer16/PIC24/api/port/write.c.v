// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module port

#define port__write(PORT_NAME, VALUE)	LAT ## PORT_NAME = VALUE