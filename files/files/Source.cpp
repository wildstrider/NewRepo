#include <iostream>
#include <fstream>
using namespace std;

#define tab "\t" 
int main()
{
	int size = 50;
	int* arr = new int[size];
	for (int i = 0; i < size; arr[i] = rand(), i++);
	ofstream file;
	file.open("D:\\array.txt");

	for (int i = 0; i < size;i++){

	if(i == size/10)
		file << arr[i] << tab;

	}
	file.close();
	delete[] arr;
	return 0;
}