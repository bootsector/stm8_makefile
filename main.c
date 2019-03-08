/*
    Multi source files Makefile based project template for STM8.

    Blink code based on https://lujji.github.io/blog/bare-metal-programming-stm8/
*/

#include "delay.h"

#define _SFR_(mem_addr)     (*(volatile uint8_t *)(0x5000 + (mem_addr)))

/* PORT D */
#define PB_ODR      _SFR_(0x05)
#define PB_DDR      _SFR_(0x07)
#define PB_CR1      _SFR_(0x08)

#define LED_PIN     5

void main() {
    PB_DDR |= (1 << LED_PIN); // configure PD4 as output
    PB_CR1 |= (1 << LED_PIN); // push-pull mode
    
    while (1) {
        /* toggle pin every 250ms */
        PB_ODR ^= (1 << LED_PIN);
        delay_ms(250);
    }
}