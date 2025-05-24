#pragma once

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class VWindow
{
private:
    HINSTANCE m_hInstance;
    HWND m_hWnd;

public:
    VWindow();
    VWindow(const VWindow &) = delete;
    VWindow &operator=(const VWindow &) = delete;
    ~VWindow();

    bool ProcessMessages();
};
