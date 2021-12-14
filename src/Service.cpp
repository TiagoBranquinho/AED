#include <iostream>
#include "../include/Service.h"

using namespace std;


Service::Service() = default;

Service::Service(string type, const Date &date, Employee *employee) {
    if (validType(type, employee))
        throw InvalidEmplpoyeeException(employee);
    this->date = date;
    this->type = type;
    this->employee = employee;
}

string Service::getType() {
    return type;
}

Date &Service::getDate() {
    return date;
}

Employee *Service::getEmployee() {
    return employee;
}

void Service::setType(string type) {
    if (validType(type, employee))
        this->type = type;
    else
        throw InvalidEmplpoyeeException(employee);
}

void Service::setDate(const Date &date) {
    this->date = date;
}

void Service::setEmployee(Employee *employee) {
    if (validType(type, employee))
        this->employee = employee;
    else
        throw InvalidEmplpoyeeException(employee);
}

bool Service::validType(string type, Employee *employee) {
    return employee->getType() == type;
}