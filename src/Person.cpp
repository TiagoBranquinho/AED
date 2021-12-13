//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Person.h"

using namespace std;


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
