from lib2to3.pgen2.token import MINUS
from aix_lexer import aix_lexer
from sly import Parser
#import sys, os

class aix_parser(Parser):

    debugfile = 'parser.out'

    precedence = (
        ( 'left' , LOGICAL_OR ),
        ( 'left' , LOGICAL_AND ), 
        ( 'left' , EQUALS, NOT_EQUALS, LESS, LESS_OR_EQUALS, GREATER, GREATER_OR_EQUALS ),   
        ( 'left' , PLUS, MINUS, OR, CARET ),
        ( 'left' , STAR, DIV, MOD, LSHIFT, RSHIFT, AMPERSAND ),
        ( 'left' , PLUS_PLUS, MINUS_MINUS ),
        ( 'right', EXCLAMATION, UMINUS ),
        ( 'right', ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN, CARET_ASSIGN, STAR_ASSIGN, AMPERSAND_ASSIGN, 
                   OR_ASSIGN, DIV_ASSIGN, MOD_ASSIGN, LSHIFT_ASSIGN,RSHIFT_ASSIGN ),
        ( 'right', RETURN ),
    )

    tokens = aix_lexer.tokens

    def __init__(self): 
        self.error_s = ''       #error stream
        self.output_s = ''      #output stream
        self.exType = ''

        # self.output_header =    """include <stdint.h>
        #                            int main(void){
        #                         """
    
    #guarda los archivos de salida
    def saveOutput(self, name):
        outText = open(name,'w' )
        outText.write( self.output_s )  
        outText.close()
        
        # outText = open(name + '.var', 'w' )
        # for v in self.vars:
        #     outText.write( v + '\t' )
        # outText.close()
        #pass

    def error(self, p):
        if p:
            print( '\nSyntax error in the line ' + str(p.lineno) )
        else:
            print( '\nSyntax error at the end of file' )
        pass

    #************************* Program *************************  
    @_( 'Statements' )    
    def prog(self, p):
        self.output_s += p.Statements
    
    #************************* Statements *************************   
    @_( 'Statement', 'Statements Statement' )      
    def Statements(self, p):
        if len(p) == 2:
            return p.Statements + p.Statement
        elif len(p) == 1:
            return p.Statement
    
    @_( 'Item', 'DeclareStatement', 'ExpressionStatement' )
    def Statement(self, p):
        return p[0] + '\n'
    
    #************************* Items *************************
    @_( 'Function', 'StaticItem' )
    def Item(self, p):
        return p[0]
    
    #--------------- Static item ---------------
    @_( 'STATIC IDENTIFIER DECLARE_ASSIGN Type L_PAREN Expression R_PAREN NEWL' )   #variable declaration and initialization
    def StaticItem(self, p):
        self.exType = ''
        return 'static' + p.Type + ' ' + p.IDENTIFIER + ' = ' + p.Expression + ';'       
    
    #--------------- Functions ---------------
    @_( 'FN IDENTIFIER L_PAREN FunctionParameters R_PAREN Type BlockExpression',
        'FN IDENTIFIER L_PAREN FunctionParameters R_PAREN BlockExpression' )
    def Function(self, p):
        if len(p) == 7:
            return '\n' + p.Type + ' ' + p.IDENTIFIER + '( ' + p.FunctionParameters + ' )\n' + p.BlockExpression
        elif len(p) == 6:
            return '\nvoid ' + p.IDENTIFIER + '( ' + p.FunctionParameters + ' )\n' + p.BlockExpression

    @_( 'FN IDENTIFIER L_PAREN R_PAREN Type BlockExpression',
        'FN IDENTIFIER L_PAREN R_PAREN BlockExpression' )
    def Function(self, p):
        if p.IDENTIFIER == 'main':
            return '\nint main(void)\n' + p.BlockExpression[:-2] + '\n\n\treturn 0;\n}'
        elif len(p) == 6:
            return '\n' + p.Type + ' ' + p.IDENTIFIER + '(void)\n' + p.BlockExpression
        elif len(p) == 5:
            return '\nvoid ' + p.IDENTIFIER + '(void)\n' + p.BlockExpression
    
    @_( 'FunctionParameters COMMA FunctionParam',
        'FunctionParam' )      
    def FunctionParameters(self, p):
        if len(p) == 3: 
            return p.FunctionParameters + ', ' + p.FunctionParam
        elif len(p) == 1:
            return p.FunctionParam
    
    @_( 'IDENTIFIER Type' )      
    def FunctionParam(self, p):
        return p.Type + ' ' + p.IDENTIFIER
    
    #--------------- Declare statement ---------------
    @_( 'IDENTIFIER DECLARE_ASSIGN Type L_PAREN Expression R_PAREN NEWL',    #variable declaration and initialization
        'IDENTIFIER DECLARE_ASSIGN Expression NEWL' )  #variable inicialization (default types)
    def DeclareStatement(self, p):
        if len(p) == 7:
            self.exType = ''
            return p.Type + ' ' + p.IDENTIFIER + ' = ' + p.Expression + ';'
        elif len(p) == 4:
            defaultType = ''
            if self.exType == 'BOOLEAN_LIT':
                defaultType = 'bool'    #bool
            elif self.exType == 'FLOAT_LIT':
                defaultType = 'float'   #f32
            elif self.exType == 'INT_LIT':
                defaultType = 'int16_t' #i16
            elif self.exType == 'RUNE_LIT':
                defaultType = 'char'    #rune
            self.exType = ''
            return defaultType + ' ' + p.IDENTIFIER + ' = ' + p.Expression.replace("`","'") + ';'  #i16

    #--------------- Expresion statement ---------------
    @_( 'Expression NEWL', 'ExpressionWithBlock NEWL', 'ExpressionWithBlock' )   
    def ExpressionStatement(self, p):
        if len(p) == 2:
            return p[0] + ';'
        elif len(p) == 1:
            return p[0]
    
    # @_( 'error' )   
    # def ExpressionStatement(self, p):
    #     msg = 'Error: Invalid expression. Line ' + str(p.lineno) + '\n'
    #     self.error_s += msg
    #     print(msg)
    
    #************************* Expresions *************************
    @_( 'ExpressionWithoutBlock' )#, 'ExpressionWithBlock' )      
    def Expression(self, p):
        return p[0]
    
    @_( 'BlockExpression', 'IfExpression', 'LoopExpression'  )
    def ExpressionWithBlock(self, p):
        return '\n' + p[0]
    
    @_( 'InfiniteLoopExpression', 'PredicateLoopExpression',)# 'IteratorLoopExpression' )
    def LoopExpression(self, p):
        return p[0]
    
    @_( 'FOR BlockExpression' )
    def InfiniteLoopExpression(self, p):
        return 'while(true)\n' + p.BlockExpression
    
    @_( 'FOR Expression BlockExpression' )
    def PredicateLoopExpression(self, p):
        return 'while(' + p.Expression + ')\n' + p.BlockExpression
    
    @_( 'IF Expression BlockExpression',
        'IF Expression BlockExpression ELSE BlockExpression',
        'IF Expression BlockExpression ELSE IfExpression' )      
    def IfExpression(self, p):
        if len(p) == 3:
            return 'if( ' + p.Expression + ' )\n' + p[2]
        elif len(p) == 5:
            return 'if( ' + p.Expression + ' )\n' + p[2] + '\nelse\n' + p[4]
    
    @_( 'L_CURLY Statements R_CURLY' )          
    def BlockExpression(self, p):
        return '{\n\t' + p[1].replace( '\n','\n\t' ) + ';\n}'
    
    @_( 'IDENTIFIER', 'basicLit', 'OperatorExpression', 'GroupedExpression',
        'ReturnExpression' )      
    def ExpressionWithoutBlock(self, p):
        return p[0]
    
    @_( 'NegationExpression', 'AssignmentExpression', 'ArithmeticOrLogicalExpression',
        'LazyBooleanExpression', 'ComparisonExpression', 'CompoundAssignmentExpression',
        'IncDecExpression' )      
    def OperatorExpression(self, p):
        return p[0]
    
    @_( 'L_PAREN Expression R_PAREN' )      
    def GroupedExpression(self, p):
        return '( ' + p[1] + ' )'
    
    @_( 'Expression PLUS Expression', 'Expression MINUS Expression',
        'Expression STAR Expression', 'Expression DIV Expression',
        'Expression MOD Expression', 'Expression AMPERSAND Expression',
        'Expression OR Expression', 'Expression CARET Expression',
        'Expression LSHIFT Expression', 'Expression RSHIFT Expression' )      
    def ArithmeticOrLogicalExpression(self, p):
        return p[0] + ' ' + p[1] + ' ' + p[2]
    
    @_( 'Expression LOGICAL_AND Expression', 'Expression LOGICAL_OR Expression' )      
    def LazyBooleanExpression(self, p):
        return p[0] + ' ' + p[1] + ' ' + p[2]
    
    @_( 'Expression EQUALS Expression', 'Expression NOT_EQUALS Expression',
        'Expression GREATER Expression', 'Expression LESS Expression',
        'Expression GREATER_OR_EQUALS Expression', 'Expression LESS_OR_EQUALS Expression' )      
    def ComparisonExpression (self, p):
        return p[0] + ' ' + p[1] + ' ' + p[2]      

    @_( 'Expression PLUS_PLUS', 'Expression MINUS_MINUS' )      
    def IncDecExpression(self, p):
        return p[0] + p[1]

    @_( 'Expression PLUS_ASSIGN Expression', 'Expression MINUS_ASSIGN Expression',
        'Expression STAR_ASSIGN Expression', 'Expression DIV_ASSIGN Expression',
        'Expression MOD_ASSIGN Expression', 'Expression AMPERSAND_ASSIGN Expression',
        'Expression OR_ASSIGN Expression', 'Expression CARET_ASSIGN Expression',
        'Expression LSHIFT_ASSIGN Expression', 'Expression RSHIFT_ASSIGN Expression' )      
    def CompoundAssignmentExpression(self, p):
        return p[0] + ' ' + p[1] + ' ' + p[2]

    @_( 'Expression ASSIGN Expression' )      
    def AssignmentExpression(self, p):
        return p[0] + ' = ' + p[2]
    
    @_( 'Expression ASSIGN error' )      
    def AssignmentExpression(self, p):
        msg = 'Error: Invalid assigment. Line ' + str(p.lineno) + '\n'
        self.error_s += msg
        print(msg)

    @_( 'MINUS Expression %prec UMINUS', 'EXCLAMATION Expression' )  
    def NegationExpression(self, p):
        return p[0] + p.Expression

    @_( 'RETURN Expression', 'RETURN' )      
    def ReturnExpression(self, p):
        if len(p) == 2:
            return 'return ' + p.Expression
        elif len(p) == 1:
            return 'return'

    @_( 'RETURN error' )      
    def ReturnExpression(self, p):
        msg = 'Error: Invalid return value. Line ' + str(p.lineno) + '\n'
        self.error_s += msg
        print(msg)

    @_( 'type "(" expression ")"' )      
    def conversion(self, p):
        if len(p) == 2:
            return 'return ' + p.Expression
        elif len(p) == 1:
            return 'return'

    #************************* Types *************************
    @_( 'primitiveType' )
    def Type(self, p):
        return p[0]
    
    @_( 'RUNE', 'BOOL', 'numericType' )
    def primitiveType(self, p):
        return p[0]
    
    #--------------- Floating point types ---------------
    @_( 'F64' )
    def numericType(self, p):
        return 'long double'
    
    @_( 'F32' )
    def numericType(self, p):
        return 'float'
    
    #--------------- INT_LIT types ---------------
    @_( 'U8', 'U16', 'U32', 'U64' )
    def numericType(self, p):
        return p[0].replace( 'u', 'uint' ) + '_t'

    @_( 'I8', 'I16', 'I32', 'I64' )
    def numericType(self, p):
        return p[0].replace( 'i', 'int' ) + '_t'

    @_( 'USIZE', 'ISIZE' )
    def numericType(self, p):
        if p[0][0] == 'u':
            return'uint16_t'
        else:
            return'int16_t'

    #--------------- Literals ---------------
    @_( 'STRING_LIT' )                   
    def basicLit(self, p):
        return p[0]
    
    @_( 'RUNE_LIT' )                   
    def basicLit(self, p):
        if self.exType != '' and self.exType != 'RUNE_LIT':
            self.error = 'Type error: it is not a rune value.\n'
        else:
            self.exType = 'RUNE_LIT'
        return p[0]

    @_( 'TRUE', 'FALSE' )                   
    def basicLit(self, p):
        if self.exType != '' and self.exType != 'BOOLEAN_LIT':
            self.error = 'Type error: it is not a boolean value.\n'
        else:
            self.exType = 'BOOLEAN_LIT'
        return p[0]

    @_( 'FLOAT_LIT' )                   
    def basicLit(self, p):
        if self.exType != '' and self.exType != 'INT_LIT' and self.exType != 'FLOAT_LIT':
            self.error = 'Type error: it is not a numeric value.\n' 
        else:
            self.exType = 'FLOAT_LIT'
        return p[0].replace( '_', '' )  # remove backslashes

    @_( 'INT_LIT' )                   
    def basicLit(self, p):
        if self.exType != '' and self.exType != 'INT_LIT' and self.exType != 'FLOAT_LIT':
            self.error = 'Type error: it is not a numeric value.\n' 
        elif self.exType != 'FLOAT_LIT':
            self.exType = 'INT_LIT'
        return p[0].replace( '_', '' )  # remove backslashes

    @_( 'DECIMAL_LIT', 'BINARY_LIT', 'OCTAL_LIT', 'HEX_LIT' )                   
    def INT_LIT(self, p):
        return p[0]

    #--------------- Lexer complements ---------------
    @_( '"|" "|"', '"&" "&"', 'REL_OP', 'ADD_OP', 'MUL_OP' )
    def BINARY_OP(self, p):
        if len(p) == 2:
            return p[0] + p[1]
        elif len(p) == 1:
            return p[0]     

    @_( '"=" "="', '"!" "="', '"<"' , '"<" "="', '">"' , '">" "="' )
    def REL_OP(self, p):
        if len(p) == 2:
            return p[0] + p[1]
        elif len(p) == 1:
            return p[0]

    @_( '"+"', '"-"', '"|"', '"^"' )   
    def ADD_OP(self, p):
        return P[0]

    @_( '"*"', '"/"', '"%"', '"&"', '"<" "<"', '">" ">"' )      
    def MUL_OP(self, p):
        if len(p) == 2:
            return p[0] + p[1]
        elif len(p) == 1:
            return p[0]

    @_( '"+"', '"-"', '"!"', '"&"' )   # '^'     
    def UNARY_OP(self, p):
        return p[0]