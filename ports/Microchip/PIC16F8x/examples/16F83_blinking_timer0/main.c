// This C code was automatically generated by Aixt Project
//     https://github.com/fermarsan/aixt
// Device = PIC16F83
// Board = ---
// Backend = c

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
// typedef NOT SUPPORTED i64;
typedef int8_t isize;
typedef int32_t int_literal;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
// typedef NOT SUPPORTED u64;
typedef uint8_t usize;
typedef float f32;
// typedef NOT SUPPORTED f64;
typedef float float_literal;
typedef char rune;

#define _const_main__cpu_freq_mhz	_const_main__cpu_freq/1000000
#define _const_main__cpu_freq  10000000

#define TIMER0_IRQ_IN_USE

#define _XTAL_FREQ _const_main__cpu_freq

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#if defined(TIMER0_IRQ_IN_USE) || defined(EXT_IRQ_IN_USE)   // if any interrupt source is activated

#ifdef EXT_IRQ_IN_USE    
void (*ptr_ext_isr)(void);      // Interrupt Service Routine pointer
#endif  // EXT_IRQ_IN_USE 

#ifdef TIMER0_IRQ_IN_USE    
void (*ptr_timer0_isr)(void);   // Interrupt Service Routine pointer
#endif  // TIMER0_IRQ_IN_USE 

void __interrupt() Global_ISR() {
	#ifdef EXT_IRQ_IN_USE    
	if(INTF == 1) {
		ptr_ext_isr();
		INTF = 0;
	}
	#endif  // EXT_IRQ_IN_USE 
	
	#ifdef TIMER0_IRQ_IN_USE    
	if(T0IF == 1) {
		ptr_timer0_isr();
		T0IF = 0;
	}
	#endif  // TIMER0_IRQ_IN_USE 
}

#endif  // defined(TIMER0_IRQ_IN_USE) || defined(EXT_IRQ_IN_USE)

u8 timer0__initial = (u8)(0);

#define timer0__read()  (u8)(TMR0)

#define timer0__irq_disable() T0IE = 0

#define timer0__irq_enable() \
GIE = 1; \
T0IE = 1; \
// end #define

#define timer0__restart() TMR0 = (u8)(timer0__initial)

#define _const_timer0__max_cycles_presc_1 (u32)(1024)
#define _const_timer0__max_cycles_presc_2 (u32)(2048)
#define _const_timer0__max_cycles_presc_4 (u32)(4096)
#define _const_timer0__max_cycles_presc_8 (u32)(8192)
#define _const_timer0__max_cycles_presc_16 (u32)(16384)
#define _const_timer0__max_cycles_presc_32 (u32)(32768)
#define _const_timer0__max_cycles_presc_64 (u32)(65536)
#define _const_timer0__max_cycles_presc_128 (u32)(131072)

#define timer0__max_t_prescaler(max_cycles_presc)  (u32)(max_cycles_presc / (u8)(_const_main__cpu_freq_mhz))
#define _const_timer0__presc_1_shift (u8)(2)
#define _const_timer0__presc_2_shift (u8)(3)
#define _const_timer0__presc_4_shift (u8)(4)
#define _const_timer0__presc_8_shift (u8)(5)
#define _const_timer0__presc_16_shift (u8)(6)
#define _const_timer0__presc_32_shift (u8)(7)
#define _const_timer0__presc_64_shift (u8)(8)
#define _const_timer0__presc_128_shift (u8)(9)
#define _const_timer0__presc_256_shift (u8)(10)

#define timer0__init_value(period, shift)  (u8)(256 - (u16)(period >> shift) * (u16)(_const_main__cpu_freq_mhz))

