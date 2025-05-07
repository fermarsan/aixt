# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 285 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/xc8/v3.00/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2






# 1 "/opt/microchip/xc8/v3.00/pic/include/xc.h" 1 3
# 18 "/opt/microchip/xc8/v3.00/pic/include/xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);


# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/xc8debug.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 2 3





# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/features.h" 1 3
# 11 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 2 3
# 21 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 1 3
# 24 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef long int wchar_t;
# 128 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 174 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef __int24 int24_t;
# 210 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 22 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);



double atof (const char *);


float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);





unsigned long __strtoxl(const char * s, char ** endptr, int base, char is_signed);
# 55 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 3
int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);




typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;




div_t div (int, int);
ldiv_t ldiv (long, long);




typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 5 "/opt/microchip/xc8/v3.00/pic/include/c99/xc8debug.h" 2 3







#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 24 "/opt/microchip/xc8/v3.00/pic/include/xc.h" 2 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/builtins.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 1 3
# 26 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 1 3
# 133 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef short intptr_t;
# 164 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 179 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef long int32_t;
# 192 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef int32_t intmax_t;







typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 215 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uint32_t;
# 233 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef uint32_t uintmax_t;
# 27 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;




typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;




typedef uint8_t uint_fast8_t;




typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;
# 148 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 2 3
# 5 "/opt/microchip/xc8/v3.00/pic/include/builtins.h" 2 3


#pragma intrinsic(__nop)
extern void __nop(void);
# 19 "/opt/microchip/xc8/v3.00/pic/include/builtins.h" 3
#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(uint32_t);
# 25 "/opt/microchip/xc8/v3.00/pic/include/xc.h" 2 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/pic.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/xc.h" 1 3
# 5 "/opt/microchip/xc8/v3.00/pic/include/pic.h" 2 3






# 1 "/opt/microchip/xc8/v3.00/pic/include/pic_chip_select.h" 1 3
# 1965 "/opt/microchip/xc8/v3.00/pic/include/pic_chip_select.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 1 3
# 50 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char INDF __attribute__((address(0x000)));

__asm("INDF equ 00h");




extern volatile unsigned char TMR0 __attribute__((address(0x001)));

__asm("TMR0 equ 01h");




extern volatile unsigned char PCL __attribute__((address(0x002)));

__asm("PCL equ 02h");




extern volatile unsigned char STATUS __attribute__((address(0x003)));

__asm("STATUS equ 03h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned RP :2;
        unsigned IRP :1;
    };
    struct {
        unsigned :5;
        unsigned RP0 :1;
        unsigned RP1 :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0x003)));
# 157 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char FSR __attribute__((address(0x004)));

__asm("FSR equ 04h");




extern volatile unsigned char PORTA __attribute__((address(0x005)));

__asm("PORTA equ 05h");


typedef union {
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
    };
} PORTAbits_t;
extern volatile PORTAbits_t PORTAbits __attribute__((address(0x005)));
# 208 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char PORTB __attribute__((address(0x006)));

__asm("PORTB equ 06h");


typedef union {
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
} PORTBbits_t;
extern volatile PORTBbits_t PORTBbits __attribute__((address(0x006)));
# 270 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char EEDATA __attribute__((address(0x008)));

__asm("EEDATA equ 08h");




extern volatile unsigned char EEADR __attribute__((address(0x009)));

__asm("EEADR equ 09h");




extern volatile unsigned char PCLATH __attribute__((address(0x00A)));

__asm("PCLATH equ 0Ah");


typedef union {
    struct {
        unsigned PCLATH :5;
    };
} PCLATHbits_t;
extern volatile PCLATHbits_t PCLATHbits __attribute__((address(0x00A)));
# 304 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char INTCON __attribute__((address(0x00B)));

__asm("INTCON equ 0Bh");


typedef union {
    struct {
        unsigned RBIF :1;
        unsigned INTF :1;
        unsigned T0IF :1;
        unsigned RBIE :1;
        unsigned INTE :1;
        unsigned T0IE :1;
        unsigned EEIE :1;
        unsigned GIE :1;
    };
    struct {
        unsigned :2;
        unsigned TMR0IF :1;
        unsigned :2;
        unsigned TMR0IE :1;
    };
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __attribute__((address(0x00B)));
# 382 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char OPTION_REG __attribute__((address(0x081)));

__asm("OPTION_REG equ 081h");


typedef union {
    struct {
        unsigned PS :3;
        unsigned PSA :1;
        unsigned T0SE :1;
        unsigned T0CS :1;
        unsigned INTEDG :1;
        unsigned nRBPU :1;
    };
    struct {
        unsigned PS0 :1;
        unsigned PS1 :1;
        unsigned PS2 :1;
    };
} OPTION_REGbits_t;
extern volatile OPTION_REGbits_t OPTION_REGbits __attribute__((address(0x081)));
# 452 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char TRISA __attribute__((address(0x085)));

__asm("TRISA equ 085h");


typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
    };
} TRISAbits_t;
extern volatile TRISAbits_t TRISAbits __attribute__((address(0x085)));
# 496 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char TRISB __attribute__((address(0x086)));

