#ifndef LIGHT_EMITTING_DIODE_H
#define LIGHT_EMITTING_DIODE_H

#include "digitalIO.h"

typedef struct LED_s {
    pin_t pin;
    state_t state;
} LED_t;

/**
 * @brief Constructs a new `LED_t` object
 * @param port Pointer to an `pin_t` in which the LED is connected to
 * @return `LED_t` object to control LED with
 */
extern LED_t LED_construct(port_t port, uint8_t port_bit, pin_mode_t mode);

/**
 * @brief Sets the state of the LED to a specified state
 * @param LED Pointer to the `LED_t` to set the state of
 * @param state The state to set the LED to
 */
extern void LED_set_state(LED_t* LED, state_t state);

/**
 * @brief Toggle the state of an LED
 * @param LED Pointer to the `LED_t` to toggle
 */
extern void LED_toggle_state(LED_t* LED);

#endif // LIGHT_EMITTING_DIODE_H