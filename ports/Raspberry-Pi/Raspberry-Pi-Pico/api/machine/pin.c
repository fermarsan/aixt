#define out OUTPUT

//#define out1 OUTPUT

//#define out2 OUTPUT

//#define out3 OUTPUT

//#define out4 OUTPUT

//#define out5 OUTPUT

//#define val INPUT

//#define pot INPUT

//#define BRILLO INPUT

#define in INPUT_PULLUP

#define pin_mode(PIN_NAME, MODE)    pinMode(PIN_NAME, MODE)

#define pin_high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)

#define pin_low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)

#define pin_read(PIN_NAME)   digitalRead(PIN_NAME)

#define adc_read(PIN_NAME)   analogRead(PIN_NAME)

#define adc_write(PIN_NAME, MODE)   analogWrite(PIN_NAME, MODE)

#define uart0_setup(baud_rate)   Serial.begin(baud_rate)
#define uart_setup(baud_rate)   Serial.begin(baud_rate)

#define uart0_ready()  Serial.available()
#define uart_ready()   Serial.available()

#define uart0_read()   Serial.read()
#define uart_read()   Serial.read()

#define println(message)   Serial.println(message)