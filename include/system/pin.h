#ifndef GENERAL_PURPOSE_PIN_H
#define GENERAL_PURPOSE_PIN_H

#include <stdint.h>

/**
 * @brief returns a byte of 0's except for a 1 at specified bit
 *
 * This is used as a bitmask to select only the wanted bit from the bytes
 *
 * @param X The bit to be set HIGH
 * @return Integer number representing bit sequence
 */
#define BIT_MASK(X) (1 << (X))
#define NULL ((void *)0)

typedef volatile uint8_t* register_t;

typedef enum port_e {
    PORT_B = 1,
    PORT_C,
    PORT_D,
} port_t;

typedef enum pin_mode_e {
    OUTPUT,
    OUTPUT_ACTIVE_LOW,
    INPUT,
    INPUT_PULLUP,
    ERROR
} pin_mode_t;

typedef struct pin_s
{
    register_t port_register;
    uint8_t port_bit;
    pin_mode_t mode;
} pin_t;

/**
 * @brief Define a new GPIO pin for use
 * @param port The `port_t` enum value corresponding to the pin's port
 * @param port_bit the with within the port being used
 * @param mode a `pin_mode_t` value, generally either `INPUT` or `OUTPUT`
 * @return The `pin_t` object for use in the digitalIO module
 */
extern pin_t define_pin(port_t port, uint8_t port_bit, pin_mode_t mode);

#endif //GENERAL_PURPOSE_PIN_H