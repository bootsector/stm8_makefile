/*
    Multi source files Makefile based project template for STM8.

    Blink code based on https://lujji.github.io/blog/bare-metal-programming-stm8/
*/

#include "stm8s.h"
#include "delay.h"

#define LED_PIN     5

void main() {
    PB_DDR |= (1 << LED_PIN); // configure PD4 as output
    PB_CR1 |= (1 << LED_PIN); // push-pull mode
    
    while (1) {
        /* toggle pin every 1s */
        PB_ODR ^= (1 << LED_PIN);
        delay_ms(1000);
    }
}