@for preproc in gen.c_preproc_cmds
@preproc
@end

@for cmd in gen.init_cmds
@cmd
@end

void setup() {
    @for def in gen.definitions
    @def
    @end
}

@for line in gen.out 
@line
@end

