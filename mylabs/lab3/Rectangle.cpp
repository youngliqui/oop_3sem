#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle():Square() {
	b = 0;
}
Rectangle::Rectangle(double a, double b):Square(a) {
	this->b = b;
}

Rectangle::~Rectangle() {
}

double Rectangle::getB() {
	return b;
}

double Rectangle::getPerimeter() {
	return 2 * a + 2 * b;
}

double Rectangle::getDiagonal() {
	return std::sqrt(a * a + b * b);
}

double Rectangle::getArea() {
	return a * b;
}

void Rectangle::printInfo() {
	std::cout << "Recrangle: a - " << a << "; b - " << b << "; diagonal - " << getDiagonal() << "; perimeter - "
		<< getPerimeter() << "; area - " << getArea() << "." << std::endl;
}