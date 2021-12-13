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

std::vector<Flight> Airport::getFlights() {
    return flights;
}

void Airport::setFlights(std::vector<Flight> flights) {
    this->flights = flights;
}

void Airport::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

void Airport::removeFlight(const Flight &flight) {
    for(auto it = flights.begin(); it != flights.end(); it++){ // had to make getNumber const, otherwise --> ERROR
        if((*it).getNumber() == flight.getNumber()){
            flights.erase(it);
            break;
        }
    }
}

void Airport::addGroundTransportation(const GroundTransportation &groundTransportation) {
    locals.addGroundTransportation(groundTransportation);
}

void Airport::printLocals() {
    locals.print();
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

