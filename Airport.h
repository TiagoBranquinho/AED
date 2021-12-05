//
// Created by Tiago Branquinho on 05/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRPORT_H
#define PROJETOAEROPORTO_AIRPORT_H

#include <vector>
#include <string>
#include "Plane.h"

class Airport {
private:
    std::string name;
    std::string city;
    std::vector<Plane> planes;
    std::vector<Flight> flights;
public:
    Airport();
    Airport(std::string name, std::string city);
    std::string getName();
    std::string getCity();
    void setName(std::string name);
    void setCity(std::string city);
    void addPlane(const Plane &plane);
    void removePlane(const Plane &plane);
    void addFlight(const Flight &flight);
    void removeFlight(const Flight &flight);
};


#endif //PROJETOAEROPORTO_AIRPORT_H
