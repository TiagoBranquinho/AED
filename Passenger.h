//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_PASSENGER_H
#define PROJETOAEROPORTO_PASSENGER_H


#include "Person.h"
#include "Baggage.h"

class Passenger: public Person{
private:
    Baggage baggage;
public:
    Passenger();
    Passenger(string name);
    Passenger(string name, Baggage baggage);
    void setBaggage(Baggage baggage);
    Baggage getBaggage();

};


#endif //PROJETOAEROPORTO_PASSENGER_H
