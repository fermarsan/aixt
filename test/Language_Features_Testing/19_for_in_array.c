// This C code was automatically generated by Aixt Project
// Device = Emulator
// Board = Linux, Windows and Android
// Backend = c

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void  main__init();
void  main__clear_screen();

void  main__init() {
	
	printf("\033[1;37m"); 
	
}

void  main__clear_screen() {
	
	// linux
	system("clear");; 
	
}

int main() {
	main__init();
	
	long arr[4] = {2, 4, 9, 7}; 
	for(int __i_1 = 0; __i_1 < 4; __i_1++) {long a = arr[__i_1];long b = a;a++;arr[__i_1] = a;} 
	return 0;
}