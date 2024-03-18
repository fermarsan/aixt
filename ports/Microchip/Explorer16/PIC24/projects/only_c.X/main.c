/*
 * File:   main.c
 * Author: fercho
 *
 * Created on March 15, 2024, 1:06 PM${aixt_path}/.template/${device}.v
 */


#include "xc.h"

int A;

int B[] = {1,2,3,4,5};

int main(void) {
    A = 0xFACA;
    A = 0x9876;
    
    for(int i=0; i<5; i++) {
        B[i] = B[i] + 10;
    }
    return 0;
}
