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
    /**
     * Default class constructor
     */
    Passenger();
    /**
     * Class constructor with the passenger's name
     * @param name name string of the passenger
     */
    Passenger(std::string name);
    /**
     * Class constructor with passenger's name, baggage and his decision on wanting automatic checkin or not
     * @param name passenger's name string
     * @param baggage baggage object pointer
     * @param wantsAutomaticCheckIn true if passenger wants automatic checkin or false otherwise
     */
    Passenger(std::string name, Baggage *baggage, bool wantsAutomaticCheckIn);
    Baggage* getBaggage() const;
    int baggageWeight() const;
    void checkIn();
    bool isCheckedIn() const;
    bool wantsAutomaticCheckIn() const;
    /**
     * Operator to print the passenger object in the correct format
     * @param os stream where the passenger will be printed
     * @param passenger passenger object passed by reference
     * @return ostream with the passenger printed
     */
    friend std::ostream& operator<<(std::ostream& os, const Passenger &passenger);
};


#endif //PROJETOAEROPORTO_PASSENGER_H
