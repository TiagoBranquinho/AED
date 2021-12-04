#ifndef PROJETOAEROPORTO_SERVICE_H
#define PROJETOAEROPORTO_SERVICE_H

#include <string>
#include "Date.h"
#include "Employee.h"

using namespace std;

class Service {
private:
    string type;
    Date date;
    Employee employee;
public:
    Service();
    Service(string type, Date date, Employee employee);
    string getType();
    Date getDate();
    Employee getEmployee();
    void setType(string type);
    void setDate(Date date);
    void setEmployee(Employee employee);
};


#endif //PROJETOAEROPORTO_SERVICE_H
