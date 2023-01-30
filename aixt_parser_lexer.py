from lark import Transformer, v_args

@v_args(inline=True)
class aixt_transformer(Transformer):
    def __init__(self):
        self.symbols = {}

    @v_args(inline=False)
    def source_file(self, sf):
        o = ''
        for s in sf:
            o += s
        return o

    def stmt(self, st):
        return '{};'.format(st)
    
    def assign_stmt(self, ex1,op,ex2):
        return '{} {} {}'.format(ex1,op,ex2)

    @v_args(inline=False)
    def assign_op(self, op):
        if len(op) == 1:
            return '{}'.format(*op)     # "="
        elif len(op) == 2:
            return '{}{}'.format(*op)   # "+=", "<<=", etc.

    def expr(self, ex):
        return '{}'.format(ex)

    # def unaryExpr(self, op, expr):
    #     return '({}){}'.format(op, expr)

    @v_args(inline=False)
    def eos(self, eo):
        return '\n'   

