/*
  DigitShield.cpp - DigitShield Library
  Copyright (C) 2011 nootropic design, LLC
  All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/


#include "DigitShield_A2.h"

DigitShieldClass *digitShields[4];
int nDigitShields = 0;

DigitShieldClass::DigitShieldClass() {
  clockPin = CLOCK;
  latchPin = LATCH;
  dataPin = DATA;
  dpPin = DP;
  digitShields[nDigitShields++] = this;
}

DigitShieldClass::DigitShieldClass(byte clock, byte latch, byte data, byte dp) {
  clockPin = clock;
  latchPin = latch;
  dataPin = data;
  dpPin = dp;
  digitShields[nDigitShields++] = this;
}

void DigitShieldClass::begin() {
  // Use pins 2-4 for shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(dpPin, OUTPUT);


  intValue = 0;
  doubleValue = 0;
  intValueSet = false;
  doubleValueSet = false;
  displayValue = 0;
  precision = 0;
  dpBits = 0;
  currentDigit = 0;
  leadingZeros = false;
  blank = false;
  invalid = false;
  digitValues[0] = 0xF;
  digitValues[1] = 0xF;
  digitValues[2] = 0xF;
  digitValues[3] = 0xF;
/*
  // Disable the timer overflow interrupt
  TIMSK2 &= ~(1 << TOIE2);

  // Set timer2 to normal mode
  TCCR2A &= ~((1 << WGM21) | (1 << WGM20));
  TCCR2B &= ~(1 << WGM22);

  // Use internal I/O clock
  ASSR &= ~(1 << AS2);

  // Disable compare match interrupt
  TIMSK2 &= ~(1 << OCIE2A);

  // Prescalar is clock divided by 128
  TCCR2B |= (1 << CS22);
  TCCR2B &= ~(1 << CS21);
  TCCR2B |= (1 << CS20);

  // Start the counting at 0
  TCNT2 = 0;

  // Enable the timer2 overflow interrupt
  TIMSK2 |= (1 << TOIE2);  */


  
  // TIMER1
  // Disable the timer overflow interrupt
  TIMSK1 &= ~(1 << TOIE1);

  // Set timer1 to normal mode
  TCCR1A &= ~((1 << WGM11) | (1 << WGM10));
  TCCR1B &= ~((1 << WGM13) | (1 << WGM12));

  // Disable compare match interrupt
  TIMSK1 &= ~(1 << OCIE1A);
  TIMSK1 &= ~(1 << OCIE1B);

  // Prescalar is clock divided by 128
  TCCR1B &= ~(1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B |= (1 << CS10);

  // Start the counting at 0
  TCNT1 = 0;

  // Enable the timer2 overflow interrupt
  TIMSK1 |= (1 << TOIE1);  
  

}


void DigitShieldClass::setValue(int i) {
  intValue = i;
  intValueSet = true;
  doubleValueSet = false;
  if ((i < 0) || (i > 9999)) {
    invalid = true;
    return;
  }
  int v = i;
  for(int j=0;j<precision;j++) {
    v = v * 10;
  }
  displayValue = v;
  if ((displayValue > 9999) || (displayValue < 0)) {
    invalid = true;
    return;
  } else {
    invalid = false;
  }
}

void DigitShieldClass::setValue(double f) {
  doubleValue = f;
  doubleValueSet = true;
  intValueSet = false;
  if ((f < 0) || (f > 9999)) {
    invalid = true;
    return;
  }
  double v = f;
  for(int j=0;j<precision;j++) {
    v = v * 10;
  }
  displayValue = (int)(v + 0.5);
  if ((displayValue > 9999) || (displayValue < 0)) {
    invalid = true;
    return;
  } else {
    invalid = false;
  }
}

void DigitShieldClass::setPrecision(int p) {
  if ((p >= 0) && (p <= 3)) {
    precision = p;
    dpBits = 0;
    if (p > 0) {
      dpBits = (1 << p);
    }

    // since we changed precision, call setValue again
    // to recalculate the displayValue
    if (intValueSet) {
      setValue(intValue);
    } else {
      if (doubleValueSet) {
	setValue(doubleValue);
      }
    }
  }
}

void DigitShieldClass::setBlank(boolean b) {
  blank = b;
}

