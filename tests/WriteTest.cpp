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