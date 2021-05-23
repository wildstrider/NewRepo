#include <windows.h>
#include <CommCtrl.h>

#pragma comment(lib, "ComCtl32.lib")

TCHAR czClassName[] = L"myClass";
TCHAR czFormName[] = L"Это мое окно";
HWND hwndA;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY: PostQuitMessage(0); break;

    default: return DefWindowProc(hwnd, message, wParam, lParam); break;
    }
}

ATOM myRegistryClass(HINSTANCE hInst, int cmdMode)
{
    WNDCLASS cw;

    cw.style = CS_VREDRAW | CS_HREDRAW;
    cw.cbClsExtra = 0;
    cw.cbWndExtra = 0;
    cw.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    cw.hCursor = LoadCursor(NULL, IDC_ARROW);
    cw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    cw.hInstance = hInst;
    cw.lpfnWndProc = WndProc;
    cw.lpszClassName = czClassName;
    cw.lpszMenuName = NULL;

    RegisterClass(&cw);

    return 0;
}


BOOL InitInstance(HINSTANCE hInst, int Mode)
{


    hwndA = CreateWindow(
        czClassName,
        czFormName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInst,
        NULL);

    ShowWindow(hwndA, Mode);
    UpdateWindow(hwndA);

    return TRUE;
}


/*Главная функция*/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR IpszCmdParam, int cmdShow)
{
    MSG msg;

    myRegistryClass(hInst, cmdShow);
    InitInstance(hInst, cmdShow);

    InitCommonControls();

    /*Создание строки состояния*/
    HWND hStatusWindow = CreateStatusWindow(WS_CHILD | WS_VISIBLE, L"", hwndA, 5000);

    HMENU hmenu1;
    hmenu1 = CreateMenu();

    AppendMenu(hmenu1, MF_STRING, 0, L"&File");
    AppendMenu(hmenu1, MF_STRING, 0, L"&Edit");
    AppendMenu(hmenu1, MF_STRING, 0, L"&Help");

    SetMenu(hwndA, hmenu1);


    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}