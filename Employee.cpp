//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "Employee.h"

Employee::Employee() = default;

Employee::Employee(string name, string type) {
    this->name = name;
    this->type = type;
}

void Employee::setType(string type) {
    this->type = type;
}

string Employee::getType() {
    return std::string();
}

