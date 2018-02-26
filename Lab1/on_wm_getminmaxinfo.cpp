#include "src/lab1.hpp"

void OnWmGetminmaxinfo(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	LPMINMAXINFO winSize = (LPMINMAXINFO)lParam;
    winSize->ptMinTrackSize.x = 400;
    winSize->ptMinTrackSize.y = 425;
    winSize->ptMaxTrackSize.x = 700;
    winSize->ptMaxTrackSize.y = 700;
}