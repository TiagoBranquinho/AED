#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Plane.h"

using namespace std;
using testing::Eq;

TEST(test_1, createPlane){
    Plane p("A320", 324);
    cout << "Plane plate: " << p.getPlate() << endl;
    cout << "Plane capacity: " << p.getCapacity() << endl;
    EXPECT_EQ(p.getPlate(), "A320");

    try{
        Plane pl1 ("As20", 342);
    }
    catch (exception &e){
        cout << e.what() << endl;
    }
}