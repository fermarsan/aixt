void setup(uint32_t baud_rate) {
    TRISFbits.TRISF2 = 1;   // Rx
    TRISFbits.TRISF3 = 0;   // Tx
    
    LATFbits.LATF3 = 1;     // Tx line initialization
    
    // STSEL 1; IREN disabled; PDSEL 8N; UARTEN enabled; RTSMD disabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; RXINV disabled; UEN TX_RX; 
    U1MODE = (0x8008 & ~(1<<15));  // disabling UARTEN bit   
    // UTXISEL0 TX_ONE_CHAR; UTXINV disabled; OERR NO_ERROR_cleared; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; 
    U1STA = 0x0000;
    //              FCY 
    // UBRG = ─────────────── - 1
    //         4 * baud_rate 
    U1BRG = (uint16_t)(FCY / (4 * baud_rate) - 1);
    
    U1MODEbits.UARTEN = 1;  // enabling UARTEN bit
    U1STAbits.UTXEN = 1;   
}