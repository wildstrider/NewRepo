#include "String.h"

const char* String::GetStr() const { return str; }
unsigned int String::Getsize()const { return size; }
char* String::GetStr() { return str; }

void String::Setsize(int size) { this->size = size; }
String::String(unsigned int size) : size(size), str(new char[size] {})
{
	// this->size = size; 
	// this->str = new char[size] {}; 
	cout << "defconstructor\t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{

	for (int i = 0; str[i]; i++) { this->str[i] = str[i]; }
	cout << "constractor\t" << this << endl;
}
String::String(String& other) : String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) { this->str[i] = other.str[i]; }*/
	cout << "CopyConstructor:\t" << this << endl;
}
String& String::operator=(const String& other)
{

	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) { this->str[i] = other.str[i]; }
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
const  char& String::operator[](unsigned int i) const { return str[i]; }
char& String::operator[](unsigned int i) { return str[i]; }
String::String(String&& other)
{
	// должен работать так как не должен работать констрактор
	// должен выполнять deepcopy а moveconts 
	//moveconst не должен выделять динамическую память
	//он использует память другого обьекта и передает ее создаваемому обьекту.
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "moveconstructor:\t" << this << endl;
}
String& String::operator=(String&& other)
{
	delete[] str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "moveassigment: " << this << endl;
	return *this;
}
String& String::operator+=(const String& other) { return *this = *this + other; }

String::~String() { delete[] this->str; cout << "dectructor\t" << this << endl; }
void String::print() const
{
	cout << "size: " << size << endl;
	cout << "str: " << str << endl;
}
//friend String operator+(const String& left, const String& right);


ostream& operator<<(ostream& os, const String& obj) { return os << obj.GetStr(); }
String operator+(const String& left, const String& right)
{
	int s = 0;
	String temp;
	temp.Setsize(left.Getsize() + right.Getsize() - 1);
	for (int i = 0; i < temp.Getsize(); i++) { (i < left.Getsize() - 1) ? temp[i] = left[i] : temp[i] = right[s++]; }
	return temp;
}
istream& operator>>(istream& in, String& other) { cout << "Введите строку: "; return  in >> other.GetStr(); }