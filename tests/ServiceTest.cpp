#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Service.h"

using namespace std;
using testing::Eq;

TEST(test_1, createService){
    Service s1("maintenance", Employee("Jose Manuel", "maintenance"));
    Service s2("cleaner", Employee("Maria Leal", "cleaner"));
    Service s3("maintenance", Employee("Jose Cardoso", "maintenance"));

    cout << s1.getDate().getDay() << "/" << s1.getDate().getMonth() << "/" << s1.getDate().getYear() << endl;

    EXPECT_EQ(s1.getDate().getDay(), 14);
    EXPECT_EQ(s1.getDate().getMonth(), 12);
    EXPECT_EQ(s1.getDate().getYear(), 2021);
    EXPECT_EQ(s2.getType(), "cleaner");
    EXPECT_EQ(s3.getType(), "maintenance");
}