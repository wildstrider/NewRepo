/*1. ��� ���������� �������� � ����� ������� ������� � ������� ? ? ? push_back(? ? ? );
2. � ������ DynamicMemory �������� ������� :
? ? ? push_front(? ? ? );	//��������� �������� � ������ �������
? ? ? insert(? ? ? );		//��������� �������� � ������ �� ���������� �������
? ? ? pop_back(? ? ? );		//������� ��������� ������� �� �������
? ? ? pop_front(? ? ? );		//������� ������� ������� �� �������
? ? ? erase(? ? ? );			//������� ������� �� ������� �� ��������� �������
��� ���� ����� ������� ������� �� �������, � �������� ������ ����� ����������� ��� ����� ���������� ��������.*/




#include <iostream>
using namespace std;
#define tab "\t"

void Fillarr(int arr[], int s);
void Print(int arr[], int s);
void push_back(int arr[], int* buffer, int s, int n, int el, int N);
void Add_element();
void push_front();

void main()
{
	setlocale(LC_ALL, "ru");
	int s;
	cout << "������� ������ �������: "; cin >> s;
	int* arr = new int[s] {};
	Fillarr(arr, s);
	Print(arr, s);
	int n = 0, el, N1 = 0;
	Add_element(s);
	cout << "������� ����������� �������:" << endl;
	while (n != 0)
	{
		cin >> el;
		push_back(arr, buffer, k, n, el, N);
		n--;
	}
	Print(buffer, k);
	delete[] arr;
	arr = buffer;
	delete[] buffer;
}

void Fillarr(int arr[], int s)
	{
	for (int i = 0; i < s; i++) {

		arr[i] = rand() % 100;
    }
}
void Print(int arr[], int s) 
{

	for (int i = 0; i < s; i++) {
	
		cout << arr[i] << tab;
	}
	cout << endl;
}
void push_back(int arr[], int* buffer, int k, int n, int el, int N)
{
	for (int i = 0; i < k; i++) {

		if (N == n) {
			buffer[i] = arr[i];
		}
		if (i == k - n) {
			buffer[i] = el;
			break;
			
		}
		
	}		
}
void Add_element(int s)
{
	cout << "������� ���������� ����������� ���������: "; cin >> n;
	int k = s + n;
	int N = n;
	int* buffer = new int[k] {};
}
void push_front(int arr[], int* buffer, int k, int n, int el, int N)
{
	for (int i = 0; i < k; i++) {

        if (i == 0) {
			buffer[i] = el;
		}
		else
			buffer[i] = arr[i];
	}
}