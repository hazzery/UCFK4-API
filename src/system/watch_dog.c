//
// Created by Harry on 11/12/22.
//

#include "system/watch_dog.h"
#include <avr/wdt.h>
#include <avr/io.h>

static inline void watch_dog_clear(void) {
    MCUSR &= ~(1 << WDRF);
}

static inline void watch_dog_prescaler(void) {
    /* Write logical one to WDCE and WDE and keep old prescaler
       setting to prevent unintentional time-out.  */
    WDTCSR |= (1 << WDCE) | (1 << WDE);
}

static inline void watch_dog_disable(void) {
    /* Turn off watchdog timer.  */
    WDTCSR = 0x00;
}

void watch_dog_init (void) {
    wdt_reset ();

    watch_dog_clear();

    watch_dog_prescaler();

    watch_dog_disable();
}
