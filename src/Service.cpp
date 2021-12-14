#include <iostream>
#include "../include/Service.h"

using namespace std;


Service::Service() = default;

Service::Service(string type, const Employee &employee) {
    time_t dt = time(nullptr);
    tm *ltm = localtime(&dt);
    this->date = Date(ltm->tm_mday, ltm->tm_mon+1, ltm->tm_year+1900);
    this->type = type;
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

void Service::setDate(const Date &date) {
    this->date = date;
}

void Service::setEmployee(const Employee &employee) {
    if(employee.getType() == type)
        this->employee = employee;
    else
        cout << "The employee selected is not qualified for the service" << endl;
}

