#if defined(__linux) || defined(linux)
#define clear_screen    "clear"
#else
#define clear_screen    "cls"
#endif