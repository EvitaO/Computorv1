#include "gtest/gtest.h"
#include "header.hpp"
#include <cmath>

TEST(roottest, HandlesZeroInput){
    EXPECT_EQ(calculateroot(0), sqrt(0));
    EXPECT_EQ(calculateroot(-0), sqrt(-0));
}

TEST(roottest, HandlesPositiveInput){
    EXPECT_FLOAT_EQ(calculateroot(2), sqrt(2));
    EXPECT_FLOAT_EQ(calculateroot(124.134), sqrt(124.134));
    EXPECT_FLOAT_EQ(calculateroot(1.484), sqrt(1.484));
    EXPECT_FLOAT_EQ(calculateroot(48342.73833), sqrt(48342.73833));
    EXPECT_FLOAT_EQ(calculateroot(2341443494.3455), sqrt(2341443494.3455));
}

TEST(roottest, HandlesNegativeInput){
    EXPECT_EQ(isnan(calculateroot(-42.73833)), isnan(sqrt(-42.73833)));
}