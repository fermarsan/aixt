#if defined(__linux) || defined(linux)
#define CLEAR_SCREEN    "clear" // for Linux
#else
#define CLEAR_SCREEN    "cls"   // for Windows
#endif