/*
    MIT License

    Copyright (c) 2019 Bruno Freitas - http://www.brunofreitas.com/

    #include "LICENSE"
 */

#include "stm8s.h"
#include "delay.h"

void delay_us(uint16_t us) {
	// Prescaler = 2^1: Increments at every 1uS
	TIM2_PSCR = 0x01;

	// Initialize counter
	bit_set(TIM2_EGR, 1 << 0);

	// Enable counter
	bit_set(TIM2_CR1, 1 << 0);

	// Wait until counter reaches requested us
	while(TIM2_CNTR < us);
}

void delay_ms(uint16_t ms) {
	// 125 times in 1ms
	TIM2_PSCR = 0x04;

	// Initialize counter
	bit_set(TIM2_EGR, 1 << 0);

	// Enable counter
	bit_set(TIM2_CR1, 1 << 0);

	while(ms > 0) {
		while(TIM2_CNTR < 125);

		TIM2_CNTR = 0;

		ms--;
	}
}
