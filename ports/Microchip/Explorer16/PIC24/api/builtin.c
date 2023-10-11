// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Builtin definitions (Explorer16-PIC24 port)
#define led3    la0  // Onboard LEDs            
#define led4    la1        
#define led5    la2        
#define led6    la3       
#define led7    la4       
#define led8    la5        
#define led9    la6        
#define led10   la7    

#define sw3     rd6  // Onboard switchs  
#define sw4     rd13  
#define sw5     ra7  
#define sw6     rd7  

#define pot     rb5  // Onboard potentiometer

#define ta0     TRISAbits.TRISA0    // pin configuration pits
#define ta1     TRISAbits.TRISA1 
#define ta2     TRISAbits.TRISA2 
#define ta3     TRISAbits.TRISA3 
#define ta4     TRISAbits.TRISA4 
#define ta5     TRISAbits.TRISA5 
#define ta6     TRISAbits.TRISA6 
#define ta7     TRISAbits.TRISA7 
#define ta8     TRISAbits.TRISA8 
#define ta9     TRISAbits.TRISA9 
#define ta10    TRISAbits.TRISA10
#define ta11    TRISAbits.TRISA11
#define ta12    TRISAbits.TRISA12
#define ta13    TRISAbits.TRISA13
#define ta14    TRISAbits.TRISA14
#define ta15    TRISAbits.TRISA15

#define tb0     TRISBbits.TRISB0 
#define tb1     TRISBbits.TRISB1 
#define tb2     TRISBbits.TRISB2 
#define tb3     TRISBbits.TRISB3 
#define tb4     TRISBbits.TRISB4 
#define tb5     TRISBbits.TRISB5 
#define tb6     TRISBbits.TRISB6 
#define tb7     TRISBbits.TRISB7 
#define tb8     TRISBbits.TRISB8 
#define tb9     TRISBbits.TRISB9 
#define tb10    TRISBbits.TRISB10
#define tb11    TRISBbits.TRISB11
#define tb12    TRISBbits.TRISB12
#define tb13    TRISBbits.TRISB13
#define tb14    TRISBbits.TRISB14
#define tb15    TRISBbits.TRISB15

#define tc0     TRISCbits.TRISC0 
#define tc1     TRISCbits.TRISC1 
#define tc2     TRISCbits.TRISC2 
#define tc3     TRISCbits.TRISC3 
#define tc4     TRISCbits.TRISC4 
#define tc5     TRISCbits.TRISC5 
#define tc6     TRISCbits.TRISC6 
#define tc7     TRISCbits.TRISC7 
#define tc8     TRISCbits.TRISC8 
#define tc9     TRISCbits.TRISC9 
#define tc10    TRISCbits.TRISC10
#define tc11    TRISCbits.TRISC11
#define tc12    TRISCbits.TRISC12
#define tc13    TRISCbits.TRISC13
#define tc14    TRISCbits.TRISC14
#define tc15    TRISCbits.TRISC15

#define td0     TRISDbits.TRISD0 
#define td1     TRISDbits.TRISD1 
#define td2     TRISDbits.TRISD2 
#define td3     TRISDbits.TRISD3 
#define td4     TRISDbits.TRISD4 
#define td5     TRISDbits.TRISD5 
#define td6     TRISDbits.TRISD6 
#define td7     TRISDbits.TRISD7 
#define td8     TRISDbits.TRISD8 
#define td9     TRISDbits.TRISD9 
#define td10    TRISDbits.TRISD10
#define td11    TRISDbits.TRISD11
#define td12    TRISDbits.TRISD12
#define td13    TRISDbits.TRISD13
#define td14    TRISDbits.TRISD14
#define td15    TRISDbits.TRISD15

#define te0     TRISEbits.TRISE0 
#define te1     TRISEbits.TRISE1 
#define te2     TRISEbits.TRISE2 
#define te3     TRISEbits.TRISE3 
#define te4     TRISEbits.TRISE4 
#define te5     TRISEbits.TRISE5 
#define te6     TRISEbits.TRISE6 
#define te7     TRISEbits.TRISE7 
#define te8     TRISEbits.TRISE8 
#define te9     TRISEbits.TRISE9 
#define te10    TRISEbits.TRISE10
#define te11    TRISEbits.TRISE11
#define te12    TRISEbits.TRISE12
#define te13    TRISEbits.TRISE13
#define te14    TRISEbits.TRISE14
#define te15    TRISEbits.TRISE15

