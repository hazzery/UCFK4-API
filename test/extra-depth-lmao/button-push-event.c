//
// Created by Harry on 6/12/22.
//

#include "system/LED.h"
#include "system/button.h"

int main(void)
{
    button_t pushy = button_construct(PORT_D, 7, INPUT);
    LED_t bluey = LED_construct(PORT_C, 2, OUTPUT);

    if (button_pushed_event(&pushy)) {
        LED_set_state(&bluey, HIGH);
    }
    return 0;
}
