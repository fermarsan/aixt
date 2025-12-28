// Project name: Example for ex_array library
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 29/01/2025
// CLI emulator (Windows, Linux and Android-Termux) 

import uart
import ex_array

my_array := [20, 7, 3, 11, 9]

minimum := ex_array.min(my_array, 5)

uart.println('The minimum of array is: ${minimum}')

