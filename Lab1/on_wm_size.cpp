#include "src/lab1.hpp"

void OnWmSize(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    cxCoord = LOWORD(lParam); // 550
    cyCoord = HIWORD(lParam); // 375

    // give position to elements
    MoveWindow(
        button1,
        cxCoord - 150, 40,
        100, 40,
        TRUE);

    MoveWindow(
        button2,
        cxCoord - 150, cyCoord / 2 + 40,
        100, 40,
        TRUE);

    MoveWindow(
        text_box1,
        15, 40,
        cxCoord - 200, cyCoord / 3,
        TRUE);

    MoveWindow(
        text_box2,
        15, cyCoord / 2 + 40,
        cxCoord - 200, cyCoord / 3,
        TRUE);
}