//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Employee.h"

using namespace std;


Employee::Employee() = default;


Employee::Employee(string name, string type): Person(name), type(type) {}

void Employee::setType(string type) {
    this->type = type;
}

string Employee::getType() const {
    return type;
}

void Employee::setOnDuty() {
    onDuty = true;
}

void Employee::setOffDuty() {
    onDuty = false;
}

bool Employee::isOnDuty() const{
    return onDuty;
}

std::ostream &operator<<(ostream &os, const Employee &employee) {
    os << employee.getId() << setw(3) << "-" << setw(16) << employee.getName() << setw(3) << "-"<< setw(12) <<  employee.getType() << '\n';
    return os;
}
