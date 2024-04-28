import uart

name := 'Fernando'
height := 1.72
weight := 89

uart.println('Mr. ${name} your IMC is ${weight / (height*height)}.')