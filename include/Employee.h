//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_EMPLOYEE_H
#define PROJETOAEROPORTO_EMPLOYEE_H

#include "Person.h"


class Employee: public Person {
private:
    unsigned int id;
    std::string type;  // pilot, cleaner or maintenance
    bool onDuty = false;
public:
    static unsigned int ID;

public:
    Employee();
    Employee(std::string name, std::string type);
    void setType(std::string type);
    std::string getType() const;
    void setOnDuty();
    void setOffDuty();
    bool isOnDuty();
    bool operator==(const Employee& emp);
};


#endif //PROJETOAEROPORTO_EMPLOYEE_H
