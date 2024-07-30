attrs := ['inline ', 'static']
ret_type := 'int'
name := 'main'
params := 'int a, float b'
stmts := [
	'float c = a + b;',
	'return c'
]
ret_stmt := 'return 0;'

println($tmpl('fn_decl.c') + '\n\n')