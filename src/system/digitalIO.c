#include "system/digitalIO.h"

/**
 * @brief Sends a digital signal to the specified pin
 * @param pin `pin_t` describing port to write to
 * @param state The state to set the pin to, either HIGH or LOW
 */
void digital_write(pin_t* pin, state_t state)
{
    if (pin->mode == OUTPUT) {
        if (state == HIGH) {
            *(pin->port_register) |= BIT_MASK(pin->port_bit);

        } else {
            *(pin->port_register) &= ~BIT_MASK(pin->port_bit);
        }
    }
}

/**
 * @brief Reads a digital signal from a specified pin
 * @param pin Pointer to a `pin_t` describing pin to read from
 * @return The state of the bit when read, either HIGH or LOW
 */
state_t digital_read(pin_t* pin)
{
    if (pin->mode == INPUT || pin->mode == OUTPUT) {
        return (*(pin->port_register) & BIT_MASK(pin->port_bit)) >> pin->port_bit;

    } else if (pin->mode == INPUT_PULLUP || pin->mode == OUTPUT_ACTIVE_LOW) {
        return !(*(pin->port_register) & BIT_MASK(pin->port_bit));

    } else {
        return ERROR_STATE;
    }
}
