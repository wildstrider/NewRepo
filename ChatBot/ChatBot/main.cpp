#include <iostream>
//#include <string>
using namespace std;

class ChatBot
{
protected:
	char* massege;
public:
	ChatBot(char* massage) { this->massege = massage; } 
	bool comparing(char* ant)
	{
		for (int i = 0; i < strlen(ant) - 1; i++)
		{
			if (ant[i] != massege[i]) { return false; }
		}
		return true;
	}
	virtual void Ans() = 0;
};
class Bot1 : ChatBot
{
public:
	Bot1(char* massege):ChatBot(massege){}
	void Ans()
	{
		char sam[] = "Good";
		if (comparing(sam)) { cout << "it's good keep it up" << endl; }
	}
};

class Bot2 : ChatBot
{
public:
	Bot2(char* massege) :ChatBot(massege) {}
	
	void Ans()
	{
		char sam[] = "Bad";
		if (comparing(sam)) { cout << ":( Cheer up everything will work out" << endl; }
	}
};
int main()
{
	cout << "How are you? (Bab or Good)" << endl;
	char M[256];
	cin.getline(M, 256);
	Bot1 B(M);
	B.Ans();
	Bot2 A(M);
	A.Ans();
	return 0;
}