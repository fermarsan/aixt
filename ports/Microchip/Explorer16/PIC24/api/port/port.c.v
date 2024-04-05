// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin port management functions (Explorer16-PIC24 port)
module port

#define TRISa	TRISA	// port setup name equivalents
#define TRISb	TRISB
#define TRISc	TRISC
#define TRISd	TRISD
#define TRISe	TRISE
#define TRISf	TRISF
#define TRISg	TRISG

#define PORTa	PORTA	// port in name equivalents
#define PORTb	PORTB
#define PORTc	PORTC
#define PORTd	PORTD
#define PORTe	PORTE
#define PORTf	PORTF
#define PORTg	PORTG

#define LATa	LATA	// port out name equivalents
#define LATb	LATB
#define LATc	LATC
#define LATd	LATD
#define LATe	LATE
#define LATf	LATF
#define LATg	LATG

fn init() {
	
}