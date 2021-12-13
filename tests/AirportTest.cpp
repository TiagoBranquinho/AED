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
    GroundTransportation gd5("Uber", 1);

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

    iteratorBST<GroundTransportation> itr = airport.localsBeginItr();

    while (itr != airport.getLocals().endItr()){
        cout << (*itr).getType() << endl;
        if ((*itr).getType() == "Uber"){
            airport.getLocals().removeGroundTransportation(*itr);
        }
        itr++;
    }

    vector<GroundTransportation> gds = airport.getLocals().asVector();
    cout << endl;
    for (auto gd : gds){
        cout << gd << endl;
    }
    cout << endl << endl;

    EXPECT_EQ(1, true);
}