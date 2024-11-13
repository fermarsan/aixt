// "for" through array elements
import uart

arr := [2, 4, 9, 7]

for a in arr {
	a++
	uart.println('value : ${a}')
}
