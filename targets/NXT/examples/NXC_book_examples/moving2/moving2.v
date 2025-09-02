import array


mut aaa 	:= 0		
mut bbb 	:= 0		
mut ccc   	:= 0		
mut values	:= []int{len: 0}	


aaa = 10
bbb = 20 + 5
ccc = bbb
ccc /= 5 
ccc -= 5 
aaa = 10 * (ccc + 3)
array.init(values, 0, 10)
values[0] = aaa
values[1] = bbb
values[2] = aaa*bbb
values[3] = ccc

sum := int(array.sum[int](values, 0, 5))