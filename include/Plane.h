#pragma once
#ifndef PROJETOAEROPORTO_PLANE_H
#define PROJETOAEROPORTO_PLANE_H

#include <string>
#include <list>
#include <queue>

#include "Flight.h"
#include "Service.h"

class Plane {

private:
    std::string plate;
    unsigned int capacity;
    bool onDuty = false;
    std::list<Flight> flightPlan;
    std::queue<Service> servicesTODO;
    std::vector<Service> servicesDONE;
    std::list<Baggage> planeTrunk;

public:
    Plane(std::string plate, unsigned int capacity);
    std::string getPlate() const;
    unsigned int getCapacity() const;
    std::list<Flight> &getFlightPlan();
    std::vector<Service> getServicesDone() const;
    std::queue<Service> getServicesToDo() const;
    list<Baggage> getTrunk() const;
    bool getOnDuty() const;
    void setOnDuty(bool duty);
    void addFlight(const Flight &flight);
    void removeFlight(const Flight &flight);
    void addService(const Service &service);
    void serviceDone(const Service &service);
    void addBaggage(const Baggage &baggage);
    void removeServiceDONE(); // removes service from serviceTODO queue and adds it to serviceDONE vector
    bool validPlate(std::string plate);
    void setServicesToDo(queue<Service> &services);
    void setServicesDone(vector<Service> &services);
    void setPlaneTrunk(list<Baggage> &baggages);
    bool operator==(const Plane &plane) const;
    friend std::ostream& operator<<(std::ostream& os, const Plane &plane);
};

class InvalidPlateException: public std::exception{
private:
    std::string plate;
public:
    InvalidPlateException(std::string plate){this->plate = plate;}
    std::string getPlate(){return plate;}
    const char * what () const noexcept override {
        return "Invalid plane plate!";
    }
};


#endif //PROJETOAEROPORTO_PLANE_H