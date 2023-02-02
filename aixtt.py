# This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
#
# The MIT License (MIT)
# 
# Copyright (c) 2023 Fernando Martínez Santa

from lark import Lark
from aixt_transformer import aixt_transformer
import sys


parser = Lark.open( 'aixt.lark', 
                    start='source_file', 
                    rel_to=__file__, 
                    parser='lalr'   
                    )

if len(sys.argv) > 1:
    name = sys.argv[1]
    with open(name,'r') as inFile:  #abre el archivo de entrada
        tree = parser.parse( inFile.read() )

        # print(tree)
        # print('_'*60 + '\n') 
        
        print(tree.pretty())
        print('_'*60 + '\n')

        print(aixt_transformer().transform(tree))
        print('_'*60 + '\n')
