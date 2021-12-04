//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_EMPLOYEE_H
#define PROJETOAEROPORTO_EMPLOYEE_H


#include "Person.h"

class Employee: public Person {
private:
    string type;  // pilot, cleaner or maintenance

public:
    Employee();
    Employee(string name, string type);
    void setType(string type);
    string getType();
};


#endif //PROJETOAEROPORTO_EMPLOYEE_H
