// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// stmt is the code generation function for statements.
fn (mut gen Gen) stmt(node ast.Stmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	println('${node.type_name().after('v.ast.')}:\t\t${node}')
	match node {
		ast.Module {
			return gen.module_stmt(node)
		}
		ast.Import {
			return gen.import_stmt(node)
		}
		ast.GlobalDecl {
			return gen.global_decl(node)
		}
		ast.ConstDecl {
			return gen.const_decl(node)
		}
		ast.FnDecl {
			return gen.fn_decl(node)
		}
		ast.EnumDecl {
			return gen.enum_decl(node)
		}
		ast.AssignStmt {
			return gen.assign_stmt(node)
		}
		ast.ExprStmt {
			return gen.expr_stmt(node)
		}
		ast.Return {
			return gen.return_stmt(node)
		}
		ast.BranchStmt {
			return gen.branch_stmt(node)
		}
		ast.ForStmt {
			return gen.for_stmt(node)
		}
		ast.ForCStmt {
			return gen.for_c_stmt(node)
		}
		ast.ForInStmt {
			return gen.for_in_stmt(node)
		}
		ast.HashStmt {
			return gen.hash_stmt(node)
		}
		ast.AsmStmt {
			return gen.asm_stmt(node)
		}
		ast.Block {
			return gen.block(node)
		}
		ast.StructDecl {
			return gen.struct_decl(node)
		}
		ast.TypeDecl {
			return gen.type_decl(node)
		}
		ast.SemicolonStmt {
			return []
		}
		else { panic('\n\n***** Transpiler error *****:\nUndefined statement.\n') }
	}
}