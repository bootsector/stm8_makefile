/*
    MIT License

    Copyright (c) 2019 Bruno Freitas - http://www.brunofreitas.com/

    #include "LICENSE"
*/

#ifndef STM8S_H_
#define STM8S_H_

#include <stdint.h>

#define _SFR8_(mem_addr)    (*(volatile uint8_t *)(0x5000 + (mem_addr)))
#define _SFR16_(mem_addr)   (*(volatile uint16_t *)(0x5000 + (mem_addr)))

/* PORT B */
#define PB_ODR      _SFR8_(0x0005)
#define PB_DDR      _SFR8_(0x0007)
#define PB_CR1      _SFR8_(0x0008)

/* TIMER 2 */
#define TIM2_CR1    _SFR8_(0x0300)
#define TIM2_EGR    _SFR8_(0x0306)
#define TIM2_CNTR   _SFR16_(0x030C) // (CNTRH << 8) | CNTRL
#define TIM2_PSCR   _SFR8_(0x030E)

#endif /* STM8S_H_ */
