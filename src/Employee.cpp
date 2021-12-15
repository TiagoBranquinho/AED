//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Employee.h"

using namespace std;


Employee::Employee() = default;


Employee::Employee(string name, string type) {
    this->name = name;
    this->type = type;
}

void Employee::setType(string type) {
    this->type = type;
}

string Employee::getType() const {
    return std::string();
}

void Employee::setOnDuty() {
    onDuty = true;
}

void Employee::setOffDuty() {
    onDuty = false;
}

bool Employee::isOnDuty() {
    return onDuty;
}

