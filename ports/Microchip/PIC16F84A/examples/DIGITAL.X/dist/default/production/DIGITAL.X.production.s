subtitle "Microchip MPLAB XC8 C Compiler v2.41 (Free license) build 20230208172133 Og1 "

pagewidth 120

	opt flic

	processor	16F84A
include "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\16f84a.cgen.inc"
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
# 54 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
INDF equ 00h ;# 
# 61 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
TMR0 equ 01h ;# 
# 68 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PCL equ 02h ;# 
# 75 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
STATUS equ 03h ;# 
# 161 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
FSR equ 04h ;# 
# 168 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PORTA equ 05h ;# 
# 212 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PORTB equ 06h ;# 
# 274 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EEDATA equ 08h ;# 
# 281 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EEADR equ 09h ;# 
# 288 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PCLATH equ 0Ah ;# 
# 308 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
INTCON equ 0Bh ;# 
# 386 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
OPTION_REG equ 081h ;# 
# 456 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
TRISA equ 085h ;# 
# 500 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
TRISB equ 086h ;# 
# 562 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EECON1 equ 088h ;# 
# 606 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EECON2 equ 089h ;# 
# 54 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
INDF equ 00h ;# 
# 61 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
TMR0 equ 01h ;# 
# 68 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PCL equ 02h ;# 
# 75 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
STATUS equ 03h ;# 
# 161 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
FSR equ 04h ;# 
# 168 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PORTA equ 05h ;# 
# 212 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PORTB equ 06h ;# 
# 274 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EEDATA equ 08h ;# 
# 281 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EEADR equ 09h ;# 
# 288 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
PCLATH equ 0Ah ;# 
# 308 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
INTCON equ 0Bh ;# 
# 386 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
OPTION_REG equ 081h ;# 
# 456 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
TRISA equ 085h ;# 
# 500 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
TRISB equ 086h ;# 
# 562 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EECON1 equ 088h ;# 
# 606 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\pic\include\proc\pic16f84a.h"
EECON2 equ 089h ;# 
	debug_source C
	FNCALL	_main,_main__init
	FNCALL	_main__init,_pin__init
	FNROOT	_main
	global	_PORTBbits
_PORTBbits	set	0x6
	global	_TRISBbits
_TRISBbits	set	0x86
; #config settings
	config pad_punits      = on
	config apply_mask      = off
	config ignore_cmsgs    = off
	config default_configs = off
	config default_idlocs  = off
	config FOSC = "HS"
	config WDTE = "OFF"
	config PWRTE = "OFF"
	config CP = "OFF"
	file	"dist/default/production\DIGITAL.X.production.s"
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
??_pin__init:	; 1 bytes @ 0x0
??_main__init:	; 1 bytes @ 0x0
??_main:	; 1 bytes @ 0x0
psect	cstackBANK0,class=BANK0,space=1,noexec
global __pcstackBANK0
__pcstackBANK0:
?_pin__init:	; 1 bytes @ 0x0
?_main__init:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
	global	main@x
main@x:	; 1 bytes @ 0x0
	ds	1
	global	main@x1
main@x1:	; 1 bytes @ 0x1
	ds	1
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
;!    COMMON            0      0       0
;!    BANK0            66      2       2

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
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
;! (0) _main                                                 2     2      0      48
;!                                              0 BANK0      2     2      0
;!                         _main__init
;! ---------------------------------------------------------------------------------
;! (1) _main__init                                           0     0      0       0
;!                          _pin__init
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
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            0      0       0       0        0.0%
;!EEDATA              40      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!BITSFR0              0      0       0       1        0.0%
;!SFR0                 0      0       0       1        0.0%
;!COMMON               0      0       0       1        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!SFR1                 0      0       0       2        0.0%
;!STACK                0      0       0       2        0.0%
;!BANK0               42      2       2       3        3.0%
;!ABS                  0      0       0       4        0.0%
;!BITBANK0            42      0       0       5        0.0%
;!DATA                 0      0       0       6        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 63 in file "Digital.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  x1              1    1[BANK0 ] unsigned char 
;;  x               1    0[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       2
;;      Temps:          0       0
;;      Totals:         0       2
;;Total ram usage:        2 bytes
;; Hardware stack levels required when called: 2
;; This function calls:
;;		_main__init
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"Digital.c"
	line	63
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"Digital.c"
	line	63
	
_main:	
;incstack = 0
	callstack 6
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	64
	
l649:	
	fcall	_main__init
	line	65
	
l651:	
	bsf	status, 5	;RP0=1, select bank1
	bsf	(134)^080h,2	;volatile
	line	66
	
l653:	
	bsf	(134)^080h,4	;volatile
	line	67
	
l655:	
	bcf	(134)^080h,0	;volatile
	line	68
	
l657:	
	bcf	(134)^080h,1	;volatile
	line	69
	
l659:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	(6),0	;volatile
	line	70
	
l661:	
	bcf	(6),1	;volatile
	line	71
	
l663:	
	line	72
	
l665:	
	line	74
	
l667:	
	movlw	0
	btfsc	(6),2	;volatile
	movlw	1
	movwf	(main@x)
	line	75
	
l669:	
	movlw	0
	btfsc	(6),4	;volatile
	movlw	1
	movwf	(main@x1)
	line	76
	
l671:	
		decf	((main@x)),w
	btfss	status,2
	goto	u31
	goto	u30
u31:
	goto	l675
u30:
	line	77
	
l673:	
	bsf	(6),0	;volatile
	line	78
	bsf	(6),1	;volatile
	line	79
	goto	l667
	line	80
	
l675:	
		decf	((main@x1)),w
	btfss	status,2
	goto	u41
	goto	u40
u41:
	goto	l667
u40:
	line	81
	
l677:	
	bcf	(6),0	;volatile
	line	82
	bcf	(6),1	;volatile
	goto	l667
	global	start
	ljmp	start
	callstack 0
	line	85
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_main__init

;; *************** function _main__init *****************
;; Defined at:
;;		line 55 in file "Digital.c"
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
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 1
;; This function calls:
;;		_pin__init
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	55
global __ptext1
__ptext1:	;psect for function _main__init
psect	text1
	file	"Digital.c"
	line	55
	
_main__init:	
;incstack = 0
	callstack 6
; Regs used in _main__init: [status,2+status,0+pclath+cstack]
	line	56
	
l647:	
	fcall	_pin__init
	line	58
	
l9:	
	return
	callstack 0
GLOBAL	__end_of_main__init
	__end_of_main__init:
	signat	_main__init,89
	global	_pin__init

;; *************** function _pin__init *****************
;; Defined at:
;;		line 60 in file "Digital.c"
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
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main__init
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	60
global __ptext2
__ptext2:	;psect for function _pin__init
psect	text2
	file	"Digital.c"
	line	60
	
_pin__init:	
;incstack = 0
	callstack 6
; Regs used in _pin__init: []
	line	61
	
l12:	
	return
	callstack 0
GLOBAL	__end_of_pin__init
	__end_of_pin__init:
	signat	_pin__init,89
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 04Eh

	DABS	1,78,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
