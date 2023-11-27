/*
		Консольное приложение. Запросить у пользователя количество объектов его поля. 
	Создать объекты через выделение памяти операцией new.
	Объявления класса и его методов– в отдельном заголовочном файле *.h.
	По окончании работы с массивом освободить занимаемую массивом память с помощью деструктора.
	Реализация методов– вне класса. Организовать простейшее меню 
    (1 просмотр текущего состояния объектов, 2 создание объектов, 3 выход).

		26.Создать класс прямоугольник, члены класса – длины сторон a и b.
	Предусмотреть в классе методы вычисления и вывода сведений о фигуре –
	длины сторон, диагоналей, периметр, площадь. Создать производный класс –
	параллелепипед с высотой с, добавить в класс метод определения объема
	фигуры, перегрузить методы расчета площади и вывода сведений о фигуре.
	Написать программу, демонстрирующую работу с классом: дано N
	прямоугольников и M параллелепипедов, найти количество прямоугольников, у
	которых площадь больше средней площади прямоугольников и количество
	кубов (все ребра равны).
*/

#include <iostream>
#include "Parallelepiped.h"
#include "Rectangle.h"
#include <vector>
#include <conio.h>


int menu();
int getNumOfRectanglesWithAreaLargerThenAvg(std::vector<Rectangle*>);
int getNumberOfCubes(std::vector<Parallelepiped*>);

template<typename T>
void deleteObjects(std::vector<T>&);


int main() {

	std::vector<Rectangle*> rectangles;
	std::vector<Parallelepiped*> parallelepipeds;

	int choice = 0;

	while (choice != 6) {

		switch (choice = menu()) {

		case 1:
			if (rectangles.empty() && parallelepipeds.empty())
				std::cout << "Figures are missing!" << std::endl;
			else {
				std::cout << std::endl;
				for (int i = 0; i < rectangles.size(); i++) {
					rectangles[i]->printInfo();
				}

				std::cout << std::endl;
				for (int i = 0; i < parallelepipeds.size(); i++) {
					parallelepipeds[i]->printInfo();
				}
				std::cout << std::endl;
			}

			break;

		case 2:
		{
			int n = 0;
			std::cout << "Enter the number of rectangles: n = ";
			std::cin >> n;

			for (int i = 0; i < n; i++) {
				double a, b;
				std::cout << "\nEnter the sides of rectangle " << i + 1 << ": \n"
					<< "Length a = ";
				std::cin >> a;
				std::cout << "Width b = ";
				std::cin >> b;

				rectangles.push_back(new Rectangle(a, b));
			}
			break;
		}

		case 3:
		{
			int m = 0;
			std::cout << "Enter the number of Parallelepipeds: m = ";
			std::cin >> m;

			for (int i = 0; i < m; i++) {
				double a, b, c;
				std::cout << "\nEnter the sides of parallelepiped " << i + 1 << ": \n"
					<< "Length a = ";
				std::cin >> a;
				std::cout << "Width b = ";
				std::cin >> b;
				std::cout << "height c = ";
				std::cin >> c;
				parallelepipeds.push_back(new Parallelepiped(a, b, c));
			}
			break;
		}

		case 4:
			deleteObjects(rectangles);
			deleteObjects(parallelepipeds);
			break;
			
		case 5:
			std::cout << "The number of rectangles, whose area is larger than the average area: "
				<< getNumOfRectanglesWithAreaLargerThenAvg(rectangles) << std::endl;
			
			std::cout << "Number of cubes: " << getNumberOfCubes(parallelepipeds) << std::endl;

			break;

		case 6:
			break;

		default:
			std::cout << "Invalid value!" << std::endl;
			break;
		}

		puts("\nPress any key to continue\n");
		_getch();
		system("cls");
	}

	deleteObjects(rectangles);
	deleteObjects(parallelepipeds);
}


int menu() {
	std::cout << "\t\t+--------------- Menu: ------------------+" << std::endl
		<< "\t\t|1. Viewing the current state of objects |" << std::endl
		<< "\t\t|2. Creating rectangles                  |" << std::endl
		<< "\t\t|3. Creating parallelepipeds             |" << std::endl
		<< "\t\t|4. Deleting shapes                      |" << std::endl
		<< "\t\t|5. Task                                 |" << std::endl
		<< "\t\t|6. Exit                                 |" << std::endl
		<< "\t\t+----------------------------------------+" << std::endl
		<< "\t\tSelect an option: ";
	int input;
	std::cin >> input;
	return input;
}

template<typename T>
void deleteObjects(std::vector<T> &objects) {
	for (auto i = objects.begin(); i < objects.end(); ++i) {
		delete *i;
	}
	objects.clear();
}

int getNumOfRectanglesWithAreaLargerThenAvg(std::vector<Rectangle*> rectangles) {
	double avg = 0;

	for (int i = 0; i < rectangles.size(); i++) {
		avg += rectangles[i]->getArea();
	}
	avg /= rectangles.size();

	int number = 0;
	for (int i = 0; i < rectangles.size(); i++) {
		if (rectangles[i]->getArea() > avg)
			number++;
	}

	return number;
}

int getNumberOfCubes(std::vector<Parallelepiped*> parallelepipeds) {
	int number = 0;

	for (int i = 0; i < parallelepipeds.size(); i++) {
		if (parallelepipeds[i]->getA() == (parallelepipeds[i]->getB()) 
			&& (parallelepipeds[i]->getC()) == parallelepipeds[i]->getA()) {
			number++;
		}
	}

	return number;
}

