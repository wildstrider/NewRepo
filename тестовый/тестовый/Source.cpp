#include <iostream>
using namespace std;
#define tab "\t"

void Fill(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			arr[i][j] = rand() % 200;
		}
    }

}

void Print(int**& arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}

void Pop_row_back(int**& arr, int& rows, int& cols, int value)
{
	cols -= value;
	int** buffer = new int* [rows]{};
	
	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols];
		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	system("pause");
	/*for (int i = ; i < rows + value; i++) {
		delete[] arr[i];
	}*/
	delete[] arr;
	arr = buffer;

}

int main()
{
	setlocale(LC_ALL, "ru");
	int rows, cols;
	cout << "строки: "; cin >> rows;
	cout << "колонки: "; cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {

		arr[i] = new int[cols];
	}
	system("pause");
	Fill(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << "==============================================" << endl;
	int v = 2;
	cout << "кол"; cin >> v;
	Pop_row_back(arr, rows, cols, v);
	
	cout << endl;
	Print(arr, rows, cols); 


	return 0;
}