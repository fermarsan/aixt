// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: seconds delay function
//              (PIC18F452)

module time

#define time__sleep(TIME)               delay_s(TIME*1000)