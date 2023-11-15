/*
*   Создать программу с классом Tool, порождающим объекты– данные об инструментах в пункте проката. 
    Класс включает в себя следующие поля:
        - название инструмента;
        - модель;
        - статус (на руках, в прокате / в пункте проката (boolean));
        - дата начала времени проката;
        - дата окончания;
       и следующие методы:
        - конструктор по умолчанию;
        - деструктор;
        - метод инициализации текущего состояния объектов;
        -функция-друг, выводящая список инструментов, доступных для проката на текущий момент;
        -функция-друг, выводящая список инструментов, которые будут доступны в прокате на указанное время.
*
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "Tool.h"

bool compareTime(std::string, std::string);
int menu();
void showAvailableToolsForTime(std::vector<Tool*>, std::string);
void showAvailableTools(std::vector<Tool*>);

template<typename T>
void deleteObjects(std::vector<T>&);


int main() {

    Tool* tool = new Tool();
    tool->x = new (int);
    *(tool->x) = 10;
    std::cout << *(tool->x) << std::endl;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

	std::vector<Tool*> tools;

    int choice = 0;

    while (choice != 5) {
        choice = menu();

        switch (choice) {

        case 1:

            if (tools.empty())
                std::cout << "Инструменты отстутствуют";
            else {
                for (int i = 0; i < tools.size(); i++) {
                    tools[i]->display();
                }
            }

            break;

        case 2: {
            std::string name, model, startTime, endTime;
            bool status;

            std::cout << "Введите название: ";
            std::cin >> name;

            std::cout << "Модель: ";
            std::cin >> model;

            std::cout << "Статус (1 - Свободен, 0 - В прокате): ";
            std::cin >> status;

            if (!status) {
                std::cout << "Начало проката (hour:minute): ";
                std::cin >> startTime;

                std::cout << "Конец проката (hour:minute): ";
                std::cin >> endTime;
            }

            tools.push_back(new Tool(name, model, status, startTime, endTime));

            std::cout << std::endl;

            break;
        }
        case 3:
            if (tools.empty())
                std::cout << "Инструменты отстутствуют";
            else {
                std::cout << "\nСписок доступных инструментов:" << std::endl;
                for (int i = 0; i < tools.size(); i++) {
                    if (tools[i]->getStatus()) {
                        tools[i]->display();
                    }
                }
            }

            std::cout << std::endl;

            break;

        case 4:
        {
            if (tools.empty())
                std::cout << "Инструменты отстутствуют";
            else {
                std::string time;
                std::cout << "Введите желаемое время проката: ";
                std::cin >> time;

                std::cout << "Список доступных инструментов на " + time + ":" << std::endl;
                showAvailableToolsForTime(tools, time);
            }
            
            break;
        }
            

        case 5:
            break;

        default:
            std::cout << "Неверное значение." << std::endl;
            break;
        }
        puts("\nPress any key to continue\n");
        _getch();
        system("cls");
    }

    deleteObjects(tools);

    return 0;
}

int menu() {
    std::cout << "\t\t+-------------------------- Меню: ---------------------------------+" << std::endl
        << "\t\t|1. Просмотр текущего состояния объекта.                           |" << std::endl
        << "\t\t|2. Создание объектов.                                             |" << std::endl
        << "\t\t|3. Просмотр инструментов, доступных для проката на текущий момент.|" << std::endl
        << "\t\t|4. Просмотр инструментов, которые будут доступны.                 |" << std::endl
        << "\t\t|5. Выход                                                          |" << std::endl
        << "\t\t+------------------------------------------------------------------+" << std::endl
        << "\t\tSelect an option: ";
    int input;
    std::cin >> input;
    return input;
}

bool compareTime(std::string time1, std::string time2) {
    int hour1 = std::stoi(time1.substr(0, 2));
    int minute1 = std::stoi(time1.substr(3));

    int hour2 = std::stoi(time2.substr(0, 2));
    int minute2 = std::stoi(time2.substr(3));

    if (hour1 < hour2) {
        return true;
    }
    else if (hour1 > hour2) {
        return false;
    }

    if (minute1 < minute2) {
        return true;
    }
    else if (minute1 > minute2) {
        return false;
    }

    return false;
}

/*
*   friend - функции:
*/

void showAvailableToolsForTime(std::vector<Tool*> tools, std::string time) {
    for (int i = 0; i < tools.size(); i++) {
        if (!tools[i]->status && compareTime(tools[i]->endTime, time) || tools[i]->status) {
            tools[i]->display();
        }
    }
}

void showAvailableTools(std::vector<Tool*> tools) {
    for (int i = 0; i < tools.size(); i++) {
        if (tools[i]->status == false) {
            std::cout << "Название: " << tools[i]->name << std::endl;
            std::cout << "Модель: " << tools[i]->model << std::endl;
            std::cout << "Статус: " << tools[i]->status << std::endl;

            std::cout << "Начало проката: " << tools[i]->startTime << std::endl;

            std::cout << "Конец пропата: " << tools[i]->endTime << std::endl << std::endl;
        }
    }
}

template<typename T>
void deleteObjects(std::vector<T>& objects) {
    for (auto i = objects.begin(); i < objects.end(); ++i) {
        delete* i;
    }
    objects.clear();
}