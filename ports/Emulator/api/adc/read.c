int adc__read(int channel) {
    system(CLEAR_SCREEN);
    printf(" Aixt virtual ADC input     ADC %ld : ", channel);
    scanf("%ld", &adc__value);
    return adc__value;
}