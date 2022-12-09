//
// Created by Harry on 6/12/22.
//

#include "system/LED.h"
#include <stdlib.h>

int main(void)
{
    LED_t blue = LED_construct(PORT_C, 2, OUTPUT);

    LED_set_state(&blue, HIGH);

    return EXIT_SUCCESS;
}
