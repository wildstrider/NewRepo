#include <iostream>
using namespace std;
#define tab "\t"
#define delimiter "====================================="

class String
{
	unsigned int size;
	char* str;
public:
	const char* GetStr() const { return str; }
	unsigned int Getsize()const { return size; }
     char* GetStr() { return str; }

	void Setsize(int size) { this->size = size; }
   explicit	String(unsigned int size = 80): size(size), str(new char[size]{})
   { 
	  // this->size = size;
	  // this->str = new char[size] {};
	   cout << "defconstructor\t" << this << endl;
   }
	String (const char str[]):size(strlen(str) + 1), str(new char[size] {})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++) { this->str[i] = str[i]; }
		cout << "constractor\t" << this << endl;
	}
	String(String& other): size(other.size), str(new char[size] {})
	{
		//this->size = other.size;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++) { this->str[i] = other.str[i]; }
		cout << "CopyConstructor:\t" << this << endl;
	}
	String& operator=(const String& other)// : size(other.) список инициализации можно использовать только в крнструкторах
	{

		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) { this->str[i] = other.str[i]; }
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	const  char& operator[](unsigned int i) const { return str[i]; }
	char& operator[](unsigned int i) { return str[i]; }
	String(String&& other) : size(other.size), str(other.str)
	{
		// должен работать так как не должен работать констрактор
		// должен выполнять deepcopy а moveconts 
		//moveconst не должен выделять динамическую память
		//он использует память другого обьекта и передает ее создаваемому обьекту.
		//this->size = other.size;
		//this->str = other.str;
		other.str = nullptr;
		cout << "moveconstructor:\t" << this << endl;
	}
	String& operator=(String&& other)
	{
		delete[] str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "moveassigment: " << this << endl;
		return *this;
	}
	String& operator+=(const String& other) { return *this = *this + other; }

	~String() { delete[] this->str; cout << "dectructor\t" << this << endl; }
	void print() const
	{
		cout << "size: " << size << endl;
		cout << "str: " << str << endl;
	}
	friend String operator+(const String& left, const String& right);
};

ostream& operator<<(ostream& os, const String& obj) { return os << obj.GetStr(); }
String operator+(const String& left, const String& right)
{
	int s = 0;
	String temp;
	temp.Setsize(left.Getsize() + right.Getsize() - 1);
	for(int i = 0; i < temp.Getsize(); i++) { (i < left.Getsize() - 1)? temp[i] = left[i] : temp[i] = right[s++]; }
	return temp;
}
//istream& operator>>(istream& in, String& other) { cout << "Введите строку: "; return  in >> other.GetStr(); }
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
	String str1 = "hello";
	String str2 = "world";
	String str3 = str1;
	cout << delimiter << endl;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << "str3: " << str3 << endl;
	//str1 += str2;
	cout << "str1: " << (str1 += str2) << endl;
#endif // OPERATOR_PLUS_CHECK
	//String str1; // defalt constructor
	//String str2 = "hello"; // single argument constructor

	 


	return 0;
}