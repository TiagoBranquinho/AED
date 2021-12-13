//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Passenger.h"

using namespace std;


Passenger::Passenger() = default;

Passenger::Passenger(string name) {
    this->name = name;
    // null baggage?? -> no caso de nao apresentar mala
}

Passenger::Passenger(string name, const Baggage &baggage) {
    this->name = name;
    this->baggage = baggage;
    withBaggage = true;
}

void Passenger::setBaggage(const Baggage &baggage) {
    this->baggage = baggage;      // if MAX_WEIGHT == const --> ERROR!
    withBaggage = true;
}

Baggage Passenger::getBaggage() const{
    return baggage;
}

std::string Passenger::getName() const {
    return std::string();
}

void Passenger::checkIn() {

}

bool Passenger::operator==(const Passenger &passenger) {
    return (this->getName() == passenger.getName() && this->getBaggage() == passenger.getBaggage() && this->isCheckedIn() == passenger.isCheckedIn());
}

bool Passenger::isCheckedIn() const{
    return checkedIn;
}

void Passenger::Checkin() {
    checkedIn = true;
}


