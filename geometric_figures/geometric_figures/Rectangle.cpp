#include "Rectangle.h"

void Rectangle::recalculatePS()
{
    P = (a + b) * 2;
    S = a * b;
}

void Rectangle::displayRect()
{
    cout << "Rectangle ";
    display();
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
