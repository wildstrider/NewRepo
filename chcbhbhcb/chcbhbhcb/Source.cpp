#include <iostream>
#include <Windows.h>
using namespace std;



int  to_int_number(char str[])
{
	int x, y = 0;
	int s = strlen(str) - 1;
	int sum = pow(10, s);
	for (int i = 0; str[i]; i++) {

		x = sum * (str[i] - '0');
		y += x;
		sum /= 10;
	}
	return y;
}

void dec(char str) {
	
	switch (str)
	{
	case 49:
		cout << "���� ";
		break;
	case 50:
		cout << "��� ";
		break;
	case 51:
		cout << "��� ";
		break;
	case 52:
		cout << "������ ";
		break;
	case 53:
		cout << "���� ";
		break;
	case 54:
		cout << "����� ";
		break;
	case 55:
		cout << "���� ";
		break;
	case 56:
		cout << "������ ";
		break;
	case 57:
		cout << "������ ";
		break;
	}
}
string hund(char str)
{
	string v;
	switch (str)
	{
	case 49:
		cout << "���� ������";
		break;
	case 50:
		cout << "��� ������ ";
		break;
	case 51:
		cout << "��� ������";
		break;
	case 52:
		cout << "������ ������ ";
		break;
	case 53:
		cout << "���� ������";
		break;
	case 54:
		cout << "����� ����� ";
		break;
	case 55:
		 v = "���� ����� ";
		
		break;
	case 56:
		cout << "������ ����� ";
		break;
	case 57:
		cout << "������ ����� ";
		break;
	}
	return v;
}

string foo(char str[], int s) {
	const int f = 3;
	string v[f];
	int sum = pow(10, (s - 1));
	for (int i = 0; str[i]; i++) {

		
		switch (s)
		{
		case 1:
		
			
			break;
		case 2:

			break;
		case 3:
              v[i] = hund(str[i]);
			cout << v[i];
			break;
		}
	}
	return *v;
}


int main() {
	int k = 0;
	const int s = 50;
	char str[s];
	//SetConsoleCP(1251);
	SetConsoleOutputCP(866);
	cin.getline(str, s);
	int h = strlen(str);
	cout << str << endl;
	int num = to_int_number(str);
	//cout << "int - " <<  num << endl;
	//SetConsoleCP(866);
	SetConsoleOutputCP;
	cout << foo(str, h);

}