#pragma once
#include "Figure.h"

class Square: public Figure {
protected:
	double a;

public:
	Square();
	Square(double a);
	~Square();

	double getA();
	double getPerimeter() override;
	double getDiagonal();
	double getArea() override;
	void printInfo() override;
};