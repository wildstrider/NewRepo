#include "Menu.h"
#include "rows_arr.h"
#include <iostream>
using namespace std;

template <typename T> void Menu(T** arr, int rows, int cols)
{   
	cout << "1 - ������ � ��������." << endl;
	cout << "2 - ������ � ���������." << endl;
	int work; cin >> work;
	switch (work)
	{
	case 1:
		rows_arr(arr, rows, cols);
		break;
	}
}