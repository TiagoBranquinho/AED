//
// Created by Tiago Branquinho on 07/12/2021.
//

#include "../include/Airline.h"

Airline::Airline() = default;

Airline::Airline(std::vector<Plane> planes) {
    this->planes = planes;
}

void Airline::addPlane(const Plane &plane) {
    planes.push_back(plane);
}

void Airline::removePlane(const Plane &plane) {
    for(auto it = planes.begin(); it != planes.end(); it++){
        if((*it) == plane){
            planes.erase(it);
            return;
        }
    }
    throw(PlaneNotFoundException(plane.getPlate()));
}

void Airline::addFlight(Flight &flight) {
    if (!duplicatedFlight(flight))
        flights.push_back(flight);
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

std::vector<Plane> &Airline::getPlanes() {
    return planes;
}

void Airline::addPassengerToFlight(Flight &flight, const Plane &plane, const Passenger &passenger) {
    if(!validPlane(plane))
        throw PlaneNotFoundException(plane.getPlate());
    addFlight(flight);
    if(plane.getCapacity() > flight.getNumberPassengers()){
        flight.addPassenger(passenger);
    }
    else
        throw FullPlaneException(plane.getCapacity());
}

void Airline::checkInPassenger(Flight &flight, Passenger &passenger) {
    if(!flight.getCheckInStatus())
        throw ClosedCheckInException(flight.getNumber());
    bool hasTicket = false;
    for(Passenger &p : flight.getPassengers()){
        if(p == passenger){
            hasTicket = true;
            passenger.checkIn();
            if(passenger.getBaggage() != nullptr && passenger.wantsAutomaticCheckIn())
                baggageTransportation(flight, *passenger.getBaggage());
            break;
        }
    }
    if(!hasTicket)
        throw NoTicketException(passenger.getName());
}

void Airline::baggageTransportation(Flight &flight, const Baggage &baggage) {
    addToTreadmill(baggage);
    if(treadmill.size() == flight.getNumberBaggages()){
        while(!treadmill.empty()){
            transportCart.addBaggage(treadmill.front());
            treadmill.pop();
        }
    }

    // ... not finished

}

void Airline::addToTreadmill(const Baggage &baggage) {
    treadmill.push(baggage);
}

bool Airline::validPlane(const Plane &plane) {
    for(Plane p : planes){
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
