#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Date.h"

using namespace std;
using testing::Eq;

TEST(test_1, createDate){
    try{
        Date s1(29,2,2024);
        cout << s1.getDate() << endl;
    } catch (exception &e){
        cout << e.what() << endl;
    }

    Date s1(29,2,2024);
    Date s2(1,12,2020);
    Date s3(28,2,2021);

    EXPECT_EQ(s2 < s3, true);
    EXPECT_EQ(s2 < s1, true);
    EXPECT_EQ(s3 < s1, true);
}

TEST(test_1, setDate){
    Date s1(29,2,2024);

    s1.setDate("2012/03/14");
    EXPECT_EQ(s1.getYear(), 2012);
    EXPECT_EQ(s1.getMonth(), 3);
    EXPECT_EQ(s1.getDay(), 14);
}