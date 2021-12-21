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
    bool checkIn;
    unsigned int numberOfBaggages = 0;
    std::queue<Baggage> treadmill;
public:
    /**
     * Default class constructor
     */
    Flight();
    /**
     * Class constructor with the number, date, origin airport and destiny airport of the flight
     * @param number number of the flight
     * @param date date object point
     * @param origin origin airport pointer
     * @param destiny destiny airport pointer
     */
    Flight(unsigned int number, const Date *date, Airport* origin, Airport* destiny);
    unsigned int getNumber() const;
    Date getDate() const;
    /**
     * Sets the departure schedule of the flight
     * @param departure departure string in HH:MM format
     */
    void setDeparture(std::string departure);
    std::string getDeparture() const;
    /**
     * Gets the scheduled arrival of the flight
     * @return arrival string in HH:MM format
     */
    std::string getArrival() const;
    /**
     * Sets the duration of the flight
     * @param duration duration string in HH:MM format
     */
    void setDuration(std::string duration);
    /**
     * Gets the duration of the flight
     * @return duration string in HH:MM format
     */
    std::string getDuration();
    void setOrigin(Airport* origin);
    /**
     * Gets the name of the city of the origin airport
     * @return name string of the city
     */
    std::string getOrigin() const;
    /**
     * Gets the name of the city of the destiny airport
     * @return name string of the city
     */
    std::string getDestiny() const;
    /**
     * Gets the list of the flight's passengers
     * @return a reference to the passenger's list
     */
    std::list<Passenger> &getPassengers();
    unsigned int getNumberPassengers() const;
    unsigned int getNumberBaggages() const;
    /**
     * Gets the treadmill queue of the passenger's baggage
     * @return a reference to the treadmill queue
     */
    queue<Baggage> &getTreadmill();
    void setTreadmill(queue<Baggage> &q);
    void addPassenger(const Passenger &passenger);
    /**
     * Closes checkin of the flight changing checkin bool variable
     */
    void closeCheckIn();
    /**
     * Opens checkin of the flight changing checkin bool variable
     */
    void openCheckIn();
    void setCheckIn(bool var);
    bool getCheckInStatus() const;
    Airport* getOriginPointer() const;
    Airport* getDestinyPointer() const;
    /**
     * Checks if a flight is the same as another based on their number
     * @param flight flight object passed by reference
     * @return true if the number of flights is the same or false otherwise
     */
    bool operator==(const Flight &flight) const;
    /**
     * Operator to print the flight object in the correct format
     * @param os stream where the flight will be printed
     * @param flight flight object passed by reference
     * @return ostream with the flight printed
     */
    friend std::ostream& operator<<(std::ostream& os, const Flight &flight);
};

class InvalidFlightException: public std::exception{
private:
    unsigned int number;
public:
    InvalidFlightException(unsigned int number){this->number = number;}
    const char * what () const noexcept override {
        return "Invalid flight!";
    }
};

#endif //PROJETOAEROPORTO_FLIGHT_H
