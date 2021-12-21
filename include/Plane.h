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
    /**
     * Class constructor with the plate and the plane capacity number
     * @param plate plate string in <uppercase letter><0-9><0-9><0-9> format
     * @param capacity capacity integer number
     */
    Plane(std::string plate, unsigned int capacity);
    std::string getPlate() const;
    unsigned int getCapacity() const;
    /**
     * Gets a reference to the flight plane list of the plane
     * @return reference to flightPlane list
     */
    std::list<Flight> &getFlightPlan();
    std::vector<Service> getServicesDone() const;
    std::queue<Service> getServicesToDo() const;
    list<Baggage> getTrunk() const;
    bool getOnDuty() const;
    /**
     * Sets the plane duty variable to the argument boolean value
     * @param duty true if the plane is in flight or false otherwise
     */
    void setOnDuty(bool duty);
    void addFlight(const Flight &flight);
    void removeFlight(const Flight &flight);
    void addService(const Service &service);
    void serviceDone(const Service &service);
    void addBaggage(const Baggage &baggage);
    /**
     * Removes service from serviceTODO queue and adds it to serviceDONE vector
     */
    void removeServiceDONE();
    /**
     * Checks if a plate is valid
     * @param plate plate string in <uppercase letter><0-9><0-9><0-9>
     * @return true if plate is valid or false otherwise
     */
    bool validPlate(std::string plate);
    void setServicesToDo(queue<Service> &services);
    void setServicesDone(vector<Service> &services);
    /**
     * Sets the plane trunk in a list of baggage
     * @param baggages list of baggage objects passed by reference
     */
    void setPlaneTrunk(list<Baggage> &baggages);
    /**
     * Checks if the plane is the same as another based one is plate
     * @param plane plane object passed by reference
     * @return true if the plane's plate is the same or false otherwise
     */
    bool operator==(const Plane &plane) const;
    /**
     * Operator to print the plane object in the correct format
     * @param os stream where the plane will be printed
     * @param plane plane object passed by reference
     * @return ostream with the plane printed
     */
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