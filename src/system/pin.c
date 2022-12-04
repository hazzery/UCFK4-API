#include "pin.h"

/**
 * @brief Sets the given port as in output
 * 
 * @param port The name of the pin's port
 * @param port_bit the the pin's bit within the port
 * @return Memory address to write to given port
 */
static register_t set_output_pin(const port_t port, const uint8_t port_bit)
{
    switch (port)
    {
    case PORT_B:
        DDRB |= BIT(port_bit);
        return &PORTB;
        
    case PORT_C:
        DDRC |= BIT(port_bit);
        return &PORTC;
        
    case PORT_D:
        DDRD |= BIT(port_bit);
        return &PORTD;
    
    default:
        return NULL;
    }
}

/**
 * @brief Sets the given port as in input
 * 
 * @param port The name of the pin's port
 * @param port_bit the the pin's bit within the port
 * @return Memory address to read from given port
 */
static register_t set_input_pin(const port_t port, const uint8_t port_bit)
{
    switch (port)
    {
    case PORT_B:
        DDRB &= ~BIT(port_bit);
        return &PINB;

    case PORT_C:
        DDRC &= ~BIT(port_bit);
        return &PINC;

    case PORT_D:
        DDRD &= ~BIT(port_bit);
        return &PIND;

    default:
        return NULL;
    }
}

/**
 * @brief Initialises new pin for use on UCFK4 and sets pin mode
 * 
 * @param port The name of the pin's port
 * @param port_bit the the pin's bit within the port
 * @param mode OUTPUT to write, or INPUT to read
 * @return initialized pin_t object - .mode = ERROR if port_bit > 7
 */
pin_t define_pin(const port_t port, const uint8_t port_bit, const pin_mode_t mode)
{
    // Checks to see if bit number is valid
    if (port_bit > 7) {
        return (pin_t) {
            .registr = NULL, .port_bit = 255, .mode = ERROR
        };
    }

    register_t port_register;

    // Sets pin mode
    if (mode == OUTPUT) {
        port_register = set_output_pin(port, port_bit);
    } else {
        port_register = set_input_pin(port, port_bit);
    }

    // Returns new pin_t object
    return (pin_t) {
        .registr = port_register, .port_bit = port_bit, .mode = mode
    };
}