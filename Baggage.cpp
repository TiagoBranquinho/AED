//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "Baggage.h"

Baggage::Baggage() = default;

Baggage::Baggage(double weight, bool special) {
    this->weight = weight;
    this->special = special;
    checkWeight();
}

double Baggage::getWeight() {
    return weight;
}

void Baggage::setWeight(double weight) {
    this->weight = weight;
    checkWeight();

}

bool Baggage::isSpecial() {
    return special;
}

void Baggage::setSpecial(bool special) {
    this->special = special;

}

bool Baggage::isOverweight() {
    return overweight;
}

void Baggage::checkWeight() {
    if(weight <= MAXWEIGHT)
        overweight = false;
    else
        overweight = true;
}
