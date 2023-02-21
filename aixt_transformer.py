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
        self.moduleStack = []   #stacks
        self.typeStack  = []
        self.exprStack  = []
        self.stmtStack  = []
        self.constStack = []
        self.topDecl    = []
        self.main = False
        # self.includes = ''
        # self.moduleDef = ''
        # self.preprocessor = ''
        self.rangeStart = 0
        self.rangeEnd = 0
        
        
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
            
            s += ';\n'.join(self.topDecl) + ';\n' if len(self.topDecl) != 0 else ''    #top level declarations      
            s += '\n'
            if not self.main:       #adds the main function structure if not exist
                s += 'task' if self.setup['nxc'] else ''
                s += self.setup['main_ret_type'] if self.setup['main_ret_type'] != 'none' else ''
                s += ' main('
                s += self.setup['main_params'] if self.setup['main_params'] != 'none' else ''
                s += ') {' 
                for i in self.setup['initialization']:
                    s += i + '\n' if i != '' else ''
                s += '\n\n'
                s += ';\n'.join(self.stmtStack) + ';\n' if len(self.stmtStack) != 0 else ''
                s += 'return 0;\n}' if self.setup['main_ret_type'] == 'int' else '\n}' 
            else:
                s += ';\n'.join(self.stmtStack) + ';' if len(self.stmtStack) != 0 else ''
            s = re.sub(";\n;",";\n",s)  #removes unnecessary semicolons
            s = re.sub("};","}",s)
            s = re.sub("\n;","\n",s)
            s = re.sub("; ;",";",s)
            s = re.sub('";','"',s)
            outText.write(s)  

    @v_args(inline=False)
    def source_file(self, sf):
        s = ';\n'.join(self.topDecl) + ';\n' if len(self.topDecl) != 0 else ''
        s += ';\n'.join(self.stmtStack) + ';' if len(self.stmtStack) != 0 else ''
        return s

    @v_args(inline=False)
    def top_decl_list(self, tdl):
        return ''

    def top_decl(self, td):
        self.topDecl.append(td) 
        return ''

    @v_args(inline=False)
    def import_stmt(self, ist): 
        # print(ist)
        if ist[1] in self.setup['api_modules']:
            self.moduleStack.append(ist[1])
            if len(ist) == 2:
                s = '#include "./{}.h"'.format(ist[1])
            else:
                s = ''
                for i in range(3,len(ist)):
                    if ist[i] not in ['}', ',']:
                        s += '#include "./{}/{}.h"\n'.format(ist[1], ist[i])
        return s
                        
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

    @v_args(inline=False)
    def const_decl(self, cd):
        s = 'const {} {};\n'.format( self.typeStack.pop(0),
                                     self.constStack.pop(0))
        for i in range(len(self.constStack)):
            s += 'const {} {};\n'.format( self.typeStack.pop(0),
                                       self.constStack.pop(0))
        return s

    def const_item(self, idf,eq,ex):
        self.constStack.append(idf + ' = ' + ex) 
        return ''

    @v_args(inline=False)
    def stmt_list(self, sl):
        print(sl)
        for t in sl:
            # if t != ';':
            #     self.stmtStack.append(t)
            self.stmtStack.append(t)
        return ''

    @v_args(inline=False)
    def stmt(self, st):
        # print(st)
        s = st[0]
        for i in range(1,len(st)):
            s += ' ' + st[i]
        return s

    def decl_assign_stmt(self, ex1,op,ex2):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        s = ''
        for i in range(len(self.exprStack)):
            if self.typeStack[0] == 'mutex':
                self.topDecl.insert(0, 'mutex ' + self.identStack.pop(0))
                self.exprStack.pop()
            elif self.typeStack[0] == 'char []':
                if self.setup['nxc']:
                    s += 'string {} = {}; '.format(self.identStack.pop(0), self.exprStack.pop(0))    
                else:     
                    s += 'const char {} [] = {}; '.format(self.identStack.pop(0), self.exprStack.pop(0))  
            else:
                # print('{}\n{}\n{}'.format('#'*30,self.typeStack[0],'#'*30)) 
                s += '{} {} = {}; '.format(self.typeStack[0], self.identStack.pop(0), self.exprStack.pop(0)) 
            self.typeStack.pop(0)
        # print(s)
        return s

    def simple_assign_stmt(self, el1,op,el2):
        # print(self.typeStack);print(self.identStack);print(self.exprStack)
        s = ''
        half_len = len(self.exprStack) // 2
        for i in range(half_len):
            s += '{} {} {}'.format(self.exprStack[i], op ,self.exprStack[i+half_len])
            # s += ';\t' if i <= n-2 else ''  # intermediate semicolons
        self.exprStack.clear();     
        return s

    def array_init(self, il,ap,lb,el,rb):
        # print('{}\n{}\n{}'.format('#'*40, self.exprStack, '#'*40))
        s = '{} {}[] = {{'.format(self.typeStack[0], self.identStack.pop(0)) 
        for i in range(len(self.exprStack)):
            s += self.exprStack.pop(0) + ', '
        self.typeStack.clear()
        return s[:-2] + '};'

    def inc_dec_stmt(self, ex,op):
        return ex + op

    def return_stmt(self, ret, ex): 
        return 'return ' + ex

    def for_bare_stmt(self, fk,bl):
        return 'while(true)' + bl

    def for_cond_stmt(self, fk,ex,bl):
        return 'while({}) {}'.format(ex,bl)

    def for_c_stmt(self, fk,as1,sc1,ex,sc2,as2,bl):
        return 'for({}; {}; {}){}'.format(as1,ex,as2,bl)

    def for_in_stmt(self, fk,idf,ik,re,bl):
        return 'for(int {}={}; {}<{}; {}++){}'.format( idf, self.rangeStart, 
                                                       idf, self.rangeEnd, 
                                                       idf, bl )
           
    @v_args(inline=False)
    def ident_list(self, il):
        for i in il:
            if i != ',':
                self.identStack.append(i)
        # print('ident_list: ', self.identStack)
        return ''

    def block(self, lb,bl,rb):
        # print(self.identStack)
        s = '{\n'
        s += ';\n'.join(self.stmtStack) + ';'
        self.stmtStack.clear()
        return s + '\n}'

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
    def expr_list(self, el):
        for e in el:
            if e != ',':    
                self.exprStack.append(e)
        print('expr_list: ', self.exprStack)
        return ''

    @v_args(inline=False)
    def expr(self, ex):
        print(ex)
        s = ''
        for e in ex:
            s += e
        return s

    def index_expr(self, id,lb,li,rb):
        return '{}[{}]'.format(id,li)

    def call_expr(self, idt,lb,el,rb):
        if '.' in idt:  # module's method
            module, method = str(idt).split('.')
            if module in self.moduleStack:
                s = method + "("
        else:           # standalone function
            s = idt + "("
        for i in range(len(self.exprStack)):
            s += self.exprStack.pop(0) + ", "
        self.typeStack.clear()
        return s[:-2] + ")"

    def cast_expr(self, tn,lp,ex,rp):
        self.typeStack[-1] = self.setup[tn]
        # print('{}\n{}\n{}'.format('#'*30,self.typeStack,'#'*30))
        return ex

    def range_expr(self, ex1,dts,ex2):
        self.rangeStart = ex1
        self.rangeEnd = ex2
        return ''

    @v_args(inline=False)
    def if_expr(self, ie):
        s = 'if({}){}'.format(ie[1], ie[2]) # "if" + expr + block
        n = len(ie)
        if n > 3:
            for i in range(3,n):
                s += 'else ' if ie[i] == 'else' else ie[i]
        return s

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