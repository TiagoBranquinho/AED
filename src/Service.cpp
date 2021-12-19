#include <iostream>
#include "../include/Service.h"

using namespace std;


Service::Service() = default;

Service::Service(string type, const Date &date, Employee *employee) {
    if(!validType(type, employee))
        throw InvalidEmployeeException(employee);
    this->date = date;
    this->type = type;
    this->employee = employee;
}

string Service::getType() const{
    return type;
}

const Date Service::getDate() const{
    return date;
}

Employee *Service::getEmployee() const{
    return employee;
}

void Service::setType(string type) {
    if (validType(type, employee))
        this->type = type;
    else
        throw InvalidEmployeeException(employee);
}

void Service::setDate(const Date &date) {
    this->date = date;
}

void Service::setEmployee(Employee *employee) {
    if (validType(type, employee))
        this->employee = employee;
    else
        throw InvalidEmployeeException(employee);
}

bool Service::validType(string type, Employee *employee) {
    return employee->getType() == type;
}

std::ostream &operator<<(ostream &os, const Service &service) {
    os << service.type << " - " << service.getDate().getDate() << " - " << service.getEmployee()->getId() << " - " << service.getEmployee()->getName() << '\n';
    return os;
}
