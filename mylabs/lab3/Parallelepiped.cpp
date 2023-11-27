#include "Parallelepiped.h"
#include <iostream>

double Parallelepiped::getC() {
	return c;
}

Parallelepiped::Parallelepiped():Rectangle() {
	c = 0;
}

Parallelepiped::Parallelepiped(double a, double b, double c) :Rectangle(a, b) {
	this->c = c;
}

Parallelepiped::~Parallelepiped() {
}

double Parallelepiped::getVolume() {
	return getArea() * c;
}

double Parallelepiped::getArea() {
	return 2 * (a * b + a * c + b * c);
}

double Parallelepiped::getPerimeter() {
	return 4 * (a + b + c);
}

void Parallelepiped::printInfo() {
	std::cout << "Parallelepiped: a - " << a << "; b - " << b << "; c - " << c << "; area - "
		<< getArea() << "; volume - " << getVolume() << "." << std::endl;
}