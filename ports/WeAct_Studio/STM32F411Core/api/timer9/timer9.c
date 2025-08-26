#define TIMER9_SETOVERFLOW(VALUE, FORMAT) timer9->setOverflow(VALUE, FORMAT)
#define TIMER9_ATTACHINTERRUPT(HANDLER)  timer9->attachInterrupt(HANDLER)
#define TIMER9_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer9->attachInterrupt(CH, HANDLER)
#define TIMER9_RESUME() timer9->resume()
#define TIMER9_WRITE_PERCENT_CHANNEL(CH, VAL) timer9->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER9_WRITE_PERCENT(VALUE) timer9->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER9_SETMODE(channel, mode, pin) timer9->setMode(channel, mode, pin)
#define TIMER9__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER9_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM9;
HardwareTimer *timer9 = new HardwareTimer(inst);