void DigitShieldClass::setLeadingZeros(boolean l) {
  leadingZeros = l;
}

void DigitShieldClass::setDigit(int d, int n) {
  intValueSet = false;
  doubleValueSet = false;
  if ((d >= 1) && (d <= 4)) {
    digitValues[4-d] = n;
  }
}

void DigitShieldClass::setDecimalPoint(int d, boolean on) {
  intValueSet = false;
  doubleValueSet = false;
  if ((d >= 1) && (d <= 4)) {
    if (on) {
      dpBits |= (1 << (4-d));
    } else {
      dpBits &= ~(1 << (4-d));
    }
  }
}


void DigitShieldClass::displayVal() {
  byte nDigits = 4;
  byte data;
  byte digitValue;

  if ((!leadingZeros) && (!invalid)) {
    if ((displayValue == 0) || (doubleValueSet && (doubleValue < 1.0))) {
      nDigits = precision + 1;
    } else {
      if (displayValue < 1000) {
	nDigits = 3;
      }
      if (displayValue < 100) {
	nDigits = 2;
      }
      if (displayValue < 10) {
	nDigits = 1;
      }
    }
  }
  if (++currentDigit > (nDigits-1)) {
    currentDigit = 0;
  }

  switch (currentDigit) {
  case 0:
    digitValue = displayValue % 10;
    break;
  case 1:
    digitValue = (displayValue / 10) % 10;
    break;
  case 2:
    digitValue = (displayValue / 100) % 10;
    break;
  case 3:
    digitValue = (displayValue / 1000) % 10;
    break;
  }

  if (invalid) {
    digitValue = 15;
  }

  // Upper 4 bits of data are the value for the current digit.
  // They are loaded into shift register outputs QA-QD
  data = (digitValue << 4);

  // Lower 4 bits 3-0 represent which digit to turn on.  3 is most significan digit, 0 is least
  // They are loaded into shift register outputs QE-QH
  // digit transistors are active low, so set them all high
  data |= 0x0F;
  // now turn off the bit for digit we want illuminated.
  if (!blank) {
    data &= ~(1 << currentDigit);
  }

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  // Turn off decimal point.  Inactive HIGH
  digitalWrite(dpPin, HIGH);
  digitalWrite(latchPin, HIGH);
  if (((((dpBits >> currentDigit) & 1) == 1) && (!blank)) || (invalid)) {
    // Turn on decimal point.  Active LOW
    digitalWrite(dpPin, LOW);
  }
}

void DigitShieldClass::displayDirect() {
  byte data;
  byte digitValue;

  if (++currentDigit > 3) {
    currentDigit = 0;
  }

  // Upper 4 bits of data are the value for the current digit.
  // They are loaded into shift register outputs QA-QD
  data = (digitValues[currentDigit] << 4);

  // Lower 4 bits 3-0 represent which digit to turn on.  3 is most significan digit, 0 is least
  // They are loaded into shift register outputs QE-QH
  // digit transistors are active low, so set them all high
  data |= 0x0F;
  // now turn off the bit for digit we want illuminated.
  if (!blank) {
    data &= ~(1 << currentDigit);
  }

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  // Turn off decimal point.  Inactive HIGH
  digitalWrite(dpPin, HIGH);
  digitalWrite(latchPin, HIGH);
  if (((((dpBits >> currentDigit) & 1) == 1) && (!blank))) {
    // Turn on decimal point.  Active LOW
    digitalWrite(dpPin, LOW);
  }
}

void DigitShieldClass::isr() {
  if (intValueSet || doubleValueSet) {
    displayVal();
  } else {
    displayDirect();
  }
}

/*
// Interrupt service routine is invoked when timer2 overflows.
ISR(TIMER2_OVF_vect) {
  TCNT2 = 0;
  for(int i=0;i<nDigitShields;i++) {
    digitShields[i]->isr();
  }
}
*/

// Interrupt service routine is invoked when timer1 overflows.
ISR(TIMER1_OVF_vect) {
  TCNT1 = 0;
  for(int i=0;i<nDigitShields;i++) {
    digitShields[i]->isr();
  }
}


DigitShieldClass DigitShield = DigitShieldClass();
