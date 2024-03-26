subtitle "Microchip MPLAB XC8 C Compiler v2.41 (Free license) build 20230208172133 Og1 "

pagewidth 120

	opt flic

	processor	16F886
include "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\16f886.cgen.inc"
getbyte	macro	val,pos
	(((val) >> (8 * pos)) and 0xff)
endm
byte0	macro	val
	(getbyte(val,0))
endm
byte1	macro	val
	(getbyte(val,1))
endm
byte2	macro	val
	(getbyte(val,2))
endm
byte3	macro	val
	(getbyte(val,3))
endm
byte4	macro	val
	(getbyte(val,4))
endm
byte5	macro	val
	(getbyte(val,5))
endm
byte6	macro	val
	(getbyte(val,6))
endm
byte7	macro	val
	(getbyte(val,7))
endm
getword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffff)
endm
word0	macro	val
	(getword(val,0))
endm
word1	macro	val
	(getword(val,2))
endm
word2	macro	val
	(getword(val,4))
endm
word3	macro	val
	(getword(val,6))
endm
gettword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffffff)
endm
tword0	macro	val
	(gettword(val,0))
endm
tword1	macro	val
	(gettword(val,3))
endm
tword2	macro	val
	(gettword(val,6))
endm
getdword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffffffff)
endm
dword0	macro	val
	(getdword(val,0))
endm
dword1	macro	val
	(getdword(val,4))
