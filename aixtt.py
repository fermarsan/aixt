from lark import Lark
from aixt_parser_lexer import aixt_transformer
import sys


parser = Lark.open( 'aixt_grammar.lark', 
                    start='source_file', 
                    rel_to=__file__, 
                    parser='lalr'   )

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
