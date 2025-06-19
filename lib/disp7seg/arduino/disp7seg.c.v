// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: lcd module (Arduino Nano - ATmega328P port)

module disp7seg

#include "disp7seg.c"
#include "DigitShield_A2.h"

fn C.DIGITSHIELD_BEGIN() 
fn C.DIGITSHIELD_SETVALUE(p1 int) 
fn C.DIGITSHIELD_SETPRECISION(p1 int) 
fn C.DIGITSHIELD_SETVALUEFLOAT(p1 f64) 
fn C.DIGITSHIELD_SETLEADINGZEROS(p1 bool) 
fn C.DIGITSHIELD_SETBLANK(p1 bool) 
fn C.DIGITSHIELD_SETDIGIT(p1 int, p2 int) 
fn C.DIGITSHIELD_SETDECIMALPOINT(p1 int, p2 bool) 





