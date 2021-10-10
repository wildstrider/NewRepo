#pragma once
#include "Figures.h"
class Rectangle :
    public Figures
{
private:
    double a; // стороны прямоугольника
    double b;

public:
    Rectangle(double a, double b, string name) : a{ a }, b{ b } {
        this->name = name;
        recalculatePS();
        cornerCount = 4;
    }

    void recalculatePS();

    // setters 
    void set_a(double a) {
        this->a = a;
        recalculatePS();
    }
    void set_b(double b) {
        this->b = b;
        recalculatePS();
    }
    void set_ab(double a, double b) {
        set_a(a);
        set_b(b);
    }

    void displayRect();
};

