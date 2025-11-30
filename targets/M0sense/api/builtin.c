// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2023
// License: MIT
//
// Description: Builtin definitions (Exp16-PIC24 port)
#define led3    a0  // Onboard LEDs            
#define led4    a1        
#define led5    a2        
#define led6    a3       
#define led7    a4       
#define led8    a5        
#define led9    a6        
#define led10   a7    

#define sw3     d6_i  // Onboard switchs  
#define sw4     d13_i  
#define sw5     a7_i  
#define sw6     d7_i  

#define pot     b5_i  // Onboard potentiometer

@[as_macro] pub const a0 =_s    TRISAbits.TRISA0    // pin configuration pits
@[as_macro] pub const a1 =_s    TRISAbits.TRISA1 
@[as_macro] pub const a2 =_s    TRISAbits.TRISA2 
@[as_macro] pub const a3 =_s    TRISAbits.TRISA3
@[as_macro] pub const a4 =_s    TRISAbits.TRISA4 
@[as_macro] pub const a5 =_s    TRISAbits.TRISA5 
@[as_macro] pub const a6 =_s    TRISAbits.TRISA6 
@[as_macro] pub const a7 =_s    TRISAbits.TRISA7 
@[as_macro] pub const a8 =_s    TRISAbits.TRISA8 
@[as_macro] pub const a9 =_s    TRISAbits.TRISA9 
@[as_macro] pub const a10 =_s   TRISAbits.TRISA10
@[as_macro] pub const a11 =_s   TRISAbits.TRISA11
@[as_macro] pub const a12 =_s   TRISAbits.TRISA12
@[as_macro] pub const a13 =_s   TRISAbits.TRISA13
@[as_macro] pub const a14 =_s   TRISAbits.TRISA14
@[as_macro] pub const a15 =_s   TRISAbits.TRISA15

@[as_macro] pub const b0 =_s    TRISBbits.TRISB0 
@[as_macro] pub const b1 =_s    TRISBbits.TRISB1 
@[as_macro] pub const b2 =_s    TRISBbits.TRISB2 
@[as_macro] pub const b3 =_s    TRISBbits.TRISB3 
@[as_macro] pub const b4 =_s    TRISBbits.TRISB4 
@[as_macro] pub const b5 =_s    TRISBbits.TRISB5 
@[as_macro] pub const b6 =_s    TRISBbits.TRISB6 
@[as_macro] pub const b7 =_s    TRISBbits.TRISB7 
@[as_macro] pub const b8 =_s    TRISBbits.TRISB8 
@[as_macro] pub const b9 =_s    TRISBbits.TRISB9 
@[as_macro] pub const b10 =_s   TRISBbits.TRISB10
@[as_macro] pub const b11 =_s   TRISBbits.TRISB11
@[as_macro] pub const b12 =_s   TRISBbits.TRISB12
@[as_macro] pub const b13 =_s   TRISBbits.TRISB13
@[as_macro] pub const b14 =_s   TRISBbits.TRISB14
@[as_macro] pub const b15 =_s   TRISBbits.TRISB15

@[as_macro] pub const c0 =_s    TRISCbits.TRISC0 
@[as_macro] pub const c1 =_s    TRISCbits.TRISC1 
@[as_macro] pub const c2 =_s    TRISCbits.TRISC2 
@[as_macro] pub const c3 =_s    TRISCbits.TRISC3 
@[as_macro] pub const c4 =_s    TRISCbits.TRISC4 
@[as_macro] pub const c5 =_s    TRISCbits.TRISC5 
@[as_macro] pub const c6 =_s    TRISCbits.TRISC6 
@[as_macro] pub const c7 =_s    TRISCbits.TRISC7 
@[as_macro] pub const c8 =_s    TRISCbits.TRISC8 
@[as_macro] pub const c9 =_s    TRISCbits.TRISC9 
@[as_macro] pub const c10 =_s   TRISCbits.TRISC10
@[as_macro] pub const c11 =_s   TRISCbits.TRISC11
@[as_macro] pub const c12 =_s   TRISCbits.TRISC12
@[as_macro] pub const c13 =_s   TRISCbits.TRISC13
@[as_macro] pub const c14 =_s   TRISCbits.TRISC14
@[as_macro] pub const c15 =_s   TRISCbits.TRISC15

