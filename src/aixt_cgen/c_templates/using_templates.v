attrs := 'inline'
ret_val := 'int'
params := 'int a, float b'
stmts := [
	'float c = a + b;',
	'return c'
]

println($tmpl('fn_main.c.tmpl') + '\n\n')
println($tmpl('fn_main_nxc.c.tmpl') + '\n\n')