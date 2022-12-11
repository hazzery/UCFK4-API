//
// Created by Harry on 6/12/22.
//

#include "system/LED.h"
#include "system/button.h"

int main(void)
{
    button_t pushy = button_construct(PORT_D, 7, INPUT);
    LED_t bluey = LED_construct(PORT_C, 2, OUTPUT);

    while (true) {
        button_update_state(&pushy);

        if (button_being_pressed(&pushy)) {
            LED_set_state(&bluey, HIGH);
        } else {
            LED_set_state(&bluey, LOW);
        }
    }
    return 0;
}
