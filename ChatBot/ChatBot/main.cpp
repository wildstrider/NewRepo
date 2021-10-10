#include <iostream>
#include <string>
using namespace std;

class ChatBot
{
protected:
	string* massege;
	int size;
public:
	ChatBot(string* massage) { this->massege = massage; }
	virtual void display() = 0; 
};

class Bot1 : ChatBot
{
public:
	Bot1(string* massege):ChatBot(massege){}
	void display()
	{
		cout << *massege << endl;
	}
};
int main()
{
	cout << "enter string " << endl;
	string M;
	getline(cin, M);
	Bot1 B(&M);
	B.display();

	return 0;
}