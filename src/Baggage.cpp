//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "../include/Baggage.h"

using namespace std;

unsigned Baggage::ID = 0;

Baggage::Baggage() = default;

Baggage::Baggage(double weight) {
    this->weight = weight;
    id = ID++;
    checkWeight();
}

unsigned int Baggage::getId() const {
    return id;
}

double Baggage::getWeight() const{
    return weight;
}

void Baggage::setWeight(double weight) {
    this->weight = weight;
    checkWeight();

}

bool Baggage::isOverweight() const{
    return overweight;
}

void Baggage::checkWeight() {
    if(weight <= MAX_WEIGHT)
        overweight = false;
    else
        overweight = true;
}

bool Baggage::operator==(const Baggage &baggage) {
    return(this->id == baggage.getId());
}
