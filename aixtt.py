# This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
#
# The MIT License (MIT)
# 
# Copyright (c) 2023 Fernando Martínez Santa

from lark import Lark
from aixt_transformer import aixtTransformer
import sys
import yaml
import re


parser = Lark.open( 'aixt.lark', 
                    start='source_file', 
                    rel_to=__file__, 
                    parser='lalr',
                    # lexer='basic'   
                    )
transpiler = aixtTransformer()

if len(sys.argv) > 1:
    name = sys.argv[1]
    with open(name,'r') as inFile:  # opens the input file        program = inFile.read()
        program = inFile.read()
    if len(sys.argv) > 2:
        if sys.argv[2] == '-nxc':                       #if -nxt flag
            with open(r'../api/equivalents.yaml','r') as eq_file:
                equivalents = yaml.load(eq_file, Loader=yaml.FullLoader)
                for k in equivalents.keys():
                    # print(type(k))
                    # print(equivalents[k])
                    program = re.sub(k,equivalents[k],program)  # replace the NXC equivalents
        else:
            print('Invalid flag.\n')
        
    # ---------- Parsing ----------
    tree = parser.parse( program )  
    # print(tree)
    # print('_'*60 + '\n') 

    print(tree.pretty())
    print('_'*60 + '\n')    
    print_out = transpiler.transform(tree)

    print(print_out)
    print('_'*60 + '\n')    

    if len(sys.argv) > 2:   # saves the output file
        if sys.argv[2] == '-nxc':                       
            transpiler.saveOutput(name.replace('.v','.nxc'))
    else:
        transpiler.saveOutput(name.replace('.v','.c'))

else:
    print('no input file.\n')