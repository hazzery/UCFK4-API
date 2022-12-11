//
// Created by Harry on 11/12/22.
//
#include <avr/wdt.h>
#include <avr/io.h>

void clock_initialize(void) {
    /* Switch 1 MHz CPU clock to 8 MHz.  */
    CLKPR = 1 << CLKPCE;
    CLKPR = 0;
}