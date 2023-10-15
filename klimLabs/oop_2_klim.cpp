// 12.	Создать программу с классом Chip, порождающим объекты – данные о микросхемах памяти, 
//	хранящиеся на складе.Класс включает в себя следующие поля :
//		-тип(оперативная – RAM, постоянная – ROM);
//		-информационная ёмкость(бит);
//		-наименование;
//		-месяц / год даты производства;
//		и следующие функции - члены класса :
//		-конструктор по умолчанию;
//		-деструктор;
//		-метод инициализации текущего состояния объектов;
//		-функция - друг, выводящая список микросхем, указанной информационной ёмкости.



#include <iostream>
#include <vector>
#include "Chip.h"

// Функция для вывода списка микросхем указанной информационной ёмкости
void printByCapacity(const std::vector<Chip> chips, int capacity) {
    for (int i = 0; i < chips.size(); i++) {
        if (chips[i].getCapacity() == capacity) {
            std::cout << "Type: " << chips[i].getType() << std::endl;
            std::cout << "Capacity: " << chips[i].getCapacity() << " bits" << std::endl;
            std::cout << "Name: " << chips[i].getName() << std::endl;
            std::cout << "Production Date: " << chips[i].getProductionDate() << std::endl;
            std::cout << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    std::vector<Chip> chips;

    int choice = 0;
    while (choice != 4) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Просмотр текущего состояния объекта." << std::endl;
        std::cout << "2. Создание объектов." << std::endl;
        std::cout << "3. Выполнение метода индивидуального задания." << std::endl;
        std::cout << "4. Выход." << std::endl;

        std::cin >> choice;
        switch (choice) {
        case 1:
            for (int i = 0; i < chips.size(); i++) {
                std::cout << "Тип: " << chips[i].getType() << std::endl;
                std::cout << "Объём: " << chips[i].getCapacity() << std::endl;
                std::cout << "Наименование: " << chips[i].getName() << std::endl;
                std::cout << "Дата производства: " << chips[i].getProductionDate() << std::endl << std::endl;
            }
            break;
        case 2: {
            std::string type, name, date;
            int capacity;

            std::cout << "Введите Тип: ";
            std::cin >> type;

            std::cout << "Введите объём: ";
            std::cin >> capacity;

            std::cout << "Введите наименование: ";
            std::cin >> name;

            std::cout << "Введите дату производства: ";
            std::cin >> date;

            Chip chip;
            chip.init(type, capacity, name, date);
            chips.push_back(chip);

            break;
        }
        case 3:
            int capacity;
            std::cout << "Введите искомый объём:";
            std::cin >> capacity;
            printByCapacity(chips, capacity);
            break;

        case 4:
            break;

        default:
            std::cout << "Неверное значение." << std::endl;
            break;
        }
    }

    return 0;
}