// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git
// File Name: write.c.v
// Author: Fernando Martinez Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module pwm

#define pwm__write(PIN, VALUE)   analogWrite(PIN, VALUE)