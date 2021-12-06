//
// Created by Tiago Branquinho on 05/12/2021.
//

#include "Airport.h"

Airport::Airport() = default;

Airport::Airport(std::string name, std::string city, std::vector<Plane> planes, std::vector<Flight> flights) {
    this->name = name;
    this->city = city;
    this->planes = planes;
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

std::vector<Plane> Airport::getPlanes() {
    return planes;
}

std::vector<Flight> Airport::getFlights() {
    return flights;
}

void Airport::setPlanes(std::vector<Plane> planes) {
    this->planes = planes;
}

void Airport::setFlights(std::vector<Flight> flights) {
    this->flights = flights;
}

void Airport::addPlane(const Plane &plane) {
    planes.push_back(plane);
}

void Airport::removePlane(const Plane &plane) {
    for(std::vector<Plane>::iterator it = planes.begin(); it != planes.end(); it++){  // had to make getPlate const, otherwise --> ERROR
        if((*it).getPlate() == plane.getPlate())
            planes.erase(it);
    }
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