__asm("TRISB equ 086h");


typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
        unsigned TRISB3 :1;
        unsigned TRISB4 :1;
        unsigned TRISB5 :1;
        unsigned TRISB6 :1;
        unsigned TRISB7 :1;
    };
} TRISBbits_t;
extern volatile TRISBbits_t TRISBbits __attribute__((address(0x086)));
# 558 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char EECON1 __attribute__((address(0x088)));

__asm("EECON1 equ 088h");


typedef union {
    struct {
        unsigned RD :1;
        unsigned WR :1;
        unsigned WREN :1;
        unsigned WRERR :1;
        unsigned EEIF :1;
    };
} EECON1bits_t;
extern volatile EECON1bits_t EECON1bits __attribute__((address(0x088)));
# 602 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile unsigned char EECON2 __attribute__((address(0x089)));

__asm("EECON2 equ 089h");
# 619 "/opt/microchip/xc8/v3.00/pic/include/proc/pic16f83.h" 3
extern volatile __bit CARRY __attribute__((address(0x18)));


extern volatile __bit DC __attribute__((address(0x19)));


extern volatile __bit EEIE __attribute__((address(0x5E)));


extern volatile __bit EEIF __attribute__((address(0x444)));


extern volatile __bit GIE __attribute__((address(0x5F)));


extern volatile __bit INTE __attribute__((address(0x5C)));


extern volatile __bit INTEDG __attribute__((address(0x40E)));


extern volatile __bit INTF __attribute__((address(0x59)));


extern volatile __bit IRP __attribute__((address(0x1F)));


extern volatile __bit PS0 __attribute__((address(0x408)));


extern volatile __bit PS1 __attribute__((address(0x409)));


extern volatile __bit PS2 __attribute__((address(0x40A)));


extern volatile __bit PSA __attribute__((address(0x40B)));


extern volatile __bit RA0 __attribute__((address(0x28)));


extern volatile __bit RA1 __attribute__((address(0x29)));


extern volatile __bit RA2 __attribute__((address(0x2A)));


extern volatile __bit RA3 __attribute__((address(0x2B)));


extern volatile __bit RA4 __attribute__((address(0x2C)));


extern volatile __bit RB0 __attribute__((address(0x30)));


extern volatile __bit RB1 __attribute__((address(0x31)));


extern volatile __bit RB2 __attribute__((address(0x32)));


extern volatile __bit RB3 __attribute__((address(0x33)));


extern volatile __bit RB4 __attribute__((address(0x34)));


extern volatile __bit RB5 __attribute__((address(0x35)));


extern volatile __bit RB6 __attribute__((address(0x36)));


extern volatile __bit RB7 __attribute__((address(0x37)));


extern volatile __bit RBIE __attribute__((address(0x5B)));


extern volatile __bit RBIF __attribute__((address(0x58)));


extern volatile __bit RD __attribute__((address(0x440)));


extern volatile __bit RP0 __attribute__((address(0x1D)));


extern volatile __bit RP1 __attribute__((address(0x1E)));


extern volatile __bit T0CS __attribute__((address(0x40D)));


extern volatile __bit T0IE __attribute__((address(0x5D)));


extern volatile __bit T0IF __attribute__((address(0x5A)));


extern volatile __bit T0SE __attribute__((address(0x40C)));


extern volatile __bit TMR0IE __attribute__((address(0x5D)));


extern volatile __bit TMR0IF __attribute__((address(0x5A)));


extern volatile __bit TRISA0 __attribute__((address(0x428)));


extern volatile __bit TRISA1 __attribute__((address(0x429)));


extern volatile __bit TRISA2 __attribute__((address(0x42A)));


extern volatile __bit TRISA3 __attribute__((address(0x42B)));


extern volatile __bit TRISA4 __attribute__((address(0x42C)));


extern volatile __bit TRISB0 __attribute__((address(0x430)));


