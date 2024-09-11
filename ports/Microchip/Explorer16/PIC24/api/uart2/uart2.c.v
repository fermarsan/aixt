module uart2

#define uart2.println(MSG)		uart2.print(MSG);  uart2.write('\n');  uart2.write('\r')