# YAML setup file support
from sly import Lexer

#lexic analizer
class aixt_lexer(Lexer):

    tokens = {  
        I8, I16, I32, I64, ISIZE, U8, U16, U32, U64, USIZE,         # Types
        F32, F64, BOOL, RUNE, STRING,                               

        AS, BREAK, CONST, CONTINUE, ELSE, ENUM, FN, FOR, IF,        # Keywords and identifierS
        IMPORT, IN, MAP, MATCH, RETURN, STATIC, STRUCT, TYPE,
        IDENTIFIER,   

        DECIMAL_LIT, BINARY_LIT, OCTAL_LIT, HEX_LIT, FLOAT_LIT,     # literals      
        TRUE, FALSE, RUNE_LIT, STRING_LIT,

        LOGIC_OR, LOGIC_AND, EQ, NE, LT, LE, GT, GE,                # operators
        PLUS, MINUS, OR, XOR, STAR, DIV, MOD, SHL, SHR, AND,
        PLUS_PLUS, MINUS_MINUS, EXCLM, UMINUS, ASSIGN, 
        DECL_ASGN, PLUS_ASGN, MINUS_ASGN, XOR_ASGN, STAR_ASGN, 
        AND_ASGN, OR_ASGN, DIV_ASGN, MOD_ASGN, SHL_ASGN, SHR_ASGN,  

        NEWL,
 
    }

    #ignore_comment = r'(//.*)|(/\*(.|\n)*\*/)'    # Ignored pattern

    #Tokens
    BOOL            = r'bool'   # Types
    RUNE            = r'rune'
    STRING          = r'string'
    USIZE           = r'usize'
    ISIZE           = r'isize'
    U8              = r'u8'
    U16             = r'u16'
    U32             = r'u32'
    U64             = r'u64'
    I8              = r'i8'
    I16             = r'i16'
    I32             = r'i32'
    I64             = r'i64'
    F32             = r'f32'
    F64             = r'f64'

    TRUE            = r'true'   # Boolean literals  
    FALSE           = r'false'

    AS              = r'as'         # Keywords 
    BREAK           = r'break'      
    CONST           = r'const' 
    CONTINUE        = r'continue' 
    ELSE            = r'else' 
    ENUM            = r'enum'
    FN              = r'fn'   
    FOR             = r'for'
    IF              = r'if'
    IMPORT          = r'import'
    IN              = r'in'
    MAP             = r'map' 
    MATCH           = r'match'
    RETURN          = r'return'
    STATIC          = r'static'  
    STRUCT          = r'struct'            
    TYPE            = r'type'

    ASSIGN          = r'='
    DECL_ASGN       = r':='
    PLUS_PLUS       = r'\+\+'
    MINUS_MINUS     = r'--'

    PLUS_ASGN       = r'\+='    # Compound operators    
    MINUS_ASGN      = r'-='     
    XOR_ASGN        = r'\^='    
    STAR_ASGN       = r'\*='    
    AND_ASGN        = r'&='     
    OR_ASGN         = r'\|='    
    DIV_ASGN        = r'/='    
    MOD_ASGN        = r'%='    
    SHL_ASGN        = r'<<='     
    SHR_ASGN        = r'>>='    

    LOGIC_OR        = r'\|\|'   # Logicas operators
    LOGIC_AND       = r'&&'
    EXCLM           = r'!'

    OR              = r'\|'     # Arithmetic operators
    DIV             = r'/'
    MOD             = r'%'
    SHL             = r'<<'
    SHR             = r'>>'

    PLUS            = r'\+'     # Mixed operators
    MINUS           = r'-'
    XOR             = r'\^'
    STAR            = r'\*'
    AND             = r'&'

    EQ              = r'=='     # Relation operators
    NE              = r'!='
    LT              = r'<'
    LE              = r'<='
    GT              = r'>'
    GE              = r'>='

    NEWL            = r'\n+'

    IDENTIFIER      = r'[a-zA-Z_][a-zA-Z0-9_]*'
    STRING_LIT      = r'\'.*\''
    RUNE_LIT        = r'`.`'
    FLOAT_LIT       = r'[0-9_]+\.[0-9_]+'
    HEX_LIT         = r'0x[0-9A-Fa-f_]+'
    OCTAL_LIT       = r'0o[0-7_]+'
    BINARY_LIT      = r'0b[01_]+'
    DECIMAL_LIT     = r'[0-9_]+'
    
    ignore = ' \t'

    literals = { '(', ')', '{', '}', '[', ']',
                 ';', ',', '.',
               }


    def __init__(self):
        self.error_s = ''       #error stream

    # @_(r'\n+')  #line counting
    # def newline(self, t):
    #     self.push_state('\n')
    #     self.lineno += t.value.count('\n')
    #     #self.lineno += len(t.value)
        

    def error(self, t):
        self.error_s += 'Error: ilegal character \'' + str(t.value[0]) 
        self.error_s += '\'. Line ' + str(t.lineno) + '\n'
        self.index += 1