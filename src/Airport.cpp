//
// Created by Tiago Branquinho on 05/12/2021.
//

#include "../include/Airport.h"

Airport::Airport() = default;

Airport::Airport(std::string name, std::string city, std::vector<Flight> flights) {
    this->name = name;
    this->city = city;
    this->flights = flights;
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
    for(std::vector<Flight>::iterator it = flights.begin(); it != flights.end(); it++){ // had to make getNumber const, otherwise --> ERROR
        if((*it).getNumber() == flight.getNumber())
            flights.erase(it);
    }
}
