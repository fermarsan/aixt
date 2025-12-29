import pin
import time

time.sleep(1)

// asm wasm {
// 	// Set PORTB pin 0 as output
// 	bsf STATUS, RP0        // Bank 1
// 	bcf TRISB, 0          // Set RB0 as output
// 	bcf STATUS, RP0        // Bank 0

// 	// Turn on LED connected to PORTB pin 0
// 	bsf PORTB, 0          // Set RB0 high
// }
