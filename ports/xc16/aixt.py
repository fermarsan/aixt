#Support:
# - Inspired by the V language grammar (https://vlang.io/)
#       - Golang grammar was taken as reference (https://github.com/antlr/grammars-v4/tree/master/golang)
#       - as well as Rust grammar (https://doc.rust-lang.org/stable/reference/)
# - Integer literals in binary, octal, hexadecimal and decimal notation
# - Floating point, character and boolean literals
# - Literals with '_'
# - Declaration of boolean and character variables
# - Declaration of signed and unsigned 8, 16, 32 and 64 bit integer variables (also isize and usize)
# - Declaration of variables in floating point of 32 and 64 bits
# - Declaration and simultaneous stipulation
# - Declaration by default type inference
# - DOES NOT support the 'mut' keyword since by default all variables are mutable
# - line and block comments
# - Variable assignment
# - numeric and boolean negation
# - bitwise arithmetic and logical operations
# - parentheses in expressions
# - logical operations and and or
# - compare operations
# - of compound operations '+=', etc.
# - block expressions '{ Code_block }' (a tab is added to the block)
# - function declarations and return values
# - if-else statements, for infinity, for while

from aix_lexer import aix_lexer
from aix_parser import aix_parser
import re
#from os import system
import sys

if len(sys.argv) > 1:

    lexer = aix_lexer()        #carga el analizador Léxico
    parser = aix_parser()      #y el sintáctico
    
    #carga el archivo
    name = sys.argv[1]
    inFile = open(name,'r')  #abre el archivo de entrada
    program = inFile.read()

    # preprocessing
    program = re.sub("//.*\n","",program)           # remove the line comments
    program = re.sub("/\*(.|\n)*\*/","",program)    # remove the multi-line comments
    program = re.sub("\n+","\n",program)            # remove multiple new lines
    program = program[1:] if program[0] == '\n' else program     # ignore the first new line

    #print(program)
    inFile.close()
    
    #analiza el archivo
    # for t in lexer.tokenize(program):   
    #     print(t)
    parser.parse(lexer.tokenize(program))     #analiza y ejecuta el programa 
    
    #guarda los archivos de salida
    parser.saveOutput(name.replace('.v','.c'))

else:
    print('No se especificó un archivo de entrada.\n')
        

    

    
    