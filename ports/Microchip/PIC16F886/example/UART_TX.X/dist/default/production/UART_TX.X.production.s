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
	FNCALL	_main,_main__init
	FNCALL	_main,_uart__setup
	FNCALL	_main,_uart__write
	FNCALL	_main__init,_pin__init
	FNCALL	_main__init,_time__init
	FNCALL	_main__init,_uart__init
	FNROOT	_main
	global	_TXREG
_TXREG	set	0x19
	global	_RCSTAbits
_RCSTAbits	set	0x18
	global	_RCREG
_RCREG	set	0x1A
	global	_TRISCbits
_TRISCbits	set	0x87
	global	_TXSTAbits
_TXSTAbits	set	0x98
	global	_SPBRG
_SPBRG	set	0x99
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
	file	"dist/default/production\UART_TX.X.production.s"
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
?_uart__init:	; 1 bytes @ 0x0
??_uart__init:	; 1 bytes @ 0x0
?_time__init:	; 1 bytes @ 0x0
??_time__init:	; 1 bytes @ 0x0
?_main__init:	; 1 bytes @ 0x0
??_main__init:	; 1 bytes @ 0x0
?_uart__setup:	; 1 bytes @ 0x0
??_uart__setup:	; 1 bytes @ 0x0
?_uart__write:	; 1 bytes @ 0x0
??_uart__write:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
	global	uart__write@data
uart__write@data:	; 1 bytes @ 0x0
	ds	1
??_main:	; 1 bytes @ 0x1
	ds	3
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
;!    COMMON           14      4       4
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
;!    _main->_uart__write
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
;;Main: autosize = 0, tempsize = 3, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 3     3      0      15
;!                                              1 COMMON     3     3      0
;!                         _main__init
;!                        _uart__setup
;!                        _uart__write
;! ---------------------------------------------------------------------------------
;! (1) _uart__write                                          1     1      0      15
;!                                              0 COMMON     1     1      0
;! ---------------------------------------------------------------------------------
;! (1) _uart__setup                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _main__init                                           0     0      0       0
;!                          _pin__init
;!                         _time__init
;!                         _uart__init
;! ---------------------------------------------------------------------------------
;! (2) _uart__init                                           0     0      0       0
;! ---------------------------------------------------------------------------------
;! (2) _time__init                                           0     0      0       0
;! ---------------------------------------------------------------------------------
;! (2) _pin__init                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _main__init
;!     _pin__init
;!     _time__init
;!     _uart__init
;!   _uart__setup
;!   _uart__write
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!EEDATA             100      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      4       4       1       28.6%
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
;;		line 136 in file "uart_tx.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
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
;;      Locals:         0       0       0       0       0
;;      Temps:          3       0       0       0       0
;;      Totals:         3       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels required when called: 2
;; This function calls:
;;		_main__init
;;		_uart__setup
;;		_uart__write
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"uart_tx.c"
	line	136
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"uart_tx.c"
	line	136
	
_main:	
;incstack = 0
	callstack 6
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	137
	
l665:	
	fcall	_main__init
	line	138
	
l667:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(135)^080h,6	;volatile
	line	139
	
l669:	
	fcall	_uart__setup
	line	141
	
l671:	
	movlw	low(033h)
	fcall	_uart__write
	line	142
	
l673:	
	asmopt push
asmopt off
movlw  6
movwf	((??_main+0)+0+2)
movlw	19
movwf	((??_main+0)+0+1)
	movlw	173
movwf	((??_main+0)+0)
	u17:
decfsz	((??_main+0)+0),f
	goto	u17
	decfsz	((??_main+0)+0+1),f
	goto	u17
	decfsz	((??_main+0)+0+2),f
	goto	u17
	nop2
asmopt pop

	line	143
	movlw	low(099h)
	fcall	_uart__write
	line	144
	
l675:	
	asmopt push
asmopt off
movlw  6
movwf	((??_main+0)+0+2)
movlw	19
movwf	((??_main+0)+0+1)
	movlw	173
movwf	((??_main+0)+0)
	u27:
decfsz	((??_main+0)+0),f
	goto	u27
	decfsz	((??_main+0)+0+1),f
	goto	u27
	decfsz	((??_main+0)+0+2),f
	goto	u27
	nop2
asmopt pop

	goto	l671
	global	start
	ljmp	start
	callstack 0
	line	146
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_uart__write

