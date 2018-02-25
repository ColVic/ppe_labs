#include <windows.h>
#include <stdlib.h>
#include <tchar.h>

#define IDC_BUTTON_1 1
#define IDC_BUTTON_2 2
#define IDC_TEXTAREA1 3
#define IDC_TEXTAREA2 4

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

char szClassName[ ] = "CodeBlocksWindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
  HWND hwnd;               /* This is the handle for our window */
  MSG messages;            /* Here messages to the application are saved */
  WNDCLASSEX wincl;        /* Data structure for the windowclass */

  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = szClassName;
  wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
  wincl.style = CS_HREDRAW | CS_VREDRAW;              /* Catch double-clicks */
  wincl.cbSize = sizeof (WNDCLASSEX);

  wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
  wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
  wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
  wincl.lpszMenuName = NULL;                 /* No menu */
  wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
  wincl.cbWndExtra = 0;                      /* structure or the window instance */

  wincl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

  if (!RegisterClassEx (&wincl))
    return 0;

  hwnd = CreateWindowEx (
    0,                   /* Extended possibilites for variation */
    szClassName,         /* Classname */
    "PPE Lab#1 Colta Victor",  /* Title Text */
    WS_OVERLAPPEDWINDOW, /* default window */
    CW_USEDEFAULT,       /* Windows decides the position */
    CW_USEDEFAULT,       /* where the window ends up on the screen */
    550,                 /* The programs width */
    375,                 /* and height in pixels */
    HWND_DESKTOP,        /* The window is a child-window to desktop */
    NULL,                /* No menu */
    hThisInstance,       /* Program Instance handler */
    NULL                 /* No Window Creation data */
  );

  ShowWindow (hwnd, nCmdShow);

  while (GetMessage (&messages, NULL, 0, 0)){
    /* Translate virtual-key messages into character messages */
    TranslateMessage(&messages);
    /* Send message to WindowProcedure */
    DispatchMessage(&messages);
  }

  return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rect;
    static HWND button1, button2, text_box1, text_box2;
    static int cxCoord, cyCoord;
    LRESULT textSize;
    char box2[500];
    int screenW, screenH;

    switch (message){
        case WM_CREATE:
            button1 = CreateWindowEx(
                NULL, "BUTTON", "Clear",
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON ,
                0, 0, 0, 0,
                hwnd, (HMENU)IDC_BUTTON_1, NULL, NULL
            );
            button2 = CreateWindowEx(
                NULL, "BUTTON", "ReplacedName",
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON|BS_OWNERDRAW,
                0, 0, 0, 0,
                hwnd, (HMENU)IDC_BUTTON_2, NULL, NULL
            );
            text_box1 = CreateWindowEx(
                WS_EX_CLIENTEDGE, "EDIT", "",
                WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
                0, 0, 0, 0,
                hwnd, (HMENU)IDC_TEXTAREA1, NULL, NULL
            );
            text_box2 = CreateWindowEx(
                WS_EX_CLIENTEDGE, "EDIT", "",
                WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
                0, 0, 0, 0,
                hwnd, (HMENU)IDC_TEXTAREA2, NULL, NULL
            );
            break;

        case WM_SIZE:
            cxCoord = LOWORD(lParam); // 550
            cyCoord = HIWORD(lParam); // 375
            // give position to elements
            MoveWindow(
                button1,
                cxCoord-150, 40,
                100, 40,
                TRUE
            );
            MoveWindow(
                button2,
                cxCoord-150, cyCoord/2+40,
                100, 40,
                TRUE
            );
            MoveWindow(
                text_box1,
                15, 40,
                cxCoord-200, cyCoord/3,
                TRUE
            );
            MoveWindow(
                text_box2,
                15, cyCoord/2+40,
                cxCoord-200, cyCoord/3,
                TRUE
            );
            break;

     case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);

        DrawText(
            hdc, "Pay attention, this text will split into lines if the window is too small",
            -1, &rect, DT_WORDBREAK | DT_CENTER | DT_TOP
        );
        DrawText(
            hdc, "One does not simply make the fist laboratory.",
            -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER
        );

        SetBkColor(hdc, RGB(204, 255, 102));
        SetTextColor(hdc, RGB(0, 102, 255));

        DrawText(
            hdc, "Goodbye. :)",
            -1, &rect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM
        );

        EndPaint(hwnd, &ps);

        return 0;
        break;

    case WM_DRAWITEM:
        // redraw button
        if ((UINT)wParam == IDC_BUTTON_2) {
            LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT*)lParam;
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
                (lpdis->itemState & ODS_SELECTED ? EDGE_SUNKEN : EDGE_RAISED ),
                BF_RECT);
            return TRUE;
        }
        break;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
            case IDC_BUTTON_1:
                SendMessage(text_box1, WM_SETTEXT, NULL, NULL);
                break;

            case IDC_BUTTON_2:
                textSize = SendMessage(text_box1, WM_GETTEXT, 100, (LPARAM)box2); // text size
                box2[textSize] = _T('\0');                                        // initialization with null character
                SendMessage(text_box2, EM_REPLACESEL, 0, (LPARAM)box2);           // add inputed text to window
                SendMessage(text_box2, EM_REPLACESEL, 0, (LPARAM)" ");
                RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
                break;
        }
        break;

    case WM_GETMINMAXINFO:{
        LPMINMAXINFO winSize = (LPMINMAXINFO)lParam;
        winSize->ptMinTrackSize.x = 400;
        winSize->ptMinTrackSize.y = 425;
        winSize->ptMaxTrackSize.x = 700;
        winSize->ptMaxTrackSize.y = 700;
        break;
    }

    case WM_CTLCOLOREDIT:
        if (IDC_TEXTAREA2 == GetDlgCtrlID((HWND)lParam))
            {
                HDC hdcStatic = (HDC) wParam;
                SetBkColor(hdcStatic, RGB(255,255,204));
                return (INT_PTR)CreateSolidBrush(RGB(255,255,204));
            }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
        break;
    }

    return 0;
}