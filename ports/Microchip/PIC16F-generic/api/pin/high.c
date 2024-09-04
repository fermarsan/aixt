#define pin__high(name) \
    *(&PORTA + (name >> 3))  |=  0x01 << (name - ((name >> 3) << 3)) 
 // *(&PORTA + (name / 8) )  |=   0x01 << (name % 8)
 // compute port            ...   compute bit