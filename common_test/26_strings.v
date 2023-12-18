var := ''
var2 := ''
str := 'constant'
b1 := false

var = str
println(var)

var += ' '
var += str
println(var)

var2 = var + str
println(var2)

b1 = var == var2
if b1 {
	println('true')
} else {
	println('false')
}

var2 += ' ' + str
println(var2)

if str == 'constant' {
	println('true')
}
