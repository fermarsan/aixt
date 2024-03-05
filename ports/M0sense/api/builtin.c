// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Builtin definitions (Explorer16-PIC24 port)
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

#define a0_s    TRISAbits.TRISA0    // pin configuration pits
#define a1_s    TRISAbits.TRISA1 
#define a2_s    TRISAbits.TRISA2 
#define a3_s    TRISAbits.TRISA3
#define a4_s    TRISAbits.TRISA4 
#define a5_s    TRISAbits.TRISA5 
#define a6_s    TRISAbits.TRISA6 
#define a7_s    TRISAbits.TRISA7 
#define a8_s    TRISAbits.TRISA8 
#define a9_s    TRISAbits.TRISA9 
#define a10_s   TRISAbits.TRISA10
#define a11_s   TRISAbits.TRISA11
#define a12_s   TRISAbits.TRISA12
#define a13_s   TRISAbits.TRISA13
#define a14_s   TRISAbits.TRISA14
#define a15_s   TRISAbits.TRISA15

#define b0_s    TRISBbits.TRISB0 
#define b1_s    TRISBbits.TRISB1 
#define b2_s    TRISBbits.TRISB2 
#define b3_s    TRISBbits.TRISB3 
#define b4_s    TRISBbits.TRISB4 
#define b5_s    TRISBbits.TRISB5 
#define b6_s    TRISBbits.TRISB6 
#define b7_s    TRISBbits.TRISB7 
#define b8_s    TRISBbits.TRISB8 
#define b9_s    TRISBbits.TRISB9 
#define b10_s   TRISBbits.TRISB10
#define b11_s   TRISBbits.TRISB11
#define b12_s   TRISBbits.TRISB12
#define b13_s   TRISBbits.TRISB13
#define b14_s   TRISBbits.TRISB14
#define b15_s   TRISBbits.TRISB15

#define c0_s    TRISCbits.TRISC0 
#define c1_s    TRISCbits.TRISC1 
#define c2_s    TRISCbits.TRISC2 
#define c3_s    TRISCbits.TRISC3 
#define c4_s    TRISCbits.TRISC4 
#define c5_s    TRISCbits.TRISC5 
#define c6_s    TRISCbits.TRISC6 
#define c7_s    TRISCbits.TRISC7 
#define c8_s    TRISCbits.TRISC8 
#define c9_s    TRISCbits.TRISC9 
#define c10_s   TRISCbits.TRISC10
#define c11_s   TRISCbits.TRISC11
#define c12_s   TRISCbits.TRISC12
#define c13_s   TRISCbits.TRISC13
#define c14_s   TRISCbits.TRISC14
#define c15_s   TRISCbits.TRISC15

#define d0_s    TRISDbits.TRISD0 
#define d1_s    TRISDbits.TRISD1 
#define d2_s    TRISDbits.TRISD2 
#define d3_s    TRISDbits.TRISD3 
#define d4_s    TRISDbits.TRISD4 
#define d5_s    TRISDbits.TRISD5 
#define d6_s    TRISDbits.TRISD6 
#define d7_s    TRISDbits.TRISD7 
#define d8_s    TRISDbits.TRISD8 
#define d9_s    TRISDbits.TRISD9 
#define d10_s   TRISDbits.TRISD10
#define d11_s   TRISDbits.TRISD11
#define d12_s   TRISDbits.TRISD12
#define d13_s   TRISDbits.TRISD13
#define d14_s   TRISDbits.TRISD14
#define d15_s   TRISDbits.TRISD15

#define e0_s    TRISEbits.TRISE0 
#define e1_s    TRISEbits.TRISE1 
#define e2_s    TRISEbits.TRISE2 
#define e3_s    TRISEbits.TRISE3 
#define e4_s    TRISEbits.TRISE4 
#define e5_s    TRISEbits.TRISE5 
#define e6_s    TRISEbits.TRISE6 
#define e7_s    TRISEbits.TRISE7 
#define e8_s    TRISEbits.TRISE8 
#define e9_s    TRISEbits.TRISE9 
#define e10_s   TRISEbits.TRISE10
#define e11_s   TRISEbits.TRISE11
#define e12_s   TRISEbits.TRISE12
#define e13_s   TRISEbits.TRISE13
#define e14_s   TRISEbits.TRISE14
#define e15_s   TRISEbits.TRISE15

#define f0_s     TRISFbits.TRISF0 
#define f1_s     TRISFbits.TRISF1 
#define f2_s     TRISFbits.TRISF2 
#define f3_s     TRISFbits.TRISF3 
#define f4_s     TRISFbits.TRISF4 
#define f5_s     TRISFbits.TRISF5 
#define f6_s     TRISFbits.TRISF6 
#define f7_s     TRISFbits.TRISF7 
#define f8_s     TRISFbits.TRISF8 
#define f9_s     TRISFbits.TRISF9 
#define f10_s    TRISFbits.TRISF10
#define f11_s    TRISFbits.TRISF11
#define f12_s    TRISFbits.TRISF12
#define f13_s    TRISFbits.TRISF13
#define f14_s    TRISFbits.TRISF14
#define f15_s    TRISFbits.TRISF15

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

