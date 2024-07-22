// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module time

$if linux {
	#include <unistd.h>
} $else {
	#include <windows.h>
}