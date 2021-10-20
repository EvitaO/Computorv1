#include "gtest/gtest.h"
#include "utils.hpp"
#include <cmath>

TEST(roottest, HandlesZeroInput){
    EXPECT_EQ(calculateRoot(0), sqrt(0));
    EXPECT_EQ(calculateRoot(-0), sqrt(-0));
}

TEST(roottest, HandlesPositiveInput){
    EXPECT_FLOAT_EQ(calculateRoot(2), sqrt(2));
    EXPECT_FLOAT_EQ(calculateRoot(124.134), sqrt(124.134));
    EXPECT_FLOAT_EQ(calculateRoot(1.484), sqrt(1.484));
    EXPECT_FLOAT_EQ(calculateRoot(48342.73833), sqrt(48342.73833));
    EXPECT_FLOAT_EQ(calculateRoot(2341443494.3455), sqrt(2341443494.3455));
}

TEST(roottest, HandlesNegativeInput){
    EXPECT_EQ(isnan(calculateRoot(-42.73833)), isnan(sqrt(-42.73833)));
}