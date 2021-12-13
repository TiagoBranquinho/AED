//
// Created by Tiago Branquinho on 05/12/2021.
//

#include "../include/Airport.h"

Airport::Airport(std::string name, std::string city) {
    this->name = name;
    this->city = city;
}

std::string Airport::getName() {
    return name;
}

std::string Airport::getCity() const{
    return city;
}

void Airport::setName(std::string name) {
    this->name = name;
}

void Airport::setCity(std::string city) {
    this->city = city;
}

void Airport::addGroundTransportation(const GroundTransportation &groundTransportation) {
    locals.addGroundTransportation(groundTransportation);
}

void Airport::printLocals() {
    locals.printLocals();
}

BSTItrIn<GroundTransportation> Airport::localsItrIn() {
    return locals.localsItrIn();
}

