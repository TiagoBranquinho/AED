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
        if((*it).getPlate() == plane.getPlate()){
            planes.erase(it);
            break;
        }
    }
    throw(PlaneNotFoundException(plane.getPlate()));
}

void Airline::addFlight(Flight &flight) {
    if(validFlight(flight))
        flights.push_back(flight);
    else
        throw InvalidFlightException(flight.getNumber());
}

bool Airline::validFlight(Flight &flight) {
    for(const Flight &f : flights){
        if(f.getNumber() == flight.getNumber())
            return false;
    }
    return true;
}

std::vector<Plane> Airline::getPlanes() {
    return planes;
}

void Airline::addPassengerToFlight(Flight &flight, const Plane &plane, const Passenger &passenger) {
    bool found = false;
    for(const Flight &f : flights){
        if(flight.getNumber() == f.getNumber()){
            found = true;
            break;
        }
    }
    if(!found)
        flights.push_back(flight);
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
    for(Passenger p : flight.getPassengers()){
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
