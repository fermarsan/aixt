from sly import Lexer

#lexic analizer
class aix_lexer(Lexer):

    tokens = {  
        I8, I16, I32, I64, ISIZE, U8, U16, U32, U64, USIZE,         # Types
        F32, F64, BOOL, RUNE,                               

        IF, ELSE, FOR, BREAK, CONTINUE, FN, RETURN, MATCH,          # Keywords and identifier
        STATIC, CONST, STRUCT, MAP, IMPORT, AS, IDENTIFIER,                

        DECIMAL_LIT, BINARY_LIT, OCTAL_LIT, HEX_LIT, FLOAT_LIT,     # literals      
        TRUE, FALSE, RUNE_LIT, STRING_LIT,     

        EQUALS, NOT_EQUALS, LESS, LESS_OR_EQUALS,                   # Relation operators 
        GREATER, GREATER_OR_EQUALS, 
    }

    ignore_comment = r'(//.*)|(/\*(.|\n)*\*/)'    # Ignored pattern

    #Tokens
    BOOL                = r'bool'   # Types
    RUNE                = r'rune'
    USIZE               = r'usize'
    ISIZE               = r'isize'
    U8                  = r'u8'
    U16                 = r'u16'
    U32                 = r'u32'
    U64                 = r'u64'
    I8                  = r'i8'
    I16                 = r'i16'
    I32                 = r'i32'
    I64                 = r'i64'
    F32                 = r'f32'
    F64                 = r'f64'

    TRUE                = r'true'   # Boolean literals  
    FALSE               = r'false'

    BREAK               = r'break'  # Keywords    
    FN                  = r'fn'            
    MAP                 = r'map' 
    MATCH               = r'match'           
    STRUCT              = r'struct'            
    ELSE                = r'else'  
    STATIC              = r'static'          
    CONST               = r'const'            
    IF                  = r'if'                      
    CONTINUE            = r'continue'            
    FOR                 = r'for'            
    IMPORT              = r'import'   
    AS                  = r'as'         
    RETURN              = r'return'                

    NEWL                = r'\n+'

    IDENTIFIER          = r'[a-zA-Z_][a-zA-Z0-9_]*'
    STRING_LIT          = r'\'.*\''
    RUNE_LIT            = r'`.`'
    FLOAT_LIT           = r'[0-9_]+\.[0-9_]+'
    HEX_LIT             = r'0x[0-9A-Fa-f_]+'
    OCTAL_LIT           = r'0o[0-7_]+'
    BINARY_LIT          = r'0b[01_]+'
    DECIMAL_LIT         = r'[0-9_]+'
    
    ignore = ' \t'

    literals = { '+', '-', '*', '/', '%',
                 '&', '|', '^', '!',  
                 '<', '>', '=',  
                 '\(', '\)', '\{', '\}', '\[', '\]',
                 ':', ',', '\.',
               }
    
    #ignore_comment = r'//.*'    # Ignored pattern

    def __init__(self):
        self.error_s = ''       #error stream

    @_(r'\n+')  #line counting
    def newline(self, t):
        self.lineno += t.value.count('\n')

    def error(self, t):
        self.error_s += 'Error: ilegal character \'' + str(t.value[0]) 
        self.error_s += '\'. Line ' + str(t.lineno) + '\n'
        self.index += 1