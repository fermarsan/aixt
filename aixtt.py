from aixt_lexer import aixt_lexer
from aixt_parser import aixt_parser
import re
import yaml
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

    if len(sys.argv) > 2:
        if sys.argv[2] == '-nxc':                       #if -nxt flag
            with open(r'api/equivalents.yaml','r') as eq_file:
                equivalents = yaml.load(eq_file, Loader=yaml.FullLoader)
                for k in equivalents.keys():
                    # print(type(k))
                    # print(equivalents[k])
                    program = re.sub(k,equivalents[k],program)  # replace the NXC equivalents
        else:
            print('Invalid flag.\n')
    
    #analiza el archivo
    # for t in lexer.tokenize(program):   
    #     print(t)
    parser.parse(lexer.tokenize(program))     #analiza y ejecuta el programa 
    
    #guarda los archivos de salida
    if len(sys.argv) > 2:
        if sys.argv[2] == '-nxc':                       
            parser.saveOutput(name.replace('.v','.nxc'))
        else:
            parser.saveOutput(name.replace('.v','.c'))

else:
    print('no input file.\n')