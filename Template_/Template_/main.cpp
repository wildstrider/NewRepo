#include <iostream>
#include "rows_arr.h"
#include "Menu.h"


#define tab "\t"

using namespace std;

template <typename T> void New_arr(T**& arr1, int rows, int cols) {

	T** arr = new T * [rows] {};
	for (int i = 0; i < rows; i++) {

		arr[i] = new T[cols]{};
	}
	//system("pause");
	arr1 = arr;
	
}

template <typename T> void Delete_arr(T** arr,int rows)
{
	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;

}


template <typename T> void Fill(T** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {


		for (int j = 0; j < cols; j++) {
			
			
			 arr[i][j] = rand()%255;
		}
    }
	
}

template <typename T> void Print(T** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	int rows;
	cout << "Введите количество строк: "; cin >> rows;
	int cols;
	cout << "Введите количество колонок: "; cin >> cols;
	cout << "Выберите тип данных" << endl;
	cout << "1 - int"
		"\n2 - double"
		"\n3 - char" << endl;
	int** arr = 0;
	double** arr1 = nullptr;
    char** arr2 = nullptr;
	
	int Type; cin >> Type;
	switch (Type)
	{
	case 1:
	    New_arr(arr, rows, cols);
		Fill(arr, rows, cols);
	    Print(arr, rows, cols);
		Menu(arr, rows, cols);
	    Delete_arr(arr, rows);
		break;
	case 2:
		New_arr(arr1, rows, cols);
		Fill(arr1, rows, cols);
		Print(arr1, rows, cols);
		//Menu(arr1, rows, cols);
		Delete_arr(arr1, rows);
		break;
	case 3:
		New_arr(arr2,rows, cols);
		Fill(arr2, rows, cols);
		Print(arr2, rows, cols);
		//Menu(arr2, rows, cols);
		Delete_arr(arr2, rows);
		
	}
	
	//Print(arr, rows, cols);

	return 0;
}