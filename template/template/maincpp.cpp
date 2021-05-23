#include <iostream>
#include "Fill.h"
using namespace std;
#define tab "\t"

//template <typename T> void fillrand(T** arr, int rows, int cols, T x);
template <typename T> void Print(T** arr, int rows, int cols, T x);
//template <typename T> void buffer();
template <typename T> void push_cols_front(T**& arr, int rows, int& cols, T x);

int main()
{
	setlocale(LC_ALL, "rus");
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество колонок: "; cin >> cols;

	double** arr = new double* [rows] {};
	for (int i = 0; i < rows; i++) {

		arr[i] = new double[cols] {};
	}
	double x = 2.5;
	fillrand(arr, rows, cols, x);
	Print(arr, rows, cols, x);
	push_cols_front(arr, rows, cols, x);
	cout << endl;
	Print(arr, rows, cols, x);

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;

	cout << "========================================" << endl;

	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols] {};
	}

	int y = 4;
	fillrand(buffer, rows, cols, y);
	Print(buffer, rows, cols, y);

	for (int i = 0; i < rows; i++) {

		delete[] buffer[i];
	}
	delete[] buffer;

	cout <<"==========================================" << endl;

	char k = '#';
	char** buffer2 = new char* [rows];
	for (int i = 0; i < rows; i++) {

		buffer2[i] = new char[cols];
	}
	fillrand(buffer2, rows, cols, k);
	Print(buffer2, rows, cols, k);

	for (int i = 0; i < rows; i++) {

		delete[] buffer2[i];
	}
	delete[] buffer2;
	return 0;
}

//template <typename T> void fillrand(T** arr, int rows, int cols, T x)
//{
//	for (int i = 0; i < rows; i++) {
//
//		for (int j = 0; j < cols; j++) {
//
//			arr[i][j] = x;
//		}
//	}
//	
//}
template <typename T> void Print(T** arr, int rows, int cols, T x)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;

	
}
//template <typename T> void buffer()
//{
//	T** buffer = new T[rows];
//}

template <typename T> void push_cols_front(T**& arr, int rows, int& cols, T x)
{
	cols++;
	T** buffer = new T* [rows] {};

	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols];

		for (int j = 0; j < cols; j++) {

			if (j == 0) {
				buffer[i][j] = x + 10;
			}
			else
				buffer[i][j] = arr[i][j - 1];
		}
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
