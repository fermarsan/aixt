#define TIMER10_SETOVERFLOW(VALUE, FORMAT) timer10->setOverflow(VALUE, FORMAT)
#define TIMER10_ATTACHINTERRUPT(HANDLER)  timer10->attachInterrupt(HANDLER)
#define TIMER10_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer10->attachInterrupt(CH, HANDLER)
#define TIMER10_RESUME() timer10->resume()
#define TIMER10_WRITE_PERCENT_CHANNEL(CH, VAL) timer10->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER10_WRITE_PERCENT(VALUE) timer10->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER10_SETMODE(channel, mode, pin) timer10->setMode(channel, mode, pin)
#define TIMER10__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER10_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM10;
HardwareTimer *timer10 = new HardwareTimer(inst);