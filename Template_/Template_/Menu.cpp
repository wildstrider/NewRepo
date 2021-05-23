#include "Menu.h"
#include "rows_arr.h"
#include <iostream>
using namespace std;

template <typename T> void Menu(T** arr, int rows, int cols)
{   
	cout << "1 - Работа с строками." << endl;
	cout << "2 - Работа с колонками." << endl;
	int work; cin >> work;
	switch (work)
	{
	case 1:
		rows_arr(arr, rows, cols);
		break;
	}
}