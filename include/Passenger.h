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
public:
    Passenger();
    Passenger(std::string name);
    Passenger(std::string name, Baggage *baggage, bool wantsAutomaticCheckIn);
    void setBaggage(Baggage *baggage);
    Baggage* getBaggage() const;
    std::string getName() const;
    void checkIn();
    bool isCheckedIn() const;
    bool wantsAutomaticCheckIn();

};


#endif //PROJETOAEROPORTO_PASSENGER_H
