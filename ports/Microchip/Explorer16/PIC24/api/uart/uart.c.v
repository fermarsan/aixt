module uart

#define uart__println(MSG)		uart__print(MSG);  uart__write('\n');  uart__write('\r')