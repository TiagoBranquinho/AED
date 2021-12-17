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