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
    baggageWgh = baggage->getWeight();
}

Baggage* Passenger::getBaggage() const{
    return baggage;
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
    os << setw(16) << passenger.getName() << setw(3) << "-" << setw(2) << passenger.getId() << setw(3) <<  "-" << setw(14) <<  passenger.baggageWeight() << setw(14) << "-" << setw(18) <<  passenger.wantsAutomaticCheckIn() << '\n';
    return os;
}


int Passenger::baggageWeight() const{
    return baggageWgh;
}


