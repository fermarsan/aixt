
Expr = IfExpr | MatchExpr | CallExpr | ParExpr | InfixExpr | PrefixExpr | PostfixExpr | IndexExpr | CastExpr | ArrayInit | Literal | Ident | EnumVal | ComptimeSelector | EmptyExpr | UnsafeExpr | RangeExpr | SelectorExpr | ArrayDecompose | StructInit | NodeError;

Literal = StringLiteral | StringInterLiteral | CharLiteral | FloatLiteral | IntegerLiteral | BoolLiteral;

IfExpr = 'if' Expr Block [ 'else' ( IfExpr | Block ) ];
MatchExpr = 'match' Expr '{' { MatchBranch } '}';
MatchBranch = Expr { ',' Expr } Block;
CallExpr = Expr '(' [ Expr { ',' Expr } ] ')';
ParExpr = '(' Expr ')';
InfixExpr = Expr InfixOp Expr;
PrefixExpr = PrefixOp Expr;
PostfixExpr = Expr PostfixOp;
IndexExpr = Expr '[' Expr ']';
CastExpr = Type '(' Expr ')'; (* Simplified V cast syntax *)
ArrayInit = '[' [ Expr { ',' Expr } ] ']';
Ident = Letter { Letter | Digit | '_' };
StringLiteral = '"' { AnyChar - '"' } '"';
StringInterLiteral = "'" { AnyChar - "'" } "'";
CharLiteral = '`' ( AnyChar - '`' ) '`';
FloatLiteral = Digit { Digit } '.' Digit { Digit };
IntegerLiteral = Digit { Digit };
BoolLiteral = 'true' | 'false';
EnumVal = '.' Ident;
ComptimeSelector = '$' Ident;
EmptyExpr = ; (* Represents an empty expression placeholder *)
UnsafeExpr = 'unsafe' Block;
RangeExpr = Expr '..' Expr;
SelectorExpr = Expr '.' Ident;
ArrayDecompose = '[' { Ident } ']';
StructInit = Ident '{' { Ident ':' Expr } '}';
NodeError = ; (* Represents a parsing error in the AST *)

(* Basic Definitions (implementation-dependent) *)
Block = '{' (* Statements *) '}';
InfixOp = '+' | '-' | '*' | '/' | '%' | '==' | '!=' | '<' | '<=' | '>' | '>=' | '&&' | '||' | '&' | '|' | '^' | '<<' | '>>';
PrefixOp = '!' | '-' | '+' | '++' | '--' | '&';
PostfixOp = '++' | '--';
Letter = 'a'..'z' | 'A'..'Z';
Digit = '0'..'9';
AnyChar = ? any character ?;
Type = Ident; (* Simplified type definition *)
