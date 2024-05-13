module uart2

#define uart2__println(MSG)		uart2__print(MSG);  uart2__write('\n');  uart2__write('\r')