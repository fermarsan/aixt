for( int @index_name = 0; @index_name < @len; @index_name ++ ) {
@var_type @var_name = @{init_or_name}[@{index_name}];
@for stmt in stmts 
@stmt 
@end
@mut_var_write
}