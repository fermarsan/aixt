// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: ports_0.h
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Definition of pins for the Explorer 16.
//
// Usage:
// 1. Run the program using `v run aixt.v command device input_file_name`
// Copyright (c) 2022 Fernando Martínez Santa

#ifndef _PORTS_0_H_
#define _PORTS_0_H_

enum pins {
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, //port A  
    B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10, B11, B12, B13, B14, B15, //port B
    C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, //port C
    D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15, //port D
    E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, //port E
    F0, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, //port F
    G0, G1, G2, G3, G4, G5, G6, G7, G8, G9, G10, G11, G12, G13, G14, G15  //port G
} port;

#endif  //_PORTS_H_