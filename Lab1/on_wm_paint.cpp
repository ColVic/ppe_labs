#include "src/lab1.hpp"

void OnWmPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);

	DrawText(
		hdc, "Pay attention, this text will split into lines if the window is too small",
		-1, &rect, DT_WORDBREAK | DT_CENTER | DT_TOP);

	SelectObject(hdc, hfont);

	DrawText(
		hdc, "One does not simply make the fist laboratory",
		-1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	SetBkColor(hdc, RGB(204, 255, 102));
	SetTextColor(hdc, RGB(0, 102, 255));

	DrawText(
		hdc, "Goodbye. :)",
		-1, &rect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);

	EndPaint(hwnd, &ps);
}