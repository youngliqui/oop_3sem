#include <iostream>
#include <cmath>
#include "Square.h"

Square::Square() {
	a = 0;
}

Square::Square(double a) {
	this->a = a;
}

Square::~Square() {
}

double Square::getA() {
	return a;
}

double Square::getPerimeter() {
	return a * 4;
}

double Square::getDiagonal() {
	return a * std::sqrt(2);
}

double Square::getArea() {
	return a * a;
}

void Square::printInfo() {
	std::cout << "Square: a - " << a << "; perimeter - " << getPerimeter() << "; area - " << getArea() << ".";
}