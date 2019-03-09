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
	TIM2_EGR |= (1 << 1);

	// Enable counter
	TIM2_CR1 |= (1 << 1);

	// Wait until counter reaches requested us
	while(TIM2_CNTR < us);
}

void delay_ms(uint16_t ms) {
	for(uint16_t i = 0; i < ms; i++) {
		delay_us(1000);
	}
}
