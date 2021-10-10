#include<iostream>
#include <string>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Figures.h"
#include "Trapezoid.h"
#include "rhombus.h"

int main()
{
	// 1. Прямоугольник
	Rectangle rect(3, 4, "ABCD");

	rect.displayRect();
	rect.set_ab(3.5, 5.6);
	rect.displayRect();

	// 2. Окружность
	Circle circle(3, "O");
	circle.displayCircle();
	circle.setR(9);
	circle.displayCircle();

	// 3. Треугольник
	Triangle tr(3, 4, 5, "ABC");
	tr.displayTrgl();

	// 4. Трапеция
	Trapezoid trap(4, 8, 5, 3, "Trapezoid");
	trap.TrapezoidDisplay();

	// 5. Ромб
	Rhombus rhom(5, 3, "rhombus");
	rhom.DisplayRhombus();

	return 0;
}