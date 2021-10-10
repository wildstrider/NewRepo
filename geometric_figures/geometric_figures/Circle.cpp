#include "Circle.h"

void Circle::recalculatePS()
{
	P = 2 * pi * R;
	S = pi * R * R;
}

void Circle::displayCircle()
{
    cout << "Circle ";
    display();
    cout << "R = " << R << endl;
}
