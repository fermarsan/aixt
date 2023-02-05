# This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
#
# The MIT License (MIT)
# 
# Copyright (c) 2023 Fernando Martínez Santa

from lark import Transformer, v_args
import yaml
import re

@v_args(inline=True)
class aixtTransformer(Transformer):
    def __init__(self):
        # self.symbols = {}
        self.errStream = ''       #error stream
        self.outStream = ''      #output stream
        # self.exType = ''
        # self.lineno = 1
        self.identStack = []   #stacks
        self.typeStack = []
        self.exprStack = []
        self.main = False
        # self.includes = ''
        # self.moduleDef = ''
        # self.preprocessor = ''
        self.topDecl = ''
        
        with open(r'../setup.yaml','r') as setup_file:
            self.setup = yaml.load(setup_file, Loader=yaml.FullLoader)
            # for s in self.setup:
            #     print(s)

    def saveOutput(self, name):

        if not self.setup['nxc']:
            with open('../settings.h','w') as outSettings:   #settings file creation
                s = '#ifndef _SETTINGS_H_\n#define _SETTINGS_H_\n\n'
                for h in self.setup['headers']:             #append the header files
                    s += '#include ' + h + '\n'
                s += '\n'
                for m in self.setup['macros']:              #append the macros
                    s += '#define ' + m + '\n'
                s += '\n'
                for c in self.setup['configuration']:       #append the configuration lines
                    s += self.setup['config_operator'] + ' ' + c + '\n'    
                s += '\n#endif  //_SETTINGS_H_'
                outSettings.write(s) 

        with open(name,'w') as outText:
            s = '//Generated '
            s += 'NXC' if self.setup['nxc'] else 'C'
            s += ' file for:\n//Device = ' + self.setup['device'] 
            s += '\n//Board = ' + self.setup['board'] + '\n\n'
            s += '#include "settings.h"\n\n' if not self.setup['nxc'] else ''
            # s += self.preprocessor + '\n'        #user defined C preprocessor commands
            # s += '// ' + self.moduleDef + '\n'  #module definition
            # s += self.includes + '\n'            #user defined headers files
            s += self.topDecl + '\n\n'           #top level declarations      
            if not self.main:       #adds the main function structure if not exist
                s += 'task' if self.setup['nxc'] else ''
                s += self.setup['main_ret_type'] if self.setup['main_ret_type'] != 'none' else ''
                s += ' main('
                s += self.setup['main_params'] if self.setup['main_params'] != 'none' else ''
                s += ') {' 
                for i in self.setup['initialization']:
                    s += i + '\n' if i != '' else ''
                s += ('\n' + self.outStream).replace('\n','\n\t')
                s += 'return 0;\n}' if self.setup['main_ret_type'] == 'int' else '\n}' 
            else:
                s += self.outStream
            s = re.sub("(\t)*\n(\t)*\n((\t)*\n)+","\n\n",s) # removes sequences of more than 3 '\n'
            outText.write(s)  

    @v_args(inline=False)
    def source_file(self, sf):
        self.outStream = ''
        for line in sf:
            self.outStream += line
        return self.outStream

    def top_decl(self, td):
        self.topDecl += td 
        self.topDecl += ';\n\n' if self.topDecl[-1] != '}' else ''
        return ''

    @v_args(inline=False)
    def stmt(self, st):
        s = ''
        for e in st:
            s += e + ' '
        if s[-1] == '}':
            return s[:-1]
        else:
            return s[:-1] + ';'
    
    # def return_stmt(self, rs):
    #     return 

    @v_args(inline=False)
    def fn_decl(self, fd):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        if 'main' in fd[1] + fd[2] + fd[3]:
            self.main = True
        s = ''
        n = len(fd)
        for i in range(1,n):    # avoids the attribute
            s += fd[i] if fd[i] != 'fn' else ''
            if fd[i] == ')':
                break
        s = self.typeStack.pop(0) + ' ' + s if fd[-2] != ')' else s    # return value
        s += fd[-1] # "block"
        s = s[1:] if s[0] == '\n' else s    # removes the initial "\n"
        if fd[0] == '[inline]':
            return 'inline ' + s
        elif fd[0] == '[task]':
            return 'task ' + s
        else:
            return s

    def fn_return(self, fr):
        self.typeStack.append(self.setup[fr])
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        return ''

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
            s += self.identStack.pop(0) + ' ' + op + ' ' + self.exprStack.pop(0)
            s += ';\t' if i <= n-2 else ''  # intermediate semicolons
        # self.typeStack.clear();     
        return s

    @v_args(inline=False)
    def const_decl(self, cd):
        s = ''
        for c in cd:
            if c != 'const' and c != '(' and c != '\n' and c != ';' and c != ')':
                s += 'const ' + self.typeStack.pop(0) + ' ' + c + ';'
                s += '\n' if cd[-1] == ')' else ''
        return s[:-2]

    def const_spec(self, id,eq,ex):
        return id + ' = ' + ex 

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

    @v_args(inline=False)
    def call_expr(self, ce):
        s = ce[0] + "("  #IDENT
        for i in range(len(self.exprStack)):
            s += self.exprStack.pop(0) + ", "
        return s[:-2] + ")"

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