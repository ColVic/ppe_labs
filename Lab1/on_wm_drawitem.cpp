#include "src/lab1.hpp"

void OnWmDrawitem(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if ((UINT)wParam == IDC_BUTTON_2)
	{
		LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT *)lParam;
		SIZE size;
		char button2[11];
		strcpy(button2, "Copy text");
		GetTextExtentPoint32(lpdis->hDC, button2, strlen(button2), &size);
		SetBkColor(lpdis->hDC, RGB(255, 0, 102));
		SetTextColor(lpdis->hDC, RGB(0, 0, 255));

		ExtTextOut(
			lpdis->hDC,
			((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
			((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
			ETO_OPAQUE | ETO_CLIPPED,
			&lpdis->rcItem,
			button2,
			strlen(button2),
			NULL);

		DrawEdge(
			lpdis->hDC,
			&lpdis->rcItem,
			(lpdis->itemState & ODS_SELECTED ? EDGE_SUNKEN : EDGE_RAISED),
			BF_RECT);
	}
}
