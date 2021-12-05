//
// Created by Tiago Branquinho on 05/12/2021.
//

#include "Airport.h"

using namespace std;

Airport::Airport() = default;

Airport::Airport(std::string name, std::string city) {
    this->name = name;
    this->city = city;
}

std::string Airport::getName() {
    return name;
}

std::string Airport::getCity() {
    return city;
}

void Airport::setName(std::string name) {
    this->name = name;

}

void Airport::setCity(std::string city) {
    this-> city = city;

}

void Airport::addPlane(const Plane &plane) {
    planes.push_back(plane);
}

void Airport::removePlane(const Plane &plane) {
    remove(planes.begin(), planes.end(), plane);
}

void Airport::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

void Airport::removeFlight(const Flight &flight) {
    std::remove(flights.begin(), flights.end(), flight);
}
