# This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
#
# The MIT License (MIT)
# 
# Copyright (c) 2023 Fernando Martínez Santa

from lark import Transformer, v_args
import yaml

@v_args(inline=True)
class aixtTransformer(Transformer):
    def __init__(self):
        self.symbols = {}
        self.error_s = ''       #error stream
        self.output_s = ''      #output stream
        self.exType = ''
        self.lineno = 1

        self.identStack = []   #stacks
        self.typeStack = []
        # self.valueStack = []
        self.exprStack = []

        self.attrib = ''
        self.paramList = ''
        self.fnReturn = ''
    
        self.main = False
        self.includes = ''
        self.moduleDef = ''
        self.preprocessor = ''
        self.topLevel = ''
        
        with open(r'./setup.yaml','r') as setup_file:
            self.setup = yaml.load(setup_file, Loader=yaml.FullLoader)
            # for s in self.setup:
            #     print(s)

    @v_args(inline=False)
    def source_file(self, sf):
        output = ''
        for line in sf:
            output += line
        return output

    def stmt(self, st):
        if st[-1] == '}':
            return st
        else:
            return st + ';'
    
    @v_args(inline=False)
    def fn_decl(self, fd):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        s = ''
        # attribute = 'inline' if fd[0] == '[inline]' else ''
        n = len(fd)
        for i in range(n):
            s += fd[i] if fd[i] != 'fn' else ''
            # print('fd:',s)
            if fd[i] == ')':
                break
        s = self.typeStack.pop(0) + ' ' + s if fd[-2] != ')' else ''    # return value
        s += fd[-1] # "block"
        # print(s)
        return s

    def fn_return(self, fr):
        self.typeStack.append(fr)
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        return ''

    # @v_args(inline=False)
    # def attrib(self, a):
    #     print(a)
    #     self.attrib = a  # IDENT
    #     return ''

    def decl_assign_stmt(self, ex1,op,ex2):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        s = ''
        n = len(self.exprStack)
        for i in range(n):
            if self.typeStack[0] == 'char []':
                s += 'const char ' + self.identStack.pop(0) + '[] = ' 
            else: 
                s += self.typeStack[0] + ' ' + self.identStack.pop(0) + ' = ' 
            s += self.exprStack.pop(0)#self.valueStack.pop(0)
            s += ';\t' if i <= n-2 else ''  # intermediate semicolons
            self.typeStack.pop(0)
        return s

    def simple_assign_stmt(self, ex1,op,ex2):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        s = ''
        n = len(self.identStack)
        for i in range(n):
            s += self.identStack.pop(0) + ' = ' + self.exprStack.pop(0)
            s += ';\t' if i <= n-2 else ''  # intermediate semicolons
        # self.typeStack.clear();     
        return s

    @v_args(inline=False)
    def block(self, bl):
        s = ''
        for b in bl:
            s += b
        s = s.replace('\n','\n\t')
        return s.replace('\t}','}')

    @v_args(inline=False)
    def param_list(self, pl):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        s = ''
        n = len(self.exprStack)
        for i in range(n):
            s += self.typeStack.pop(0) + ' ' + self.exprStack.pop(0)
            s += ', ' if i <= n-2 else ''   # intermediate commas
        # print('param_list: ', s)
        return s

    def param(self, ex,tn):
        self.typeStack.append(self.setup[tn])
        self.exprStack.append(ex)
        return ''

    @v_args(inline=False)
    def stmt_list(self, sl):
        s = ''
        for t in sl:
            s += t
        return s

    @v_args(inline=False)
    def expr_list(self, el):
        for e in el:
            if e != ',':
                self.exprStack.append(e)
        # print('expr_list: ', self.exprStack)
        return ''

    @v_args(inline=False)
    def ident_list(self, il):
        for i in il:
            if i != ',':
                self.identStack.append(i)
        # print('ident_list: ', self.identStack)
        return ''

    @v_args(inline=False)
    def expr(self, ex):
        s = ''
        for e in ex:
            s += e
        return s

    def conversion(self, tn,lp,ex,rp):
        self.typeStack[-1] = self.setup[tn]
        return ex

    def string_literal(self, sl):
        s = sl.replace("'",'"') #changes the quotation marks
        self.typeStack.append('char []')
        return s

    def char_literal(self, cl):
        s = cl.replace('`',"'") #changes the quotation marks
        self.typeStack.append('char')
        return s

    def bool_literal(self, bl):
        self.typeStack.append('bool')
        return bl

    def float_literal(self, fl):
        s = str(eval(fl.replace('_', ''))) # removes "_". "eval" adds missing zeros at both sides of "."
        self.typeStack.append(self.setup['default_float'])
        return s     
        
    def integer_literal(self, il):
        s = il.replace('_', '') # removes"_"
        self.typeStack.append(self.setup['default_int'])
        return s

    def eos(self, eo):
        return '\n'   