@[as_macro] pub const d0 =_s    TRISDbits.TRISD0 
@[as_macro] pub const d1 =_s    TRISDbits.TRISD1 
@[as_macro] pub const d2 =_s    TRISDbits.TRISD2 
@[as_macro] pub const d3 =_s    TRISDbits.TRISD3 
@[as_macro] pub const d4 =_s    TRISDbits.TRISD4 
@[as_macro] pub const d5 =_s    TRISDbits.TRISD5 
@[as_macro] pub const d6 =_s    TRISDbits.TRISD6 
@[as_macro] pub const d7 =_s    TRISDbits.TRISD7 
@[as_macro] pub const d8 =_s    TRISDbits.TRISD8 
@[as_macro] pub const d9 =_s    TRISDbits.TRISD9 
@[as_macro] pub const d10 =_s   TRISDbits.TRISD10
@[as_macro] pub const d11 =_s   TRISDbits.TRISD11
@[as_macro] pub const d12 =_s   TRISDbits.TRISD12
@[as_macro] pub const d13 =_s   TRISDbits.TRISD13
@[as_macro] pub const d14 =_s   TRISDbits.TRISD14
@[as_macro] pub const d15 =_s   TRISDbits.TRISD15

@[as_macro] pub const e0 =_s    TRISEbits.TRISE0 
@[as_macro] pub const e1 =_s    TRISEbits.TRISE1 
@[as_macro] pub const e2 =_s    TRISEbits.TRISE2 
@[as_macro] pub const e3 =_s    TRISEbits.TRISE3 
@[as_macro] pub const e4 =_s    TRISEbits.TRISE4 
@[as_macro] pub const e5 =_s    TRISEbits.TRISE5 
@[as_macro] pub const e6 =_s    TRISEbits.TRISE6 
@[as_macro] pub const e7 =_s    TRISEbits.TRISE7 
@[as_macro] pub const e8 =_s    TRISEbits.TRISE8 
@[as_macro] pub const e9 =_s    TRISEbits.TRISE9 
@[as_macro] pub const e10 =_s   TRISEbits.TRISE10
@[as_macro] pub const e11 =_s   TRISEbits.TRISE11
@[as_macro] pub const e12 =_s   TRISEbits.TRISE12
@[as_macro] pub const e13 =_s   TRISEbits.TRISE13
@[as_macro] pub const e14 =_s   TRISEbits.TRISE14
@[as_macro] pub const e15 =_s   TRISEbits.TRISE15

@[as_macro] pub const f0 =_s     TRISFbits.TRISF0 
@[as_macro] pub const f1 =_s     TRISFbits.TRISF1 
@[as_macro] pub const f2 =_s     TRISFbits.TRISF2 
@[as_macro] pub const f3 =_s     TRISFbits.TRISF3 
@[as_macro] pub const f4 =_s     TRISFbits.TRISF4 
@[as_macro] pub const f5 =_s     TRISFbits.TRISF5 
@[as_macro] pub const f6 =_s     TRISFbits.TRISF6 
@[as_macro] pub const f7 =_s     TRISFbits.TRISF7 
@[as_macro] pub const f8 =_s     TRISFbits.TRISF8 
@[as_macro] pub const f9 =_s     TRISFbits.TRISF9 
@[as_macro] pub const f10 =_s    TRISFbits.TRISF10
@[as_macro] pub const f11 =_s    TRISFbits.TRISF11
@[as_macro] pub const f12 =_s    TRISFbits.TRISF12
@[as_macro] pub const f13 =_s    TRISFbits.TRISF13
@[as_macro] pub const f14 =_s    TRISFbits.TRISF14
@[as_macro] pub const f15 =_s    TRISFbits.TRISF15

