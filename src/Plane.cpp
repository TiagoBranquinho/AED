#include "../include/Plane.h"

using namespace std;

Plane::Plane(string plate, unsigned int capacity) {
    if(!validPlate(plate))
        throw InvalidPlateException(plate);
    this->plate = plate;
    this->capacity = capacity;
}

string Plane::getPlate() const{
    return plate;
}

unsigned int Plane::getCapacity() const{
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

bool Plane::validPlate(std::string plate) {
    if (plate.size() != 4)
        return false;
    string l = plate.substr(0,1);
    if (int(l[0]) < 65 || int(l[0]) > 90)
        return false;
    for (char c : plate.substr(1,3)){
        if (int(c) > 59 || int(c) < 48)
            return false;
    }
    return true;
}

bool Plane::operator==(const Plane &plane) {
    return this->getPlate() == plane.getPlate();
}

