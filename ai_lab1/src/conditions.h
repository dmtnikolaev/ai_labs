#ifndef AI_LAB1_CONDITIONS_H
#define AI_LAB1_CONDITIONS_H

#include "tag.h"

struct Conditions {
    constexpr static field_t init_field {{
        {0, 4, 3},
        {6, 2, 1},
        {7, 5, 8}
    }};
    constexpr static field_t target_field {{
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}
    }};

    const TagState init_state = TagState(init_field, {0, 0});
    const TagState target_state = TagState(target_field, {1, 1});
};

#endif //AI_LAB1_CONDITIONS_H