endm
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
# 54 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
INDF equ 00h ;# 
# 61 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR0 equ 01h ;# 
# 68 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PCL equ 02h ;# 
# 75 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
STATUS equ 03h ;# 
# 161 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
FSR equ 04h ;# 
# 168 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTA equ 05h ;# 
# 230 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTB equ 06h ;# 
# 292 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTC equ 07h ;# 
# 354 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTE equ 09h ;# 
# 375 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PCLATH equ 0Ah ;# 
# 382 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
INTCON equ 0Bh ;# 
# 460 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIR1 equ 0Ch ;# 
# 516 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIR2 equ 0Dh ;# 
# 573 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR1 equ 0Eh ;# 
# 580 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR1L equ 0Eh ;# 
# 587 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR1H equ 0Fh ;# 
# 594 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
T1CON equ 010h ;# 
# 688 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR2 equ 011h ;# 
# 695 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
T2CON equ 012h ;# 
# 766 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPBUF equ 013h ;# 
# 773 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPCON equ 014h ;# 
# 843 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR1 equ 015h ;# 
# 850 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR1L equ 015h ;# 
# 857 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR1H equ 016h ;# 
# 864 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCP1CON equ 017h ;# 
# 961 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
RCSTA equ 018h ;# 
# 1056 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TXREG equ 019h ;# 
# 1063 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
RCREG equ 01Ah ;# 
# 1070 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR2 equ 01Bh ;# 
# 1077 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR2L equ 01Bh ;# 
# 1084 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR2H equ 01Ch ;# 
# 1091 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCP2CON equ 01Dh ;# 
# 1161 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADRESH equ 01Eh ;# 
# 1168 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADCON0 equ 01Fh ;# 
# 1269 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
OPTION_REG equ 081h ;# 
# 1339 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISA equ 085h ;# 
# 1401 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISB equ 086h ;# 
# 1463 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISC equ 087h ;# 
# 1525 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISE equ 089h ;# 
# 1546 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIE1 equ 08Ch ;# 
# 1602 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIE2 equ 08Dh ;# 
# 1659 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PCON equ 08Eh ;# 
# 1706 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
OSCCON equ 08Fh ;# 
# 1771 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
OSCTUNE equ 090h ;# 
# 1823 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPCON2 equ 091h ;# 
# 1885 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PR2 equ 092h ;# 
# 1892 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPADD equ 093h ;# 
# 1899 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPMSK equ 093h ;# 
# 1904 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
MSK equ 093h ;# 
# 2021 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPSTAT equ 094h ;# 
# 2190 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
WPUB equ 095h ;# 
# 2260 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
IOCB equ 096h ;# 
# 2330 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
VRCON equ 097h ;# 
# 2400 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TXSTA equ 098h ;# 
# 2486 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SPBRG equ 099h ;# 
# 2548 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SPBRGH equ 09Ah ;# 
# 2618 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PWM1CON equ 09Bh ;# 
# 2688 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ECCPAS equ 09Ch ;# 
# 2770 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PSTRCON equ 09Dh ;# 
# 2814 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADRESL equ 09Eh ;# 
# 2821 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADCON1 equ 09Fh ;# 
# 2855 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
WDTCON equ 0105h ;# 
# 2908 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CM1CON0 equ 0107h ;# 
# 2973 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CM2CON0 equ 0108h ;# 
# 3038 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CM2CON1 equ 0109h ;# 
# 3089 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEDATA equ 010Ch ;# 
# 3094 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEDAT equ 010Ch ;# 
# 3101 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEADR equ 010Dh ;# 
# 3108 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEDATH equ 010Eh ;# 
# 3115 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEADRH equ 010Fh ;# 
# 3122 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SRCON equ 0185h ;# 
# 3179 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
BAUDCTL equ 0187h ;# 
# 3231 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ANSEL equ 0188h ;# 
# 3275 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ANSELH equ 0189h ;# 
# 3325 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EECON1 equ 018Ch ;# 
# 3370 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EECON2 equ 018Dh ;# 
# 54 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
INDF equ 00h ;# 
# 61 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR0 equ 01h ;# 
# 68 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PCL equ 02h ;# 
# 75 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
STATUS equ 03h ;# 
# 161 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
FSR equ 04h ;# 
# 168 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTA equ 05h ;# 
# 230 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTB equ 06h ;# 
# 292 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTC equ 07h ;# 
# 354 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PORTE equ 09h ;# 
# 375 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PCLATH equ 0Ah ;# 
# 382 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
INTCON equ 0Bh ;# 
# 460 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIR1 equ 0Ch ;# 
# 516 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIR2 equ 0Dh ;# 
# 573 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR1 equ 0Eh ;# 
# 580 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR1L equ 0Eh ;# 
# 587 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR1H equ 0Fh ;# 
# 594 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
T1CON equ 010h ;# 
# 688 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TMR2 equ 011h ;# 
# 695 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
T2CON equ 012h ;# 
# 766 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPBUF equ 013h ;# 
# 773 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPCON equ 014h ;# 
# 843 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR1 equ 015h ;# 
# 850 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR1L equ 015h ;# 
# 857 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR1H equ 016h ;# 
# 864 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCP1CON equ 017h ;# 
# 961 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
RCSTA equ 018h ;# 
# 1056 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TXREG equ 019h ;# 
# 1063 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
RCREG equ 01Ah ;# 
# 1070 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR2 equ 01Bh ;# 
# 1077 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR2L equ 01Bh ;# 
# 1084 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCPR2H equ 01Ch ;# 
# 1091 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CCP2CON equ 01Dh ;# 
# 1161 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADRESH equ 01Eh ;# 
# 1168 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADCON0 equ 01Fh ;# 
# 1269 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
OPTION_REG equ 081h ;# 
# 1339 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISA equ 085h ;# 
# 1401 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISB equ 086h ;# 
# 1463 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISC equ 087h ;# 
# 1525 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TRISE equ 089h ;# 
# 1546 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIE1 equ 08Ch ;# 
# 1602 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PIE2 equ 08Dh ;# 
# 1659 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PCON equ 08Eh ;# 
# 1706 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
OSCCON equ 08Fh ;# 
# 1771 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
OSCTUNE equ 090h ;# 
# 1823 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPCON2 equ 091h ;# 
# 1885 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PR2 equ 092h ;# 
# 1892 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPADD equ 093h ;# 
# 1899 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPMSK equ 093h ;# 
# 1904 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
MSK equ 093h ;# 
# 2021 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SSPSTAT equ 094h ;# 
# 2190 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
WPUB equ 095h ;# 
# 2260 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
IOCB equ 096h ;# 
# 2330 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
VRCON equ 097h ;# 
# 2400 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
TXSTA equ 098h ;# 
# 2486 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SPBRG equ 099h ;# 
# 2548 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SPBRGH equ 09Ah ;# 
# 2618 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PWM1CON equ 09Bh ;# 
# 2688 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ECCPAS equ 09Ch ;# 
# 2770 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
PSTRCON equ 09Dh ;# 
# 2814 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADRESL equ 09Eh ;# 
# 2821 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ADCON1 equ 09Fh ;# 
# 2855 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
WDTCON equ 0105h ;# 
# 2908 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CM1CON0 equ 0107h ;# 
# 2973 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CM2CON0 equ 0108h ;# 
# 3038 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
CM2CON1 equ 0109h ;# 
# 3089 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEDATA equ 010Ch ;# 
# 3094 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEDAT equ 010Ch ;# 
# 3101 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEADR equ 010Dh ;# 
# 3108 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEDATH equ 010Eh ;# 
# 3115 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EEADRH equ 010Fh ;# 
# 3122 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
SRCON equ 0185h ;# 
# 3179 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
BAUDCTL equ 0187h ;# 
# 3231 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ANSEL equ 0188h ;# 
# 3275 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
ANSELH equ 0189h ;# 
# 3325 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EECON1 equ 018Ch ;# 
# 3370 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f886.h"
EECON2 equ 018Dh ;# 
	debug_source C
	FNCALL	_main,_adc__read
	FNCALL	_main,_main__init
	FNCALL	_main__init,_adc__init
	FNCALL	_main__init,_pin__init
	FNROOT	_main
	global	_ADCON0
