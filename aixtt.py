from lark import Lark, Transformer, v_args

@v_args(inline=True)
class aixt_to_c(Transformer):
    def __init__(self):
        self.symbols = {}

    def stmt(self, s):
        return '{}'.format(s)
    
    def assign_stmt(self, e1,op,e2):
        return '{} {} {}'.format(e1,op,e2)

    # def assign_op(self, op):
    #     return '{}'.format(op)

    # def assign_op(self, op1, op2):
    #     return '{}'.format(op1, op2)

    @v_args(inline=False)
    def assign_op(self, op):
        if len(op) == 1:
            return '{}'.format(*op)
        elif len(op) == 2:
            return '{}{}'.format(*op)

    def expr(self, a):
        return '{}'.format(a)


    # def unaryExpr(self, op, expr):
    #     return '({}){}'.format(op, expr)

parser = Lark.open('aixt_grammar.lark', start='stmt', rel_to=__file__, parser='lalr')


# aixt_to_c())


if __name__ == '__main__':
    tree = parser.parse('a *= 45')
    print('_'*60 + '\n')
    print(tree)
    print('_'*60 + '\n') 
    print(tree.pretty())
    print('_'*60 + '\n')
    print(aixt_to_c().transform(tree))
    print('_'*60 + '\n')