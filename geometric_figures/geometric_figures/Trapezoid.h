#pragma once
#include "Figures.h"

class Trapezoid : Figures
{
private:
	double a; // основания трапеции
	double b;
	double c; // равные стороны
	double h; // выстота
public:
	Trapezoid(double a, double b, double c, double h, string name) : a{ a }, b{ b }, c{ c }, h{ h }
	{
		this->name = name;
		cornerCount = 4;
		RecalculatePSTrap();
	}
	void TrapezoidDisplay();
	void RecalculatePSTrap();
	void Set_a(double a) { this->a = a; RecalculatePSTrap(); }
	void Set_b(double b) { this->b = b; RecalculatePSTrap(); }
	void Set_c(double c) { this->c = c; RecalculatePSTrap(); }
	void Set_h(double h) { this->h = h; RecalculatePSTrap(); }
	void Set_abch(double a, double b, double c, double h) { Set_a(a); Set_b(b); Set_c(c); Set_h(h); RecalculatePSTrap(); }
};