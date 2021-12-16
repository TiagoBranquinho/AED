//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_PERSON_H
#define PROJETOAEROPORTO_PERSON_H

#include <string>
#include <sstream>

class Person {
protected:
    unsigned int id;
    std::string name;
    static unsigned int ID;
public:
    Person();
    Person(std::string name);
    void setName(std::string name);
    std::string getName() const;
    unsigned int getId() const;
    bool operator==(const Person& person) const;
};


#endif //PROJETOAEROPORTO_PERSON_H
