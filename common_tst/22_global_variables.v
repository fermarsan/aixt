/* as in V, all variables in Aixt are local.
   However,is it possible to make an exception
   using the reserved word "__global" */

__global (
	x = int(3)
	y = int(4)
)

mut a := 1

a = x + y + a