#define g0_s    TRISGbits.TRISG0 
#define g1_s    TRISGbits.TRISG1 
#define g2_s    TRISGbits.TRISG2 
#define g3_s    TRISGbits.TRISG3 
#define g4_s    TRISGbits.TRISG4 
#define g5_s    TRISGbits.TRISG5 
#define g6_s    TRISGbits.TRISG6 
#define g7_s    TRISGbits.TRISG7 
#define g8_s    TRISGbits.TRISG8 
#define g9_s    TRISGbits.TRISG9 
#define g10_s   TRISGbits.TRISG10
#define g11_s   TRISGbits.TRISG11
#define g12_s   TRISGbits.TRISG12
#define g13_s   TRISGbits.TRISG13
#define g14_s   TRISGbits.TRISG14
#define g15_s   TRISGbits.TRISG15

@[as_macro] pub const a0 =_i    PORTAbits.RA0       // pin input pits 
@[as_macro] pub const a1 =_i    PORTAbits.RA1 
@[as_macro] pub const a2 =_i    PORTAbits.RA2 
@[as_macro] pub const a3 =_i    PORTAbits.RA3 
@[as_macro] pub const a4 =_i    PORTAbits.RA4 
@[as_macro] pub const a5 =_i    PORTAbits.RA5 
@[as_macro] pub const a6 =_i    PORTAbits.RA6 
@[as_macro] pub const a7 =_i    PORTAbits.RA7 
@[as_macro] pub const a8 =_i    PORTAbits.RA8 
@[as_macro] pub const a9 =_i    PORTAbits.RA9 
@[as_macro] pub const a10 =_i   PORTAbits.RA10
@[as_macro] pub const a11 =_i   PORTAbits.RA11
@[as_macro] pub const a12 =_i   PORTAbits.RA12
@[as_macro] pub const a13 =_i   PORTAbits.RA13
@[as_macro] pub const a14 =_i   PORTAbits.RA14
@[as_macro] pub const a15 =_i   PORTAbits.RA15

@[as_macro] pub const b0 =_i    PORTBbits.RB0 
@[as_macro] pub const b1 =_i    PORTBbits.RB1 
@[as_macro] pub const b2 =_i    PORTBbits.RB2 
@[as_macro] pub const b3 =_i    PORTBbits.RB3 
@[as_macro] pub const b4 =_i    PORTBbits.RB4 
@[as_macro] pub const b5 =_i    PORTBbits.RB5 
@[as_macro] pub const b6 =_i    PORTBbits.RB6 
@[as_macro] pub const b7 =_i    PORTBbits.RB7 
@[as_macro] pub const b8 =_i    PORTBbits.RB8 
@[as_macro] pub const b9 =_i    PORTBbits.RB9 
@[as_macro] pub const b10 =_i   PORTBbits.RB10
@[as_macro] pub const b11 =_i   PORTBbits.RB11
@[as_macro] pub const b12 =_i   PORTBbits.RB12
@[as_macro] pub const b13 =_i   PORTBbits.RB13
@[as_macro] pub const b14 =_i   PORTBbits.RB14
@[as_macro] pub const b15 =_i   PORTBbits.RB15

@[as_macro] pub const c0 =_i    PORTCbits.RC0 
@[as_macro] pub const c1 =_i    PORTCbits.RC1 
@[as_macro] pub const c2 =_i    PORTCbits.RC2 
@[as_macro] pub const c3 =_i    PORTCbits.RC3 
@[as_macro] pub const c4 =_i    PORTCbits.RC4 
@[as_macro] pub const c5 =_i    PORTCbits.RC5 
@[as_macro] pub const c6 =_i    PORTCbits.RC6 
@[as_macro] pub const c7 =_i    PORTCbits.RC7 
@[as_macro] pub const c8 =_i    PORTCbits.RC8 
@[as_macro] pub const c9 =_i    PORTCbits.RC9 
@[as_macro] pub const c10 =_i   PORTCbits.RC10
@[as_macro] pub const c11 =_i   PORTCbits.RC11
@[as_macro] pub const c12 =_i   PORTCbits.RC12
@[as_macro] pub const c13 =_i   PORTCbits.RC13
@[as_macro] pub const c14 =_i   PORTCbits.RC14
@[as_macro] pub const c15 =_i   PORTCbits.RC15

