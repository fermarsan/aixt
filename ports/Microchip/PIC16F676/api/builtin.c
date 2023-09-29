// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Builtin definitions
//              (Explorer16-PIC16F676)

#define an0    ra0  // Onboard LED            
#define an1    ra1        
#define an2    ra2              
#define an3    ra4       
#define an4    rc0        
#define an5    rc1        
#define an6    rc2   
#define an7    rc3  

enum __pin_names {
     ra0,  ra1,  ra2,  ra3,  ra4,  ra5, _ra6, _ra7,   //port A  
    _rb0, _rb1, _rb2, _rb3, _rb4, _rb5, _rb6, _rb7,   //port B
     rc0,  rc1,  rc2,  rc3,  rc4,  rc5, _rc6, _rc7,   //port C
    _rd0, _rd1, _rd2, _rd3, _rd4, _rd5, _rd6, _rd7,   //port D
    _re0, _re1, _re2, _re3, _re4, _re5, _re6, _re7    //port E

}; 