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
    /**
     * Default class constructor
     */
    Service();
    /**
     * Class constructor with the type, date and the employee responsible for the service
     * @param type type of service
     * @param date Date object passed by reference
     * @param employee a pointer to the employee object
     */
    Service(std::string type, const Date &date, Employee *employee);
    std::string getType() const;
    Date getDate()const ;
    Employee *getEmployee()const ;
    void setType(std::string type);
    /**
     * Checks if the type of the service matches the work type of of the employee
     * @param type type of the service
     * @param employee a pointer to the employee object
     * @return true if the type matches or false otherwise
     */
    bool validType(std::string type, Employee *employee);
    /**
     * Operator to print the service object in the correct format
     * @param os stream where the service will be printed
     * @param service service object passed by reference
     * @return ostream with the service printed
     */
    friend std::ostream& operator<<(std::ostream& os, const Service &service);
};

class InvalidEmployeeException: public std::exception{
private:
    Employee *emp;
public:
    explicit InvalidEmployeeException(Employee *employee): emp(employee){};
    const char * what () const noexcept override {
        return "The employee selected is not qualified for the service!";
    }
};

#endif //PROJETOAEROPORTO_SERVICE_H
