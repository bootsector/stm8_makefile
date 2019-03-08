#include "delay.h"

#define F_CPU 2000000UL

void delay_ms(uint16_t ms) {
    for (uint32_t i = 0; i < ((F_CPU / 18000UL) * ms); i++) {
        __asm__("nop");
    }
}
