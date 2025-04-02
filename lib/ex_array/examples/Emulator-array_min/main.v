// Project name: Example for ex_array library
// Author: Fernando M. Santa
// Date: 29/01/2025
// CLI emulator (Windows, Linux and Android-Termux) 

import uart
import ex_array

my_array := [20, 7, 3, 11, 9]

minimum := ex_array.min(my_array, 5)

uart.println('The minimum of array is: ${minimum}')

