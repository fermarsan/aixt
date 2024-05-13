int read(int channel) {
    system(CLEAR_SCREEN);
    printf(" Aixt virtual ADC input     ADC %ld : ", channel);
    scanf("%ld", &value__);
    return value__;
}