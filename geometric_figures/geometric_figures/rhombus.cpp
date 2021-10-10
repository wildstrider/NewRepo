#include "rhombus.h"

void Rhombus::RecalculatePSrhom()
{
	S = a * h;
	P = cornerCount * a;
}

void Rhombus::DisplayRhombus()
{
	cout << "Rhombus ";
	display();
	cout << "a = " << a << endl;
	cout << "h = " << h << endl;
}
