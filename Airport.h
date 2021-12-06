//
// Created by Tiago Branquinho on 05/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRPORT_H
#define PROJETOAEROPORTO_AIRPORT_H

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
    Airport(std::string name, std::string city, std::vector<Plane> planes, std::vector<Flight> flights);
    std::string getName();
    std::string getCity() const;
    void setName(std::string name);
    void setCity(std::string city);
    std::vector<Plane> getPlanes();
    std::vector<Flight> getFlights();
    void setPlanes(std::vector<Plane> planes);
    void setFlights(std::vector<Flight> flights);
    void addPlane(const Plane &plane);
    void removePlane(const Plane &plane);
    void addFlight(const Flight &flight);
    void removeFlight(const Flight &flight);

};


#endif //PROJETOAEROPORTO_AIRPORT_H