_ADCON0	set	0x1F
	global	_PORTCbits
_PORTCbits	set	0x7
	global	_ADRESH
_ADRESH	set	0x1E
	global	_ADCON0bits
_ADCON0bits	set	0x1F
	global	_ADCON1
_ADCON1	set	0x9F
	global	_TRISCbits
_TRISCbits	set	0x87
	global	_ADRESL
_ADRESL	set	0x9E
; #config settings
	config pad_punits      = on
	config apply_mask      = off
	config ignore_cmsgs    = off
	config default_configs = off
	config default_idlocs  = off
	config FOSC = "HS"
	config WDTE = "OFF"
	config PWRTE = "OFF"
	config MCLRE = "OFF"
	config CP = "OFF"
	config CPD = "OFF"
	config BOREN = "OFF"
	config IESO = "OFF"
	config FCMEN = "OFF"
	config LVP = "OFF"
	config BOR4V = "BOR40V"
	config WRT = "OFF"
	file	"dist/default/production\ADC.X.production.s"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect cinit,class=CODE,delta=2,merge=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_pin__init:	; 1 bytes @ 0x0
??_pin__init:	; 1 bytes @ 0x0
?_adc__init:	; 1 bytes @ 0x0
??_adc__init:	; 1 bytes @ 0x0
?_main__init:	; 1 bytes @ 0x0
??_main__init:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
	global	?_adc__read
?_adc__read:	; 2 bytes @ 0x0
	global	adc__read@channel
adc__read@channel:	; 2 bytes @ 0x0
	ds	2
??_adc__read:	; 1 bytes @ 0x2
	ds	1
??_main:	; 1 bytes @ 0x3
	global	main@a
main@a:	; 2 bytes @ 0x3
	ds	2
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         0
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14      5       5
;!    BANK0            80      0       0
;!    BANK1            80      0       0
;!    BANK3            96      0       0
;!    BANK2            96      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMMON
;!
;!    _main->_adc__read
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 2     2      0     232
;!                                              3 COMMON     2     2      0
;!                          _adc__read
;!                         _main__init
;! ---------------------------------------------------------------------------------
;! (1) _main__init                                           0     0      0       0
;!                          _adc__init
;!                          _pin__init
;! ---------------------------------------------------------------------------------
;! (2) _pin__init                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! (2) _adc__init                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _adc__read                                            3     1      2      98
;!                                              0 COMMON     3     1      2
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _adc__read
;!   _main__init
;!     _adc__init
;!     _pin__init
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!EEDATA             100      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      5       5       1       35.7%
;!BITSFR0              0      0       0       1        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!SFR1                 0      0       0       2        0.0%
;!STACK                0      0       0       2        0.0%
;!ABS                  0      0       0       3        0.0%
;!BITBANK0            50      0       0       4        0.0%
;!BITSFR3              0      0       0       4        0.0%
;!SFR3                 0      0       0       4        0.0%
;!BANK0               50      0       0       5        0.0%
;!BITSFR2              0      0       0       5        0.0%
;!SFR2                 0      0       0       5        0.0%
;!BITBANK1            50      0       0       6        0.0%
;!BANK1               50      0       0       7        0.0%
;!BITBANK3            60      0       0       8        0.0%
;!BANK3               60      0       0       9        0.0%
;!BITBANK2            60      0       0      10        0.0%
;!BANK2               60      0       0      11        0.0%
;!DATA                 0      0       0      12        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 114 in file "adc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  a               2    3[COMMON] unsigned short 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         2       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         2       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels required when called: 2
;; This function calls:
;;		_adc__read
;;		_main__init
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"adc.c"
	line	114
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"adc.c"
	line	114
	
