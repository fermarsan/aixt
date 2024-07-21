inline void sleep_ms(int tms) {
    #if defined(__linux) || defined(linux)
        return usleep(tms*1000)
    #else
        return Sleep(tms)
    #endif
}