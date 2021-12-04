//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_PERSON_H
#define PROJETOAEROPORTO_PERSON_H

#include <string>

using namespace std;

class Person {
protected:
    string name;
public:
    Person();
    Person(string name);
    void setName(string name);
    string getName();
};


#endif //PROJETOAEROPORTO_PERSON_H
