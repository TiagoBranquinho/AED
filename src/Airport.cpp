//
// Created by Tiago Branquinho on 05/12/2021.
//

#include "../include/Airport.h"

unsigned Airport::ID = 0;

Airport::Airport(std::string name, std::string city) {
    this->name = name;
    this->city = city;
    id = ID++;
}

unsigned int Airport::getId() const {
    return id;
}

std::string Airport::getName() const{
    return name;
}

std::string Airport::getCity() const{
    return city;
}

void Airport::addGroundTransportation(const GroundTransportation &groundTransportation) {
    locals.addGroundTransportation(groundTransportation);
}

BSTItrIn<GroundTransportation> Airport::localsItrIn() {
    return locals.itrInOrder();
}

iteratorBST<GroundTransportation> Airport::localsBeginItr() {
    return locals.beginItr();
}

iteratorBST<GroundTransportation> Airport::localsEndItr() {
    return locals.endItr();
}

TransportationLocals &Airport::getLocals() {
    return locals;
}

std::ostream &operator<<(ostream &os, const Airport &airport) {
    os << airport.getId() << setw(3) << "-" << setw(20) << airport.getName() << setw(3) << "-" << setw(10) << airport.getCity() << endl;
    return os;
}


