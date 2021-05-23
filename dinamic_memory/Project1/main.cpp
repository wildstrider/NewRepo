/*1. ��� ���������� �������� � ����� ������� ������� � ������� ? ? ? push_back(? ? ? );
2. � ������ DynamicMemory �������� ������� :
? ? ? push_front(? ? ? );	//��������� �������� � ������ �������
? ? ? insert(? ? ? );		//��������� �������� � ������ �� ���������� �������
? ? ? pop_back(? ? ? );		//������� ��������� ������� �� �������
? ? ? pop_front(? ? ? );		//������� ������� ������� �� �������
? ? ? erase(? ? ? );			//������� ������� �� ������� �� ��������� �������
��� ���� ����� ������� ������� �� �������, � �������� ������ ����� ����������� ��� ����� ���������� ��������.*/

#include < iostream>
using namespace std;
#define tab "\t"

void Fillarr(int arr[], int size);
void Print(int arr[], int size);

void push_back(int arr[], int buffer[], int buf, int quan, int elem, int N);
void push_front(int arr[], int buffer[], int buf, int quan, int elem, int N, int k);
void insert(int arr[], int buffer[], int buf, int elem, int fir_in, int index, int las_in);
void Add_element(int arr[], int size);

void pop_back(int arr[], int buffer[], int buf);
void pop_front(int arr[], int buffer[], int buf, int del);
void erase(int arr[], int buffer[], int size, int index, int del, bool flag);
void Delete_element(int arr[], int size);

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	cout << "������� ������ �������: "; cin >> size;
	int* arr = new int[size];
	Fillarr(arr, size);
	Print(arr, size);
	int menu;
	cout << "�������� ��������." << endl;
	cout << "1 - ���������� ��������."
		"\n2 - �������� ��������" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		Add_element(arr, size);
		break;
	case 2:
		Delete_element(arr, size);
	}
	delete[] arr;
	int rep;
	cout << "��� ������� ������� 1(����� 0): "; cin >> rep;
	switch (rep)
	{
	case 1:
		main();
		break;
	case 0:
	    return 0;
	}
}

void Fillarr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {

		arr[i] = rand() % 100;
	}
}
void Print(int arr[], int size)
{

	for (int i = 0; i < size; i++) {

		cout << arr[i] << tab;
	}
	cout << endl;
}

void push_back(int arr[], int buffer[], int buf, int quan, int elem, int N)
{
	for (int i = 0; i < buf; i++) {

		if (N == quan) {
			buffer[i] = arr[i];
		}
		if (i == buf - quan) {
			buffer[i] = elem;
			break;
		}
	}
}
void push_front(int arr[], int buffer[], int buf, int quan, int elem, int N, int k)
{
	int j = 0;
	for (int i = 0; i < buf; i++) {

		if (quan >= 1) {
			buffer[k] = elem;		
		}
		if (quan == 1) {
		
			buffer[N++] = arr[j++];	
		}
    }
}
void insert(int arr[], int buffer[], int buf, int elem, int fir_in, int index, int las_in)
{
	for (int i = 0; i < buf; i++) {

		if (i < fir_in) {

			buffer[i] = arr[i];
		}
		if (i == index) {
			buffer[i] = elem;
		}
		if (index == las_in && i > index) {
			buffer[i] = arr[fir_in++];
		}
    }
}

void Add_element(int arr[],int size)
{
	int quan;
	cout << "������� ���������� ����������� ���������: "; cin >> quan;
	int buf = size + quan;
	int N = quan;// ���������� ����������� ��������� 
	int* buffer = new int[buf] {};

	cout << "������� � ����� ����� ������� �������� �������" << endl;
	cout << "1 - � ������"
		"\n2 - � �����"
		"\n3 - �� ���������� �������" << endl;
	int part_arr;
	cin >> part_arr;
	int k = 0;// ������ � ������� ���������� �������
	int elem;
	switch (part_arr)
	{
	case 1:
		cout << "������� ����������� �������:" << endl;
		
		while (quan != 0)
		{
			cin >> elem;
			push_front(arr, buffer, buf, quan, elem, N, k);
			quan--;
			k++;
		}
		Print(buffer, buf);
		break;
	 case 2:
		 cout << "������� ����������� �������:" << endl;
		while (quan != 0)
		{
			cin >> elem;
			push_back(arr, buffer, buf, quan, elem, N);
			quan--;
		}
		Print(buffer, buf);
		break;
	 case 3:
		 int index;
		 cout << "������� � ������ ������� ��������� ��������: "; cin >> index;
		 cout << "������� ����������� �������:" << endl;
		 int fir_in = index; //����� ������� � �������� �������� ����������
		 int las_in = index + (quan - 1);// ����� ������� ���������� ������������ ��������
		 while (quan != 0)
		 {
			 cin >> elem;
			 insert(arr, buffer, buf, elem, fir_in, index, las_in);
			 quan--;
			 index++;
		 }
	    Print(buffer, buf);
		break;
	}
	delete[] buffer;
}

void pop_back(int arr[], int buffer[], int buf)
{
	for (int i = 0; i < buf; i++) {

		buffer[i] = arr[i];
    }
}
void pop_front(int arr[], int buffer[], int buf, int del)
{
	for (int i = 0; i < buf; i++) {

		buffer[i] = arr[del++];
	}
}
void erase(int arr[], int buffer[], int size, int index, int del, bool flag)
{
	int x;
	switch (flag) {
	case false:
		for (int i = 0, j = 0; i < size; i++) {

			if (i == index) {
				continue;
			}
			buffer[j++] = arr[i];
		}
		break;
	case true:
		x = index + del;
		for (int i = 0, j = 0; i < size; i++) {

			if (i == index && index < x) {
				index++;
				continue;
			}
			buffer[j++] = arr[i];
		}
    }
}

void Delete_element(int arr[], int size)
{
	int del;
	cout << "������� ���������� ��������� ���������: "; cin >> del;
	while (del >= size)
	{
		cout << "����������� ����!!! ���������� ��� ���."; cin >> del;
	}
	int buf = size - del;
	int* buffer = new int[buf] {};

	cout << "������� �� ����� ����� ������� ������� ��������" << endl;
	cout << "1 - ������"
		"\n2 - �����"
		"\n3 - �� ���������� �������" << endl;
	int part_arr;
	cin >> part_arr;
	switch (part_arr)
	{
	case 1:
		pop_front(arr, buffer, buf, del);
		Print(buffer, buf);
		break;
	case 2:
		pop_back(arr, buffer, buf);
		Print(buffer, buf);
		break;
	case 3:
		int index;
		bool flag = false;
		if (del > 1) {

			flag = true;
			cout << "������� � ������ ������� ������ ������� ��������: "; 
		}
		else
		    cout << "������� �� ������ ������� ������� �������: ";

		cin >> index;
		while (index + del > size)
		{
	       cout << "����������� ����!!! ���������� ��� ���."; cin >> index;
		}
		erase(arr, buffer, size, index, del, flag);
		Print(buffer, buf);
	}
	delete[] buffer;
}