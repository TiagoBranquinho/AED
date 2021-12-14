//
// Created by Tiago Branquinho on 14/12/2021.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Airline.h"

using namespace std;
using testing::Eq;

TEST(test_1, addBaggage){
    Date date = Date(12,3,2020);
    Flight f = Flight(23, date , 3, "Porto", "Lisbon");
    Plane plane("A213", 81);
    Passenger passenger1 = Passenger("Alberto",new Baggage(14,false), true);
    Passenger passenger2 = Passenger("Toze", nullptr, true);
    /*Airline airline = Airline();
    airline.addFlight(f);
    airline.addPlane(plane);
    airline.addPassengerToFlight(f,plane,passenger1);
    airline.addPassengerToFlight(f,plane,passenger2);*/

    EXPECT_EQ(f.getNumberPassengers(), 2);
    EXPECT_EQ(f.getNumberBaggages(), 1);
}