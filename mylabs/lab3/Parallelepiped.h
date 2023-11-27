#pragma once
#include "Rectangle.h"

class Parallelepiped : public Rectangle {
protected:
	double c;

public:
	Parallelepiped();
	Parallelepiped(double a, double b, double c);
	~Parallelepiped();

	double getC();
	double getPerimeter() override;
	double getVolume();
	double getArea() override;
	void printInfo() override;

private:
	double getDiagonal;
};