#define a0_i    PORTAbits.RA0       // pin input pits 
#define a1_i    PORTAbits.RA1 
#define a2_i    PORTAbits.RA2 
#define a3_i    PORTAbits.RA3 
#define a4_i    PORTAbits.RA4 
#define a5_i    PORTAbits.RA5 
#define a6_i    PORTAbits.RA6 
#define a7_i    PORTAbits.RA7 
#define a8_i    PORTAbits.RA8 
#define a9_i    PORTAbits.RA9 
#define a10_i   PORTAbits.RA10
#define a11_i   PORTAbits.RA11
#define a12_i   PORTAbits.RA12
#define a13_i   PORTAbits.RA13
#define a14_i   PORTAbits.RA14
#define a15_i   PORTAbits.RA15

#define b0_i    PORTBbits.RB0 
#define b1_i    PORTBbits.RB1 
#define b2_i    PORTBbits.RB2 
#define b3_i    PORTBbits.RB3 
#define b4_i    PORTBbits.RB4 
#define b5_i    PORTBbits.RB5 
#define b6_i    PORTBbits.RB6 
#define b7_i    PORTBbits.RB7 
#define b8_i    PORTBbits.RB8 
#define b9_i    PORTBbits.RB9 
#define b10_i   PORTBbits.RB10
#define b11_i   PORTBbits.RB11
#define b12_i   PORTBbits.RB12
#define b13_i   PORTBbits.RB13
#define b14_i   PORTBbits.RB14
#define b15_i   PORTBbits.RB15

#define c0_i    PORTCbits.RC0 
#define c1_i    PORTCbits.RC1 
#define c2_i    PORTCbits.RC2 
#define c3_i    PORTCbits.RC3 
#define c4_i    PORTCbits.RC4 
#define c5_i    PORTCbits.RC5 
#define c6_i    PORTCbits.RC6 
#define c7_i    PORTCbits.RC7 
#define c8_i    PORTCbits.RC8 
#define c9_i    PORTCbits.RC9 
#define c10_i   PORTCbits.RC10
#define c11_i   PORTCbits.RC11
#define c12_i   PORTCbits.RC12
#define c13_i   PORTCbits.RC13
#define c14_i   PORTCbits.RC14
#define c15_i   PORTCbits.RC15

#define d0_i    PORTDbits.RD0 
#define d1_i    PORTDbits.RD1 
#define d2_i    PORTDbits.RD2 
#define d3_i    PORTDbits.RD3 
#define d4_i    PORTDbits.RD4 
#define d5_i    PORTDbits.RD5 
#define d6_i    PORTDbits.RD6 
#define d7_i    PORTDbits.RD7 
#define d8_i    PORTDbits.RD8 
#define d9_i    PORTDbits.RD9 
#define d10_i   PORTDbits.RD10
#define d11_i   PORTDbits.RD11
#define d12_i   PORTDbits.RD12
#define d13_i   PORTDbits.RD13
#define d14_i   PORTDbits.RD14
#define d15_i   PORTDbits.RD15

#define e0_i    PORTEbits.RE0 
#define e1_i    PORTEbits.RE1 
#define e2_i    PORTEbits.RE2 
#define e3_i    PORTEbits.RE3 
#define e4_i    PORTEbits.RE4 
#define e5_i    PORTEbits.RE5 
#define e6_i    PORTEbits.RE6 
#define e7_i    PORTEbits.RE7 
#define e8_i    PORTEbits.RE8 
#define e9_i    PORTEbits.RE9 
#define e10_i   PORTEbits.RE10
#define e11_i   PORTEbits.RE11
#define e12_i   PORTEbits.RE12
#define e13_i   PORTEbits.RE13
#define e14_i   PORTEbits.RE14
#define e15_i   PORTEbits.RE15

#define f0_i    PORTFbits.RF0 
#define f1_i    PORTFbits.RF1 
#define f2_i    PORTFbits.RF2 
#define f3_i    PORTFbits.RF3 
#define f4_i    PORTFbits.RF4 
#define f5_i    PORTFbits.RF5 
#define f6_i    PORTFbits.RF6 
#define f7_i    PORTFbits.RF7 
#define f8_i    PORTFbits.RF8 
#define f9_i    PORTFbits.RF9 
#define f10_i   PORTFbits.RF10
#define f11_i   PORTFbits.RF11
#define f12_i   PORTFbits.RF12
#define f13_i   PORTFbits.RF13
#define f14_i   PORTFbits.RF14
#define f15_i   PORTFbits.RF15

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