#define tf0     TRISFbits.TRISF0 
#define tf1     TRISFbits.TRISF1 
#define tf2     TRISFbits.TRISF2 
#define tf3     TRISFbits.TRISF3 
#define tf4     TRISFbits.TRISF4 
#define tf5     TRISFbits.TRISF5 
#define tf6     TRISFbits.TRISF6 
#define tf7     TRISFbits.TRISF7 
#define tf8     TRISFbits.TRISF8 
#define tf9     TRISFbits.TRISF9 
#define tf10    TRISFbits.TRISF10
#define tf11    TRISFbits.TRISF11
#define tf12    TRISFbits.TRISF12
#define tf13    TRISFbits.TRISF13
#define tf14    TRISFbits.TRISF14
#define tf15    TRISFbits.TRISF15

#define tg0     TRISGbits.TRISG0 
#define tg1     TRISGbits.TRISG1 
#define tg2     TRISGbits.TRISG2 
#define tg3     TRISGbits.TRISG3 
#define tg4     TRISGbits.TRISG4 
#define tg5     TRISGbits.TRISG5 
#define tg6     TRISGbits.TRISG6 
#define tg7     TRISGbits.TRISG7 
#define tg8     TRISGbits.TRISG8 
#define tg9     TRISGbits.TRISG9 
#define tg10    TRISGbits.TRISG10
#define tg11    TRISGbits.TRISG11
#define tg12    TRISGbits.TRISG12
#define tg13    TRISGbits.TRISG13
#define tg14    TRISGbits.TRISG14
#define tg15    TRISGbits.TRISG15

#define pa0     PORTAbits.RA0       // pin input pits 
#define pa1     PORTAbits.RA1 
#define pa2     PORTAbits.RA2 
#define pa3     PORTAbits.RA3 
#define pa4     PORTAbits.RA4 
#define pa5     PORTAbits.RA5 
#define pa6     PORTAbits.RA6 
#define pa7     PORTAbits.RA7 
#define pa8     PORTAbits.RA8 
#define pa9     PORTAbits.RA9 
#define pa10    PORTAbits.RA10
#define pa11    PORTAbits.RA11
#define pa12    PORTAbits.RA12
#define pa13    PORTAbits.RA13
#define pa14    PORTAbits.RA14
#define pa15    PORTAbits.RA15

#define pb0     PORTBbits.RB0 
#define pb1     PORTBbits.RB1 
#define pb2     PORTBbits.RB2 
#define pb3     PORTBbits.RB3 
#define pb4     PORTBbits.RB4 
#define pb5     PORTBbits.RB5 
#define pb6     PORTBbits.RB6 
#define pb7     PORTBbits.RB7 
#define pb8     PORTBbits.RB8 
#define pb9     PORTBbits.RB9 
#define pb10    PORTBbits.RB10
#define pb11    PORTBbits.RB11
#define pb12    PORTBbits.RB12
#define pb13    PORTBbits.RB13
#define pb14    PORTBbits.RB14
#define pb15    PORTBbits.RB15

#define pc0     PORTCbits.RC0 
#define pc1     PORTCbits.RC1 
#define pc2     PORTCbits.RC2 
#define pc3     PORTCbits.RC3 
#define pc4     PORTCbits.RC4 
#define pc5     PORTCbits.RC5 
#define pc6     PORTCbits.RC6 
#define pc7     PORTCbits.RC7 
#define pc8     PORTCbits.RC8 
#define pc9     PORTCbits.RC9 
#define pc10    PORTCbits.RC10
#define pc11    PORTCbits.RC11
#define pc12    PORTCbits.RC12
#define pc13    PORTCbits.RC13
#define pc14    PORTCbits.RC14
#define pc15    PORTCbits.RC15

