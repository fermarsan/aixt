/*
  DigitShield - DigitShield Library
  Copyright (C) 2011 nootropic design, LLC
  All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef DigitShield_A2_h
#define DigitShield_A2_h

#include <inttypes.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

class DigitShieldClass {
public:
  DigitShieldClass();
  DigitShieldClass(byte clock, byte latch, byte data, byte dp);
  void begin();
  void setValue(int i);
  void setValue(double v);
  void setPrecision(int p);
  void setLeadingZeros(boolean l);
  void setBlank(boolean b);
  void setDigit(int d, int n);
  void setDecimalPoint(int d, boolean on);
  void isr();

private:
  byte clockPin, latchPin, dataPin, dpPin;
  void displayVal();
  void displayDirect();
  boolean leadingZeros;
  int intValue;
  double doubleValue;
  boolean intValueSet;
  boolean doubleValueSet;
  int displayValue;
  int precision;
  uint8_t dpBits;
  volatile uint8_t currentDigit;
  boolean blank;
  boolean invalid;
  int digitValues[4];
};

#define CLOCK 2
#define LATCH 3
#define DATA 4
#define DP 5

extern DigitShieldClass DigitShield;

#endif /* DigitShield_A2_h */
