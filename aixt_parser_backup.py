from aixt_lexer_backup import aixt_lexer
from sly import Parser
import yaml
#import re

#import sys, os

class aixt_parser(Parser):

    debugfile = 'parser.out'

    precedence = (
        ( 'left' , LOGIC_OR ),
        ( 'left' , LOGIC_AND ), 
        ( 'left' , EQ, NE, LT, LE, GT, GE ),   
        ( 'left' , PLUS, MINUS, OR, XOR ),
        ( 'left' , STAR, DIV, MOD, SHL, SHR, AND ),
        ( 'left' , PLUS_PLUS, MINUS_MINUS ),
        ( 'right', UOP ),
        ( 'right', ASSIGN, PLUS_ASGN, MINUS_ASGN, XOR_ASGN, STAR_ASGN, AND_ASGN, 
                   OR_ASGN, DIV_ASGN, MOD_ASGN, SHL_ASGN, SHR_ASGN ),
        ( 'right', RETURN ),
    )

    tokens = aixt_lexer.tokens

    def __init__(self): 
        self.error_s = ''       #error stream
        self.output_s = ''      #output stream
        self.exType = ''
        self.lineno = 1
        self.identifiers = []   #stacks
        self.values = []
        self.types = []
        self.main = False
        self.includes = ''
        self.module_def = ''
        self.preprocessor = ''
        self.top_level = ''

        #load de setup file
        with open(r'./setup.yaml','r') as setup_file:
            self.setup = yaml.load(setup_file, Loader=yaml.FullLoader)
            # for s in self.setup:
            #     print(s)

    
    #guarda los archivos de salida
    def saveOutput(self, name):

        with open('./settings.h','w') as outSettings:   #settings file creation
            out_text = '#ifndef _SETTINGS_H_\n#define _SETTINGS_H_\n\n'

            for h in self.setup['headers']:             #append the header files
                out_text += '#include ' + h + '\n'
            out_text += '\n'

            for m in self.setup['macros']:              #append the macros
                out_text += '#define ' + m + '\n'
            out_text += '\n'
            
            for c in self.setup['configuration']:       #append the configuration lines
                out_text += self.setup['config_operator'] + ' ' + c + '\n'    

            out_text += '\n#endif  //_SETTINGS_H_'
            outSettings.write(out_text) 

        with open(name,'w') as outText:
            if self.setup['nxc']:
                out_text = '//Generated NXC file for:  Device = '
                out_text += self.setup['device'] + '  Board = '
                out_text += self.setup['board'] + '\n\n'
            else:
                out_text = '//Generated C file for:  Device = '
                out_text += self.setup['device'] + '  Board = '
                out_text += self.setup['board'] + '\n\n#include "settings.h"\n\n'

            out_text += self.preprocessor + '\n'        #user defined C preprocessor commands
            out_text += '// ' + self.module_def + '\n'  #module definition
            out_text += self.includes + '\n'            #user defined headers files
            out_text += self.top_level + '\n'           #top level declarations      

            if not self.main:       #adds the main function structure if not exist
                if self.setup['nxc']:
                    out_text += 'task'
                elif self.setup['main_ret_type'] != 'none':
                    out_text += self.setup['main_ret_type']

                out_text += ' main('

                if self.setup['main_params'] != 'none':
                    out_text += self.setup['main_params']
                out_text += ') {\n' 

                for i in self.setup['initialization']:
                    out_text += i + '\n'

                out_text += ('\n' + self.output_s).replace('\n','\n\t')

                if self.setup['main_ret_type'] == 'int':
                    out_text += 'return 0;\n}' 
                else:
                    out_text += '\n}' 
            else:
                out_text = self.output_s

            outText.write(out_text)  

    def del_zeros(self, s):   # removes final zeros in a float string 
        l = list(s)
        while l[-1] == '0' and l[-2] != '.':
            l.pop()
        return ''.join(l)
        
    def error(self, p):
        if p:
            print( '\nSyntax error in the line ' + str(self.lineno) )
        else:
            print( '\nSyntax error at the end of file' )
        pass

    #************************* Program *************************  

    @_( 'cPreprocessors moduleClause importDecls topLevelDecls orphanStmtList',
        'moduleClause importDecls topLevelDecls orphanStmtList',
        'cPreprocessors importDecls topLevelDecls orphanStmtList',
        'cPreprocessors moduleClause topLevelDecls orphanStmtList',
        'importDecls topLevelDecls orphanStmtList',
        'cPreprocessors topLevelDecls orphanStmtList',
        'moduleClause topLevelDecls orphanStmtList',
        'topLevelDecls orphanStmtList',
        'cPreprocessors moduleClause importDecls orphanStmtList',
        'moduleClause importDecls orphanStmtList',
        'cPreprocessors importDecls orphanStmtList',
        'cPreprocessors moduleClause orphanStmtList',
        'importDecls orphanStmtList',
        'cPreprocessors orphanStmtList',
        'moduleClause orphanStmtList',
        'orphanStmtList',
        )    
    def sourceFile(self, p):
        self.output_s += p.orphanStmtList + '\n'
        print('sourceFile:\n\n' + self.output_s)

    @_( 'cPreprocessors moduleClause importDecls topLevelDecls',
        'moduleClause importDecls topLevelDecls',
        'cPreprocessors importDecls topLevelDecls',
        'cPreprocessors moduleClause topLevelDecls',
        'importDecls topLevelDecls',
        'cPreprocessors topLevelDecls',
        'moduleClause topLevelDecls',
        'topLevelDecls',
        )    
    def sourceFile(self, p):
        pass

    @_( 'MODULE IDENTIFIER eos' )    
    def moduleClause(self, p):      
        # print('moduleClause:\n' + p[0] + ';\n')
        self.module_def += p[0] + ';\n'

    @_( 'C_PREPROC',
        'cPreprocessors C_PREPROC', 
        )    
    def cPreprocessors(self, p):    
        # print('cPreprocessors:\n' + pp.C_PREPROC)
        self.preprocessor += p.C_PREPROC
    
    @_( 'importDecl eos',
        'importDecls importDecl eos', 
        )    
    def importDecls(self, p):
        pass

    @_( 'IMPORT importSpec',
        )    
    def importDecl(self, p):        
        # print('importDecl:\n' + '#include "' + p[1] + '.h"\n')
        self.includes += '#include "' + p[1] + '.h"\n'

    @_( '"." importPath',
        'IDENTIFIER importPath',
        'importPath',
        )    
    def importSpec(self, p):  
        if len(p) == 1:      
            # print('importSpec:\n' + p[0])
            return p[0]
        if len(p) == 2:      
            # print('importSpec:\n' + p[0] + p[1])
            return p[0] + p[1]

    @_( 'IDENTIFIER',
        'STRING_LIT',
        )    
    def importPath(self, p):        
        # print('importPath:\n' + p[0])
        return p[0]

    @_( 'topLevelDecl eos',
        'topLevelDecls topLevelDecl eos', 
        )    
    def topLevelDecls(self, p):
        pass

    @_( 'statementList eos',
        )    
    def orphanStmtList(self, p):        
        # print('orphanStmtList:\n' + p[0] + ';\n')
        return p[0] + ';\n'

    #************************* Statements *************************   
    @_( 'constDecl',
        'functionDecl', 
        # 'methodDecl',
        )
    def topLevelDecl(self, p):
        print('topLevelDecl:\n\n' + p[0])
        self.top_level += p[0]

    @_( 'varDecl',
        #'structDecl',
        )
    def declaration(self, p):
        return p[0]

    @_( 'identifierList DECL_ASGN expressionList',
        )
    def varDecl(self, p):
        ret_value = ''
        for i in range(len(self.values)):
            # print('Multiple declaration', self.types[0], self.values[0], self.identifiers[0])
            if self.types[0] == 'char []':
                ret_value += 'const char ' + self.identifiers.pop(0) + '[] = ' 
            else: 
                ret_value += self.types[0] + ' ' + self.identifiers.pop(0) + ' = ' 
            ret_value += self.values.pop(0)
            self.types.pop(0)
        # print('varDecl:\n' + ret_value)
        return ret_value

    @_( 'CONST constSpec',
        'CONST "(" constSpecs ")"', 
        'CONST "(" eos constSpecs ")"',
        )    
    def constDecl(self, p):    
        if len(p) == 2:
            # print('constDecl:\n' + p.constSpec + '\n'
            return p.constSpec + '\n'
        else:
            # print('constDecl:\n' + p.constSpecs + '\n'
            return p.constSpecs + '\n'

    @_( 'constSpec eos',
        'constSpecs constSpec eos', 
        )    
    def constSpecs(self, p):
        if len(p) == 2:
            # print('constSpecs:\n' + p[0] + ';\n')
            return p[0] + ';\n'
        elif len(p) == 3:
            # print('constSpecs:\n' + p[0] + p[1] + ';\n')
            return p[0] + p[1] + ';\n'
    
    @_( 'constSpec',
        'constSpecs constSpec', 
        )    
    def constSpecs(self, p):
        if len(p) == 1:
            # print('constSpecs:\n' + p[0] + ';\n')
            return p[0] + ';\n'
        elif len(p) == 2:
            # print('constSpecs:\n' + p[0] + p[1] + ';\n')
            return p[0] + p[1] + ';\n'

    @_( 'IDENTIFIER ASSIGN expression',
        )
    def constSpec(self, p):
        # print(self.identifiers, self.types, self.values)
        ret_value = ''
        if self.types[0] == 'char []':
            ret_value += 'const char ' + p.IDENTIFIER + '[] = ' 
        else: 
            ret_value += 'const ' + self.types[0] + ' ' + p.IDENTIFIER + ' = ' 

        ret_value += self.values.pop(0)
        self.types.pop(0)
        # print('constSpec:\n' + ret_value)
        return ret_value

    @_( 'IDENTIFIER',
        'identifierList "," IDENTIFIER',
        )
    def identifierList(self, p):
        self.identifiers.append(p.IDENTIFIER)
        # for i in self.identifiers:
        #     print(i, end=' ')
        # print('')
        if len(p) == 3:
            return p[0] + ' ' + p[1] + ' ' + p[2]
        elif len(p) == 1:
            return p[0]

    @_( 'FN IDENTIFIER function_',
        'FN IDENTIFIER signature',
        )    
    def functionDecl(self, p):        
        print('functionDecl:\n' + p[1] + p[2])
        return p[1] + p[2]

    @_( 'signature block',
        )    
    def function_(self, p):        
        print('function_:\n' + p[0] + p[1])
        return p[0] + p[1]

    @_( 'parameters result', #{noTerminatorAfterParams(1)}? parameters result
        'parameters'
        )    
    def signature(self, p):  
        if len(p) == 1:      
            print('signature:\n' + p[0])
            return p[0]
        elif len(p) == 2:
            print('signature:\n' + p[0] + p[1])
            return p[0] + p[1]

    @_( 'parameters',
        'type_'
        )    
    def result(self, p):        
        print('result:\n' + p[0])
        return p[0]

    @_( '"(" ")"',
        '"(" parameterList ")"',
        '"(" parameterList "," ")"',
        )    
    def parameters(self, p):        
        if len(p) == 2:      
            print('parameters:\n' + '()')
            return '()'
        else:
            print('parameters:\n' + '(' + p[1] + ')')
            return '(' + p[1] + ')'

    @_( 'parameterDecl',
        'parameterList "," parameterDecl', 
        )     
    def parameterList(self, p):
        if len(p) == 1:
            # print('parameterList:\n' + p[0])
            return p[0]
        elif len(p) == 3:
            # print('parameterList:\n' + p[0] + ',' + p[2])
            return p[0] + ',' + p[2]

    @_( 'identifierList type_',
        'type_'
        )    
    def parameterDecl(self, p):        
        if len(p) == 1:
            # print('parameterDecl:\n' + p[0])
            return p[0]
        elif len(p) == 2:
            # print('parameterDecl:\n' + p[0] + ',' + p[2])
            return p[0] + p[1]

    @_( 'FN function_',
        )    
    def functionLit(self, p):        
        # print('functionLit:\n' + p[1])
        return p[1]

    @_( 'expression',
        'expressionList "," expression', 
        )
    def expressionList(self, p):
        # for t,v in zip(self.types, self.values):
        #     print(t, v, end=' ')
        # print('')
        if len(p) == 3:
            # print(p[0] + ', ' + p[2])
            return p[0] + ', ' + p[2]
        elif len(p) == 1:
            #print(p[0])
            return p[0]

    @_( #'eos',
        'statement',
        'statementList eos statement', 
        )
    def statementList(self, p):
        if len(p) == 3:
            # print('statementList:\n',p[0] + p[1] + p[2])
            return p[0] + p[1] + p[2]
        elif len(p) == 1:
            # print('statementList:\n',p[0])
            return p[0]

    # @_( 'Statement', 'Statements Statement' )      
    # def Statements(self, p):
    #     if len(p) == 2:
    #         return p.Statements + p.Statement
    #     elif len(p) == 1:
    #         return p.Statement
    
    # @_( 'Item', 'DeclareStatement', 'ExpressionStatement' )
    # def Statement(self, p):
    #     return p[0] + '\n'
    
    # #************************* Items *************************
    # @_( 'Function', 'StaticItem' )
    # def Item(self, p):
    #     return p[0]
    
    # #--------------- Static item ---------------
    # @_( 'STATIC IDENTIFIER DECLARE_ASGN Type "(" Expression ")" NEWL' )   #variable declaration and initialization
    # def StaticItem(self, p):
    #     self.exType = ''
    #     return 'static' + p.Type + ' ' + p.IDENTIFIER + ' = ' + p.Expression + ';'       
    
    # #--------------- Functions ---------------
    # @_( 'FN IDENTIFIER "(" FunctionParameters ")" Type BlockExpression',
    #     'FN IDENTIFIER "(" FunctionParameters ")" BlockExpression' )
    # def Function(self, p):
    #     if len(p) == 7:
    #         return '\n' + p.Type + ' ' + p.IDENTIFIER + '( ' + p.FunctionParameters + ' )\n' + p.BlockExpression
    #     elif len(p) == 6:
    #         return '\nvoid ' + p.IDENTIFIER + '( ' + p.FunctionParameters + ' )\n' + p.BlockExpression

    # @_( 'FN IDENTIFIER "(" ")" Type BlockExpression',
    #     'FN IDENTIFIER "(" ")" BlockExpression' )
    # def Function(self, p):
    #     if p.IDENTIFIER == 'main':
    #         return '\nint main(void)\n' + p.BlockExpression[:-2] + '\n\n\treturn 0;\n}'
    #     elif len(p) == 6:
    #         return '\n' + p.Type + ' ' + p.IDENTIFIER + '(void)\n' + p.BlockExpression
    #     elif len(p) == 5:
    #         return '\nvoid ' + p.IDENTIFIER + '(void)\n' + p.BlockExpression
    
    # @_( 'FunctionParameters COMMA FunctionParam',
    #     'FunctionParam' )      
    # def FunctionParameters(self, p):
    #     if len(p) == 3: 
    #         return p.FunctionParameters + ', ' + p.FunctionParam
    #     elif len(p) == 1:
    #         return p.FunctionParam
    
    # @_( 'IDENTIFIER Type' )      
    # def FunctionParam(self, p):
    #     return p.Type + ' ' + p.IDENTIFIER
    
    # #--------------- Declare statement ---------------
    # @_( 'IDENTIFIER DECLARE_ASGN Type "(" Expression ")" NEWL',    #variable declaration and initialization
    #     'IDENTIFIER DECLARE_ASGN Expression NEWL' )  #variable inicialization (default types)
    # def DeclareStatement(self, p):
    #     if len(p) == 7:
    #         self.exType = ''
    #         return p.Type + ' ' + p.IDENTIFIER + ' = ' + p.Expression + ';'
    #     elif len(p) == 4:
    #         defaultType = ''
    #         if self.exType == 'BOOLEAN_LIT':
    #             defaultType = 'bool'    #bool
    #         elif self.exType == 'FLOAT_LIT':
    #             defaultType = 'float'   #f32
    #         elif self.exType == 'INT_LIT':
    #             defaultType = 'int16_t' #i16
    #         elif self.exType == 'RUNE_LIT':
    #             defaultType = 'char'    #rune
    #         self.exType = ''
    #         return defaultType + ' ' + p.IDENTIFIER + ' = ' + p.Expression.replace("`","'") + ';'  #i16

    # #--------------- Expresion statement ---------------
    # @_( 'Expression NEWL', 'ExpressionWithBlock NEWL', 'ExpressionWithBlock' )   
    # def ExpressionStatement(self, p):
    #     if len(p) == 2:
    #         return p[0] + ';'
    #     elif len(p) == 1:
    #         return p[0]
    
    # @_( 'error' )   
    # def ExpressionStatement(self, p):
    #     msg = 'Error: Invalid expression. Line ' + str(self.lineno) + '\n'
    #     self.error_s += msg
    #     print(msg)
    
    #************************* Expresions *************************
    # @_( 'ExpressionWithoutBlock' )#, 'ExpressionWithBlock' )      
    # def Expression(self, p):
    #     return p[0]
    
    # @_( 'BlockExpression', 'IfExpression', 'LoopExpression'  )
    # def ExpressionWithBlock(self, p):
    #     return '\n' + p[0]
    
    # @_( 'InfiniteLoopExpression', 'PredicateLoopExpression',)# 'IterexpressionatorLoopExpression' )
    # def LoopExpression(self, p):
    #     return p[0]
    
    # @_( 'FOR BlockExpression' )
    # def InfiniteLoopExpression(self, p):
    #     return 'while(true)\n' + p.BlockExpression
    
    # @_( 'FOR Expression BlockExpression' )
    # def PredicateLoopExpression(self, p):
    #     return 'while(' + p.Expression + ')\n' + p.BlockExpression
    
    # @_( 'IF Expression BlockExpression',
    #     'IF Expression BlockExpression ELSE BlockExpression',
    #     'IF Expression BlockExpression ELSE IfExpression' )      
    # def IfExpression(self, p):
    #     if len(p) == 3:
    #         return 'if( ' + p.Expression + ' )\n' + p[2]
    #     elif len(p) == 5:
    #         return 'if( ' + p.Expression + ' )\n' + p[2] + '\nelse\n' + p[4]
    
    # @_( '"{" Statements "}"' )          
    # def BlockExpression(self, p):
    #     return '{\n\t' + p[1].replace( '\n','\n\t' ) + ';\n}'
    
    # @_( 'IDENTIFIER', 'basicLit', 'OperatorExpression', 'GroupedExpression',
    #     'ReturnExpression' )      
    # def ExpressionWithoutBlock(self, p):
    #     return p[0]
    
    # @_( 'NegationExpression', 'AssignmentExpression', 'ArithmeticOrLogicalExpression',
    #     'LazyBooleanExpression', 'ComparisonExpression', 'CompoundAssignmentExpression',
    #     'IncDecExpression' )      
    # def OperatorExpression(self, p):
    #     return p[0]
    
    # @_( '"(" Expression ")"' )      
    # def GroupedExpression(self, p):
    #     return '( ' + p[1] + ' )'
    
    
    # @_( 'Expression LOGICAL_AND Expression', 'Expression LOGICAL_OR Expression' )      
    # def LazyBooleanExpression(self, p):
    #     return p[0] + ' ' + p[1] + ' ' + p[2]
    

    # @_( 'Expression PLUS_PLUS', 'Expression MINUS_MINUS' )      
    # def IncDecExpression(self, p):
    #     return p[0] + p[1]


    @_( '"{" statementList "}"',
        '"{" eos statementList "}"',
        '"{" statementList eos "}"',
        '"{" eos statementList eos "}"',
        )
    def block(self, p):
        print('{' + p.statementList + '}')
        return '{' + p.statementList + '}'

    
    @_( 'declaration',
        'simpleStmt',
        #'returnStmt',
        #'breakStmt',
        #'continueStmt',
        #'block',
        #'ifStmt',
        #'switchStmt',
        #'forStmt',
        )
    def statement(self, p):
        # print(p[0])
        return p[0]


    @_( 'expressionStmt',
        #'incDecStmt',
        'assignment',
        )
    def simpleStmt(self, p):
        # print(p[0])
        return p[0]

    @_( 'expression' )
    def expressionStmt(self, p):
        return p[0]

    @_( 'identifierList assign_op expressionList' ) #@_( 'expressionList assign_op expressionList' ) 
    def assignment(self, p):
        # print('\n\n' + p[0] + ' ' + p[1] + ' ' + p[2] + '\n\n')
        self.values.clear()
        self.types.clear()
        self.identifiers.clear()
        return p[0] + ' ' + p[1] + ' ' + p[2]

 
    
    # @_( 'Expression ASSIGN error' )      
    # def AssignmentExpression(self, p):
    #     msg = 'Error: Invalid assigment. Line ' + str(self.lineno) + '\n'
    #     self.error_s += msg
    #     print(msg)

    # @_( 'MINUS Expression %prec UMINUS', 'EXCLAMATION Expression' )  
    # def NegationExpression(self, p):
    #     return p[0] + p.Expression

    # @_( 'RETURN Expression', 'RETURN' )      
    # def ReturnExpression(self, p):
    #     if len(p) == 2:
    #         return 'return ' + p.Expression
    #     elif len(p) == 1:
    #         return 'return'

    # @_( 'RETURN error' )      
    # def ReturnExpression(self, p):
    #     msg = 'Error: Invalid return value. Line ' + str(self.lineno) + '\n'
    #     self.error_s += msg
    #     print(msg)


    @_( '"(" ")"',
        '"(" expressionList ")"',
        '"(" expressionList "," ")"',
        '"(" type_ ")"',
        '"(" type_ "," ")"',
        '"(" type_ "," expressionList ")"',
        '"(" type_ "," expressionList "," ")"',
        )      
    def arguments(self, p):
        if len(p) == 2:
            # print('arguments:\n','()') 
            return '()'
        elif len(p) == 3 or len(p) == 4:
            # print('arguments:\n','(' + p[1] + ')') 
            return '(' + p[1] + ')'
        elif len(p) == 5 or len(p) == 6:
            # print('arguments:\n','(' + p[1] + ',' + p[3] + ')') 
            return '(' + p[1] + ',' + p[3] + ')'


    # @_( 'receiverType "." IDENTIFIER' )      
    # def methodExpr(self, p):
    #     return p[0] + ' ' + p[1] + ' ' + p[2]

    # @_( 'typeName', '"(" receiverType ")"' )      
    # def receiverType(self, p):
    #     if len(p) == 3:
    #         return p[0] + ' ' + p[1] + ' ' + p[2]
    #     elif len(p) == 1:
    #         return p[0]

    @_( 'unaryExpr', 
        'expression BINARY_OP unaryExpr', 
        )      
    def expression(self, p):
        if len(p) == 3:
            return p[0] + ' ' + p[1] + ' ' + p[2]
        elif len(p) == 1:
            #print(p[0])
            return p[0]

    @_( 'primaryExpr', 
        'UNARY_OP unaryExpr %prec UOP', 
        )      
    def unaryExpr(self, p):
        if len(p) == 1:
            #print(p[0])
            return p[0]
        else:
            s = self.values[-1]
            self.values[-1] = p[0] + s
            #print(p[0] + p[1])
            return p[0] + p[1]

    @_( 'operand', 
        'conversion',
        'primaryExpr arguments',
        )
    def primaryExpr(self, p):
        if len(p) == 1:
            # print('primaryExpr:\n' + p[0])
            return p[0]
        elif len(p) == 2:
            # print('primaryExpr:\n' + p[0] + p[1])
            return p[0] + p[1]

    @_( 'literal',
        'operandName',
        #'methodExpr',
        '"(" expression ")"', 
        )
    def operand(self, p):
        if len(p) == 3:
            return p[0] + ' ' + p[1] + ' ' + p[2]
        elif len(p) == 1:
            return p[0]

    @_( 'IDENTIFIER',
        # 'qualifiedIdent',
        )
    def operandName(self, p):
        # print('operandName:\n' + p[0])
        self.identifiers.append(p[0])
        return p[0]

    @_( 'basicLit',
        #'compositeLit',
        'functionLit',
        #'arrayLit', 
        )
    def literal(self, p):
        return p[0]


    @_( 'type_ "(" expression ")"' )      
    def conversion(self, p):
        self.types[-1] = p.type_    #changes the default type
        return p.expression

    #************************* Types *************************
    @_( 'typeName', 
        'qualifiedIdent',
        )
    def type_(self, p):
        return p[0]
    
    @_( 'IDENTIFIER "." IDENTIFIER')
    def qualifiedIdent(self, p):
        return p[0] + '.' + p[2]

    @_( 'RUNE', 'BOOL', 'STRING', 'numericType' )
    def typeName(self, p):
        return p[0]
    
    #--------------- Integer & floating point types ---------------
    @_( 'U8', 'U16', 'U32', 'U64', 'USIZE', 'UINT',
        'I8', 'I16', 'I32', 'I64', 'ISIZE', 'INT', 
        'F64', 'F32' )
    def numericType(self, p):
        return self.setup[p[0]]

    #--------------- Literals ---------------
    @_( 'STRING_LIT' )                   
    def basicLit(self, p):
        s = p[0].replace("'",'"')
        self.types.append('char []')
        self.values.append(s)
        return s
    
    @_( 'RUNE_LIT' )                   
    def basicLit(self, p):
        s = p[0].replace('`',"'")
        self.types.append('char')
        self.values.append(s)
        return s

    @_( 'TRUE', 'FALSE' )                   
    def basicLit(self, p):
        self.types.append('bool')
        self.values.append(p[0])
        print(p)
        return p[0]

    @_( 'FLOAT_LIT EXPONENT',       #ENGINEERING NOTATION
        'DECIMAL_LIT EXPONENT' )                   
    def basicLit(self, p):
        s = (p[0]+p[1]).replace( '_', '' )  # remove underscore
        self.types.append(self.setup['default_float'])
        s = '{:.15f}'.format(eval(s))   # from engineering annotation to pure float
        self.values.append(self.del_zeros(s))   # delete final zeros 
        return self.del_zeros(s)    # delete final zeros

    @_( 'FLOAT_LIT' )                   
    def basicLit(self, p):
        s = p[0].replace( '_', '' )  # remove underscore
        self.types.append(self.setup['default_float'])
        self.values.append(s)
        return s

    @_( 'DECIMAL_LIT "." DECIMAL_LIT', 
        'DECIMAL_LIT "."',
        '"." DECIMAL_LIT' )                   
    def FLOAT_LIT(self, p):
        if len(p) == 3:
            return p[0] + '.' + p[2]
        else:
            return str(eval('0' + p[0] + p[1] + '0'))  #complete the float ex: 02.0  0.20

    @_( 'INT_LIT' )                   
    def basicLit(self, p):
        s = p[0].replace( '_', '' )  # remove underscore
        self.types.append(self.setup['default_int'])
        self.values.append(s)
        return s

    @_( 'DECIMAL_LIT', 'BINARY_LIT', 'OCTAL_LIT', 'HEX_LIT' )                   
    def INT_LIT(self, p):
        return p[0]

    @_( '";"',
        'eos ";"',
        )
    def eos(self, p):
        return ';\n'   

    @_( 'NEWL', 
        'eos NEWL', 
        )
    def eos(self, p):
        self.lineno += 1    #line counter
        return ';\n'   

    #--------------- Lexer operators ---------------
    @_( 'ASSIGN', 'PLUS_ASGN', 'MINUS_ASGN', 'XOR_ASGN', 'STAR_ASGN', 
        'AND_ASGN', 'OR_ASGN', 'DIV_ASGN', 'MOD_ASGN', 'SHL_ASGN', 'SHR_ASGN' )      
    def assign_op(self, p):
        # print('assign_op:\n',p[0])
        return p[0]   

    @_( 'LOGIC_OR', 'LOGIC_AND', 'REL_OP', 'ADD_OP', 'MUL_OP' )
    def BINARY_OP(self, p):
        return p[0]     

    @_( 'EQ', 'NE', 'LT' , 'LE', 'GT' , 'GE' )
    def REL_OP(self, p):
        return p[0]

    @_( 'PLUS', 'MINUS', 'OR', 'XOR' )   
    def ADD_OP(self, p):
        return p[0]

    @_( 'STAR', 'DIV', 'MOD', 'AND', 'SHL', 'SHR' )      
    def MUL_OP(self, p):
        return p[0]

    @_( 'MINUS', 'EXCLM', 'AND' )   #NO unary plus
    def UNARY_OP(self, p):
        return p[0]