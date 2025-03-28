#ifndef GUARD_BATTLE_MAIN_H
#define GUARD_BATTLE_MAIN_H

#include "constants/abilities.h"

struct TrainerMoney
{
    u8 classId;
    u8 value;
};

struct MultiBattlePokemonTx
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 heldItem;
    /*0x04*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0F*/ u8 level;
    /*0x10*/ u16 hp;
    /*0x12*/ u16 maxhp;
    /*0x14*/ u32 status;
    /*0x18*/ u32 personality;
    /*0x1C*/ u8 gender;
    /*0x1D*/ u8 language;
};

#define TYPE_NAME_LENGTH 6
#define ABILITY_NAME_LENGTH 12

// defines for the u8 array gTypeEffectiveness
#define TYPE_EFFECT_ATK_TYPE(i)((gTypeEffectiveness[i + 0]))
#define TYPE_EFFECT_DEF_TYPE(i)((gTypeEffectiveness[i + 1]))
#define TYPE_EFFECT_MULTIPLIER(i)((gTypeEffectiveness[i + 2]))

// defines for the gTypeEffectiveness multipliers
#define TYPE_MUL_NO_EFFECT          0
#define TYPE_MUL_NOT_EFFECTIVE      5
#define TYPE_MUL_NORMAL             10
#define TYPE_MUL_SUPER_EFFECTIVE    20

// special type table Ids
#define TYPE_FORESIGHT  0xFE
#define TYPE_ENDTABLE   0xFF

// defines for the 'DoBounceEffect' function
#define BOUNCE_MON          0x0
#define BOUNCE_HEALTHBOX    0x1

extern const struct SpriteTemplate gUnknownDebugSprite;
extern const struct OamData gOamData_BattlerOpponent;
extern const struct OamData gOamData_BattlerPlayer;
extern const u8 gTypeNames[][TYPE_NAME_LENGTH + 1];
extern const u8 gStatusConditionString_PoisonJpn[8];
extern const u8 gStatusConditionString_SleepJpn[8];
extern const u8 gStatusConditionString_ParalysisJpn[8];
extern const u8 gStatusConditionString_BurnJpn[8];
extern const u8 gStatusConditionString_IceJpn[8];
extern const u8 gStatusConditionString_ConfusionJpn[8];
extern const u8 gStatusConditionString_LoveJpn[8];
extern const u8 *const gStatusConditionStringsTable[7][2];
extern const u8 gTypeEffectiveness[336];
extern const struct TrainerMoney gTrainerMoneyTable[];
extern const u8 *const gAbilityDescriptionPointers[ABILITIES_COUNT];
extern const u8 gAbilityNames[ABILITIES_COUNT][ABILITY_NAME_LENGTH + 1];

void __attribute__((long_call)) CB2_InitBattle(void);
void __attribute__((long_call)) BattleMainCB2(void);
void __attribute__((long_call)) FreeRestoreBattleData(void);
void __attribute__((long_call)) VBlankCB_Battle(void);
void __attribute__((long_call)) SpriteCB_VsLetterDummy(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_VsLetterInit(struct Sprite *sprite);
void __attribute__((long_call)) CB2_InitEndLinkBattle(void);
u32 __attribute__((long_call)) GetBattleBgTemplateData(u8 arrayId, u8 caseId);
void __attribute__((long_call)) SpriteCB_EnemyMon(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCallbackDummy_2(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_FaintOpponentMon(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_ShowAsMoveTarget(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_HideAsMoveTarget(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_AllyMon(struct Sprite *sprite);
void __attribute__((long_call)) SetIdleSpriteCallback(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_FaintSlideAnim(struct Sprite *sprite);
void __attribute__((long_call)) DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude);
void __attribute__((long_call)) EndBounceEffect(u8 battler, u8 which);
void __attribute__((long_call)) SpriteCB_PlayerThrowInit(struct Sprite *sprite);
void __attribute__((long_call)) UpdatePlayerPosInThrowAnim(struct Sprite *sprite);
void __attribute__((long_call)) BeginBattleIntroDummy(void);
void __attribute__((long_call)) BeginBattleIntro(void);
void __attribute__((long_call)) SwitchInClearSetData(void);
void __attribute__((long_call)) FaintClearSetData(void);
void __attribute__((long_call)) BattleTurnPassed(void);
u8 __attribute__((long_call)) IsRunningFromBattleImpossible(void);
void __attribute__((long_call)) UpdatePartyOwnerOnSwitch_NonMulti(u8 battler);
void __attribute__((long_call)) SwapTurnOrder(u8 id1, u8 id2);
u8 __attribute__((long_call)) GetWhoStrikesFirst(u8 battler1, u8 battler2, bool8 ignoreChosenMoves);
void __attribute__((long_call)) RunBattleScriptCommands_PopCallbacksStack(void);
void __attribute__((long_call)) RunBattleScriptCommands(void);
bool8 __attribute__((long_call)) TryRunFromBattle(u8 battler);

#endif // GUARD_BATTLE_MAIN_H
