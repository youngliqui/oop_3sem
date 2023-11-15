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
    std::cout << "��������: ";
    std::cin >> name;

    std::cout << "������: ";
    std::cin >> model;

    std::cout << "������� ������ ����������� (1 - ��������, 0 - � �������): ";
    std::cin >> status;

    std::cout << "������ ������� (hour:minute) :";
    std::cin >> startTime;

    std::cout << "����� ������� (hour:minute) :";
    std::cin >> endTime;
}

void Tool::display() {
    std::cout << "\n\n��������: " << name << std::endl;
    std::cout << "������: " << model << std::endl;

    if (status) {
        std::cout << "������: ��������" << std::endl;
    }
    else {
        std::cout << "������: � �������" << std::endl
            << "������ �������: " << startTime << std::endl
            << "����� �������: " << endTime << std::endl;
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