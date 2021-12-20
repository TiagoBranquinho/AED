#ifndef PROJETOAEROPORTO_AIRLINE_H
#define PROJETOAEROPORTO_AIRLINE_H

#include "Plane.h"
#include "TransportCart.h"

class Airline {
private:
    std::vector<Plane> planes;
    std::vector<Flight> flights;
    std::vector<Employee> employees;
    std::vector<TransportCart> carts;
public:
    /**
     * Class constructor that creates empty vectors for planes, flights, employees and carts
     */
    Airline();
    /**
     * Adds plane to planes vector
     * @param plane plane object passed by reference
     */
    void addPlane(const Plane &plane);
    /**
     * Removes plane from planes vector
     * @param plane plane object passed by reference
     */
    void removePlane(const Plane &plane);
    /**
     * Checks if a plane is already in planes vector
     * @param plane plane object passed by reference
     * @return true if the plane is in planes vector or false otherwise
     */
    bool duplicatedPlane(const Plane &plane);
    /**
     * Adds flight to flights vector
     * @param flight pointer to flight object
     */
    void addFlight(Flight *flight);
    /**
     * Removes flight from flights vector
     * @param flight flight object passed by reference
     */
    void removeFlight(const Flight &flight);
    std::vector<Flight> &getFlights();
    /**
     * Checks if a flight is already in flights vector
     * @param flight flight object passed by reference
     * @return true if flight is in flights vector or false otherwise
     */
    bool duplicatedFlight(const Flight &flight);
    std::vector<Plane> &getPlanes();
    /**
     * Searches what plane has the flight argument and adds the passenger argument to it
     * Throws FullPlaneException is the plane found is full
     * Throws InvalidFlightException if there isn't the flight argument in the flights vector
     * @param flight flight object passed by reference
     * @param passenger passenger object passed by reference
     */
    void addPassengerToFlight(Flight &flight, const Passenger &passenger);
    /**
     * Check in all the passengers of the flight argument by changing their checkin status
     * Adds their baggage to transportation process
     * @param flight flight object passed by reference
     */
    void checkInPassengers(Flight &flight);
    /**
     * Adds the baggage argument the flight's argument treadmill
     * If the treadmill has all the baggage they are added to a transportation cart
     * @param flight flight object passed by reference
     * @param baggage baggage object passed by reference
     */
    void baggageTransportation(Flight &flight, const Baggage &baggage);
    /**
     * Adds all baggage of the flight argument to the corresponding plane that is taking the flight
     * @param flight flight object passed by reference
     */
    void baggageToPlane(Flight &flight);
    /**
     * Adds the baggage argument to the flight's argument treadmill
     * @param baggage baggage object passed by reference
     * @param flight flight object passed by reference
     */
    void addToTreadmill(const Baggage &baggage, Flight &flight);
    /**
     * Adds employee argument to employees vector
     * @param employee employee object passed by reference
     */
    void addEmployee(const Employee &employee);
    /**
     * Removes employee argument from employees vector
     * @param employee employee object passed by reference
     */
    void removeEmployee(const Employee &employee);
    /**
     * Adds cart argument to carts vector
     * @param cart cart object passed by reference
     */
    void addCart(const TransportCart &cart);
    /**
     * Removes cart argument from carts vector
     * @param cart cart object passed by reference
     */
    void removeCart(const TransportCart &cart);
    std::vector<TransportCart> &getCarts();
    /**
     * Checks if a cart is already in carts vector
     * @param cart cart object passed by reference
     * @return true if the cart is in carts vector or false otherwise
     */
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
