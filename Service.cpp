#include <iostream>
#include "Service.h"

Service::Service() = default;

Service::Service(string type, Date date, Employee employee) {
    this->type = type;
    this->date = date;
    this->employee = employee;
}

string Service::getType() {
    return type;
}

Date Service::getDate() {
    return date;
}

Employee Service::getEmployee() {
    return employee;
}

void Service::setType(string type) {
    this->type = type;
}

void Service::setDate(Date date) {
    this->date = date;
}

void Service::setEmployee(Employee employee) {
    if(employee.getType() == type)
        this->employee = employee;
    else
        cout << "The employee selected is not qualified for the service" << endl;
}

