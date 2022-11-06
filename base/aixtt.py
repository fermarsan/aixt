from aixt_lexer import aixt_lexer
from aixt_parser import aixt_parser
import re
#from os import system
import sys

if len(sys.argv) > 1:

    lexer = aixt_lexer()        #carga el analizador Léxico
    parser = aixt_parser()      #y el sintáctico
    
    #carga el archivo
    name = sys.argv[1]
    with open(name,'r') as inFile:  #abre el archivo de entrada
        program = inFile.read()
        program += '\n'

        # preprocessing
        program = re.sub("//.*\n","",program)           # remove the line comments
        program = re.sub("/\*(.|\n)*\*/","",program)    # remove the multi-line comments
        program = re.sub("\n+","\n",program)            # remove multiple new lines
        program = program[1:] if program[0] == '\n' else program     # ignore the first new line
    
    #analiza el archivo
    # for t in lexer.tokenize(program):   
    #     print(t)
    parser.parse(lexer.tokenize(program))     #analiza y ejecuta el programa 
    
    #guarda los archivos de salida
    parser.saveOutput(name.replace('.v','.c'))

else:
    print('No se especificó un archivo de entrada.\n')