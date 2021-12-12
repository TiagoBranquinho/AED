//
// Created by Tiago Branquinho on 07/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRLINE_H
#define PROJETOAEROPORTO_AIRLINE_H


#include "Plane.h"
#include "TransportCart.h"

class Airline {
private:
    std::vector<Plane> planes = {Plane("ABC", 89), Plane("XYZ", 13)};
    std::queue<Baggage> treadmill;
    TransportCart transportCart = TransportCart(2,3,4);
public:
    Airline();
    Airline(std::vector<Plane> planes);
    void addPlane(const Plane &plane);
    void removePlane(const Plane &plane);
    std::vector<Plane> getPlanes();
    void addPassengerToFlight(Flight flight, const Plane &plane, const Passenger &passenger);
    void checkInPassenger(Flight &flight, Passenger &passenger);
    void baggageTransportation(Flight &flight, const Baggage &baggage);
    void addToTreadmill(const Baggage &baggage);
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

class NoTicketException{
private:
    std::string name;
public:
    NoTicketException(const std::string name){this->name = name;}
    std::string getName(){return name;}
};

class ClosedCheckInException{
private:
    unsigned int number;
public:
    ClosedCheckInException(unsigned int number){this->number = number;}
    unsigned int getNumber(){return number;}
};


#endif //PROJETOAEROPORTO_AIRLINE_H
