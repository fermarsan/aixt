// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Builtin definitions
//              (PIC16F873A)

#define an0    ra0  // Onboard LED            
#define an1    ra1        
#define an2    ra2              
#define an3    ra3       
#define an4    ra5       


enum __pin_names {
     ra0,  ra1,  ra2,  ra3,  ra4,  ra5,  ra6,  ra7,   //port A  
     rb0,  rb1,  rb2,  rb3,  rb4,  rb5,  rb6,  rb7,   //port B
     rc0,  rc1,  rc2,  rc3,  rc4,  rc5,  rc6,  rc7,   //port C
    _rd0, _rd1, _rd2, _rd3, _rd4, _rd5, _rd6, _rd7,   //port D
    _re0, _re1, _re2, _re3, _re4, _re5, _re6, _re7    //port E

}; 