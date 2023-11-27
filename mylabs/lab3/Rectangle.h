#pragma once
#include "Square.h"

class Rectangle : public Square {
protected:
	double b;

public:
	Rectangle();
	Rectangle(double a, double b);
	~Rectangle();

	double getB();
	double getPerimeter() override;
	double getDiagonal();
	double getArea() override;
	void printInfo() override;
};