#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	const int s = 255;
	char str[s];
	cin >> str;
	cout << str << endl;
	int sum = 0, sum2 = 0;
	const int x = 10;
	int res[x]{};
	for (int i = 0, j=0; str[i]; i++) {
		if (str[i] >= 48 && str[i] <= 57 && str[i+1] >= 48 && str[i+1] <= 57) res[j++] = str[i] - 48;
	}
	for (int i = 0; res[i] > 0; i++) {

	}


	for (int i = 0; i < x; i++) {
		cout << res[i] << " ";
	}


	return 0;
}