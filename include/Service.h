#ifndef PROJETOAEROPORTO_SERVICE_H
#define PROJETOAEROPORTO_SERVICE_H

#include <string>
#include <ctime>
#include "Date.h"
#include "Employee.h"


class Service {
private:
    std::string type;
    Date date;
    Employee *employee;
public:
    Service();
    Service(std::string type, const Date &date, Employee *employee);
    std::string getType() const;
    Date getDate()const ;
    Employee *getEmployee()const ;
    void setType(std::string type);
    bool validType(std::string type, Employee *employee);
    friend std::ostream& operator<<(std::ostream& os, const Service &service);
};

class InvalidEmployeeException: public std::exception{
private:
    Employee *emp;
public:
    InvalidEmployeeException(Employee *employee): emp(employee){};
    const char * what () const noexcept override {
        return "The employee selected is not qualified for the service!";
    }
};

#endif //PROJETOAEROPORTO_SERVICE_H
