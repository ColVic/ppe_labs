#include "src/lab1.hpp"

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND clear_button, copy_button, text_box1, text_box2;
PAINTSTRUCT ps;
RECT rect;
LRESULT textSize;
HFONT hfont;
char box2[500];
int cxCoord, cyCoord, screenW, screenH;


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
    switch (message)
    {
        case WM_CREATE:
            OnWmCreate(hwnd, wParam, lParam);
            break;

        case WM_SIZE:
            OnWmSize(hwnd, wParam, lParam);
            break;

        case WM_PAINT:
            OnWmPaint(hwnd, wParam, lParam);
            break;

        case WM_DRAWITEM:
            OnWmDrawitem(hwnd, wParam, lParam); // redraw button
            break;

        case WM_COMMAND:
            OnWmCommand(hwnd, wParam, lParam);
            break;

        case WM_GETMINMAXINFO:
            OnWmGetminmaxinfo(hwnd, wParam, lParam);
            break;

        case WM_CTLCOLOREDIT:
            return OnWmCtlcoloredit(hwnd, wParam, lParam);

        case WM_CLOSE:
            if (MessageBox(hwnd, "Do you really want to quit?", "Victor's first lab", MB_OKCANCEL) == IDOK)
                DestroyWindow(hwnd);

            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
        }

    return 0;
}
