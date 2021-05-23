//#include <iostream>
//using namespace std;
//
//
//int main()
//{
//
//
//	return 0;
//}


#include <windows.h>
int main()
{
    DWORD l;
    COORD point;
    point.X = 30; point.Y = 0;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
   // HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    //char title[] = "Консольная программа";
   // CharToOem(title, title);
   // SetConsoleTitle(title);
   // SetConsoleOutputCP(1251);
    SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
    FillConsoleOutputAttribute(hout, 0, 2000, point, &l); // очистка экрана
    for (int y = 0; y < 16; y++) {
        point.Y = y;
        FillConsoleOutputAttribute(hout, y << 4, 20, point, &l);
        SetConsoleCursorPosition(hout, point);
    }
    return 0;
}