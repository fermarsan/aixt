// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port

//Existe el puerto A y el puerto B
#define a A  
#define b B  

const output = C.GPIO_ModeOut_PP_5mA      
//Tambien esta el modo GPIO_ModeOut_PP_20mA
   
const input = C.GPIO_ModeIN_Floating
const in_pullup = C.GPIO_ModeIN_PU
const in_pulldown = C.GPIO_ModeIN_PD
//Tambien esta el modo GPIO_ModeIN_PU y GPIO_ModeIN_Floating

/*
Pines del puerto A y puerto B en BITS 
GPIO_Pin_4      (0x00000010)
GPIO_Pin_5      (0x00000020) 
GPIO_Pin_7      (0x00000080) 
GPIO_Pin_8      (0x00000100) 
GPIO_Pin_9      (0x00000200) 
GPIO_Pin_10     (0x00000400) 
GPIO_Pin_11     (0x00000800) 
GPIO_Pin_12     (0x00001000) 
GPIO_Pin_13     (0x00002000) 
GPIO_Pin_14     (0x00004000) 
GPIO_Pin_15     (0x00008000) 
GPIO_Pin_22     (0x00400000) 
GPIO_Pin_23     (0x00800000) 
GPIO_Pin_All    (0xFFFFFFFF) */