#include "drivers/navswitch.h"

#include <stdint.h>
#include "system/button.h"

static navswitch_direction_t state = NEUTRAL;
static navswitch_direction_t prev_state = NEUTRAL;


pin_t navswitch_pins[NAVSWITCH_NUM_DIRECTIONS];

void navswitch_initialize(void)
{
    static bool is_initialized = false;
    if (is_initialized) return;

    navswitch_pins[PUSH]  = define_pin(PORT_C, 4, INPUT);
    navswitch_pins[UP]    = define_pin(PORT_C, 7, INPUT);
    navswitch_pins[DOWN]  = define_pin(PORT_C, 5, INPUT);
    navswitch_pins[LEFT]  = define_pin(PORT_B, 7, INPUT);
    navswitch_pins[RIGHT] = define_pin(PORT_C, 6, INPUT);

    is_initialized = true;
}

navswitch_direction_t navswitch_update_state(void)
{
    for (uint8_t pin = 0; pin < NAVSWITCH_NUM_DIRECTIONS; pin++) {
        if (digital_read(&navswitch_pins[pin])) {
            prev_state = state;
            state = (navswitch_direction_t) pin;
            return pin;
        }
    }
    return NEUTRAL;
}

bool navswitch_pushed(navswitch_direction_t direction) {
    return state == direction;
}

bool navswitch_changed_to(navswitch_direction_t direction) {
    return state == direction && prev_state != state;
}