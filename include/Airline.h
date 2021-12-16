//
// Created by Tiago Branquinho on 07/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRLINE_H
#define PROJETOAEROPORTO_AIRLINE_H


#include "Plane.h"
#include "TransportCart.h"

class Airline {
private:
    std::vector<Plane> planes = {Plane("A123", 89), Plane("F032", 13)};
    std::vector<Flight> flights;
    std::vector<Employee> employees;
    std::vector<Airport> airports;
    std::vector<TransportCart> carts;
public:
    Airline();
    Airline(std::vector<Plane> planes);
    void addPlane(const Plane &plane);
    void removePlane(const Plane &plane);
    void addFlight(Flight &flight);
    void removeFlight(const Flight &flight);
    std::vector<Flight> &getFlights();
    bool duplicatedFlight(const Flight &flight);
    bool validPlane(const Plane &plane);
    std::vector<Plane> &getPlanes();
    void addPassengerToFlight(Flight &flight, const Plane &plane, const Passenger &passenger);
    void checkInPassengers(Flight &flight);
    void checkInPassenger(Flight &flight, Passenger &passenger);
    void baggageTransportation(Flight &flight, const Baggage &baggage);
    void baggageToPlane(Flight &flight);
    void addToTreadmill(const Baggage &baggage, Flight &flight);
    void addEmployee(const Employee &employee);
    void removeEmployee(const Employee &employee);
    void addCart(const TransportCart &cart);
//    void removeCart(const TransportCart &cart);
    bool duplicatedCart(const TransportCart &cart);
    std::vector<Employee> &getEmployees();
};

class PlaneNotFoundException: public std::exception{
private:
    std::string plate;
public:
    PlaneNotFoundException(const std::string &plate){this->plate = plate;}
    std::string getPlate(){return plate;}

};

class NoTicketException: public std::exception{
private:
    std::string name;
    unsigned int number;
public:
    NoTicketException(const std::string &name, const unsigned int &number){this->name = name;this->number = number;}
    std::string getName(){return name;}
    unsigned int getNumber(){return number;}
};

class FullPlaneException: public std::exception{
private:
    unsigned int capacity;
public:
    FullPlaneException(const unsigned int capacity){this->capacity = capacity;}
    unsigned int getCapacity() const{return capacity;}
};

class ClosedCheckInException: public std::exception{
private:
    unsigned int number;
public:
    ClosedCheckInException(unsigned int number){this->number = number;}
    unsigned int getNumber() const{return number;}
};

#endif //PROJETOAEROPORTO_AIRLINE_H
