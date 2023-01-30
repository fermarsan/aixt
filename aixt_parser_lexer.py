from lark import Transformer, v_args

@v_args(inline=True)
class aixt_transformer(Transformer):
    def __init__(self):
        self.symbols = {}

    def stmt(self, s):
        return '{};'.format(s)
    
    def assign_stmt(self, e1,op,e2):
        return '{} {} {}'.format(e1,op,e2)

    @v_args(inline=False)
    def assign_op(self, op):
        if len(op) == 1:
            return '{}'.format(*op)     # "="
        elif len(op) == 2:
            return '{}{}'.format(*op)   # "+=", "<<=", etc.

    def expr(self, a):
        return '{}'.format(a)


    # def unaryExpr(self, op, expr):
    #     return '({}){}'.format(op, expr)
