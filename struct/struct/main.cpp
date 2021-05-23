#include <iostream>
using namespace std;

int main()
{
	struct magazin
	{
		string namefilm;
		string rejiser;
		string janr;
		float reyting;
		int price;
	}; 

	magazin evenger = { "evengers", "I", "fantezy", 8.9, 124 };
	cout << evenger.namefilm << endl;
	cout << evenger.rejiser << endl;
	cout << evenger.janr << endl;
	cout << evenger.reyting << endl;
	cout << evenger.price << endl;
	

	return 0;
}