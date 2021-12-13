//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_PERSON_H
#define PROJETOAEROPORTO_PERSON_H

#include <string>


class Person {
protected:
    std::string name;
public:
    Person();
    Person(std::string name);
    void setName(std::string name);
    std::string getName();
};


#endif //PROJETOAEROPORTO_PERSON_H
