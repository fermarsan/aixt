import uart

a := 5

match false {
  a > 4 { uart.println('if') }
  a == 4 { uart.println('else if') }
  a == 2 { uart.println('else if 2') }
  else { uart.println('else') }
}

match a {
  0 ... 4 { uart.println('range 1') }
  5 ... 9 { uart.println('range 2') }
  20 ... 25 { uart.println('range 3') }
  else { uart.println('none of ranges') }
}