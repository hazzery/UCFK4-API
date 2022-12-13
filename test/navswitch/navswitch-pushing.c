//
// Created by Harry on 13/12/22.
//

#include "drivers/navswitch.h"
#include "system/LED.h"

int main(void)
{
    navswitch_initialize();

    LED_t bluey = LED_construct(PORT_C, 2, OUTPUT);

    while (true) {
        navswitch_update_state();

        if (navswitch_pushed(UP)) {
            LED_set_state(&bluey, HIGH);
        } else {
            LED_set_state(&bluey, LOW);
        }
    }
    return 0;
}