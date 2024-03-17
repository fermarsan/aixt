/*
 * File:   prueba.c
 * Author: fercho
 *
 * Created on March 15, 2024, 4:36 PM
 */


#include "xc.h"

int A;  // declaración de variable entera

int main(void) {
    
    A = 0x1F4A;
    A = 0xCAB0;
    
    if(A == 45) {
        A++;
    } else {
        A--;
    }
    
    return 0;
}