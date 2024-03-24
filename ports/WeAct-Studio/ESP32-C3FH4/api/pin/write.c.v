// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c.v
// Author: Farith Ochoa León, Felipe Cardozo Hernandez and Fernando Martínez Santa
// Date: 2024
// License: MIT

module pin 

#define pin__write(PIN_NAME, VALUE)     digitalWrite(PIN_NAME, VALUE)