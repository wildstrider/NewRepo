#include <iostream>
using namespace std;
class Pet
{
protected:
	string name;
	double weight;
	int age;
	string breed;
public:
	Pet(string name, double weight, int age, string breed) : name{ name }, weight{ weight }, age{ age }, breed{ breed } {}
	void display()
	{
		cout << "name " << name << endl;
		cout << "weight " << weight << endl;
		cout << "age " << age << endl;
		cout << "breed " << breed << endl;
	}
};

class Dog : public Pet
{
public:
	Dog(string name, double weight, int age, string breed) :Pet(name, weight, age, breed) {}
	void Dogdisplay()
	{
		cout << "Dog ";
		display();
		cout << "dog says woof!!!" << endl;
	}
};

class Cat : public Pet
{
public:
	Cat(string name, double weight, int age, string breed) :Pet(name, weight, age, breed) {}
	void Catdisplay()
	{
		cout << "Cat ";
		display();
		cout << "cat says meow!!! " << endl;
	}
};
class Parrot : public Pet
{
public:
	Parrot(string name, double weight, int age, string breed) : Pet(name, weight, age, breed) {}
	void Parrotdisplay()
	{
		cout << "Parrot ";
		display();
		cout << "parrot says hello!!! " << endl;
	}
};

int main()
{
	Dog dog("chak", 15, 8, "cur");
	dog.Dogdisplay();
	cout << endl;
	Cat cat("murka", 5, 6, "siamese");
	cat.Catdisplay();
	cout << endl;
	Parrot parrot("argo", 0.2, 2, "ara");
	parrot.Parrotdisplay();
	return 0;
}