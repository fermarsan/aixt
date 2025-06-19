#define PIN_WRITE(PIN_NAME, VAL)    PIN_NAME##_Write(VAL)
#define PIN_HIGH(PIN_NAME)   PIN_NAME##_Write(1)
#define PIN_LOW(PIN_NAME)   PIN_NAME##_Write(0)
