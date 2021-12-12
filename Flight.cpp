//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "Flight.h"

using namespace std;


Flight::Flight() = default;

Flight::Flight(unsigned int number, const Date &date, unsigned int duration, string origin, string destiny) {
    this->number = number;
    this->date = date;
    this->duration = duration;
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

void Flight::setDuration(unsigned int duration) {
    this->duration = duration;
}

unsigned int Flight::getDuration() {
    return duration;
}

void Flight::setOrigin(string origin) {
    this->origin = origin;
}

string Flight::getOrigin() {
    return origin;
}

void Flight::setDestiny(string destiny) {
    this->destiny = destiny;
}

string Flight::getDestiny() {
    return destiny;
}

std::list<Passenger> Flight::getPassengers() const{
    return passengers;
}

unsigned int Flight::getNumberPassengers() {
    return passengers.size();
}

void Flight::addPassenger(const Passenger &passenger) {
    passengers.push_back(passenger);
}

void Flight::closeCheckIn() {
    checkIn = false;
}

void Flight::openCheckIn() {
    checkIn = true;
}

bool Flight::getCheckInStatus() {
    return checkIn;
}

