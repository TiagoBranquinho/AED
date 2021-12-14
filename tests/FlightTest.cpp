#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Flight.h"

using namespace std;
using testing::Eq;

TEST(test_1, createFlight){
    Date date = Date(12,3,2020);
    Flight f = Flight(23, date , 3, "Porto", "Lisbon");
    cout << "Flight number: " << f.getNumber() << endl;
    cout << f.getOrigin() << " to " << f.getDestiny() << endl;
    cout << f.getNumberPassengers() << " passengers " << endl;
    f.openCheckIn();

    EXPECT_EQ(f.getCheckInStatus(), true);
}
