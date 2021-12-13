//
// Created by Tiago Branquinho on 05/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRPORT_H
#define PROJETOAEROPORTO_AIRPORT_H

#include <string>
#include <vector>
#include "bst.h"
#include "Flight.h"
#include "TransportationLocals.h"

class Airport {
private:
    std::string name;
    std::string city;
    std::vector<Flight> flights;
    TransportationLocals locals;

public:
    Airport(std::string name, std::string city);
    std::string getName();
    std::string getCity() const;
    void setName(std::string name);
    void setCity(std::string city);
    std::vector<Flight> getFlights();
    void setFlights(std::vector<Flight> flights);
    void addFlight(const Flight &flight);
    void removeFlight(const Flight &flight);
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    void printLocals();
    BSTItrIn<GroundTransportation> localsItrIn();
};


#endif //PROJETOAEROPORTO_AIRPORT_H
