//
// Created by Tiago Branquinho on 05/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRPORT_H
#define PROJETOAEROPORTO_AIRPORT_H

#include <string>
#include <vector>
#include "Flight.h"


class Airport {
private:
    std::string name;
    std::string city;
    std::vector<Flight> flights;
public:
    Airport();
    Airport(std::string name, std::string city, std::vector<Flight> flights);
    std::string getName();
    std::string getCity() const;
    void setName(std::string name);
    void setCity(std::string city);
    std::vector<Flight> getFlights();
    void setFlights(std::vector<Flight> flights);
    void addFlight(const Flight &flight);
    void removeFlight(const Flight &flight);

};


#endif //PROJETOAEROPORTO_AIRPORT_H
