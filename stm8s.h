#ifndef STM8S_H_
#define STM8S_H_

#define _SFR_(mem_addr)     (*(volatile uint8_t *)(0x5000 + (mem_addr)))

/* PORT D */
#define PB_ODR      _SFR_(0x0005)
#define PB_DDR      _SFR_(0x0007)
#define PB_CR1      _SFR_(0x0008)

/* TIMER 2 */

#define TIM2_CR1    _SFR_(0x0300)
#define TIM2_EGR    _SFR_(0x0306)
#define TIM2_CNTRH  _SFR_(0x030C)
#define TIM2_CNTRL  _SFR_(0x030D)
#define TIM2_PSCR   _SFR_(0x030E)

#endif /* STM8S_H_ */