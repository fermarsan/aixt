// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
import v.ast
import v.ast.walker
import v.checker
import v.pref
import v.parser
import strings

mut attr		:= ''
mut ret_type	:= ''
mut params		:= ''
mut stmt_list	:= []string

if os.args.len > 1 {
    name = os.args[1]
    program := read_file(name) or { eprintln('file does not exist. ') } // opens the input file 
    if os.args.len > 2 {
        if os.args[2] == '-nxc' {	// if -nxt flag
            with open(r'../api/equivalents.yaml','r') as eq_file:
                equivalents = yaml.load(eq_file, Loader=yaml.FullLoader)
                for k in equivalents.keys():
                    // println(type(k))
                    // println(equivalents[k])
                    program = re.sub(k,equivalents[k],program)  // replace the NXC equivalents
		} else {
            println('Invalid flag.\n')
		}
	}
    // ---------- Parsing ----------
    tree = parser.parse( program )  
    // println(tree)
    // println('_'*60 + '\n') 

    // println(tree.pretty())
    println('_'*60 + '\n')    
    print_out = transpiler.transform(tree)

    println(print_out)
    println('_'*60 + '\n')    

    // saves the output file
    output_ext = '.nxc' if len(os.args) > 2 and os.args[2] == '-nxc' else '.c'
    output_name = name.replace('.v', output_ext)
    output_name = output_name.replace('.aixt', output_ext)
    output_name = output_name.replace('.aix', output_ext)       
    transpiler.saveOutput(output_name)
} else {
    println('no input file.\n')
}






path := 'simple_assign.v'
table := ast.new_table()
mut vpref := &pref.Preferences{}
vpref.is_script = true
prog := parser.parse_file(path, table, .skip_comments, vpref)
println(prog)
println(strings.repeat_string('#',80))
mut checker_ := checker.new_checker(table, vpref)
checker_.check(prog)
println(prog)
walker.inspect(prog, unsafe { nil }, fn (node &ast.Node, data voidptr) bool {
	match node {
		ast.Stmt {
			match node {
				ast.FnDecl {
					if node.is_main {
						attr = ''
						ret_type = if node.return_type == ast.void_type_idx { 'void' } else { 'int' }
						params = if node.params == [] { 'void' } else { 'int' }
					}
				}
				ast.AssignStmt {
					for i in 0..node.left.len {
						stmt_list << '${node.left[i]} ${node.op} ${node.right[i]}\n'
					}
					return false
				}
				else{} 
			}
		}
		else {}
	}	
	println(node)		
	return true
})

mut output := '${attr} ${ret_type} main(${params}) {\n${stmt_list.join('\n')}\n}'
output = if output[0] == ` ` { output[1..] } else { output } 
println(output)
