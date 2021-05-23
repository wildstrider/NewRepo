#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
//using namespace std;
//#define VERTICAL "\n\n\n\n\n\n\n\n"
//#define HORIZONT "\t\t\t\t\t\t"

//int foo(int n, ...);
//
//int main(int argc, char* argv[])
//{
//	int arr[] = { 3, 5, 8, 13, 21, 34 };
//	int n = 1, m = 2, g = 3, h = 3, y = 4, t = 5, r = 6, l = 10, q = 5;
//	cout << endl;
//	//cout << foo(n, m, g, h, y, t, r, l, q, 0);
//	cout << foo(3, 5, 8, 13, 21, 34, 55) << endl;
//	return 0;
//}
//
//int foo(int n, ...)
//{
//	int* num = &n;
//	int sum = 0;
//	while (*num) sum += *num++;
//	return sum;
//}

//HWND hwndA;


int main()
{
	WNDCLASSA wcl;
	   memset(&wcl, 0, sizeof(WNDCLASSA));
	   wcl.lpszClassName = "my Window";
	   wcl.lpfnWndProc = DefWindowProcA;
	RegisterClassA(&wcl);

	HWND hwnd;
	hwnd = CreateWindow( TEXT("my Window"), TEXT("Window Name"), 
		                 WS_OVERLAPPEDWINDOW,
	                     10, 10, 640, 480, NULL, NULL, NULL, NULL);

	ShowWindow(hwnd, SW_SHOWNORMAL);

	HWND bt_quit;
	bt_quit = CreateWindow(TEXT("button"), TEXT("Quit"),
		                   WS_VISIBLE | WS_CHILD,
		                   10, 10, 100, 50, hwnd, NULL, NULL, NULL);

	HWND bt_exit;
	bt_quit = CreateWindow(TEXT("button"), TEXT("Exit"),
		                   WS_VISIBLE | WS_CHILD,
		                   150, 10, 100, 50, hwnd, NULL, NULL, NULL);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return 0;
}