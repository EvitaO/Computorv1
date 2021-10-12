#include "gtest/gtest.h"
#include "header.hpp"
#include <cmath>

TEST(roottest, HandlesZeroInput){
    EXPECT_EQ(calculateroot(0), sqrt(0));
}

TEST(roottest, HandlesPositifinput){
    //EXPECT_EQ(calculateroot(2), sqrt(2));
    EXPECT_NEAR(calculateroot(2), sqrt(2), 0.0001);
    EXPECT_NEAR(calculateroot(124.134), sqrt(124.134), 0.0001);
    EXPECT_NEAR(calculateroot(1.484), sqrt(1.484), 0.0001);
    EXPECT_NEAR(calculateroot(48342.73833), sqrt(48342.73833), 0.0001);
}