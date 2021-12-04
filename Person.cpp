//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "Person.h"

Person::Person() = default;

Person::Person(string name) {
    this->name = name;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}
