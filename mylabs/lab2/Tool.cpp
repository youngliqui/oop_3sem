#include <iostream>
#include <vector>
#include "Tool.h"


Tool::Tool() = default;

Tool::Tool(std::string name, std::string model, bool status, std::string startTime, std::string endTime) {
    this->name = name;
    this->model = model;
    this->status = status;
    this->startTime = startTime;
    this->endTime = endTime;
}

Tool::~Tool() {
}

void Tool::initialize() {
    std::cout << "Название: ";
    std::cin >> name;

    std::cout << "Модель: ";
    std::cin >> model;

    std::cout << "Введите статус инструмента (1 - Свободен, 0 - В прокате): ";
    std::cin >> status;

    std::cout << "Начало проката (hour:minute) :";
    std::cin >> startTime;

    std::cout << "Конец проката (hour:minute) :";
    std::cin >> endTime;
}

void Tool::display() {
    std::cout << "\n\nНазвание: " << name << std::endl;
    std::cout << "Модель: " << model << std::endl;

    if (status) {
        std::cout << "Статус: Свободен" << std::endl;
    }
    else {
        std::cout << "Статус: В прокате" << std::endl
            << "Начало проката: " << startTime << std::endl
            << "Конец проката: " << endTime << std::endl;
    }
}


std::string Tool::getName() {
    return name;
}

std::string Tool::getModel() {
    return model;
}

bool Tool::getStatus() {
    return status;
}

std::string Tool::getStartTime() {
    return startTime;
}

std::string Tool::getEndTime() {
    return endTime;
}