// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin port management functions (Explorer16-PIC24 port)
module port

#define TRISport_a	TRISA	// port setup name equivalents
#define TRISport_b	TRISB
#define TRISport_c	TRISC
#define TRISport_d	TRISD
#define TRISport_e	TRISE
#define TRISport_f	TRISF
#define TRISport_g	TRISG

#define PORTport_a	PORTA	// port in name equivalents
#define PORTport_b	PORTB
#define PORTport_c	PORTC
#define PORTport_d	PORTD
#define PORTport_e	PORTE
#define PORTport_f	PORTF
#define PORTport_g	PORTG

#define LATport_a	LATA	// port out name equivalents
#define LATport_b	LATB
#define LATport_c	LATC
#define LATport_d	LATD
#define LATport_e	LATE
#define LATport_f	LATF
#define LATport_g	LATG
