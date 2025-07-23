@for ex in exprs
case @ex:
@end
{
@for stmt in stmts 
@stmt 
@end
break;
}