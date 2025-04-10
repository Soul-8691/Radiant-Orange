#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

typedef void (*MainCallback)(void);
typedef void (*IntrCallback)(void);
typedef void (*IntrFunc)(void);
typedef void (*EraseFlash)(u16);

#include "global.h"

extern IntrFunc gIntrTable[];

struct Main
{
    /*0x000*/ MainCallback callback1;
    /*0x004*/ MainCallback callback2;

    /*0x008*/ MainCallback savedCallback;

    /*0x00C*/ IntrCallback vblankCallback;
    /*0x010*/ IntrCallback hblankCallback;
    /*0x014*/ IntrCallback vcountCallback;
    /*0x018*/ IntrCallback serialCallback;

    /*0x01C*/ vu16 intrCheck;

    /*0x020*/ u32 *vblankCounter1;
    /*0x024*/ u32 vblankCounter2;

    /*0x028*/ u16 heldKeysRaw;           // held keys without L=A remapping
    /*0x02A*/ u16 newKeysRaw;            // newly pressed keys without L=A remapping
    /*0x02C*/ u16 heldKeys;              // held keys with L=A remapping
    /*0x02E*/ u16 newKeys;               // newly pressed keys with L=A remapping
    /*0x030*/ u16 newAndRepeatedKeys;    // newly pressed keys plus key repeat
    /*0x032*/ u16 keyRepeatCounter;      // counts down to 0, triggering key repeat
    /*0x034*/ bool16 watchedKeysPressed; // whether one of the watched keys was pressed
    /*0x036*/ u16 watchedKeysMask;       // bit mask for watched keys

    /*0x038*/ struct OamData oamBuffer[128];

    /*0x438*/ u8 state;

    /*0x439*/ u8 oamLoadDisabled:1;
    /*0x439*/ u8 inBattle:1;
    /*0x439*/ u8 field_439_x4:1;
};

extern struct Main gMain;
extern bool8 __attribute__((long_call)) gSoftResetDisabled;
extern bool8 __attribute__((long_call)) gLinkVSyncDisabled;

extern const u8 gGameVersion;
extern const u8 gGameLanguage;

void __attribute__((long_call)) AgbMain(void);
void __attribute__((long_call)) SetMainCallback2(MainCallback callback);
void __attribute__((long_call)) InitKeys(void);
void __attribute__((long_call)) SetVBlankCallback(IntrCallback callback);
void __attribute__((long_call)) SetHBlankCallback(IntrCallback callback);
void __attribute__((long_call)) SetVCountCallback(IntrCallback callback);
void __attribute__((long_call)) SetSerialCallback(IntrCallback callback);
void __attribute__((long_call)) InitFlashTimer(void);
void __attribute__((long_call)) DoSoftReset(void);
void __attribute__((long_call)) ClearPokemonCrySongs(void);
void __attribute__((long_call)) RestoreSerialTimer3IntrHandlers(void);
void __attribute__((long_call)) SetVBlankCounter1Ptr(u32 *ptr);
void __attribute__((long_call)) DisableVBlankCounter1(void);
void __attribute__((long_call)) StartTimer1(void);
void __attribute__((long_call)) SeedRngAndSetTrainerId(void);
u16 __attribute__((long_call)) GetGeneratedTrainerIdLower(void);

#define GAME_CODE_LENGTH 4
extern const char RomHeaderGameCode[GAME_CODE_LENGTH];
extern const char RomHeaderSoftwareVersion;

extern u8 __attribute__((long_call)) gLinkTransferringData;
extern u16 __attribute__((long_call)) gKeyRepeatStartDelay;

#endif // GUARD_MAIN_H
