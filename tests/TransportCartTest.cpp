//
// Created by User on 14/12/2021.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/TransportCart.h"

using namespace std;
using testing::Eq;

TEST(test_1, createCart) {
    TransportCart tc = TransportCart(2,3,4);
    Baggage bg1(20, false);
    Baggage bg2(12, false);

    EXPECT_EQ(tc.getC(), 2);
    EXPECT_EQ(tc.getN(), 3);
    EXPECT_EQ(tc.getM(), 4);
    EXPECT_EQ(tc.getSlots().back().size(), 3);

    EXPECT_EQ(tc.addBaggage(bg1), true);
    EXPECT_EQ(tc.addBaggage(bg2), true);

    EXPECT_EQ(tc.getSlots().size(), 2);
    EXPECT_EQ(tc.getSlots().front().size(), 3);
    EXPECT_EQ((tc.getSlots().front().front().size()), 2);
}