#pragma once

#include <iostream>

using namespace std;

class Figures
{
protected:
	string name;
	double P; // периметр
	double S; // площадь
	int cornerCount; // кол-во углов

public:
	Figures(double P, double S, int cornerCount, string name) :
		P{ P }, S{ S }, cornerCount{ cornerCount }, name{ name } {};
	Figures() : Figures(-1, -1, -1, "undefined") {};

	// getters
	string getName() {
		return name;
	}
	double getP() {
		return P;
	}
	double getS() {
		return S;
	}
	int getCornerCount() {
		return cornerCount;
	}


	// setters

	// other methods
	void display();
};