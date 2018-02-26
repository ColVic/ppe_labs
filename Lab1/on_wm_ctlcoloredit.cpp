#include "src/lab1.hpp"

LRESULT CALLBACK OnWmCtlcoloredit(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (SECOND_TEXTAREA == GetDlgCtrlID((HWND)lParam))
	{
		HDC hdcStatic = (HDC)wParam;
		SetBkColor(hdcStatic, RGB(255, 200, 200));
		return (INT_PTR)CreateSolidBrush(RGB(255, 200, 200));
	}
}