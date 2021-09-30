#include "String.h"

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK


int main()
{
	setlocale(LC_ALL, "ru");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();
	String str1 = "hello";
	str1 = str1;
	str1.print();
	String str2 = str1;
	cout << str2 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif 
#ifdef OPERATOR_PLUS_CHECK
	/*String str;
cin >> str;
cout << str << endl;*/
	//String str1 = "hello";
	//String str2 = "world";
	//String str3 = str1;
	//cout << delimiter << endl;
	//str3 = str1 + str2;
	//cout << delimiter << endl;
	//cout << "str3: " << str3 << endl;
	////str1 += str2;
	//cout << "str1: " << (str1 += str2) << endl;
#endif // OPERATOR_PLUS_CHECK
	//String str1; // defalt constructor
	//String str2 = "hello"; // single argument constructor

	 


	return 0;
}