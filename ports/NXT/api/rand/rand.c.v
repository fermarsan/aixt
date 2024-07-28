module rand

//cstdlib.c
@[inline] srand() { return C.srand() }
@[inline] rand() { return C.rand() }
@[inline] random() { return C.Random() }
@[inline] sys_random_number() { return C.SysRandomNumber() }
@[inline] sys_random_ex() { return C.SysRandomEx() }

