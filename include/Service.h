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
    const Date getDate()const ;
    Employee *getEmployee()const ;
    void setType(std::string type);
    void setDate(const Date &date);
    void setEmployee(Employee *employee);
    bool validType(std::string type, Employee *employee);
    friend std::ostream& operator<<(std::ostream& os, const Service &service);
};

class InvalidEmplpoyeeException: public std::exception{
private:
    Employee *emp;
public:
    InvalidEmplpoyeeException(Employee *employee): emp(employee){};
    Employee *getEmployee(){ return emp; };
    const char * what () const noexcept override {
        return "The employee selected is not qualified for the service!";
    }
};

#endif //PROJETOAEROPORTO_SERVICE_H
