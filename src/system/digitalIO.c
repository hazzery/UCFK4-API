#include "harry-api.h"
#include "digitalIO.h"

/**
 * @brief Writes to a specifc bit
 * 
 * @param pin An OUTPUT pin_t to be written to
 * @param state The state to set the bit to, either HIGH or LOW
 */
void digital_write(pin_t pin, state_t state)
{
    if (pin.mode == OUTPUT) {
        if (state == HIGH) {
            *(pin.registr) |= BIT(pin.port_bit);

        } else {
            *(pin.registr) &= ~BIT(pin.port_bit);
        }
    }
}

/**
 * @brief Reads the value of a specific bit
 * 
 * @param pin An INPUT or INPUT_PULLUP pin_t to read from
 * @return The state of the bit when read, either HIGH or LOW
 */
state_t digital_read(pin_t pin)
{
    if (pin.mode == INPUT) {
        return (*(pin.registr) & BIT(pin.port_bit)) != 0;

    } else if (pin.mode == INPUT_PULLUP) {
        return (*(pin.registr) & BIT(pin.port_bit)) == 0;

    } else {
        return ERROR_STATE;
    }
}
