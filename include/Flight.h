//
// Created by Tiago Branquinho on 25/11/2021.
//
#ifndef PROJETOAEROPORTO_FLIGHT_H
#define PROJETOAEROPORTO_FLIGHT_H

#include <list>
#include <ctime>
#include "Date.h"
#include "Schedule.h"
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
    std::queue<Baggage> treadmill;
public:
    Flight();
    Flight(unsigned int number, const Date *date, Airport* origin, Airport* destiny);
    void setNumber(unsigned int number);
    unsigned int getNumber() const;
    void setDate(const Date &date);
    Date getDate() const;
    void setDeparture(std::string departure);
    std::string getDeparture() const;
    std::string getArrival() const;
    void setDuration(std::string duration);
    std::string getDuration();
    void setOrigin(Airport* origin);
    std::string getOrigin() const;
    void setDestiny(Airport* destiny);
    std::string getDestiny() const;
    std::list<Passenger> getPassengers() const;
    unsigned int getNumberPassengers() const;
    unsigned int getNumberBaggages() const;
    queue<Baggage> getTreadmill();
    void setTreadmill(queue<Baggage> &q);
    vector<Baggage> getTreadmillVect();
    void addPassenger(const Passenger &passenger);
    void removePassenger(const Passenger &passenger);
    void closeCheckIn();
    void openCheckIn();
    void setCheckIn(bool var);
    bool getCheckInStatus() const;
    Airport* getOriginAir() const;
    Airport* getDestinyAir() const;
    bool operator==(const Flight &flight) const;
    bool operator<(const Flight &flight) const;
    friend std::ostream& operator<<(std::ostream& os, const Flight &flight);
};

#endif //PROJETOAEROPORTO_FLIGHT_H
