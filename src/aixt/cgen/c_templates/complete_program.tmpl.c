@for preproc in gen.c_preproc_cmds
@preproc
@end

@for def in gen.definitions
@def
@end

@for cmd in gen.init_cmds
@cmd
@end

@for line in gen.out 
@line
@end

@attrs @ret_val main(@params) {
    @for stmt in stmts 
        @stmt 
    @end
}