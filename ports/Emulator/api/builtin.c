#if defined(__linux) || defined(linux)
#define clear_screen    "clear" // for Linux
#else
#define clear_screen    "cls"   // for Windows
#endif