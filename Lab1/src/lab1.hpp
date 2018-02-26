#ifndef _LAB1_HPP_
# define _LAB1_HPP_

#include <windows.h>
#include <stdlib.h>
#include <tchar.h>

#define CLEAR_BUTTON 1
#define COPY_BUTTON 2
#define FIRST_TEXTAREA 3
#define SECOND_TEXTAREA 4

extern HWND clear_button, copy_button, text_box1, text_box2;
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