mut a := 10
mut b, c := 20.0, 30

// b = c + a

a = if b > c { b } else { c }

if b > c { a = b } else { a = c }