#define pd0     PORTDbits.RD0 
#define pd1     PORTDbits.RD1 
#define pd2     PORTDbits.RD2 
#define pd3     PORTDbits.RD3 
#define pd4     PORTDbits.RD4 
#define pd5     PORTDbits.RD5 
#define pd6     PORTDbits.RD6 
#define pd7     PORTDbits.RD7 
#define pd8     PORTDbits.RD8 
#define pd9     PORTDbits.RD9 
#define pd10    PORTDbits.RD10
#define pd11    PORTDbits.RD11
#define pd12    PORTDbits.RD12
#define pd13    PORTDbits.RD13
#define pd14    PORTDbits.RD14
#define pd15    PORTDbits.RD15

#define pe0     PORTEbits.RE0 
#define pe1     PORTEbits.RE1 
#define pe2     PORTEbits.RE2 
#define pe3     PORTEbits.RE3 
#define pe4     PORTEbits.RE4 
#define pe5     PORTEbits.RE5 
#define pe6     PORTEbits.RE6 
#define pe7     PORTEbits.RE7 
#define pe8     PORTEbits.RE8 
#define pe9     PORTEbits.RE9 
#define pe10    PORTEbits.RE10
#define pe11    PORTEbits.RE11
#define pe12    PORTEbits.RE12
#define pe13    PORTEbits.RE13
#define pe14    PORTEbits.RE14
#define pe15    PORTEbits.RE15

#define pf0     PORTFbits.RF0 
#define pf1     PORTFbits.RF1 
#define pf2     PORTFbits.RF2 
#define pf3     PORTFbits.RF3 
#define pf4     PORTFbits.RF4 
#define pf5     PORTFbits.RF5 
#define pf6     PORTFbits.RF6 
#define pf7     PORTFbits.RF7 
#define pf8     PORTFbits.RF8 
#define pf9     PORTFbits.RF9 
#define pf10    PORTFbits.RF10
#define pf11    PORTFbits.RF11
#define pf12    PORTFbits.RF12
#define pf13    PORTFbits.RF13
#define pf14    PORTFbits.RF14
#define pf15    PORTFbits.RF15

#define pg0     PORTGbits.RG0 
#define pg1     PORTGbits.RG1 
#define pg2     PORTGbits.RG2 
#define pg3     PORTGbits.RG3 
#define pg4     PORTGbits.RG4 
#define pg5     PORTGbits.RG5 
#define pg6     PORTGbits.RG6 
#define pg7     PORTGbits.RG7 
#define pg8     PORTGbits.RG8 
#define pg9     PORTGbits.RG9 
#define pg10    PORTGbits.RG10
#define pg11    PORTGbits.RG11
#define pg12    PORTGbits.RG12
#define pg13    PORTGbits.RG13
#define pg14    PORTGbits.RG14
#define pg15    PORTGbits.RG15

#define la0     LATAbits.LATA0      // pin output pits
#define la1     LATAbits.LATA1 
#define la2     LATAbits.LATA2 
#define la3     LATAbits.LATA3 
#define la4     LATAbits.LATA4 
#define la5     LATAbits.LATA5 
#define la6     LATAbits.LATA6 
#define la7     LATAbits.LATA7 
#define la8     LATAbits.LATA8 
#define la9     LATAbits.LATA9 
#define la10    LATAbits.LATA10
#define la11    LATAbits.LATA11
#define la12    LATAbits.LATA12
#define la13    LATAbits.LATA13
#define la14    LATAbits.LATA14
#define la15    LATAbits.LATA15

#define lb0     LATBbits.LATB0 
#define lb1     LATBbits.LATB1 
#define lb2     LATBbits.LATB2 
#define lb3     LATBbits.LATB3 
#define lb4     LATBbits.LATB4 
#define lb5     LATBbits.LATB5 
#define lb6     LATBbits.LATB6 
#define lb7     LATBbits.LATB7 
#define lb8     LATBbits.LATB8 
#define lb9     LATBbits.LATB9 
#define lb10    LATBbits.LATB10
#define lb11    LATBbits.LATB11
#define lb12    LATBbits.LATB12
#define lb13    LATBbits.LATB13
#define lb14    LATBbits.LATB14
#define lb15    LATBbits.LATB15

