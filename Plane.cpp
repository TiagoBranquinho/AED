#include "Plane.h"

using namespace std;


Plane::Plane() = default;

Plane::Plane(string plate, unsigned int capacity) {
    this->plate = plate;
    this->capacity = capacity;
}

string Plane::getPlate() const{
    return plate;
}

unsigned int Plane::getCapacity() {
    return capacity;
}

void Plane::setPlate(string plate) {
    this->plate = plate;
}

void Plane::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

void Plane::addFlight(const Flight &flight) {
    flightPlan.push_back(flight);
}

void Plane::addService(const Service &service) {
    servicesTODO.push(service);
}

void Plane::removeServiceDONE() {
    servicesDONE.push_back(servicesTODO.front());
    servicesTODO.pop();
}