@[as_macro] pub const d0 =_i    PORTDbits.RD0 
@[as_macro] pub const d1 =_i    PORTDbits.RD1 
@[as_macro] pub const d2 =_i    PORTDbits.RD2 
@[as_macro] pub const d3 =_i    PORTDbits.RD3 
@[as_macro] pub const d4 =_i    PORTDbits.RD4 
@[as_macro] pub const d5 =_i    PORTDbits.RD5 
@[as_macro] pub const d6 =_i    PORTDbits.RD6 
@[as_macro] pub const d7 =_i    PORTDbits.RD7 
@[as_macro] pub const d8 =_i    PORTDbits.RD8 
@[as_macro] pub const d9 =_i    PORTDbits.RD9 
@[as_macro] pub const d10 =_i   PORTDbits.RD10
@[as_macro] pub const d11 =_i   PORTDbits.RD11
@[as_macro] pub const d12 =_i   PORTDbits.RD12
@[as_macro] pub const d13 =_i   PORTDbits.RD13
@[as_macro] pub const d14 =_i   PORTDbits.RD14
@[as_macro] pub const d15 =_i   PORTDbits.RD15

@[as_macro] pub const e0 =_i    PORTEbits.RE0 
@[as_macro] pub const e1 =_i    PORTEbits.RE1 
@[as_macro] pub const e2 =_i    PORTEbits.RE2 
@[as_macro] pub const e3 =_i    PORTEbits.RE3 
@[as_macro] pub const e4 =_i    PORTEbits.RE4 
@[as_macro] pub const e5 =_i    PORTEbits.RE5 
@[as_macro] pub const e6 =_i    PORTEbits.RE6 
@[as_macro] pub const e7 =_i    PORTEbits.RE7 
@[as_macro] pub const e8 =_i    PORTEbits.RE8 
@[as_macro] pub const e9 =_i    PORTEbits.RE9 
@[as_macro] pub const e10 =_i   PORTEbits.RE10
@[as_macro] pub const e11 =_i   PORTEbits.RE11
@[as_macro] pub const e12 =_i   PORTEbits.RE12
@[as_macro] pub const e13 =_i   PORTEbits.RE13
@[as_macro] pub const e14 =_i   PORTEbits.RE14
@[as_macro] pub const e15 =_i   PORTEbits.RE15

@[as_macro] pub const f0 =_i    PORTFbits.RF0 
@[as_macro] pub const f1 =_i    PORTFbits.RF1 
@[as_macro] pub const f2 =_i    PORTFbits.RF2 
@[as_macro] pub const f3 =_i    PORTFbits.RF3 
@[as_macro] pub const f4 =_i    PORTFbits.RF4 
@[as_macro] pub const f5 =_i    PORTFbits.RF5 
@[as_macro] pub const f6 =_i    PORTFbits.RF6 
@[as_macro] pub const f7 =_i    PORTFbits.RF7 
@[as_macro] pub const f8 =_i    PORTFbits.RF8 
@[as_macro] pub const f9 =_i    PORTFbits.RF9 
@[as_macro] pub const f10 =_i   PORTFbits.RF10
@[as_macro] pub const f11 =_i   PORTFbits.RF11
@[as_macro] pub const f12 =_i   PORTFbits.RF12
@[as_macro] pub const f13 =_i   PORTFbits.RF13
@[as_macro] pub const f14 =_i   PORTFbits.RF14
@[as_macro] pub const f15 =_i   PORTFbits.RF15

#define g0_i    PORTGbits.RG0 
#define g1_i    PORTGbits.RG1 
#define g2_i    PORTGbits.RG2 
#define g3_i    PORTGbits.RG3 
#define g4_i    PORTGbits.RG4 
#define g5_i    PORTGbits.RG5 
#define g6_i    PORTGbits.RG6 
#define g7_i    PORTGbits.RG7 
#define g8_i    PORTGbits.RG8 
#define g9_i    PORTGbits.RG9 
#define g10_i   PORTGbits.RG10
#define g11_i   PORTGbits.RG11
#define g12_i   PORTGbits.RG12
#define g13_i   PORTGbits.RG13
#define g14_i   PORTGbits.RG14
#define g15_i   PORTGbits.RG15

