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
		cout << "один ";
		break;
	case 50:
		cout << "два ";
		break;
	case 51:
		cout << "три ";
		break;
	case 52:
		cout << "четыре ";
		break;
	case 53:
		cout << "п€ть ";
		break;
	case 54:
		cout << "шесть ";
		break;
	case 55:
		cout << "семь ";
		break;
	case 56:
		cout << "восемь ";
		break;
	case 57:
		cout << "дев€ть ";
		break;
	}
}
string hund(char str)
{
	string v;
	switch (str)
	{
	case 49:
		cout << "одна тыс€ча";
		break;
	case 50:
		cout << "две тыс€чи ";
		break;
	case 51:
		cout << "три тыс€чи";
		break;
	case 52:
		cout << "четыре тыс€чи ";
		break;
	case 53:
		cout << "п€ть тыс€чь";
		break;
	case 54:
		cout << "шесть тыс€ч ";
		break;
	case 55:
		 v = "семь тыс€ч ";
		
		break;
	case 56:
		cout << "восемь тыс€ч ";
		break;
	case 57:
		cout << "дев€ть тыс€ч ";
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