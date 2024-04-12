// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Builtin definitions (Explorer16-PIC24 port)
module main

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define FCY 8000000UL

#pragma config POSCMOD = NONE
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSDCMD
#pragma config FNOSC = FRCPLL
#pragma config IESO = OFF
#pragma config WDTPS = PS32768
#pragma config FWPSA = PR128
#pragma config WINDIS = ON
#pragma config FWDTEN = OFF
#pragma config ICS = PGx2
#pragma config GWRP = OFF
#pragma config GCP = OFF
#pragma config JTAGEN = OFF

#define led3    A, 0	// Onboard LEDs
#define led4    A, 1
#define led5    A, 2
#define led6    A, 3
#define led7    A, 4
#define led8    A, 5
#define led9    A, 6
#define led10   A, 7

#define sw3     D, 6	// Onboard switchs
#define sw4     D, 13
#define sw5     A, 7
#define sw6     D, 7

#define pot     B, 5	// Onboard potentiometer'

fn C.init()