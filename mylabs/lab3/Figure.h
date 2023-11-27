#pragma once

class  Figure {
public:
	virtual ~Figure() {};

	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
	virtual void printInfo() = 0;
};