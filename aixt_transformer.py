# This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
#
# The MIT License (MIT)
# 
# Copyright (c) 2023 Fernando Martínez Santa

from lark import Transformer, v_args
from lark.lexer import Token
import yaml

@v_args(inline=True)
class aixtTransformer(Transformer):
    def __init__(self):
        self.moduleStack = []
        self.stmtStack = []
        self.topDecl = []
        self.tempVars = []
        self.main = False
        # self.moduleDef = ''
        self.transpiled = ''
        self.identLevel = 1
        
        with open(r'../setup.yaml','r') as setup_file:
            self.setup = yaml.load(setup_file, Loader=yaml.FullLoader)

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
            s = '// Aixt project ('
            s += 'NXC ' if self.setup['nxc'] else 'C '
            s += 'generated code)\n// Device = {}\n// Board = {}\n\n' 
            s = s.format(self.setup['device'], self.setup['board'])
            s += '#include "settings.h"\n\n' if not self.setup['nxc'] else ''
            # s += '// ' + self.moduleDef + '\n'  #module definition
            # s += self.includes + '\n'            #user defined headers files
            for td in self.topDecl:
                s += '{}\n'.format(td) #top level declarations      
            if not self.main:       #adds the main function structure if not exist
                s += 'task' if self.setup['nxc'] else ''
                s += self.setup['main_ret_type'] if self.setup['main_ret_type'] != 'none' else ''
                s += ' main('
                s += self.setup['main_params'] if self.setup['main_params'] != 'none' else ''
                s += ') {' 
                for i in self.setup['initialization']:
                    s += i + '\n' if i != '' else ''
                s += '\n\t'
                s += self.transpiled.replace('\n','\n\t')[:-1]
                s += 'return 0;\n}' if self.setup['main_ret_type'] == 'int' else '}' 
            else:
                s += self.transpiled
            s = s.replace('};','}')
            outText.write(s)  

    @v_args(inline=False)
    def source_file(self, sf):
        print('source_file:', sf) # print('source_file:', self.topDecl)
        s = ''
        for ds in sf:
            for st in ds:
                s += '{};\n'.format(st) if st != '' else ''
        self.transpiled = s 
        
    @v_args(inline=False)
    def top_decl_list(self, tdl):
        return ''

    def top_decl(self, td):
        self.topDecl.append(td) 
        return ''

    @v_args(inline=False)
    def import_stmt(self, ist):
        s = ''
        if ist[1] in self.setup['api_modules']:
            self.moduleStack.append(ist[1])
            if len(ist) == 2:
                s = '#include "./{}.h"'.format(ist[1])
            else:
                s = ''
                for i in range(3,len(ist)):
                    if ist[i] not in ('}', ','):
                        s += '#include "./{}/{}__{}.h"\n'.format(ist[1], ist[1], ist[i])
        return s

    def global_decl(self, gl, lp, sl, rp):
        s = '\n'
        for st in sl:
            s += '{};\n'.format(st)
        return s + '\n'
        
    @v_args(inline=False)
    def fn_decl(self, fd):
        # print('fn_decl:', fd)
        s = ''
        attribute = fd.pop(0) if fd[0].type == 'ATTRIB' else ''
        fd.pop(0)   # ignores the FN keyword
        if fd[0] == 'main':
            self.main = True
            while True:
                s += fd.pop(0)
                if ')' in s:
                    break
            if self.setup['nxc']:
                attribute = 'task'   
                ret_val = ''   
            else:
                ret_val = fd[0] if '{' not in fd[0] else 'void'
        else:
            while True:
                s += fd.pop(0)
                if ')' in s:
                    break
            if self.setup['nxc'] and attribute == 'task': 
                ret_val = ''   
            else:
                ret_val = fd[0] if '{' not in fd[0] else 'void'
        s += ' ' + fd[-1]   # "block"
        s = '{} {} {}'.format(attribute, ret_val, s)
        return s if s[0] != ' ' else s[1:]  #---REVISAR---

    def attrib(self, lb,idf,rb):
        return Token(type='ATTRIB', value=idf)

    def fn_return(self, tn):
        return self.setup[tn]

    @v_args(inline=False)
    def const_decl(self, cd):
        cd.pop(0)   # CONST keyword
        s = ''
        for c in cd:
            # print('const_decl:', c.type)
            if c.type not in ('LPAR', 'RPAR'):
                s += 'const {} {};\n'.format(eval(c.type)[1], c.value)  
        return s

    def const_item(self, idf,eq,ex):
        # print('const_item:', idf, ex)
        return Token(type=ex.type, value='{} = {}'.format(idf, ex))

    @v_args(inline=False)
    def stmt_list(self, sl):
        a = []
        for t in sl:
            if t != ';':
                a.append(t)
        # print('stmt_list:', a)
        return a

    @v_args(inline=False)
    def stmt(self, stm):
        s = ''
        for st in stm:
            s += st
        return s

    def decl_assign_stmt(self, el1,op,el2):
        s = ''
        mutex = False
        for e1,e2 in zip(el1,el2):
            if eval(e2.type)[1] == 'mutex':
                mutex = True
                self.topDecl.insert(0, 'mutex {};'.format(e1))
            elif eval(e2.type)[1] == 'char []':
                s += 'string {}' if self.setup['nxc'] else 'const char {}[]'
                s += ' = {}; '
                s = s.format(e1, e2)  
                # print('decl_assign_stmt:', e1,e2)     
            else:
                s += '{} {} = {}; '.format(eval(e2.type)[1], e1, e2) 
        return '' if mutex else s[:-2]

    def simple_assign_stmt(self, el1,op,el2):
        s = ''   
        for e1,e2 in zip(el1,el2):
            s += '{} {} {}; '.format(e1, op ,e2)
        return s[:-2]

    def array_init(self, el1,ap,lb,el2,rb):
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
        # print('for_in_stmt:', re)
        return 'for(int {}={}; {}<{}; {}++){}'.format( idf, re[0], idf, 
                                                       re[1], idf, bl )

    def for_in_arr_stmt(self, fk,id1,ik,id2,bl):
        if '__i' not in self.tempVars:
            self.tempVars.append('__i')
            self.topDecl.append('int __i;')
        block = bl.replace(id1, '{}[__i]'.format(id2)) 
        len_func = 'ArrayLen' if self.setup['nxc'] else 'sizeof'
        s = 'for(__i = 0; __i < {}({}); __i++){}'.format(len_func, 
                                                         id2, 
                                                         block)
        return s

    def block(self, lb,sl,rb):
        # print('block:', sl)
        s = '{\n'
        for st in sl:
            s += '{}{};\n'.format('\t'*self.identLevel, st) if sl != '' else ''
        return '{}{}}}'.format(s, '\t'*(self.identLevel-1))   
              
    @v_args(inline=False)
    def simple_decl_list(self, sds):
        s = ''
        for sd in sds:
            s += ', ' if sd == ',' else '{} {}'.format(eval(sd.type)[1], sd)
        return s

    def simple_decl(self, ex,tn):
        return Token(type="['{}','{}']".format(ex.type, self.setup[tn]), 
                     value=ex)

    @v_args(inline=False)
    def expr_list(self, el):
        a = []
        for e in el:
            if e != ',':    
                a.append(e)
        # print('expr_list: ', a)
        return a

    @v_args(inline=False)
    def expr(self, ex):
        print('expr:', ex)
        s = ''
        for e in ex:
            s += e
        return Token(type=ex[0].type, value=s)

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
        print('cast_expr:', ex.type)
        new_type = eval(ex.type)
        new_type[1] = self.setup[tn]
        print('cast_expr:', str(new_type))
        return Token(type=str(new_type), value=ex)
    
    def par_expr(self, lp,ex,rp):
        return Token(type=ex.type, value=lp+ex+rp)
    
    def unary_expr(self, uo,ex):
        return Token(type=ex.type, value=uo+ex)
    

    def range_expr(self, ex1,dts,ex2):
        return (ex1, ex2)

    @v_args(inline=False)
    def if_expr(self, ie):
        s = 'if({}) {}'.format(ie[1], ie[2]) # "if" + expr + block
        n = len(ie)
        if n > 3:
            for i in range(3,n):
                s += 'else ' if ie[i] == 'else' else ie[i]
        return Token(type=ie[0].type, value=s)

    def string_literal(self, sl):
        s = sl.replace("'",'"') #changes the quotation marks
        # print('string_literal:', s)
        return Token(type="['{}','{}']".format(sl.type, 'char []'), value=s)

    def char_literal(self, cl):
        s = cl.replace('`',"'") #changes the quotation marks
        return Token(type="['{}','{}']".format(cl.type, 'char'), value=s)

    def bool_literal(self, bl):
        return Token(type="['{}','{}']".format(bl.type, 'bool'), value=bl)

    @v_args(inline=False)
    def float_literal(self, fl):
        s = ''.join(fl)
        s = str(eval(s.replace('_', ''))) # removes "_". "eval" adds missing zeros at both sides of "."
        return Token(type="['{}','{}']".format('float_literal',
                                               self.setup['default_float']),
                     value=s)     
        
    def integer_literal(self, il):
        s = il.replace('_', '') # removes"_"
        return Token(type="['{}','{}']".format(il.type, 
                                               self.setup['default_int']),
                     value=s)
    
    def assign_op(self, ao):
        return ao
    
    def binary_op(self, bo):
        return bo
    
    def rel_op(self, ro):
        return ro
    
    def mul_op(self, mo):
        return mo
    
    def add_op(self, ao):
        return ao
    
    def dots(self, dt):
        return dt
    
    @v_args(inline=False)
    def decimal(self, de):
        return ''.join(de)

    def lbrace(self, lb):
        self.identLevel += 1
        return lb
    
    def rbrace(self, rb):
        self.identLevel -= 1
        return rb