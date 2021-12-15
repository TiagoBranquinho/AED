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
    Flight f = Flight(23, date, new Airport("air1", "Porto"), new Airport("air2", "Lisboa"));
    Plane plane("A213", 81);
    Passenger passenger1 = Passenger("Alberto",new Baggage(14,false), true);
    Passenger passenger2 = Passenger("Toze", nullptr, true);
    Airline airline = Airline();
    airline.addFlight(f);
    airline.addPlane(plane);
    airline.addPassengerToFlight(f,plane,passenger1);
    airline.addPassengerToFlight(f,plane,passenger2);

    EXPECT_EQ(f.getNumberPassengers(), 2);
    EXPECT_EQ(f.getNumberBaggages(), 1);
}

TEST(test_1, addPassengerToFlight){
    Date date = Date(12,3,2020);
    Flight f = Flight(23, date, new Airport("air1", "Porto"), new Airport("air2", "Lisboa"));
    Plane plane("A999", 81);
    Passenger passenger1 = Passenger("Alberto",new Baggage(14,false), true);
    Passenger passenger2 = Passenger("Toze", nullptr, true);
    Airline airline = Airline();
   // airline.addFlight(f); --> NOT MANDATORY
    try {
        airline.addPassengerToFlight(f,plane,passenger1);
    } catch(PlaneNotFoundException &e){

        EXPECT_EQ(e.getPlate(),"A999");
    }

    airline.addPlane(plane);
    airline.addPassengerToFlight(f,plane,passenger2);

    EXPECT_EQ(airline.validPlane(plane), true); // if true, plane was added to AIRLINE PLANES

}

TEST(test_1, planeCapacity){
    Date date = Date(12,3,2020);
    Flight f = Flight(23, date, new Airport("air1", "Porto"), new Airport("air2", "Lisboa"));
    Plane plane("A778", 2);
    Passenger passenger1 = Passenger("Alberto",new Baggage(14,false), true);
    Passenger passenger2 = Passenger("Toze", nullptr, true);
    Passenger passenger3 = Passenger("Vaca que ri",new Baggage(8, true), true);
    Airline airline = Airline();
    airline.addFlight(f);
    airline.addPlane(plane);
    airline.addPassengerToFlight(f,plane,passenger1);
    airline.addPassengerToFlight(f,plane,passenger2);
    try{
        airline.addPassengerToFlight(f,plane,passenger2);
    }catch(FullPlaneException &e){

        EXPECT_EQ(e.getCapacity(),2);

    }

    EXPECT_EQ(f.getNumberPassengers(), 2);
}

TEST(test_1, removePlane){
    Plane plane1("A778", 2);
    Airline airline;

    EXPECT_EQ(airline.getPlanes().size(),2);

    Plane plane2("F032",13);
    airline.removePlane(plane2);

    EXPECT_EQ(airline.getPlanes().size(),1);

    try{
        airline.removePlane(plane1);
    }catch(PlaneNotFoundException &e){

        EXPECT_EQ(e.getPlate(),"A778");

    }

}