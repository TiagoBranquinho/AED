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

public:
    Flight();
    Flight(unsigned int number, Date date, unsigned int duration, std::string origin, std::string destiny);
    void setNumber(unsigned int number);
    unsigned int getNumber();
    void setDate(Date date);
    Date getDate();
    void setDuration(unsigned int duration);
    unsigned int getDuration();
    void setOrigin(std::string origin);
    std::string getOrigin();
    void setDestiny(std::string destiny);
    std::string getDestiny();
    void addPassenger(const Passenger &passenger);
};


#endif //PROJETOAEROPORTO_FLIGHT_H
