#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <p24FJ128GA010.h>
#include <libpic30.h>

#define FCY 4000000UL

#pragma config POSCMOD = XT
#pragma config OSCIOFNC = ON
#pragma config FCKSM = CSDCMD
#pragma config FNOSC = PRI
#pragma config IESO = ON
#pragma config WDTPS = PS32768
#pragma config FWPSA = PR128
#pragma config WINDIS = ON
#pragma config FWDTEN = OFF
#pragma config ICS = PGx2
#pragma config GWRP = OFF
#pragma config GCP = OFF
#pragma config JTAGEN = OFF

#endif  //_SETTINGS_H_