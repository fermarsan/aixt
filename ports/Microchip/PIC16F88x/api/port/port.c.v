// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F88x port)

module port

const a = C.A	// port name constants
const b = C.B
const c = C.C
const e = C.E

#define	port.all_inputs	0xFF	// port mode constants
#define	port.all_outputs	0x00

#define TRISport.a		TRISA	// port setup name equivalents
#define TRISport.b		TRISB
#define TRISport.c		TRISC
#define TRISport.e		TRISE

#define PORTport.a		PORTA	// port name equivalents
#define PORTport.b		PORTB
#define PORTport.c		PORTC
#define PORTport.e		PORTE