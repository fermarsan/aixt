// This C code was automatically generated by Aixt Project
// Device = Emulator
// Board = Linux, Windows and Android
// Backend = c

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  main__init();
void  main__clear_screen();
char uart__buffer[] = "";

void  uart__init();
void  uart__println(char msg[]);
void  uart__print(char msg[]);
char*  uart__input(char msg[]);
char __temp_str[80];

void  main__init() {
	
	printf("\033[1;37m"); 
	
}

void  main__clear_screen() {
	
	// linux
	system("clear");; 
	
}

void  uart__init() {
	
	printf("\033[1;32m"); 
	printf(" Aixt virtual UART\n"); 
	
}

inline void  uart__println(char msg[]) {
	
	printf("\033[1;32m"); 
	printf("%s\n", msg); 
	
}

inline void  uart__print(char msg[]) {
	
	printf("\033[1;32m"); 
	printf("%s", msg); 
	
}

char*  uart__input(char msg[]) {
	
	printf("\033[1;32m"); 
	printf("%s ", msg); 
	scanf("%s", uart__buffer); 
	return uart__buffer; 
	
}

int main() {
	main__init();
	uart__init();
	
	char msg1[80];
	strcpy(msg1, "red"); 
	char msg2[80];
	strcpy(msg2, "green"); 
	char msg3[80];
	strcpy(msg3, "blue"); 
	strcpy(msg1, msg3); 
	uart__println(msg1); 
	strcat(msg2, " "); 
	strcat(msg2, msg3); 
	uart__println(msg2); 
	strcpy(msg2, strcat(strcpy(__temp_str, msg1), msg3)); 
	uart__println(msg2); 
	if(!strcmp(msg1, msg2)) {
		uart__println("true");
	}
	else 
	{
		uart__println("false");
	}; 
	strcat(msg2, strcat(strcpy(__temp_str, " "), msg3)); 
	uart__println(msg2); 
	if(!strcmp(msg3, "blue")) {
		uart__println("true");
	}
	else 
	{
		uart__println("false");
	}; 
	return 0;
}