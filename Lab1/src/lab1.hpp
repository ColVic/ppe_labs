#ifndef _LAB1_HPP_
# define _LAB1_HPP_

#include <windows.h>
#include <stdlib.h>
#include <tchar.h>

#define IDC_BUTTON_1 1
#define IDC_BUTTON_2 2
#define IDC_TEXTAREA1 3
#define IDC_TEXTAREA2 4

extern HWND button1, button2, text_box1, text_box2;
extern PAINTSTRUCT ps;
extern RECT rect;
extern LRESULT textSize;
extern char box2[500];
extern int cxCoord, cyCoord, screenW, screenH;
extern HFONT hfont;

void OnWmCreate(HWND hwnd, WPARAM wParam, LPARAM lParam);
void OnWmSize(HWND hwnd, WPARAM wParam, LPARAM lParam);
void OnWmPaint(HWND hwnd, WPARAM wParam, LPARAM lParam);
void OnWmDrawitem(HWND hwnd, WPARAM wParam, LPARAM lParam);
void OnWmCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
void OnWmGetminmaxinfo(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK OnWmCtlcoloredit(HWND hwnd, WPARAM wParam, LPARAM lParam);

#endif