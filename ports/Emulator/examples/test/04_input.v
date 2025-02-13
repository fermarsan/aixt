import uart

mut var := ''
var = uart.input('Enter a string: ')
uart.print('Echo: ')
uart.println(var)
