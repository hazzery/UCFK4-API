#include "system/LED.h"

/**
 * @brief Constructs a new `LED_t` object
 * @param port a `port_t` enum value describing the port in which the LED is connected to
 * @param port_bit the number of the bit within the port in which the LED is connected to
 * @param mode either `OUTPUT` or `OUTPUT_ACTIVE_LOW` depending on the type of button
 * @return `LED_t` object to control LED with
 */
LED_t LED_construct(port_t port, uint8_t port_bit, pin_mode_t mode)
{
    return (LED_t) {
        .pin = define_pin(port, port_bit, mode)
    };
}

/**
 * @brief Sets the state of the LED to a specified state
 * @param LED Pointer to the `LED_t` to set the state of
 * @param state The state to set the LED to
 */
void LED_set_state(LED_t* LED, state_t state)
{
    digital_write(&LED->pin, state);
    LED->state = state;
}

/**
 * @brief Toggle the state of an LED
 * @param LED Pointer to the `LED_t` to toggle
 */
void LED_toggle_state(LED_t* LED)
{
    LED->state = !(LED->state);
    digital_write(&LED->pin, LED->state);
}