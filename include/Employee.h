//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_EMPLOYEE_H
#define PROJETOAEROPORTO_EMPLOYEE_H

#include "Person.h"


class Employee: public Person {
private:
    std::string type;  // pilot, cleaner or maintenance
    bool onDuty = false;

public:
    Employee();
    Employee(std::string name, std::string type);
    void setType(std::string type);
    std::string getType() const;
    void setOnDuty();
    void setOffDuty();
    bool isOnDuty()const;
    friend std::ostream& operator<<(std::ostream& os, const Employee &employee);
};


#endif //PROJETOAEROPORTO_EMPLOYEE_H
