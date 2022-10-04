import re
import sys

if len(sys.argv) > 1:
    
    #carga el archivo
    name = sys.argv[1]
    inFile = open(name,'r')  #abre el archivo de entrada
    program = inFile.read()

    program = re.sub("//.*\n","",program)           # remove the line comments
    program = re.sub("/\*(.|\n)*\*/","",program)    # remove the multi-line comments
    program = re.sub("\n+","\n",program)            # remove multiple new lines

    print(program[1:])
    inFile.close()