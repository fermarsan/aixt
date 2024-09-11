module uart

#define uart.println(MSG)		uart.print(MSG);  uart.write('\n');  uart.write('\r')