_main:	
;incstack = 0
	callstack 6
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	115
	
l723:	
	fcall	_main__init
	line	116
	
l725:	
	line	117
	
l727:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(135)^080h,0	;volatile
	line	118
	
l729:	
	bcf	(135)^080h,1	;volatile
	line	119
	
l731:	
	bcf	(135)^080h,2	;volatile
	line	120
	
l733:	
	bcf	(135)^080h,3	;volatile
	line	121
	
l735:	
	bcf	(135)^080h,4	;volatile
	line	122
	
l737:	
	bcf	(135)^080h,5	;volatile
	line	123
	
l739:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(7),0	;volatile
	line	124
	
l741:	
	bcf	(7),1	;volatile
	line	125
	
l743:	
	bcf	(7),2	;volatile
	line	126
	
l745:	
	bcf	(7),3	;volatile
	line	127
	
l747:	
	bcf	(7),4	;volatile
	line	128
	
l749:	
	bcf	(7),5	;volatile
	line	129
	
l751:	
	movlw	low(080h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(159)^080h	;volatile
	
l753:	
	movlw	low(0C8h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(31)	;volatile
	
l755:	
	bsf	(31),0	;volatile
	line	131
	
l757:	
	movlw	04h
	movwf	(adc__read@channel)
	movlw	0
	movwf	((adc__read@channel))+1
	fcall	_adc__read
	movf	(1+(?_adc__read)),w
	movwf	(main@a+1)
	movf	(0+(?_adc__read)),w
	movwf	(main@a)
	line	132
	
l759:	
	movlw	03h
	subwf	(main@a+1),w
	movlw	0FCh
	skipnz
	subwf	(main@a),w
	skipc
	goto	u91
	goto	u90
u91:
	goto	l763
u90:
	line	133
	
l761:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(7),0	;volatile
	line	134
	bsf	(7),1	;volatile
	line	135
	bsf	(7),2	;volatile
	line	136
	bsf	(7),3	;volatile
	line	137
	bsf	(7),4	;volatile
	line	138
	bsf	(7),5	;volatile
	line	139
	goto	l757
	line	140
	
l763:	
	movlw	03h
	subwf	(main@a+1),w
	movlw	034h
	skipnz
	subwf	(main@a),w
	skipc
	goto	u101
	goto	u100
u101:
	goto	l767
u100:
	line	141
	
l765:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(7),0	;volatile
	line	142
	bsf	(7),1	;volatile
	line	143
	bsf	(7),2	;volatile
	line	144
	bsf	(7),3	;volatile
	line	145
	bsf	(7),4	;volatile
	line	146
	bcf	(7),5	;volatile
	line	147
	goto	l757
	line	148
	
l767:	
	movlw	02h
	subwf	(main@a+1),w
	movlw	06Ch
	skipnz
	subwf	(main@a),w
	skipc
	goto	u111
	goto	u110
u111:
	goto	l771
u110:
	line	149
	
l769:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(7),0	;volatile
	line	150
	bsf	(7),1	;volatile
	line	151
	bsf	(7),2	;volatile
	line	152
	bsf	(7),3	;volatile
	line	153
	bcf	(7),4	;volatile
	line	154
	bcf	(7),5	;volatile
	line	155
	goto	l757
	line	156
	
l771:	
	movlw	01h
	subwf	(main@a+1),w
	movlw	0A4h
	skipnz
	subwf	(main@a),w
	skipc
	goto	u121
	goto	u120
u121:
	goto	l775
u120:
	line	157
	
l773:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(7),0	;volatile
	line	158
	bsf	(7),1	;volatile
	line	159
	bsf	(7),2	;volatile
	line	160
	bcf	(7),3	;volatile
	line	161
	bcf	(7),4	;volatile
	line	162
	bcf	(7),5	;volatile
	line	163
	goto	l757
	line	164
	
l775:	
	movlw	0
	subwf	(main@a+1),w
	movlw	0DCh
	skipnz
	subwf	(main@a),w
	skipc
	goto	u131
	goto	u130
u131:
	goto	l779
u130:
	line	165
	
l777:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(7),0	;volatile
	line	166
	bsf	(7),1	;volatile
	line	167
	bcf	(7),2	;volatile
	line	168
	bcf	(7),3	;volatile
	line	169
	bcf	(7),4	;volatile
	line	170
	bcf	(7),5	;volatile
	line	171
	goto	l757
	line	172
	
l779:	
	movlw	0
	subwf	(main@a+1),w
	movlw	078h
	skipnz
	subwf	(main@a),w
	skipc
	goto	u141
	goto	u140
u141:
	goto	l49
u140:
	line	173
	
l781:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(7),0	;volatile
	line	174
	bcf	(7),1	;volatile
	line	175
	bcf	(7),2	;volatile
	line	176
	bcf	(7),3	;volatile
	line	177
	bcf	(7),4	;volatile
	line	178
	bcf	(7),5	;volatile
	line	179
	goto	l757
	line	180
	
l49:	
	line	181
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(7),0	;volatile
	line	182
	bcf	(7),1	;volatile
	line	183
	bcf	(7),2	;volatile
	line	184
	bcf	(7),3	;volatile
	line	185
	bcf	(7),4	;volatile
	line	186
	bcf	(7),5	;volatile
	goto	l757
	global	start
	ljmp	start
	callstack 0
	line	189
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_main__init

;; *************** function _main__init *****************
;; Defined at:
;;		line 94 in file "adc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 1
;; This function calls:
;;		_adc__init
;;		_pin__init
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	94
global __ptext1
__ptext1:	;psect for function _main__init
psect	text1
	file	"adc.c"
	line	94
	
_main__init:	
;incstack = 0
	callstack 6
; Regs used in _main__init: [status,2+status,0+pclath+cstack]
	line	95
	
l645:	
	fcall	_pin__init
	line	96
	fcall	_adc__init
	line	98
	
l21:	
	return
	callstack 0
GLOBAL	__end_of_main__init
	__end_of_main__init:
	signat	_main__init,89
	global	_pin__init

;; *************** function _pin__init *****************
;; Defined at:
;;		line 100 in file "adc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main__init
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	100
global __ptext2
__ptext2:	;psect for function _pin__init
psect	text2
	file	"adc.c"
	line	100
	
_pin__init:	
;incstack = 0
	callstack 6
; Regs used in _pin__init: []
	line	101
	
l24:	
	return
	callstack 0
GLOBAL	__end_of_pin__init
	__end_of_pin__init:
	signat	_pin__init,89
	global	_adc__init

;; *************** function _adc__init *****************
;; Defined at:
;;		line 103 in file "adc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main__init
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=0
	line	103
global __ptext3
__ptext3:	;psect for function _adc__init
psect	text3
	file	"adc.c"
	line	103
	
_adc__init:	
;incstack = 0
	callstack 6
; Regs used in _adc__init: []
	line	104
	
l27:	
	return
	callstack 0
GLOBAL	__end_of_adc__init
	__end_of_adc__init:
	signat	_adc__init,89
	global	_adc__read

;; *************** function _adc__read *****************
;; Defined at:
;;		line 106 in file "adc.c"
;; Parameters:    Size  Location     Type
;;  channel         2    0[COMMON] unsigned short 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2    0[COMMON] unsigned short 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         2       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          1       0       0       0       0
;;      Totals:         3       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text4,local,class=CODE,delta=2,merge=1,group=0
	line	106
global __ptext4
__ptext4:	;psect for function _adc__read
psect	text4
	file	"adc.c"
	line	106
	
_adc__read:	
;incstack = 0
	callstack 7
; Regs used in _adc__read: [wreg+status,2+status,0]
	line	107
	
l715:	
	movf	(adc__read@channel),w
	movwf	(??_adc__read+0)+0
	rlf	(??_adc__read+0)+0,f
	rlf	(??_adc__read+0)+0,f
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(31),w	;volatile
	xorwf	(??_adc__read+0)+0,w
	andlw	not (((1<<4)-1)<<2)
	xorwf	(??_adc__read+0)+0,w
	movwf	(31)	;volatile
	line	108
	
l717:	
	bsf	(31),1	;volatile
	line	110
	
l30:	
	line	109
	btfsc	(31),1	;volatile
	goto	u81
	goto	u80
u81:
	goto	l30
u80:
	line	111
	
l719:	
	movf	(30),w	;volatile
	movwf	(?_adc__read+1)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movf	(158)^080h,w	;volatile
	movwf	(?_adc__read)
	line	112
	
l33:	
	return
	callstack 0
GLOBAL	__end_of_adc__read
	__end_of_adc__read:
	signat	_adc__read,4218
global	___latbits
___latbits	equ	2
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
