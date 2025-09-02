#define TIMER3_SETOVERFLOW(VALUE, FORMAT) timer3->setOverflow(VALUE, FORMAT)
#define TIMER3_ATTACHINTERRUPT(HANDLER)  timer3->attachInterrupt(HANDLER)
#define TIMER3_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer3->attachInterrupt(CH, HANDLER)
#define TIMER3_RESUME() timer3->resume()
#define TIMER3_WRITE_PERCENT_CHANNEL(CH, VAL) timer3->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER3_WRITE_PERCENT(VALUE) timer3->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER3_SETMODE(channel, mode, pin) timer3->setMode(channel, mode, pin)
#define TIMER3__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER3_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM3;
HardwareTimer *timer3 = new HardwareTimer(inst);