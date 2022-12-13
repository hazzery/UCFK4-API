#ifndef NAVIGATION_SWITCH_H
#define NAVIGATION_SWITCH_H

#include <stdbool.h>

#define NAVSWITCH_NUM_DIRECTIONS 5

typedef enum navswitch_direction_e {
    PUSH,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NEUTRAL
} navswitch_direction_t;

extern void navswitch_initialize(void);

extern navswitch_direction_t navswitch_update_state(void);

extern bool navswitch_pushed(navswitch_direction_t direction);

extern bool navswitch_changed_to(navswitch_direction_t direction);

#endif //NAVIGATION_SWITCH_H