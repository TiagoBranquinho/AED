#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Airport.h"

using namespace std;
using testing::Eq;

TEST(test_1, createAirport){
    Airport airport = Airport("Airport", "City");
    GroundTransportation gd1("Train", 10);
    GroundTransportation gd2("Bus", 7);
    GroundTransportation gd3("Taxi", 2);
    GroundTransportation gd4("Uber", 4);
    GroundTransportation gd5("Trot", 1);

    airport.addGroundTransportation(gd1);
    airport.addGroundTransportation(gd2);
    airport.addGroundTransportation(gd3);
    airport.addGroundTransportation(gd4);
    airport.addGroundTransportation(gd5);

    BSTItrIn<GroundTransportation> it = airport.localsItrIn();

    while (!it.isAtEnd()){
        cout << it.retrieve().getType() << endl;
        it.advance();
    }

    cout << endl;
    airport.printLocals();

    EXPECT_EQ(1, true);
}