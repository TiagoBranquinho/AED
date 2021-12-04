//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_EMPLOYEE_H
#define PROJETOAEROPORTO_EMPLOYEE_H

#include "Person.h"


class Employee: public Person {
private:
    std::string type;  // pilot, cleaner or maintenance

public:
    Employee();
    Employee(std::string name, std::string type);
    void setType(std::string type);
    std::string getType();
};


#endif //PROJETOAEROPORTO_EMPLOYEE_H
