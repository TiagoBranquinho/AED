//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Employee.h"

using namespace std;


Employee::Employee() = default;

unsigned int Employee::ID = 0;

Employee::Employee(string name, string type) {
    this->name = name;
    this->type = type;
    id = ID;
    ID++;
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

bool Employee::operator==(const Employee &emp) {
    return id == emp.id;
}
