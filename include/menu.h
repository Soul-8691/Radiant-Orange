#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "global.h"
#include "text.h"
#include "window.h"

#define MENU_NOTHING_CHOSEN -2
#define MENU_B_PRESSED -1

#define MENU_INFO_ICON_CAUGHT    0
#define MENU_INFO_ICON_TYPE      (NUMBER_OF_MON_TYPES + 1)
#define MENU_INFO_ICON_POWER     (NUMBER_OF_MON_TYPES + 2)
#define MENU_INFO_ICON_ACCURACY  (NUMBER_OF_MON_TYPES + 3)
#define MENU_INFO_ICON_PP        (NUMBER_OF_MON_TYPES + 4)
#define MENU_INFO_ICON_EFFECT    (NUMBER_OF_MON_TYPES + 5)

struct MenuAction
{
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
    } func;
};

// menu2
void __attribute__((long_call)) AddTextPrinterParameterized3(u8 windowId, u8 fontId, u8 x, u8 y, const u8 * color, s8 speed, const u8 * str);
void __attribute__((long_call)) AddTextPrinterParameterized4(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str);
void __attribute__((long_call)) AddTextPrinterParameterized5(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 letterSpacing, u8 lineSpacing);
void __attribute__((long_call)) Menu_PrintFormatIntlPlayerName(u8 windowId, const u8 * src, u16 x, u16 y);
void __attribute__((long_call)) StartBlendTask(u8 eva_start, u8 evb_start, u8 eva_end, u8 evb_end, u8 ev_step, u8 priority);
bool8 __attribute__((long_call)) IsBlendTaskActive(void);
u8 __attribute__((long_call)) Menu2_GetMonSpriteAnchorCoord(u16 species, u32 personality, u8 a2);
s8 __attribute__((long_call)) Menu2_GetMonSpriteAnchorCoordMinusx20(u16 species, u32 personality, u8 a2);

// list_menu
void __attribute__((long_call)) ListMenu_LoadMonIconPalette(u8 palOffset, u16 speciesId);
void __attribute__((long_call)) ListMenu_DrawMonIconGraphics(u8 windowId, u16 speciesId, u32 personality, u16 x, u16 y);
void __attribute__((long_call)) ListMenuLoadStdPalAt(u8 palOffset, u8 palId);
void __attribute__((long_call)) BlitMenuInfoIcon(u8 windowId, u8 iconId, u16 x, u16 y);

// menu
s8 __attribute__((long_call)) Menu_ProcessInputGridLayout(void);
u8 __attribute__((long_call)) MultichoiceGrid_InitCursor(u8 windowId, u8 fontId, u8 left, u8 top, u8 optionWidth, u8 cols, u8 rows, u8 cursorPos);
void __attribute__((long_call)) MultichoiceGrid_PrintItems(u8 windowId, u8 fontId, u8 itemWidth, u8 itemHeight, u8 cols, u8 rows, const struct MenuAction *strs);
void __attribute__((long_call)) DestroyYesNoMenu(void);
s8 __attribute__((long_call)) Menu_ProcessInputNoWrapClearOnChoose(void);
void __attribute__((long_call)) CreateYesNoMenu(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
void __attribute__((long_call)) AddItemMenuActionTextPrinters(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, const u8 *orderArray);
void __attribute__((long_call)) PrintMenuTable(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *strs);
void __attribute__((long_call)) MultichoiceList_PrintItems(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, u8 letterSpacing, u8 lineSpacing);
void __attribute__((long_call)) PrintTextArray(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *strs);
s8 __attribute__((long_call)) Menu_ProcessInputNoWrapAround_other(void);
s8 __attribute__((long_call)) Menu_ProcessInput_other(void);
s8 __attribute__((long_call)) Menu_ProcessInputNoWrapAround(void);
s8 __attribute__((long_call)) Menu_ProcessInput(void);
u8 __attribute__((long_call)) Menu_GetCursorPos(void);
u8 __attribute__((long_call)) Menu_MoveCursorNoWrapAround(s8 cursorDelta);
u8 __attribute__((long_call)) Menu_MoveCursor(s8 cursorDelta);
u8 __attribute__((long_call)) Menu_InitCursor(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos);
u8 __attribute__((long_call)) Menu_InitCursorInternal(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos, bool8 APressMuted);
void __attribute__((long_call)) TopBarWindowPrintTwoStrings(const u8 *string, const u8 *string2, bool8 fgColorChooser, u8 notUsed, bool8 copyToVram);
void __attribute__((long_call)) TopBarWindowPrintString(const u8 *string, u8 unUsed, bool8 copyToVram);
void __attribute__((long_call)) ClearTopBarWindow(void);
void __attribute__((long_call)) DestroyTopBarWindow(void);
u8 __attribute__((long_call)) CreateTopBarWindowLoadPalette(u8 bg, u8 width, u8 yPos, u8 palette, u16 baseTile);
void __attribute__((long_call)) ClearStdWindowAndFrameToTransparent(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) DrawStdFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum);
void __attribute__((long_call)) ClearDialogWindowAndFrameToTransparent(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) DrawDialogFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 tileNum, u8 paletteNum);

#endif // GUARD_MENU_H
