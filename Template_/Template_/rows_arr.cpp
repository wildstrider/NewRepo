#include "rows_arr.h"
#include "Menu.h"
#include <iostream>
using namespace std;


template <typename T> void push_rows_front(T**& arr, int& rows, int cols)
{
	int r = rows + 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			if (i == 0) {
				buffer[i][j] = 1;
			}
			else
				buffer[i][j] = arr[i - 1][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;


}
template <typename T> void push_rows_back(T**& arr, int& rows, int cols)
{
	int r = rows + 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			if (i == r - 1) {
				buffer[i][j] = 1;
			}
			else
				buffer[i][j] = arr[i][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
template <typename T> void insert_rows(T**& arr, int& rows, int cols)
{
	int index, temp = 0;
	cout << "Введите куда встваить строку: "; cin >> index;
	int r = rows + 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			if (i == index) {
				buffer[i][j] = 1;
			}
			else
				buffer[i][j] = arr[temp][j];

		}
		if (i != index)
			temp++;
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
template <typename T> void Add_rows(T**& arr, int& rows, int cols)
{
	int choice;
	cout << "Выберите куда добавить строку." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		push_rows_front(arr, rows, cols);
		break;
	case 2:
		push_rows_back(arr, rows, cols);
		break;
	case 3:
		insert_rows(arr, rows, cols);
	}
}

template <typename T> void pop_rows_front(T**& arr, int& rows, int cols)
{
	int r = rows - 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i + 1][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;

}
template <typename T> void pop_rows_back(T**& arr, int& rows, int cols)
{
	int r = rows - 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
template <typename T> void erase_rows(T**& arr, int& rows, int cols, int index)
{
	int index, temp = 0;
	
	int r = rows - 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		if (i == index) {
			temp++;
		}
		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[temp][j];
		}
		temp++;
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
template <typename T> void Delete_rows(T**& arr, int& rows, int cols)
{
	int choice, index;
	cout << "Выберите какую строку удалить." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_rows_front(arr, rows, cols);
		break;
	case 2:
		pop_rows_back(arr, rows, cols);
		break;
	case 3:
		cout << "Введите какую строку удалить: "; cin >> index;
		erase_rows(arr, rows, cols, index);
	}
}


template <typename T> void rows_arr(T**& arr, int rows, int cols)
{
	cout << "1 - Добавление строк." << endl;
	cout << "2 - Удаление строк." << endl;
	int x; cin >> x;
		switch (x)
		{
		case 1:
			Add_rows(arr, rows, cols);
			break;
		case 2:
			Delete_rows(arr, rows, cols);
		}
}
