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
        

    

    
    