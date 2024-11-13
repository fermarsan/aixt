import uart
import uart2

name := 'Fernando'
height := 1.72
weight := 89

imc := f32(weight / (height*height))

uart.println('Mr. ${name} your IMC is ${imc}.')
uart2.println('IMC = ${weight} / (${height}^2)')
// uart.println('Mr. ${name} your IMC is ${weight / (height*height)}.')