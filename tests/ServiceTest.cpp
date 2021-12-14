#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Service.h"

using namespace std;
using testing::Eq;

TEST(test_1, createService){
    Service s1("maintenance", Date(12,3,1223), new Employee("Jose Manuel", "maintenance"));
    Service s2("cleaner", Date(23,5,1223), new Employee("Maria Leal", "cleaner"));
    Service s3("maintenance", Date(12,11,1223), new Employee("Jose Cardoso", "maintenance"));

    cout << s1.getDate().getDay() << "/" << s1.getDate().getMonth() << "/" << s1.getDate().getYear() << endl;

    EXPECT_EQ(s1.getDate().getDay(), 12);
    EXPECT_EQ(s1.getDate().getMonth(), 3);
    EXPECT_EQ(s1.getDate().getYear(), 1223);
    EXPECT_EQ(s2.getType(), "cleaner");
    EXPECT_EQ(s3.getType(), "maintenance");
}