void sleep_s(int ts) {
    #if defined(__linux) || defined(linux)
        sleep(ts);
    #else
        Sleep(ts*1000);     
    #endif
}
