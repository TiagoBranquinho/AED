#ifndef PROJETOAEROPORTO_SERVICE_H
#define PROJETOAEROPORTO_SERVICE_H

#include <string>
#include "Date.h"
#include "Employee.h"


class Service {
private:
    std::string type;
    Date date;
    Employee employee;
public:
    Service();
    Service(std::string type, const Date &date, const Employee &employee);
    std::string getType();
    Date getDate();
    Employee getEmployee();
    void setType(std::string type);
    void setDate(const Date &date);
    void setEmployee(const Employee &employee);
};


#endif //PROJETOAEROPORTO_SERVICE_H
