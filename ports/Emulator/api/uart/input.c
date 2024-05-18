char *input(char *msg) {
    printf("\033[1;32m");	// print in green
    printf("%s ", msg);
    scanf("%s", __temp_str);
    return __temp_str;
}