#pragma once
#include "Figures.h"

class Rhombus : Figures
{
private:
	double a; // сторона ромба
	double h; //высота ромба
public:
	Rhombus(double a, double h, string name): a{a}, h{h}
	{
		this->name = name;
		cornerCount = 4;
		RecalculatePSrhom();
	}
	void RecalculatePSrhom();
	void DisplayRhombus();
	void set_a(double a) { this->a = a; RecalculatePSrhom(); }
	void set_h(double h) { this->h = h; RecalculatePSrhom(); }
	void set_ah(double a, double h) { set_a(a); set_h(h); RecalculatePSrhom(); }
};

