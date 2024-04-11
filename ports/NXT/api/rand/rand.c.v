module rand

//cstdlib.c
#define     rand__srand(...)              srand(__VA_ARGS__)
#define     rand__rand()               	  rand()
#define     rand__random(...)             Random(__VA_ARGS__)
#define     rand__sys_random_number(...)  SysRandomNumber(__VA_ARGS__)
#define     rand__sys_random_ex(...)      SysRandomEx(__VA_ARGS__)


fn init() {

}