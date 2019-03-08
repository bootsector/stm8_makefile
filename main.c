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