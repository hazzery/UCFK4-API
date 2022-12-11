#include "system/digitalIO.h"
#include "system/clock.h"
#include "system/watch_dog.h"

int main (void)
{
    clock_initialize();
    watch_dog_init();

    // Initialise port to drive LED 1.
    pin_t blue_LED = define_pin(PORT_C, 2, OUTPUT);

    // Initialise port to read S3.
    pin_t push_button = define_pin(PORT_D, 7, INPUT);

    while (1)
    {
        // Read from switch 3
        state_t button_val = digital_read(&push_button);

        if (button_val == HIGH) {
            // Turn LED 1 on
            digital_write(&blue_LED, HIGH);
        } else {
            // Turn LED 1 off
            digital_write(&blue_LED, LOW);
        }
    }
}