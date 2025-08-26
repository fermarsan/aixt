#define TIMER16_SETOVERFLOW(VALUE, FORMAT) timer16->setOverflow(VALUE, FORMAT)
#define TIMER16_ATTACHINTERRUPT(HANDLER)  timer16->attachInterrupt(HANDLER)
#define TIMER16_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer16->attachInterrupt(CH, HANDLER)
#define TIMER16_RESUME() timer16->resume()
#define TIMER16_WRITE_PERCENT_CHANNEL(CH, VAL) timer16->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER16_WRITE_PERCENT(VALUE) timer16->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER16_SETMODE(channel, mode, pin) timer16->setMode(channel, mode, pin)
#define TIMER16__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER16_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM16;
HardwareTimer *timer16 = new HardwareTimer(inst);