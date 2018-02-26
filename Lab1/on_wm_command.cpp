#include "src/lab1.hpp"

void OnWmCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDC_BUTTON_1:
		SendMessage(text_box1, WM_SETTEXT, NULL, NULL);
		break;

	case IDC_BUTTON_2:
		textSize = SendMessage(text_box1, WM_GETTEXT, 100, (LPARAM)box2); // text size
		box2[textSize] = _T('\0');										  // initialization with null character
		SendMessage(text_box2, EM_REPLACESEL, 0, (LPARAM)box2);			  // add inputed text to window
		SendMessage(text_box2, EM_REPLACESEL, 0, (LPARAM) " ");
		RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
		break;
	}
}
