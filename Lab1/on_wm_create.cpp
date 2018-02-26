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

    button1 = CreateWindowEx(
        NULL, "BUTTON", "Clear",
        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        0, 0, 0, 0,
        hwnd, (HMENU)IDC_BUTTON_1, NULL, NULL);

    button2 = CreateWindowEx(
        NULL, "BUTTON", "ReplacedName",
        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)IDC_BUTTON_2, NULL, NULL);

    text_box1 = CreateWindowEx(
        WS_EX_CLIENTEDGE, "EDIT", "",
        WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
        0, 0, 0, 0,
        hwnd, (HMENU)IDC_TEXTAREA1, NULL, NULL);

    text_box2 = CreateWindowEx(
        WS_EX_CLIENTEDGE, "EDIT", "",
        WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
        0, 0, 0, 0,
        hwnd, (HMENU)IDC_TEXTAREA2, NULL, NULL);
}