#define timer0__setup(period) \
T0CS = 0; \
if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_1) ) { \
	PSA = 1;  \
	timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_1_shift));  \
} \
else { \
	PSA = 0;  \
	OPTION_REG &= 0b11111000;  \
	if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_2) ) { \
		OPTION_REG |= 0b000;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_2_shift));  \
	} \
	else if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_4) ) { \
		OPTION_REG |= 0b001;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_4_shift));  \
	} \
	else if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_8) ) { \
		OPTION_REG |= 0b010;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_8_shift));  \
	} \
	else if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_16) ) { \
		OPTION_REG |= 0b011;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_16_shift));  \
	} \
	else if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_32) ) { \
		OPTION_REG |= 0b100;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_32_shift));  \
	} \
	else if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_64) ) { \
		OPTION_REG |= 0b101;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_64_shift));  \
	} \
	else if( period <= timer0__max_t_prescaler(_const_timer0__max_cycles_presc_128) ) { \
		OPTION_REG |= 0b110;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_128_shift));  \
	} \
	else { \
		OPTION_REG |= 0b111;  \
		timer0__initial = (u8)(timer0__init_value(period, _const_timer0__presc_256_shift));  \
	};  \
}; \
TMR0 = (u8)(timer0__initial); \
// end #define

#define _const_pin__a0 0
#define _const_pin__a1 1
#define _const_pin__a2 2
#define _const_pin__a3 3
#define _const_pin__a4 4
#define _const_pin__a5 5
#define _const_pin__a6 6
#define _const_pin__a7 7
#define _const_pin__b0 8
#define _const_pin__b1 9
#define _const_pin__b2 10
#define _const_pin__b3 11
#define _const_pin__b4 12
#define _const_pin__b5 13
#define _const_pin__b6 14
#define _const_pin__b7 15
#define _const_pin__c0 16
#define _const_pin__c1 17
#define _const_pin__c2 18
#define _const_pin__c3 19
#define _const_pin__c4 20
#define _const_pin__c5 21
#define _const_pin__c6 22
#define _const_pin__c7 23
#define _const_pin__d0 24
#define _const_pin__d1 25
#define _const_pin__d2 26
#define _const_pin__d3 27
#define _const_pin__d4 28
#define _const_pin__d5 29
#define _const_pin__d6 30
#define _const_pin__d7 31
#define _const_pin__e0 32
#define _const_pin__e1 33
#define _const_pin__e2 34
#define _const_pin__e3 35
#define _const_pin__e4 36
#define _const_pin__e5 37
#define _const_pin__e6 38
#define _const_pin__e7 39
#define _const_pin__irq 8
#define _const_pin__output 0
#define _const_pin__input 1

#define pin__read(name)  (u8)((*(&PORTA + (name >> 3)) >> (name - ((name >> 3) << 3))) & 0x01)

#define pin__toggle(name) *(&PORTA + (name >> 3)) ^= 0x01 << (name - ((name >> 3) << 3))

#define pin__low(name) *(&PORTA + (name >> 3)) &= ~(0x01 << (name - ((name >> 3) << 3)))

#define pin__write(name, value) \
*(&PORTA + (name >> 3)) &= (~(0x01 << (name - ((name >> 3) << 3)))); \
*(&PORTA + (name >> 3)) |= (value << (name - ((name >> 3) << 3))); \
// end #define

#define pin__setup(name, mode) \
if( mode == 1 ) { \
	*(&TRISA + (name >> 3)) |= (0x01 << (name - ((name >> 3) << 3)));  \
} \
else { \
	*(&TRISA + (name >> 3)) &= ~(0x01 << (name - ((name >> 3) << 3)));  \
}; \
// end #define

#define pin__high(name) *(&PORTA + (name >> 3)) |= 0x01 << (name - ((name >> 3) << 3))

 void  main__blinking() {
	timer0__restart(); 
	pin__toggle(_const_pin__b4); 
}

 void main(void) {
	ptr_timer0_isr = main__blinking;
	pin__setup(_const_pin__b4, _const_pin__output); 
	timer0__setup(100); 
	pin__low(_const_pin__b4); 
	timer0__irq_enable(); 
	while( true ) {
	} 
}

