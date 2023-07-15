/* as in V, all variables in Aixt are local.
   However,is it possible to make an exception
   using the reserved word "__global" */

__global (
	x, y := 12, 45
)

a := 0

a = x + y

