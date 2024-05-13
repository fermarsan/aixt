module array

// Constants for use with the NXC ArrayOp function and the NBC arrop statement. 
#define 	array__op_sum    	OPARR_SUM    
#define 	array__op_mean   	OPARR_MEAN   
#define 	array__op_sumsqr 	OPARR_SUMSQR 
#define 	array__op_std    	OPARR_STD    
#define 	array__op_min    	OPARR_MIN    
#define 	array__op_max    	OPARR_MAX    
#define 	array__op_sort   	OPARR_SORT   
#define 	array__op_toupper	OPARR_TOUPPER
#define 	array__op_tolower	OPARR_TOLOWER

// Functions for use with NXC array types.
#define		array__build(...) 		ArrayBuild(__VA_ARGS__) 
#define		array__len(...) 		ArrayLen(__VA_ARGS__) 
#define		array__init(...) 		ArrayInit(__VA_ARGS__) 
#define		array__subset(...) 		ArraySubset(__VA_ARGS__) 
#define		array__index(...) 		ArrayIndex(__VA_ARGS__) 
#define		array__replace(...) 	ArrayReplace(__VA_ARGS__) 
#define		array__sum(...) 		ArraySum(__VA_ARGS__) 
#define		array__mean(...) 		ArrayMean(__VA_ARGS__) 
#define		array__sum_sqr(...) 	ArraySumSqr(__VA_ARGS__) 
#define		array__std(...) 		ArrayStd(__VA_ARGS__) 
#define		array__min(...) 		ArrayMin(__VA_ARGS__) 
#define		array__max(...) 		ArrayMax(__VA_ARGS__) 
#define		array__sort(...) 		ArraySort(__VA_ARGS__) 
#define		array__op(...)			ArrayOp(__VA_ARGS__)