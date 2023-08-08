/* as in V, all variables in Aixt are local.
   However,is it possible to make an exception
   using the reserved word "__global" */

__global (
	x = int(3)
	y  int
)

mut a := 1
y = 5

a = x + y + a

