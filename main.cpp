#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "include/Flight.h"

unsigned int Flight::numberBaggages = 0;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

