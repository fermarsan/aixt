// Aixt project (C generated code)
// Device = x64
// Board = PC

#include <stdbool.h>


signed char average_8b(signed char x, signed char y) {
return (x + y) / 2;
}
int main() {
signed char a = 4;
signed char b = 7;
signed char c = 0;
c = average_8b(a, a + b);
return 0;
}