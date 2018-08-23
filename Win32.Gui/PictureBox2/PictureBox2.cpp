#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <CommCtrl.h>
#include "PictureBox2.h"

HWND form;
HWND panel1;
HWND pictureBox1;
HBITMAP picture;
WNDPROC defWndProc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
  if (message == WM_CLOSE && hwnd == form) PostQuitMessage(0);
  return CallWindowProc(defWndProc, hwnd, message, wParam, lParam);
}

int main(int argc, char* argv[]) {
  form = CreateWindowEx(0, WC_DIALOG, L"PictureBox example", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 316, 340, nullptr, nullptr, nullptr, nullptr);
  panel1 = CreateWindowEx(0, WC_DIALOG, nullptr, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_BORDER, 10, 10, 280, 280, form, nullptr, nullptr, nullptr);
  pictureBox1 = CreateWindowEx(0, WC_STATIC, L"", WS_CHILD | WS_VISIBLE | SS_BITMAP, 30, 15, 280, 280, panel1, nullptr, nullptr, nullptr);
  picture = LoadBitmap(GetModuleHandle(nullptr), MAKEINTRESOURCE(ID_BITMAP_LOGO));
  SendMessage(pictureBox1, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)picture);;

  defWndProc = (WNDPROC)SetWindowLongPtr(form, GWLP_WNDPROC, (LONG_PTR)WndProc);

  ShowWindow(form, SW_SHOW);

  MSG message;
  while (GetMessage(&message, nullptr, 0, 0))
    DispatchMessage(&message);
  return (int)message.wParam;
}