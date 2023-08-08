// This C code was automatically generated using the Aixt Project
// Device = x64
// Board = PC
// Backend = pc

#include <stdbool.h>


int main() {
	long a = 5;
	short counter = 1;
	short delta = 1;
	counter = 10;
	counter = counter + delta / 2;
	counter = delta * 4 - 35.6;
	delta = counter % 3;
	delta = counter * (delta + 2);
	signed char state = 0;
	signed char condition = 0xAA;
	state = state & condition;
	state = !state | condition;
	state = state ^ !condition;
	state = state << 6;
	state = (condition & state) >> 2;
	bool logic1 = true;
	bool logic2 = false;
	logic1 = (logic1 && logic2);
	logic2 = (logic1 || logic2);
	return 0;
}