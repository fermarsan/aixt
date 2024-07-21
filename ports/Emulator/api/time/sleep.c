inline void sleep_s(int ts) {
    #if defined(__linux) || defined(linux)
        return sleep(ts)
    #else
        return Sleep(ts*1000)     
    #endif
}
