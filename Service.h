#ifndef PROJETOAEROPORTO_SERVICE_H
#define PROJETOAEROPORTO_SERVICE_H

#include <string>
#include "Date.h"
#include "Employee.h"
#include "Plane.h"

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
    Plane getPlane();
    void setType(string type);
    void setDate(Date date);
    void setEmployee(Employee employee);
    void setPlane(Plane plane)
};


#endif //PROJETOAEROPORTO_SERVICE_H