#define a0      LATAbits.LATA0      // pin output pits
#define a1      LATAbits.LATA1 
#define a2      LATAbits.LATA2 
#define a3      LATAbits.LATA3 
#define a4      LATAbits.LATA4 
#define a5      LATAbits.LATA5 
#define a6      LATAbits.LATA6 
#define a7      LATAbits.LATA7 
#define a8      LATAbits.LATA8 
#define a9      LATAbits.LATA9 
#define a10     LATAbits.LATA10
#define a11     LATAbits.LATA11
#define a12     LATAbits.LATA12
#define a13     LATAbits.LATA13
#define a14     LATAbits.LATA14
#define a15     LATAbits.LATA15

#define b0      LATBbits.LATB0 
#define b1      LATBbits.LATB1 
#define b2      LATBbits.LATB2 
#define b3      LATBbits.LATB3 
#define b4      LATBbits.LATB4 
#define b5      LATBbits.LATB5 
#define b6      LATBbits.LATB6 
#define b7      LATBbits.LATB7 
#define b8      LATBbits.LATB8 
#define b9      LATBbits.LATB9 
#define b10     LATBbits.LATB10
#define b11     LATBbits.LATB11
#define b12     LATBbits.LATB12
#define b13     LATBbits.LATB13
#define b14     LATBbits.LATB14
#define b15     LATBbits.LATB15

#define c0      LATCbits.LATC0 
#define c1      LATCbits.LATC1 
#define c2      LATCbits.LATC2 
#define c3      LATCbits.LATC3 
#define c4      LATCbits.LATC4 
#define c5      LATCbits.LATC5 
#define c6      LATCbits.LATC6 
#define c7      LATCbits.LATC7 
#define c8      LATCbits.LATC8 
#define c9      LATCbits.LATC9 
#define c10     LATCbits.LATC10
#define c11     LATCbits.LATC11
#define c12     LATCbits.LATC12
#define c13     LATCbits.LATC13
#define c14     LATCbits.LATC14
#define c15     LATCbits.LATC15

#define d0      LATDbits.LATD0 
#define d1      LATDbits.LATD1 
#define d2      LATDbits.LATD2 
#define d3      LATDbits.LATD3 
#define d4      LATDbits.LATD4 
#define d5      LATDbits.LATD5 
#define d6      LATDbits.LATD6 
#define d7      LATDbits.LATD7 
#define d8      LATDbits.LATD8 
#define d9      LATDbits.LATD9 
#define d10     LATDbits.LATD10
#define d11     LATDbits.LATD11
#define d12     LATDbits.LATD12
#define d13     LATDbits.LATD13
#define d14     LATDbits.LATD14
#define d15     LATDbits.LATD15

#define e0      LATEbits.LATE0 
#define e1      LATEbits.LATE1 
#define e2      LATEbits.LATE2 
#define e3      LATEbits.LATE3 
#define e4      LATEbits.LATE4 
#define e5      LATEbits.LATE5 
#define e6      LATEbits.LATE6 
#define e7      LATEbits.LATE7 
#define e8      LATEbits.LATE8 
#define e9      LATEbits.LATE9 
#define e10     LATEbits.LATE10
#define e11     LATEbits.LATE11
#define e12     LATEbits.LATE12
#define e13     LATEbits.LATE13
#define e14     LATEbits.LATE14
#define e15     LATEbits.LATE15

#define f0      LATFbits.LATF0 
#define f1      LATFbits.LATF1 
#define f2      LATFbits.LATF2 
#define f3      LATFbits.LATF3 
#define f4      LATFbits.LATF4 
#define f5      LATFbits.LATF5 
#define f6      LATFbits.LATF6 
#define f7      LATFbits.LATF7 
#define f8      LATFbits.LATF8 
#define f9      LATFbits.LATF9 
#define f10     LATFbits.LATF10
#define f11     LATFbits.LATF11
#define f12     LATFbits.LATF12
#define f13     LATFbits.LATF13
#define f14     LATFbits.LATF14
#define f15     LATFbits.LATF15

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
//     pin_setup(ta0, out); // Onboard LEDs            
//     pin_setup(ta1, out);        
//     pin_setup(ta2, out);        
//     pin_setup(ta3, out);       
//     pin_setup(ta4, out);       
//     pin_setup(ta5, out);        
//     pin_setup(ta6, out);        
//     pin_setup(ta7, out);    

//     pin_setup(td6, in); // Onboard switchs  
//     pin_setup(td13, in);  
//     pin_setup(ta7, in); 
//     pin_setup(td7, in); 

//     pin_setup(tb5, in);  // Onboard potentiometer
// }