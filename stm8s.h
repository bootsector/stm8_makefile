/*
    MIT License

    Copyright (c) 2019 Bruno Freitas - http://www.brunofreitas.com/

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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