@[as_macro] pub const a0 =      LATAbits.LATA0      // pin output pits
@[as_macro] pub const a1 =      LATAbits.LATA1 
@[as_macro] pub const a2 =      LATAbits.LATA2 
@[as_macro] pub const a3 =      LATAbits.LATA3 
@[as_macro] pub const a4 =      LATAbits.LATA4 
@[as_macro] pub const a5 =      LATAbits.LATA5 
@[as_macro] pub const a6 =      LATAbits.LATA6 
@[as_macro] pub const a7 =      LATAbits.LATA7 
@[as_macro] pub const a8 =      LATAbits.LATA8 
@[as_macro] pub const a9 =      LATAbits.LATA9 
@[as_macro] pub const a10 =     LATAbits.LATA10
@[as_macro] pub const a11 =     LATAbits.LATA11
@[as_macro] pub const a12 =     LATAbits.LATA12
@[as_macro] pub const a13 =     LATAbits.LATA13
@[as_macro] pub const a14 =     LATAbits.LATA14
@[as_macro] pub const a15 =     LATAbits.LATA15

@[as_macro] pub const b0 =      LATBbits.LATB0 
@[as_macro] pub const b1 =      LATBbits.LATB1 
@[as_macro] pub const b2 =      LATBbits.LATB2 
@[as_macro] pub const b3 =      LATBbits.LATB3 
@[as_macro] pub const b4 =      LATBbits.LATB4 
@[as_macro] pub const b5 =      LATBbits.LATB5 
@[as_macro] pub const b6 =      LATBbits.LATB6 
@[as_macro] pub const b7 =      LATBbits.LATB7 
@[as_macro] pub const b8 =      LATBbits.LATB8 
@[as_macro] pub const b9 =      LATBbits.LATB9 
@[as_macro] pub const b10 =     LATBbits.LATB10
@[as_macro] pub const b11 =     LATBbits.LATB11
@[as_macro] pub const b12 =     LATBbits.LATB12
@[as_macro] pub const b13 =     LATBbits.LATB13
@[as_macro] pub const b14 =     LATBbits.LATB14
@[as_macro] pub const b15 =     LATBbits.LATB15

@[as_macro] pub const c0 =      LATCbits.LATC0 
@[as_macro] pub const c1 =      LATCbits.LATC1 
@[as_macro] pub const c2 =      LATCbits.LATC2 
@[as_macro] pub const c3 =      LATCbits.LATC3 
@[as_macro] pub const c4 =      LATCbits.LATC4 
@[as_macro] pub const c5 =      LATCbits.LATC5 
@[as_macro] pub const c6 =      LATCbits.LATC6 
@[as_macro] pub const c7 =      LATCbits.LATC7 
@[as_macro] pub const c8 =      LATCbits.LATC8 
@[as_macro] pub const c9 =      LATCbits.LATC9 
@[as_macro] pub const c10 =     LATCbits.LATC10
@[as_macro] pub const c11 =     LATCbits.LATC11
@[as_macro] pub const c12 =     LATCbits.LATC12
@[as_macro] pub const c13 =     LATCbits.LATC13
@[as_macro] pub const c14 =     LATCbits.LATC14
@[as_macro] pub const c15 =     LATCbits.LATC15

