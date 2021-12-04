//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_FLIGHT_H
#define PROJETOAEROPORTO_FLIGHT_H


#include "time.h"
#include "Date.h"
#include "Passenger.h"
#include <list>

using namespace std;


class Flight {

private:
    unsigned int number;
    Date date;
    unsigned int duration; //in seconds
    string origin, destiny;
    list<Passenger> passengers;

public:
    Flight();
    Flight(unsigned int number, Date date, unsigned int duration, string origin, string destiny);
    void setNumber(unsigned int number);
    unsigned int getNumber();
    void setDate(Date date);
    Date getDate();
    void setDuration(unsigned int duration);
    unsigned int getDuration();
    void setOrigin(string origin);
    string getOrigin();
    void setDestiny(string destiny);
    string getDestiny();
    void addPassenger(const Passenger &passenger);
};


#endif //PROJETOAEROPORTO_FLIGHT_H
