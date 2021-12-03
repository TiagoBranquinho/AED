//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "Baggage.h"

Baggage::Baggage() {
    weight = 0;
    special = false;
}

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
    return(weight <= maxWeight ? false:true);
}

void Baggage::checkWeight() {
    if(weight <= maxWeight)
        overweight = false;
    else
        overweight = true;
}
