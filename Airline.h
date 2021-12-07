//
// Created by Tiago Branquinho on 07/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRLINE_H
#define PROJETOAEROPORTO_AIRLINE_H


#include "Plane.h"

class Airline {
private:
    std::vector<Plane> planes = {Plane("ABC", 89), Plane("XYZ", 13)};
public:
    Airline();
    Airline(std::vector<Plane> planes);
    void addPlane(const Plane &plane);
    void removePlane(const Plane &plane);
    std::vector<Plane> getPlanes();
    void addPassengerToFlight(Flight flight, const Plane &plane, const Passenger &passenger);
};

class PlaneNotFoundException{
private:
    std::string plate;
public:
    PlaneNotFoundException(const std::string &plate){this->plate = plate;}
    std::string getPlate(){return plate;}

};

class FullPlaneException{
private:
    unsigned int capacity;
public:
    FullPlaneException(const unsigned int capacity){this->capacity = capacity;}
    unsigned int getCapacity(){return capacity;}
};


#endif //PROJETOAEROPORTO_AIRLINE_H
