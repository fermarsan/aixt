// "for" loop through a integer range
import uart

a := 0

for i in 10..20 {	// from 10 to 19
	a += i
	uart.println('a : ${a}')
}