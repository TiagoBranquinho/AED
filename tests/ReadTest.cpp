#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Airport.h"
#include "../include/App.h"

using namespace std;
using testing::Eq;

TEST(test_1, readAirports){
    App app;
    app.readAirportsFile();

    for (auto air : app.airports){
        cout << air.getName() << " " << air.getCity() << endl;
        auto it = air.localsBeginItr();
        while(it != air.localsEndItr()){
            cout << (*it).getType() << " " << (*it).getDistance() << "Km" << endl;
            (*it).printSchedules();
            it++;
        }
    }

    EXPECT_EQ(1, true);
}

TEST(test_1, readFlights){
    App app;
    app.readAirportsFile();
    app.readFlightsFile();
    string origin, destiny;

    for (auto &f : app.getAirline().getFlights()){
        cout << "Flight Number: " << f.getNumber() << " - from ";
        cout << f.getOriginAir()->getCity() << " to " << f.getDestinyAir()->getCity() << endl;
        cout << "passangers:" << endl;
        for (auto &p : f.getPassengers()){
            cout << p.getName() << "  bag: " << p.getBaggage()->getWeight() << "kg"<< endl;
        }
    }

    EXPECT_EQ(1, true);
}