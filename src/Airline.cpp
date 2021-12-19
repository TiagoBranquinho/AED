//
// Created by Tiago Branquinho on 07/12/2021.
//

#include "../include/Airline.h"

Airline::Airline() = default;

Airline::Airline(std::vector<Plane> planes) {
    this->planes = planes;
}

void Airline::addPlane(const Plane &plane) {
    if(!duplicatedPlane(plane))
        planes.push_back(plane);
}

void Airline::removePlane(const Plane &plane) {
    auto planeItr = find(planes.begin(), planes.end(), plane);
    if (planeItr != planes.end()) planes.erase(planeItr);
    else throw(PlaneNotFoundException(plane.getPlate()));
}

void Airline::addFlight(Flight *flight) {
    if (!duplicatedFlight(*flight))
        flights.push_back(*flight);
}

void Airline::removeFlight(const Flight &flight) {
    auto flightItr = find(flights.begin(), flights.end(), flight);
    if (flightItr != flights.end()) flights.erase(flightItr);
}

std::vector<Flight> &Airline::getFlights() {
    return flights;
}

bool Airline::duplicatedFlight(const Flight &flight) {
    for(const Flight &f : flights){
        if(f == flight)
            return true;
    }
    return false;
}

bool Airline::duplicatedPlane(const Plane &plane) {
    for(Plane &p : planes){
        if(p == plane)
            return true;
    }
    return false;
}

std::vector<Plane> &Airline::getPlanes() {
    return planes;
}

void Airline::addPassengerToFlight(Flight &flight, const Passenger &passenger) {
    bool done = false;
    for(Plane &plane : getPlanes()) {
        for (Flight &flight1: plane.getFlightPlan()) {
            if (flight1 == flight) {
                if (plane.getCapacity() > flight.getNumberPassengers()) {
                    flight.addPassenger(passenger);
                    done = true;
                } else
                    throw FullPlaneException(plane.getCapacity());
                break;
            }
        }
        if (done)
            break;
    }
    if(!done)
        throw InvalidFlightException(flight.getNumber());
}

void Airline::checkInPassengers(Flight &flight) {
    if(!flight.getCheckInStatus())
        throw ClosedCheckInException(flight.getNumber());
    for(Passenger &p : flight.getPassengers()){
        p.checkIn();
        if(p.getBaggage() != nullptr && p.wantsAutomaticCheckIn())
            baggageTransportation(flight, *p.getBaggage());
    }
    baggageToPlane(flight);
    flight.closeCheckIn();
}

void Airline::baggageTransportation(Flight &flight, const Baggage &baggage) {
    addToTreadmill(baggage,flight);
    if(flight.getTreadmill().size() == flight.getNumberBaggages() ) {
        for (TransportCart &cart: carts) {
            if (cart.getId() == flight.getNumber()) {
                while (!flight.getTreadmill().empty()) {
                    for (TransportCart &cart: carts) {
                        if (cart.getId() == flight.getNumber()) {
                            cart.addBaggage(flight.getTreadmill().front());
                            flight.getTreadmill().pop();
                        }
                    }
                }
                break;
            }
        }
    }
}

void Airline::baggageToPlane(Flight &flight) {
    for(Plane &plane : planes) {
        if(find(plane.getFlightPlan().begin(), plane.getFlightPlan().end(), flight) != plane.getFlightPlan().end()) {
            for(TransportCart &cart : carts){
                if(cart.getId() == flight.getNumber()){
                    for(list<stack<Baggage>> &carriage : cart.getSlots()){
                        for(stack<Baggage> stack : carriage){
                            while(!stack.empty()){
                                plane.addBaggage(stack.top());
                                stack.pop();
                            }
                        }
                    }
                }
                break;
            }
            break;
        }
    }
}

void Airline::addToTreadmill(const Baggage &baggage, Flight &flight) {
    flight.getTreadmill().push(baggage);
}

bool Airline::validPlane(const Plane &plane) {
    for(const Plane& p : planes){
        if (p == plane)
            return true;
    }
    return false;
}

void Airline::addEmployee(const Employee &employee) {
    employees.push_back(employee);
}

void Airline::removeEmployee(const Employee &employee) {
    auto employeeItr = find(employees.begin(), employees.end(), employee);
    if (employeeItr != employees.end()) employees.erase(employeeItr);
}

std::vector<Employee> &Airline::getEmployees() {
    return employees;
}

void Airline::addCart(const TransportCart &cart) {
    if(!duplicatedCart(cart))
        carts.push_back(cart);
}

void Airline::removeCart(const TransportCart &cart) {
    auto cartItr = find(carts.begin(), carts.end(), cart);
    if (cartItr != carts.end()) carts.erase(cartItr);
}

vector<TransportCart> &Airline::getCarts() {
    return carts;
}

bool Airline::duplicatedCart(const TransportCart &cart) {
    for(const TransportCart &tc : carts){
        if(tc == cart)
            return true;
    }
    return false;
}

