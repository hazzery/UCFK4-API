#include "system/button.h"

/**
 * @brief Constructs a new `button_t` object
 * @param port a `port_t` enum value describing the port in which the button is connected to
 * @param port_bit the number of the bit within the port in which the button is connected to
 * @param mode either `INPUT` or `INPUT_PULLUP` depending on the type of button
 * @return `button_t` object to control the button with
 */
button_t button_construct(port_t port, uint8_t port_bit, pin_mode_t mode)
{
    return (button_t) {
        .pin = define_pin(port, port_bit, mode)
    };
}

/**
 * @brief Updates the button's state
 * @param button Pointer to the `button_t` to update
 * @return the current state of the button
 */
state_t button_update_state(button_t* button)
{
    button->prev_state = button->state;
    button->state = digital_read(&button->pin);
    return button->state;
}

/**
 * @brief Returns whether or not `button` is pressed down
 * @param button Pointer to the `button_t` to read from
 * @return `true` if button is pressed down, `false` otherwise
 */
bool button_being_pressed(button_t* button)
{
    return button->state == HIGH;
}

/**
 * @brief Returns whether or not `button` was just released
 * @param button Pointer to the `button_t` to read from
 * @return `true` if button has just been released, `false` otherwise
 */
bool button_released_event(button_t* button)
{
    return (button->state != button->prev_state) && button->state == LOW;
}

/**
 * @brief Returns whether or not `button` was just pressed
 * @param button Pointer to the `button_t` to read from
 * @return `true` if button has just been pressed, `false` otherwise
 */
bool button_pushed_event(button_t* button)
{
    return (button->state != button->prev_state) && button->state == HIGH;
}