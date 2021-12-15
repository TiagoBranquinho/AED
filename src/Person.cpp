//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Person.h"

using namespace std;


Person::Person() = default;

unsigned int Person::ID = 0;

Person::Person(string name) {
    this->name = name;
    id = ID;
    ID++;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}

bool Person::operator==(const Person& person) const {
    return id == person.id;
}

