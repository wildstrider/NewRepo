#include "Trapezoid.h"


void Trapezoid::TrapezoidDisplay()
{
	cout << "Trapezoid ";
	display();
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "h = " << h << endl;
}

void Trapezoid::RecalculatePSTrap()
{
	P = a + b + 2 * c;
	S = (a + b) / 2 * h;
}
