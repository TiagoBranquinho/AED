//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "../include/Flight.h"

using namespace std;


Flight::Flight() = default;

Flight::Flight(unsigned int number, const Date *date, Airport* origin, Airport* destiny) {
    this->number = number;
    this->date = *date;
    this->origin = origin;
    this->destiny = destiny;
    openCheckIn();
}

unsigned int Flight::getNumber() const{
    return number;
}

Date Flight::getDate() const{
    return date;
}

void Flight::setDeparture(std::string departure) {
    this->departure = Schedule(departure);
}

std::string Flight::getDeparture() const{
    return departure.getTime();
}

std::string Flight::getArrival() const{
    return departure.addTime(duration).getTime();
}

void Flight::setDuration(string duration) {
    this->duration = Schedule(duration);
}

string Flight::getDuration() {
    return duration.getTime();
}

void Flight::setOrigin(Airport* origin) {
    this->origin = origin;
}

string Flight::getOrigin() const{
    return origin->getCity();
}

string Flight::getDestiny() const{
    return destiny->getCity();
}

std::list<Passenger> &Flight::getPassengers(){
    return passengers;
}

unsigned int Flight::getNumberPassengers() const {
    return passengers.size();
}

void Flight::addPassenger(const Passenger &passenger) {
    passengers.push_back(passenger);
    if(passenger.getBaggage() != nullptr)
        numberOfBaggages++;
}

void Flight::closeCheckIn() {
    checkIn = false;
}

void Flight::openCheckIn() {
    checkIn = true;
}

bool Flight::getCheckInStatus() const{
    return checkIn;
}

unsigned int Flight::getNumberBaggages() const {
    return numberOfBaggages;
}

bool Flight::operator==(const Flight &flight) const {
    return this->getNumber() == flight.getNumber();
}

queue<Baggage> Flight::getTreadmill() {
    return treadmill;
}

std::ostream &operator<<(ostream &os, const Flight &flight) {
    os << setw(5) << flight.getNumber() << setw(3) << "-" << setw(12) << flight.getDate().getDate() << setw(3) <<  "-" << setw(12) << flight.getOrigin() << setw(3) << "-"  << setw(12) << flight.getDestiny() << setw(3) << "-" << setw(10) <<  flight.getDeparture() << setw(7) << "-" << setw(10) <<  flight.getArrival() << '\n';
    return os;
}


Airport* Flight::getOriginAir() const {
    return origin;
}

Airport *Flight::getDestinyAir() const {
    return destiny;
}

void Flight::setCheckIn(bool var) {
    checkIn = var;
}

void Flight::setTreadmill(queue<Baggage> &q) {
    treadmill = q;
}