@[as_macro] pub const d0 =      LATDbits.LATD0 
@[as_macro] pub const d1 =      LATDbits.LATD1 
@[as_macro] pub const d2 =      LATDbits.LATD2 
@[as_macro] pub const d3 =      LATDbits.LATD3 
@[as_macro] pub const d4 =      LATDbits.LATD4 
@[as_macro] pub const d5 =      LATDbits.LATD5 
@[as_macro] pub const d6 =      LATDbits.LATD6 
@[as_macro] pub const d7 =      LATDbits.LATD7 
@[as_macro] pub const d8 =      LATDbits.LATD8 
@[as_macro] pub const d9 =      LATDbits.LATD9 
@[as_macro] pub const d10 =     LATDbits.LATD10
@[as_macro] pub const d11 =     LATDbits.LATD11
@[as_macro] pub const d12 =     LATDbits.LATD12
@[as_macro] pub const d13 =     LATDbits.LATD13
@[as_macro] pub const d14 =     LATDbits.LATD14
@[as_macro] pub const d15 =     LATDbits.LATD15

@[as_macro] pub const e0 =      LATEbits.LATE0 
@[as_macro] pub const e1 =      LATEbits.LATE1 
@[as_macro] pub const e2 =      LATEbits.LATE2 
@[as_macro] pub const e3 =      LATEbits.LATE3 
@[as_macro] pub const e4 =      LATEbits.LATE4 
@[as_macro] pub const e5 =      LATEbits.LATE5 
@[as_macro] pub const e6 =      LATEbits.LATE6 
@[as_macro] pub const e7 =      LATEbits.LATE7 
@[as_macro] pub const e8 =      LATEbits.LATE8 
@[as_macro] pub const e9 =      LATEbits.LATE9 
@[as_macro] pub const e10 =     LATEbits.LATE10
@[as_macro] pub const e11 =     LATEbits.LATE11
@[as_macro] pub const e12 =     LATEbits.LATE12
@[as_macro] pub const e13 =     LATEbits.LATE13
@[as_macro] pub const e14 =     LATEbits.LATE14
@[as_macro] pub const e15 =     LATEbits.LATE15

@[as_macro] pub const f0 =      LATFbits.LATF0 
@[as_macro] pub const f1 =      LATFbits.LATF1 
@[as_macro] pub const f2 =      LATFbits.LATF2 
@[as_macro] pub const f3 =      LATFbits.LATF3 
@[as_macro] pub const f4 =      LATFbits.LATF4 
@[as_macro] pub const f5 =      LATFbits.LATF5 
@[as_macro] pub const f6 =      LATFbits.LATF6 
@[as_macro] pub const f7 =      LATFbits.LATF7 
@[as_macro] pub const f8 =      LATFbits.LATF8 
@[as_macro] pub const f9 =      LATFbits.LATF9 
@[as_macro] pub const f10 =     LATFbits.LATF10
@[as_macro] pub const f11 =     LATFbits.LATF11
@[as_macro] pub const f12 =     LATFbits.LATF12
@[as_macro] pub const f13 =     LATFbits.LATF13
@[as_macro] pub const f14 =     LATFbits.LATF14
@[as_macro] pub const f15 =     LATFbits.LATF15

#define g0      LATGbits.LATG0 
#define g1      LATGbits.LATG1 
#define g2      LATGbits.LATG2 
#define g3      LATGbits.LATG3 
#define g4      LATGbits.LATG4 
#define g5      LATGbits.LATG5 
#define g6      LATGbits.LATG6 
#define g7      LATGbits.LATG7 
#define g8      LATGbits.LATG8 
#define g9      LATGbits.LATG9 
#define g10     LATGbits.LATG10
#define g11     LATGbits.LATG11
#define g12     LATGbits.LATG12
#define g13     LATGbits.LATG13
#define g14     LATGbits.LATG14
#define g15     LATGbits.LATG15

// #include "./machine/pin.c"

// void setup(void)
// {   
//     pin.setup(ta0, out); // Onboard LEDs            
//     pin.setup(ta1, out);        
//     pin.setup(ta2, out);        
//     pin.setup(ta3, out);       
//     pin.setup(ta4, out);       
//     pin.setup(ta5, out);        
//     pin.setup(ta6, out);        
//     pin.setup(ta7, out);    

//     pin.setup(td6, in); // Onboard switchs  
//     pin.setup(td13, in);  
//     pin.setup(ta7, in); 
//     pin.setup(td7, in); 

//     pin.setup(tb5, in);  // Onboard potentiometer
// }