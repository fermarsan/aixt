#define TIMER7_SETOVERFLOW(VALUE, FORMAT) timer7->setOverflow(VALUE, FORMAT)
#define TIMER7_ATTACHINTERRUPT(HANDLER)  timer7->attachInterrupt(HANDLER)
#define TIMER7_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer7->attachInterrupt(CH, HANDLER)
#define TIMER7_RESUME() timer7->resume()
#define TIMER7_WRITE_PERCENT_CHANNEL(CH, VAL) timer7->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER7_WRITE_PERCENT(VALUE) timer7->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER7_SETMODE(channel, mode, pin) timer7->setMode(channel, mode, pin)
#define TIMER7__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER7_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM7;
HardwareTimer *timer7 = new HardwareTimer(inst);