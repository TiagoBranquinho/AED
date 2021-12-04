//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "groundTransportation.h"

groundTransportation::groundTransportation() = default;

groundTransportation::groundTransportation(string type, unsigned int distance) {
    this->type = type;
    this->distance = distance;

}

void groundTransportation::setType(string type) {
    this->type = type;
}

void groundTransportation::setDistance(unsigned int distance) {
    this->distance = distance;
}

string groundTransportation::getType() {
    return type;
}

unsigned int groundTransportation::getDistance() {
    return distance;
}

