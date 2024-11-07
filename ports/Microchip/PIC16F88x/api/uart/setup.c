void setup(uint32_t baudrate) { 
    // int16_t n = (uint8_t)(_XTAL_FREQ / (16 * baudrate)) - 1;  
    // if (n < 0)  n = 0; 
    // if (n > 255) {  // low speed
    //     n = (uint8_t)(_XTAL_FREQ / (64 * baudrate)) - 1;
    //     if (n > 255) n = 255;
    //     TXSTAbits.BRGH = 0;   // low speed
    // } else {    // high speed
    //     TXSTAbits.BRGH = 1;   // high speed
    // }
    // SPBRG = n;

    SPBRG = (uint8_t)(_XTAL_FREQ / (32 * baudrate)) - 1;  
    TXSTAbits.BRGH = 0;   // low speed

    TXSTAbits.SYNC = 0;   // Asyncronous
    TXSTAbits.TXEN = 1;   // Tx enabled
    TXSTAbits.TX9 = 0;    // 8 bits

    RCSTAbits.RC9 = 0;    // 8 bits
    RCSTAbits.CREN = 1;   // Rx enabled

    RCSTAbits.SPEN  = 1;  // serial port enabled
}