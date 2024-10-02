import uart


match false {
  2 > 4, 4 > 5 { uart.println('if') }
  3 == 4 { uart.println('else if') }
  2 == 2 { uart.println('else if2') }
  else { uart.println('else') }
}
