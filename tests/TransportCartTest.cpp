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

    EXPECT_EQ(tc.getC(), 2);
    EXPECT_EQ(tc.getN(), 3);
    EXPECT_EQ(tc.getM(), 4);
    EXPECT_EQ(tc.getSlots().back().size(), 3);

    EXPECT_EQ(tc.addBaggage(Baggage()), true);

    EXPECT_EQ(tc.getSlots().size(), 2);
    EXPECT_EQ(tc.getSlots().front().size(), 3);
    EXPECT_EQ((tc.getSlots().front().front().size()), 1);
}