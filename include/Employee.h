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
    /**
     * Default class constructor
     */
    Employee();
    /**
     * Class constructor with employee's name and his work type
     * @param name employee's name string
     * @param type employee's work type string
     */
    Employee(std::string name, std::string type);
    void setType(std::string type);
    std::string getType() const;
    /**
     * Sets employee on if he has a service to do
     */
    void setOnDuty();
    /**
     * Sets employee off duty if he doesn't have any service to do
     */
    void setOffDuty();
    bool isOnDuty()const;
    /**
     * Operator to print the employee object in the correct format
     * @param os stream where the employee will be printed
     * @param employee employee object passed by reference
     * @return ostream with the employee printed
     */
    friend std::ostream& operator<<(std::ostream& os, const Employee &employee);
};


#endif //PROJETOAEROPORTO_EMPLOYEE_H
