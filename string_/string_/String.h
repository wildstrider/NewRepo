#pragma once
#include <iostream>
using namespace std;
#define tab "\t"
#define delimiter "====================================="
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
istream& operator>>(istream& in, String& other);

class String
{
	unsigned int size;
	char* str;
public:
	const char* GetStr() const;
	unsigned int Getsize()const;
	char* GetStr();

	void Setsize(int size);
	explicit String(unsigned int size = 80);
	String(const char str[]);
	String(String& other);
	String& operator=(const String& other);

	const  char& operator[](unsigned int i) const;
	char& operator[](unsigned int i);
	String(String&& other);

	String& operator=(String&& other);

	String& operator+=(const String& other);

	~String();
	void print() const;
	friend String operator+(const String& left, const String& right);
};
