#include "src/lab1.hpp"

void OnWmCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    LOGFONT logFont;

    memset(&logFont, 0, sizeof(logFont));
    logFont.lfHeight = 20;
    logFont.lfWeight = FW_BOLD;
    logFont.lfPitchAndFamily = FF_MODERN;
    strcpy(logFont.lfFaceName, "Broadway");
    hfont = CreateFontIndirect(&logFont);

    clear_button = CreateWindowEx(
        NULL, "BUTTON", "Clear",
        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        0, 0, 0, 0,
        hwnd, (HMENU)CLEAR_BUTTON, NULL, NULL);

    copy_button = CreateWindowEx(
        NULL, "BUTTON", "ReplacedName",
        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)COPY_BUTTON, NULL, NULL);

    text_box1 = CreateWindowEx(
        WS_EX_CLIENTEDGE, "EDIT", "",
        WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
        0, 0, 0, 0,
        hwnd, (HMENU)FIRST_TEXTAREA, NULL, NULL);

    text_box2 = CreateWindowEx(
        WS_EX_CLIENTEDGE, "EDIT", "",
        WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
        0, 0, 0, 0,
        hwnd, (HMENU)SECOND_TEXTAREA, NULL, NULL);
}
