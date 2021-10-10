#pragma once
#include "Figures.h"

class Circle :
	public Figures 
{
private:
	double R;
	const double pi = 3.14;

public:
	Circle(double R, string name) : R{ R } {
		this->name = name;
		recalculatePS();
		cornerCount = 0;
	}

	// 
	void recalculatePS();

	// setters
	void setR(double R) {
		this->R = R;
		recalculatePS();
	}

	// display
	void displayCircle();
};

