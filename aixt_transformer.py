# This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
#
# The MIT License (MIT)
# 
# Copyright (c) 2023 Fernando Martínez Santa

from lark import Transformer, v_args
from lark.lexer import Token
import yaml
import re

@v_args(inline=True)
class aixtTransformer(Transformer):
    def __init__(self):
        self.errStream = ''       #error stream
        self.outStream = ''      #output stream
        self.moduleStack = []   #stacks
        self.typeStack  = []
        self.exprStack  = []
        self.stmtStack  = []
        self.constStack = []
        self.topDecl    = []
        self.main = False
        # self.moduleDef = ''
        self.rangeStart = 0
        self.rangeEnd = 0
        self.temp_vars = []
        
        
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
            s = '//NXC ' if self.setup['nxc'] else '//C '
            s += 'code generated from the Aixt source'
            s += '\n//Device = ' + self.setup['device'] 
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
            s = re.sub('";','"',s)
            s = re.sub("; ;",";",s)
            s = re.sub(";;",";",s)
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
                        s += '#include "./{}/{}__{}.h"\n'.format(ist[1], ist[1], ist[i])
        return s

    def global_decl(self, gl, lp, sl, rp):
        s = '{n'
        s += ';\n'.join(self.stmtStack) + ';'
        self.stmtStack.clear()
        return s + '\n'
        
    @v_args(inline=False)
    def fn_decl(self, fd):
        print('fn_decl:', fd)
        attribute = ''
        if fd[0].type == 'ATTRIB':
            attribute = fd.pop(0)
        fd.pop(0)   # ignores the FN keyword
        if fd[0] == 'main':
            self.main = True
        s = ''
        while True:
            s += fd.pop(0)
            if ')' in s:
                break
        print('fn_decl:', fd)    
        ret_val = fd[0] if '{' not in fd[0] else 'void'
        s += ' ' + fd[-1]   # "block"
        s = '{} {} {}'.format(attribute, ret_val, s)
        return s if s[0] != ' ' else s[1:]

    def attrib(self, lb,idf,rb):
        return Token(type='ATTRIB', value=str(idf))

    def fn_return(self, tn):
        return self.setup[tn]

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
        # print(sl)
        for t in sl:
            # if t != ';':
            #     self.stmtStack.append(t)
            self.stmtStack.append(t)
        return ''

    @v_args(inline=False)
    def stmt(self, stm):
        s = ''
        for st in stm:
            s += st
        return s

    def decl_assign_stmt(self, el1,op,el2):
        s = ''
        for e1,e2 in zip(el1,el2):
            if eval(e2.type)[1] == 'mutex':
                self.topDecl.insert(0, 'mutex ' + e2)
            if eval(e2.type)[1] == 'char []':
                s += 'string {}' if self.setup['nxc'] else 'const char {} []'
                s += '= {};'
                s = s.format(e1, e2)       
            else:
                s += '{} {} = {}; '.format(eval(e2.type)[1], e1, e2) 
        return s

    def simple_assign_stmt(self, el1,op,el2):
        s = ''   
        for e1,e2 in zip(el1,el2):
            s += '{} {} {}; '.format(e1, op ,e2)
        return s

    def array_init(self, el1,ap,lb,el2,rb):
        # print('{}\n{}\n{}'.format('#'*40, self.exprStack, '#'*40))
        s = '{} {}[] = {{'.format(eval(el2[0].type)[1], el1[0]) 
        for e in el2:
            s += e + ', '
        return s[:-2] + '};'

    def inc_dec_stmt(self, ex,op):
        return '{}{}'.format(ex, op)

    def return_stmt(self, ret, ex): 
        return 'return ' + ex

    def for_bare_stmt(self, fk,bl):
        return 'while(true) {}'.format(bl)

    def for_cond_stmt(self, fk,ex,bl):
        return 'while({}) {}'.format(ex,bl)

    def for_c_stmt(self, fk,as1,sc1,ex,sc2,as2,bl):
        return 'for({}; {}; {}){}'.format(as1,ex,as2,bl)

    def for_in_stmt(self, fk,idf,ik,re,bl):
        print('for_in_stmt:', re)
        return 'for(int {}={}; {}<{}; {}++){}'.format( idf, re[0], 
                                                       idf, re[1], 
                                                       idf, bl )

    def for_in_arr_stmt(self, fk,id1,ik,id2,bl):
        if '__i__' not in self.temp_vars:
            self.temp_vars.append('__i__')
            self.topDecl.append('int __i__;')
        block = bl.replace(id1, '{}[__i__]'.format(id2)) 
        len_func = 'ArrayLen' if self.setup['nxc'] else 'sizeof'
        s = 'for(__i__ = 0; __i__ < {}({}); __i__++){}'.format(len_func, 
                                                               id2, 
                                                               block)  
        return s                                

    def block(self, lb,bl,rb):
        s = '{\n'
        s += ';\n'.join(self.stmtStack) + ';'
        self.stmtStack.clear()
        return s + '\n}'

    @v_args(inline=False)
    def simple_decl_list(self, sds):
        s = ''
        for sd in sds:
            s += ', ' if sd == ',' else '{} {}'.format(eval(sd.type)[1], sd)
        return s

    def simple_decl(self, ex,tn):
        return Token(type="['{}','{}']".format(ex.type, self.setup[tn]), 
                     value=str(ex))

    @v_args(inline=False)
    def expr_list(self, el):
        a = []
        for e in el:
            if e != ',':    
                # self.exprStack.append(e)
                a.append(e)
        print('expr_list: ', a)
        return a

    @v_args(inline=False)
    def expr(self, ex):
        print('expr:', ex)
        s = ''
        for e in ex:
            s += e
        return Token(type=e.type, value=s)

    def index_expr(self, ex1,lb,ex2,rb):
        # print('index_expr:', '{}[{}]'.format(ex1, ex2))
        return Token(type=ex1.type, value='{}[{}]'.format(ex1, ex2) )

    def call_expr(self, idt,lb,el,rb): 
        if '.' in idt:  # module's method
            module, method = str(idt).split('.')
            if module in self.moduleStack:
                s = method + "("
        else:           # standalone function
            s = idt + "("
        for e in el:
            s += e + ", "
        # print('call_expr: ' + s[:-2] + ")")
        return s[:-2] + ")"

    def cast_expr(self, tn,lp,ex,rp):
        new_type = eval(ex.type)
        new_type[1] = self.setup[tn]
        print('cast_expr:', str(new_type))
        return Token(type=str(new_type), value=str(ex))
    
    def range_expr(self, ex1,dts,ex2):
        return (ex1, ex2)

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
        return Token(type="['{}','{}']".format(sl.type, 'char []'), value=s)

    def char_literal(self, cl):
        s = cl.replace('`',"'") #changes the quotation marks
        return Token(type="['{}','{}']".format(cl.type, 'char'), value=s)

    def bool_literal(self, bl):
        return Token(type="['{}','{}']".format(bl.type, 'bool'), value=str(bl))

    def float_literal(self, fl):
        s = str(eval(fl.replace('_', ''))) # removes "_". "eval" adds missing zeros at both sides of "."
        return Token(type="['{}','{}']".format(fl.type, self.setup['default_float']),
                     value=s)     
        
    def integer_literal(self, il):
        s = il.replace('_', '') # removes"_"
        return Token(type="['{}','{}']".format(il.type, self.setup['default_int']),
                     value=s)