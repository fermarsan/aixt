#define TIMER11_SETOVERFLOW(VALUE, FORMAT) timer11->setOverflow(VALUE, FORMAT)
#define TIMER11_ATTACHINTERRUPT(HANDLER)  timer11->attachInterrupt(HANDLER)
#define TIMER11_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer11->attachInterrupt(CH, HANDLER)
#define TIMER11_RESUME() timer11->resume()
#define TIMER11_WRITE_PERCENT_CHANNEL(CH, VAL) timer11->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER11_WRITE_PERCENT(VALUE) timer11->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER11_SETMODE(channel, mode, pin) timer11->setMode(channel, mode, pin)
#define TIMER11__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER11_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM11;
HardwareTimer *timer11 = new HardwareTimer(inst);