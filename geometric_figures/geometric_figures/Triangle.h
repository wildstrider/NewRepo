#pragma once
#include "Figures.h"
class Triangle :
    public Figures
{
private:
    // стороны треугольника
    double a;
    double b;
    double c;
    // углы треугольника
    double ab;
    double bc;
    double ac;

public:
    Triangle(double a, double b, double c, string name);

    void recalculatePSAndCorners();
    
    // setters
    void set_a(double a) {
        this->a = a;
        recalculatePSAndCorners();
    }
    void set_b(double b) {
        this->b = b;
        recalculatePSAndCorners();
    }
    void set_c(double c) {
        this->c = c;
        recalculatePSAndCorners();
    }
    void set_abc(double a, double b, double c) {
        set_a(a);
        set_b(b);
        set_c(c);
    }

    // 
    void displayTrgl();

    // метод получения угла между сторонами first и second
    static const double pi;
    static double RadToDeg(double in_radian);
    static double getCornerBetweenTwoEdges(double first, double second, double third);
};

