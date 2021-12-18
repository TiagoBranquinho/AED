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

std::list<Flight> &Plane::getFlightPlan() {
    return flightPlan;
}

void Plane::setPlate(string plate) {
    this->plate = plate;
}

void Plane::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

void Plane::setOnDuty(bool duty) {
    this->onDuty = duty;
}

void Plane::addFlight(const Flight &flight) {
    flightPlan.push_back(flight);
}

void Plane::addService(const Service &service) {
    servicesTODO.push(service);
}

void Plane::serviceDone(const Service & service) {
    servicesDONE.push_back(service);
}

void Plane::addBaggage(const Baggage &baggage) {
    planeTrunk.push_back(baggage);
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

bool Plane::operator==(const Plane &plane) const{
    return this->getPlate() == plane.getPlate();
}

std::ostream &operator<<(ostream &os, const Plane &plane) {
    os << plane.getPlate() << " " << plane.getCapacity() << " " << to_string(plane.onDuty) << endl;
    return os;
}

std::vector<Service> Plane::getServicesDone() const{
    return servicesDONE;
}

std::queue<Service> Plane::getServicesToDo() const{
    return servicesTODO;
}

list<Baggage> Plane::getTrunk() const {
    return planeTrunk;
}

bool Plane::getOnDuty() const{
    return onDuty;
}

void Plane::setServicesToDo(queue<Service> &services) {
    servicesTODO = services;
}

void Plane::setPlaneTrunk(list<Baggage> &baggages) {
    planeTrunk = baggages;
}

void Plane::setServicesDone(vector<Service> &services) {
    servicesDONE = services;
}

void Plane::removeFlight(const Flight &flight) {
    flightPlan.remove(flight);
}



