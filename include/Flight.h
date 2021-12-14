//
// Created by Tiago Branquinho on 25/11/2021.
//
#ifndef PROJETOAEROPORTO_FLIGHT_H
#define PROJETOAEROPORTO_FLIGHT_H


#include <ctime>
#include "Date.h"
#include "Passenger.h"
#include <list>

class Flight {

private:
    unsigned int number;
    Date date;
    unsigned int duration; //in seconds
    std::string origin, destiny;
    std::list<Passenger> passengers;
    bool checkIn = false;
    unsigned int numberOfBaggages;
public:
    Flight();
    Flight(unsigned int number, const Date &date, unsigned int duration, std::string origin, std::string destiny);
    void setNumber(unsigned int number);
    unsigned int getNumber() const;
    void setDate(const Date &date);
    Date getDate();
    void setDuration(unsigned int duration);
    unsigned int getDuration();
    void setOrigin(std::string origin);
    std::string getOrigin();
    void setDestiny(std::string destiny);
    std::string getDestiny();
    std::list<Passenger> getPassengers() const;
    unsigned int getNumberPassengers() const;
    unsigned int getNumberBaggages() const;
    void addPassenger(const Passenger &passenger);
    void closeCheckIn();
    void openCheckIn();
    bool getCheckInStatus();
};

#endif //PROJETOAEROPORTO_FLIGHT_H
