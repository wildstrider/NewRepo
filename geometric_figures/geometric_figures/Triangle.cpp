#include "Triangle.h"

Triangle::Triangle(double a, double b, double c, string name) :
	a{ a }, b{ b }, c{ c }
{
	this->name = name;

	if ((a + b < c) || (b + c < a) || (a + c < c)) {
		a = b = c = -1;
		ab = bc = ac = -1;
		P = S = -1;
		name = "undefined";
	}
	else {
		// инициализация углов
		recalculatePSAndCorners();
	}

}

void Triangle::recalculatePSAndCorners()
{
	ab = getCornerBetweenTwoEdges(a, b, c);
	bc = getCornerBetweenTwoEdges(b, c, a);
	ac = getCornerBetweenTwoEdges(a, c, b);
	P = a + b + c;
	S = a * b * sin(ab) / 2;
}

void Triangle::displayTrgl()
{
	cout << "Triangle ";
	display();
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "In radians:" << endl;
	cout << "a^b = " << ab << endl;
	cout << "a^c = " << ac << endl;
	cout << "b^c = " << bc << endl;
	cout << "In degrees:" << endl;
	cout << "a^b = " << RadToDeg(ab) << endl;
	cout << "a^c = " << RadToDeg(ac) << endl;
	cout << "b^c = " << RadToDeg(bc) << endl;
 }

const double Triangle::pi = 3.14159;

double Triangle::RadToDeg(double in_radian)
{
	return 360 / (2 * pi) * in_radian;
}

double Triangle::getCornerBetweenTwoEdges(double first, double second, double third)
{
	return acos((first * first + second * second - third * third) / (2 * first * second));
}
