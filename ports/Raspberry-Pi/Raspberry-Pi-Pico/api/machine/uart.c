#define uart0_setup(baud_rate)   Serial.begin(baud_rate)
#define uart_setup(baud_rate)   Serial.begin(baud_rate)

#define uart0_ready()  Serial.available()
#define uart_ready()   Serial.available()

#define uart0_read()   Serial.read()
#define uart_read()   Serial.read()

#define println(message)   Serial.println(message)