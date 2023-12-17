a, b, c := 10, 20, 30

b = c + a

a = if b > c { b } else { c }

if b > c { a = b } else { a = c }