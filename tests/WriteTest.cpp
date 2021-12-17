#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Airport.h"
#include "../include/App.h"

using namespace std;
using testing::Eq;

TEST(test_1, writeAirports){
    App app;
    Airport air1 = Airport("Airport1", "lisboa");
    Airport air2 = Airport("Airport2", "porto");
    Schedule sch1("20:20");
    Schedule sch2("11:00");
    Schedule sch3("03:20");
    Schedule sch4("21:20");

    GroundTransportation gd1("Train", 10);
    GroundTransportation gd2("Bus", 7);
    GroundTransportation gd3("Taxi", 2);
    GroundTransportation gd4("Uber", 4);
    GroundTransportation gd5("Uber", 1);

    gd1.addSchedule(sch1);
    gd1.addSchedule(sch2);
    gd1.addSchedule(sch3);
    gd1.addSchedule(sch1);
    gd2.addSchedule(sch2);
    gd3.addSchedule(sch3);
    gd4.addSchedule(sch4);

    air1.addGroundTransportation(gd1);
    air1.addGroundTransportation(gd2);
    air2.addGroundTransportation(gd3);
    air2.addGroundTransportation(gd4);
    air2.addGroundTransportation(gd5);

    app.airports.push_back(air1);
    app.airports.push_back(air2);

    app.writeAirportsFile();

    EXPECT_EQ(1, true);
}

TEST(test_1, writeFlights){
    App app;
    Airport air1 = Airport("Airport1", "lisboa");
    Airport air2 = Airport("Airport2", "porto");
    Schedule sch1("20:20");
    Schedule sch2("11:00");
    Schedule sch3("03:20");
    Schedule sch4("21:20");

    GroundTransportation gd1("Train", 10);
    GroundTransportation gd2("Bus", 7);
    GroundTransportation gd3("Taxi", 2);
    GroundTransportation gd4("Uber", 4);
    GroundTransportation gd5("Uber", 1);

    gd1.addSchedule(sch1);
    gd1.addSchedule(sch2);
    gd1.addSchedule(sch3);
    gd1.addSchedule(sch1);
    gd2.addSchedule(sch2);
    gd3.addSchedule(sch3);
    gd4.addSchedule(sch4);

    air1.addGroundTransportation(gd1);
    air1.addGroundTransportation(gd2);
    air2.addGroundTransportation(gd3);
    air2.addGroundTransportation(gd4);
    air2.addGroundTransportation(gd5);

    app.airports.push_back(air1);
    app.airports.push_back(air2);

    app.writeAirportsFile();

    Flight f1 = Flight(12, new Date("2020/04/23"), &air1, &air2);
    Flight f2 = Flight(9, new Date("2020/04/30"), &air2, &air1);

    Passenger p1("joase", new Baggage(20), true);
    Passenger p2("maria", new Baggage(35), true);
    Passenger p3("antoniio", new Baggage(3), false);

    f1.addPassenger(p1);
    f1.addPassenger(p3);
    f1.addPassenger(p2);

    f2.addPassenger(p1);
    f2.addPassenger(p2);

    app.getAirline().addFlight(&f1);
    app.getAirline().addFlight(&f2);

    app.writeFlightsFile();

    EXPECT_EQ(1, true);
}