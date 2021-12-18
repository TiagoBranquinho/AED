//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/Passenger.h"

using namespace std;


Passenger::Passenger() = default;

Passenger::Passenger(string name): Person(name){}

Passenger::Passenger(string name, Baggage *baggage, bool automaticCheckIn): Person(name) {
    this->baggage = baggage;
    this->automaticCheckIn = automaticCheckIn;
}

void Passenger::setBaggage(Baggage *baggage) {
    this->baggage = baggage;
}

Baggage* Passenger::getBaggage() const{
    return baggage;
}

std::string Passenger::getName() const {
    return name;
}

void Passenger::checkIn(){
    checkedIn = true;
}

bool Passenger::isCheckedIn() const{
    return checkedIn;
}

bool Passenger::wantsAutomaticCheckIn() const{
    return automaticCheckIn;
}

std::ostream &operator<<(ostream &os, const Passenger &passenger) {
    os << passenger.getName() << " " << passenger.getId() << " " << passenger.getBaggage()->getWeight() << " " << passenger.wantsAutomaticCheckIn() << '\n';
    return os;
}


