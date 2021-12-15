//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "../include/Flight.h"

using namespace std;


Flight::Flight() = default;

Flight::Flight(unsigned int number, const Date &date, Airport* origin, Airport* destiny) {
    this->number = number;
    this->date = date;
    this->origin = origin;
    this->destiny = destiny;
}

void Flight::setNumber(unsigned int number) {
    this->number = number;
}

unsigned int Flight::getNumber() const{
    return number;
}

void Flight::setDate(const Date &date) {
    this->date = date;
}

Date Flight::getDate() {
    return date;
}

void Flight::setDeparture(std::string departure) {
    this->departure = Schedule(departure);
}

std::string Flight::getDeparture() {
    return departure.getTime();
}

std::string Flight::getArrival() {
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

string Flight::getOrigin() {
    return origin->getCity();
}

void Flight::setDestiny(Airport* destiny) {
    this->destiny = destiny;
}

string Flight::getDestiny() {
    return destiny->getCity();
}

std::list<Passenger> Flight::getPassengers() const{
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

bool Flight::operator<(const Flight &flight) const {
    return this->getNumber() < flight.getNumber();
}

