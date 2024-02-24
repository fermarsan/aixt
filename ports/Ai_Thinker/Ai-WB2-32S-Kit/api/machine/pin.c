#define pin_setup(PIN_NAME, MODE)    pinMode(PIN_NAME, MODE)

#define pin_high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)

#define pin_low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)

#define out OUTPUT

#define in INPUT_PULLUP

#define pin_read(PIN_NAME)   digitalRead(PIN_NAME)