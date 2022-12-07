#ifndef DIGITAL_INPUT_OUTPUT_H
#define DIGITAL_INPUT_OUTPUT_H

#include "pin.h"

typedef enum state_e {
    LOW,
    HIGH,
    ERROR_STATE
} state_t;

/**
 * @brief Sends a digital signal to the specified pin
 * @param pin `pin_t` describing port to write to
 * @param state state to write to the pin
 */
extern void digital_write(pin_t* pin, state_t state);

/**
 * @brief Reads a digital signal from a specified pin
 * @param pin Pointer to a `pin_t` describing pin to read from
 * @return The state of the pin once read from
 */
extern state_t digital_read(pin_t* pin);

#endif