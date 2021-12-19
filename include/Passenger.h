//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_PASSENGER_H
#define PROJETOAEROPORTO_PASSENGER_H


#include "Person.h"
#include "Baggage.h"

class Passenger: public Person{
private:
    Baggage *baggage;
    bool checkedIn = false;
    bool automaticCheckIn;
    int baggageWgh = -1;
public:
    Passenger();
    Passenger(std::string name);
    Passenger(std::string name, Baggage *baggage, bool wantsAutomaticCheckIn);
    Baggage* getBaggage() const;
    int baggageWeight() const;
    void checkIn();
    bool isCheckedIn() const;
    bool wantsAutomaticCheckIn() const;
    friend std::ostream& operator<<(std::ostream& os, const Passenger &passenger);
};


#endif //PROJETOAEROPORTO_PASSENGER_H
