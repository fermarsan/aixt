#define pin__low(name)  \
    *(&PORTA + (name >> 3))  &=  ~(0x01 << (name - ((name >> 3) << 3)))