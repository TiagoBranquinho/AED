//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Person.h"

using namespace std;


Person::Person() = default;

unsigned int Person::ID = 0;

Person::Person(string name) {
    this->name = name;
    id = ID++;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() const{
    return name;
}

bool Person::operator==(const Person& person) const {
    return id == person.id;
}

unsigned int Person::getId() const {
    return id;
}

