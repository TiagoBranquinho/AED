//
// Created by Tiago Branquinho on 25/11/2021.
//
#ifndef PROJETOAEROPORTO_FLIGHT_H
#define PROJETOAEROPORTO_FLIGHT_H

#include <list>
#include <ctime>
#include "Date.h"
#include "Passenger.h"
#include "Airport.h"

class Flight {

private:
    unsigned int number;
    Date date;
    Schedule departure;
    Schedule duration;
    Airport *origin, *destiny;
    std::list<Passenger> passengers;
    bool checkIn = false;
    unsigned int numberOfBaggages = 0;
public:
    Flight();
    Flight(unsigned int number, const Date &date, Airport* origin, Airport* destiny);
    void setNumber(unsigned int number);
    unsigned int getNumber() const;
    void setDate(const Date &date);
    Date getDate();
    void setDeparture(std::string departure);
    std::string getDeparture();
    std::string getArrival();
    void setDuration(std::string duration);
    std::string getDuration();
    void setOrigin(Airport* origin);
    std::string getOrigin();
    void setDestiny(Airport* destiny);
    std::string getDestiny();
    std::list<Passenger> getPassengers() const;
    unsigned int getNumberPassengers() const;
    unsigned int getNumberBaggages() const;
    void addPassenger(const Passenger &passenger);
    void closeCheckIn();
    void openCheckIn();
    bool getCheckInStatus();
    bool operator==(Flight &flight);
};

#endif //PROJETOAEROPORTO_FLIGHT_H
