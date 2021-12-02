#include "Plane.h"

Plane::Plane(string plate, unsigned int capacity) {
    this->plate = plate;
    this->capacity = capacity;
}

string Plane::getPlate() {
    return plate;
}

unsigned int Plane::getCapacity() {
    return capacity;
}

void Plane::setPlate(string plate) {
    this->plate = plate;
}

void Plane::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}
