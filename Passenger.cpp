//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "Passenger.h"

using namespace std;


Passenger::Passenger() = default;

Passenger::Passenger(string name) {
    this->name = name;
    // null baggage?? -> no caso de nao apresentar mala
}

Passenger::Passenger(string name, Baggage baggage) {
    this->name = name;
    this->baggage = baggage;
}

void Passenger::setBaggage(Baggage baggage) {
    this->baggage = baggage;      // if MAX_WEIGHT == const --> ERROR!
}

Baggage Passenger::getBaggage() {
    return baggage;
}
