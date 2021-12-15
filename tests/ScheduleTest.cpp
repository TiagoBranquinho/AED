#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Schedule.h"

using namespace std;
using testing::Eq;

TEST(test_1, createSchedule){
    Schedule h1 = Schedule("11:02");
    Schedule h2 = Schedule("01:02");
    Schedule h3 = Schedule("21:23");

    EXPECT_EQ(h1.getTime(), "11:02");
    EXPECT_EQ(h2.getTime(), "01:02");
    EXPECT_EQ(h3.getTime(), "21:23");

    if (h1 < h2){
        std::cout << "h2 > h1" << std::endl;
        std::cout << h2.getHour() << ":" << h2.getMin() << std::endl;

    }
    else if (h1 < h3){
        std::cout << "h3 > h1" << std::endl;
        std::cout << h3.getHour() << ":" << h3.getMin() << std::endl;
    }
}

TEST(test_1, diffSchedule){
    Schedule h1 = Schedule("11:02");
    Schedule h2 = Schedule("01:02");
    Schedule h3 = Schedule("21:23");

    Schedule h1h2 = h1.diffTime(h2);
    Schedule h2h3 = h2.diffTime(h3);
    Schedule h3h1 = h1.diffTime(h3);
    Schedule h1h1 = h1.diffTime(h1);

    EXPECT_EQ(h1h2.getTime(), "10:00");
    EXPECT_EQ(h2h3.getTime(), "20:21");
    EXPECT_EQ(h3h1.getTime(), "10:21");
    EXPECT_EQ(h1h1.getTime(), "00:00");

}