;; *************** function _uart__write *****************
;; Defined at:
;;		line 129 in file "uart_tx.c"
;; Parameters:    Size  Location     Type
;;  data            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  data            1    0[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         1       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         1       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	129
global __ptext1
__ptext1:	;psect for function _uart__write
psect	text1
	file	"uart_tx.c"
	line	129
	
_uart__write:	
;incstack = 0
	callstack 7
; Regs used in _uart__write: [wreg]
	movwf	(uart__write@data)
	line	130
	
l659:	
	movf	(uart__write@data),w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(25)	;volatile
	line	131
	
l38:	
	return
	callstack 0
GLOBAL	__end_of_uart__write
	__end_of_uart__write:
	signat	_uart__write,4217
	global	_uart__setup

;; *************** function _uart__setup *****************
;; Defined at:
;;		line 118 in file "uart_tx.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg
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
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	118
global __ptext2
__ptext2:	;psect for function _uart__setup
psect	text2
	file	"uart_tx.c"
	line	118
	
_uart__setup:	
;incstack = 0
	callstack 7
; Regs used in _uart__setup: [wreg]
	line	119
	
l643:	
	movlw	low(0Ch)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(153)^080h	;volatile
	line	120
	
l645:	
	bcf	(152)^080h,2	;volatile
	line	121
	
l647:	
	bcf	(152)^080h,4	;volatile
	line	122
	
l649:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(24),7	;volatile
	line	123
	
l651:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(152)^080h,6	;volatile
	line	124
	
l653:	
	bsf	(152)^080h,5	;volatile
	line	125
	
l655:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(24),6	;volatile
	line	126
	
l657:	
	bsf	(24),4	;volatile
	line	127
	
l35:	
	return
	callstack 0
GLOBAL	__end_of_uart__setup
	__end_of_uart__setup:
	signat	_uart__setup,89
	global	_main__init

;; *************** function _main__init *****************
;; Defined at:
;;		line 101 in file "uart_tx.c"
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
;;		_pin__init
;;		_time__init
;;		_uart__init
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=0
	line	101
global __ptext3
__ptext3:	;psect for function _main__init
psect	text3
	file	"uart_tx.c"
	line	101
	
_main__init:	
;incstack = 0
	callstack 6
; Regs used in _main__init: [status,2+status,0+pclath+cstack]
	line	102
	
l641:	
	fcall	_pin__init
	line	103
	fcall	_uart__init
	line	104
	fcall	_time__init
	line	106
	
l23:	
	return
	callstack 0
GLOBAL	__end_of_main__init
	__end_of_main__init:
	signat	_main__init,89
	global	_uart__init

;; *************** function _uart__init *****************
;; Defined at:
;;		line 111 in file "uart_tx.c"
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
psect	text4,local,class=CODE,delta=2,merge=1,group=0
	line	111
global __ptext4
__ptext4:	;psect for function _uart__init
psect	text4
	file	"uart_tx.c"
	line	111
	
_uart__init:	
;incstack = 0
	callstack 6
; Regs used in _uart__init: []
	line	112
	
l29:	
	return
	callstack 0
GLOBAL	__end_of_uart__init
	__end_of_uart__init:
	signat	_uart__init,89
	global	_time__init

;; *************** function _time__init *****************
;; Defined at:
;;		line 133 in file "uart_tx.c"
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
psect	text5,local,class=CODE,delta=2,merge=1,group=0
	line	133
global __ptext5
__ptext5:	;psect for function _time__init
psect	text5
	file	"uart_tx.c"
	line	133
	
_time__init:	
;incstack = 0
	callstack 6
; Regs used in _time__init: []
	line	134
	
l41:	
	return
	callstack 0
GLOBAL	__end_of_time__init
	__end_of_time__init:
	signat	_time__init,89
	global	_pin__init

;; *************** function _pin__init *****************
;; Defined at:
;;		line 108 in file "uart_tx.c"
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
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	line	108
global __ptext6
__ptext6:	;psect for function _pin__init
psect	text6
	file	"uart_tx.c"
	line	108
	
_pin__init:	
;incstack = 0
	callstack 6
; Regs used in _pin__init: []
	line	109
	
l26:	
	return
	callstack 0
GLOBAL	__end_of_pin__init
	__end_of_pin__init:
	signat	_pin__init,89
global	___latbits
___latbits	equ	2
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
