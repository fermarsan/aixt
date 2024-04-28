import uart

var := ''
var2 := ''
str := 'constant'
b1 := false

var = str
uart.println(var)

var += ' '
var += str
uart.println(var)

var2 = var + str
uart.println(var2)

b1 = var == var2
if b1 {
	uart.println('true')
} else {
	uart.println('false')
}

var2 += ' ' + str
uart.println(var2)

if str == 'constant' {
	uart.println('true')
}