extern volatile __bit TRISB1 __attribute__((address(0x431)));


extern volatile __bit TRISB2 __attribute__((address(0x432)));


extern volatile __bit TRISB3 __attribute__((address(0x433)));


extern volatile __bit TRISB4 __attribute__((address(0x434)));


extern volatile __bit TRISB5 __attribute__((address(0x435)));


extern volatile __bit TRISB6 __attribute__((address(0x436)));


extern volatile __bit TRISB7 __attribute__((address(0x437)));


extern volatile __bit WR __attribute__((address(0x441)));


extern volatile __bit WREN __attribute__((address(0x442)));


extern volatile __bit WRERR __attribute__((address(0x443)));


extern volatile __bit ZERO __attribute__((address(0x1A)));


extern volatile __bit nPD __attribute__((address(0x1B)));


extern volatile __bit nRBPU __attribute__((address(0x40F)));


extern volatile __bit nTO __attribute__((address(0x1C)));
# 1966 "/opt/microchip/xc8/v3.00/pic/include/pic_chip_select.h" 2 3
# 12 "/opt/microchip/xc8/v3.00/pic/include/pic.h" 2 3
# 60 "/opt/microchip/xc8/v3.00/pic/include/pic.h" 3
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);


# 1 "/opt/microchip/xc8/v3.00/pic/include/eeprom_routines.h" 1 3
# 114 "/opt/microchip/xc8/v3.00/pic/include/eeprom_routines.h" 3
extern void eeprom_write(unsigned char addr, unsigned char value);
extern unsigned char eeprom_read(unsigned char addr);
# 68 "/opt/microchip/xc8/v3.00/pic/include/pic.h" 2 3
# 102 "/opt/microchip/xc8/v3.00/pic/include/pic.h" 3
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;
# 29 "/opt/microchip/xc8/v3.00/pic/include/xc.h" 2 3
# 8 "main.c" 2

# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/stdbool.h" 1 3
# 10 "main.c" 2
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;

typedef int8_t isize;
typedef int32_t int_literal;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef uint8_t usize;
typedef float f32;

typedef float float_literal;
typedef char rune;








#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config CP = OFF








void (*ptr_timer0_isr)(void);


void __attribute__((picinterrupt(("")))) Global_ISR() {
# 57 "main.c"
 if(T0IF == 1) {
  ptr_timer0_isr();
  T0IF = 0;
 }

}



u8 timer0__initial = (u8)(0);
# 212 "main.c"
 void main__blinking() {
 TMR0 = (u8)(timer0__initial);
 *(&PORTA + (12 >> 3)) ^= 0x01 << (12 - ((12 >> 3) << 3));
}

 void main(void) {
 ptr_timer0_isr = main__blinking;
 if( 0 == 1 ) { *(&TRISA + (12 >> 3)) |= (0x01 << (12 - ((12 >> 3) << 3))); } else { *(&TRISA + (12 >> 3)) &= ~(0x01 << (12 - ((12 >> 3) << 3))); };;
 T0CS = 0; if( 100 <= (u32)((u32)(1024) / (u8)(10000000/1000000)) ) { PSA = 1; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(2)) * (u16)(10000000/1000000))); } else { PSA = 0; OPTION_REG &= 0b11111000; if( 100 <= (u32)((u32)(2048) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b000; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(3)) * (u16)(10000000/1000000))); } else if( 100 <= (u32)((u32)(4096) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b001; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(4)) * (u16)(10000000/1000000))); } else if( 100 <= (u32)((u32)(8192) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b010; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(5)) * (u16)(10000000/1000000))); } else if( 100 <= (u32)((u32)(16384) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b011; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(6)) * (u16)(10000000/1000000))); } else if( 100 <= (u32)((u32)(32768) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b100; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(7)) * (u16)(10000000/1000000))); } else if( 100 <= (u32)((u32)(65536) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b101; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(8)) * (u16)(10000000/1000000))); } else if( 100 <= (u32)((u32)(131072) / (u8)(10000000/1000000)) ) { OPTION_REG |= 0b110; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(9)) * (u16)(10000000/1000000))); } else { OPTION_REG |= 0b111; timer0__initial = (u8)((u8)(256 - (u16)(100 >> (u8)(10)) * (u16)(10000000/1000000))); }; }; TMR0 = (u8)(timer0__initial);;
 *(&PORTA + (12 >> 3)) &= ~(0x01 << (12 - ((12 >> 3) << 3)));
 GIE = 1; T0IE = 1;;
 while( 1 ) {
 }
}
