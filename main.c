/*
    MIT License

    Copyright (c) 2019 Bruno Freitas - http://www.brunofreitas.com/

    #include "LICENSE"
 */

/*
    Multi source files Makefile based project template for STM8.

    Blink code based on https://lujji.github.io/blog/bare-metal-programming-stm8/
 */

#include "stm8s.h"
#include "delay.h"

#define LED_PIN     5

void main() {
	bit_set(PB_DDR, 1 << LED_PIN);
	bit_set(PB_CR1, 1 << LED_PIN);

	while (1) {
		/* toggle pin every 1s */
		PB_ODR ^= (1 << LED_PIN);
		delay_ms(1000);
	}
}
