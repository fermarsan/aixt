void sleep_ms(int tms) {
    #if defined(__linux) || defined(linux)
        usleep(tms*1000);
    #else
        Sleep(tms);
    #endif
}