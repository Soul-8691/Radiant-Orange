#ifndef GUARD_BERRY_H
#define GUARD_BERRY_H

#include "global.h"

enum
{
    BERRY_FIRMNESS_UNKNOWN,
    BERRY_FIRMNESS_VERY_SOFT,
    BERRY_FIRMNESS_SOFT,
    BERRY_FIRMNESS_HARD,
    BERRY_FIRMNESS_VERY_HARD,
    BERRY_FIRMNESS_SUPER_HARD,
};

enum
{
    FLAVOR_SPICY,
    FLAVOR_DRY,
    FLAVOR_SWEET,
    FLAVOR_BITTER,
    FLAVOR_SOUR,
    FLAVOR_COUNT
};

#define NUM_BERRIES 44

void __attribute__((long_call)) ClearEnigmaBerries(void);
void __attribute__((long_call)) SetEnigmaBerry(u8 *src);
bool32 __attribute__((long_call)) IsEnigmaBerryValid(void);
const struct Berry *GetBerryInfo(u8 berry);
u8 __attribute__((long_call)) ItemIdToBerryType(u16 item);
void __attribute__((long_call)) GetBerryNameByBerryType(u8 berry, u8 *string);

extern const struct Berry gBerries[];

struct BerryCrushStats {
    u8 difficulty;
    u16 powder;
};

extern const struct BerryCrushStats gBerryCrush_BerryData[];

#endif // GUARD_BERRY_H
