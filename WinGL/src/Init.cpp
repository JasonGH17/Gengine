#include "include/WinGL.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinGL::Init(const wchar_t CLASSNAME[], const wchar_t WNDNAME[])
{
    WNDCLASSEX wc = { };

    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = CLASSNAME;
    wc.lpszMenuName = WNDNAME;
    wc.style = NULL;
    wc.lpfnWndProc = &WindowProc;

    if (m_hwnd == NULL)
    {
        return 0;
    }

    ::RegisterClassEx(&wc);

    m_hwnd = ::CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW, CLASSNAME, WNDNAME, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
        NULL, NULL, NULL, this
    );


    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	initialized = 1;
    return 1;
}

LRESULT CALLBACK WindowProc(HWND m_hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
}