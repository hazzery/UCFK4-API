#ifndef DIGITAL_INPUT_OUTPUT_H
#define DIGITAL_INPUT_OUTPUT_H

#include "pin.h"

typedef enum state_e {
    LOW,
    HIGH,
    ERROR_STATE
} state_t;

extern void digital_write(pin_t pin, state_t state);
extern state_t digital_read(pin_t pin);

#endif