#define lc0     LATCbits.LATC0 
#define lc1     LATCbits.LATC1 
#define lc2     LATCbits.LATC2 
#define lc3     LATCbits.LATC3 
#define lc4     LATCbits.LATC4 
#define lc5     LATCbits.LATC5 
#define lc6     LATCbits.LATC6 
#define lc7     LATCbits.LATC7 
#define lc8     LATCbits.LATC8 
#define lc9     LATCbits.LATC9 
#define lc10    LATCbits.LATC10
#define lc11    LATCbits.LATC11
#define lc12    LATCbits.LATC12
#define lc13    LATCbits.LATC13
#define lc14    LATCbits.LATC14
#define lc15    LATCbits.LATC15

#define ld0     LATDbits.LATD0 
#define ld1     LATDbits.LATD1 
#define ld2     LATDbits.LATD2 
#define ld3     LATDbits.LATD3 
#define ld4     LATDbits.LATD4 
#define ld5     LATDbits.LATD5 
#define ld6     LATDbits.LATD6 
#define ld7     LATDbits.LATD7 
#define ld8     LATDbits.LATD8 
#define ld9     LATDbits.LATD9 
#define ld10    LATDbits.LATD10
#define ld11    LATDbits.LATD11
#define ld12    LATDbits.LATD12
#define ld13    LATDbits.LATD13
#define ld14    LATDbits.LATD14
#define ld15    LATDbits.LATD15

#define le0     LATEbits.LATE0 
#define le1     LATEbits.LATE1 
#define le2     LATEbits.LATE2 
#define le3     LATEbits.LATE3 
#define le4     LATEbits.LATE4 
#define le5     LATEbits.LATE5 
#define le6     LATEbits.LATE6 
#define le7     LATEbits.LATE7 
#define le8     LATEbits.LATE8 
#define le9     LATEbits.LATE9 
#define le10    LATEbits.LATE10
#define le11    LATEbits.LATE11
#define le12    LATEbits.LATE12
#define le13    LATEbits.LATE13
#define le14    LATEbits.LATE14
#define le15    LATEbits.LATE15

#define lf0     LATFbits.LATF0 
#define lf1     LATFbits.LATF1 
#define lf2     LATFbits.LATF2 
#define lf3     LATFbits.LATF3 
#define lf4     LATFbits.LATF4 
#define lf5     LATFbits.LATF5 
#define lf6     LATFbits.LATF6 
#define lf7     LATFbits.LATF7 
#define lf8     LATFbits.LATF8 
#define lf9     LATFbits.LATF9 
#define lf10    LATFbits.LATF10
#define lf11    LATFbits.LATF11
#define lf12    LATFbits.LATF12
#define lf13    LATFbits.LATF13
#define lf14    LATFbits.LATF14
#define lf15    LATFbits.LATF15

#define lg0     LATGbits.LATG0 
#define lg1     LATGbits.LATG1 
#define lg2     LATGbits.LATG2 
#define lg3     LATGbits.LATG3 
#define lg4     LATGbits.LATG4 
#define lg5     LATGbits.LATG5 
#define lg6     LATGbits.LATG6 
#define lg7     LATGbits.LATG7 
#define lg8     LATGbits.LATG8 
#define lg9     LATGbits.LATG9 
#define lg10    LATGbits.LATG10
#define lg11    LATGbits.LATG11
#define lg12    LATGbits.LATG12
#define lg13    LATGbits.LATG13
#define lg14    LATGbits.LATG14
#define lg15    LATGbits.LATG15

#include "./machine/pin.c"

void setup(void)
{
    pin_setup(ta0, out); // Onboard LEDs            
    pin_setup(ta1, out);        
    pin_setup(ta2, out);        
    pin_setup(ta3, out);       
    pin_setup(ta4, out);       
    pin_setup(ta5, out);        
    pin_setup(ta6, out);        
    pin_setup(ta7, out);    

    pin_setup(td6, in); // Onboard switchs  
    pin_setup(td13, in);  
    pin_setup(ta7, in); 
    pin_setup(td7, in); 

    pin_setup(tb5, in);  // Onboard potentiometer
}