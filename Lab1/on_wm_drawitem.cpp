#include "src/lab1.hpp"

void OnWmDrawitem(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if ((UINT)wParam == COPY_BUTTON)
	{
		LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT *)lParam;
		SIZE size;
		char * copy_button_text = "Copy text";
		GetTextExtentPoint32(lpdis->hDC, copy_button_text, strlen(copy_button_text), &size);
		SetBkColor(lpdis->hDC, RGB(255, 0, 102));
		SetTextColor(lpdis->hDC, RGB(0, 0, 255));

		ExtTextOut(
			lpdis->hDC,
			((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
			((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
			ETO_OPAQUE | ETO_CLIPPED,
			&lpdis->rcItem,
			copy_button_text,
			strlen(copy_button_text),
			NULL);

		DrawEdge(
			lpdis->hDC,
			&lpdis->rcItem,
			(lpdis->itemState & ODS_SELECTED ? EDGE_SUNKEN : EDGE_RAISED),
			BF_RECT);
	}
}