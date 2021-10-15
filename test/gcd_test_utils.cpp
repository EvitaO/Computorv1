#include "gtest/gtest.h"
#include "header.hpp"

TEST(gcd, HandlesZeroInput){
    EXPECT_EQ(gcd(0,0), 0);
    EXPECT_EQ(gcd(1,0), 1);
}

TEST(gcd, HandlesPositiveInput){
    EXPECT_EQ(gcd(234, 675), 9);
    EXPECT_EQ(gcd(8152,136634), 2);
    EXPECT_EQ(gcd(74,3), 1);
    EXPECT_EQ(gcd(81,39), 3);
    EXPECT_EQ(gcd(65,55), 5);
    EXPECT_EQ(gcd(746,138), 2);
}

TEST(gcd, HandlesNegativeInput){
    EXPECT_EQ(gcd(-893, -138), 1);
    EXPECT_EQ(gcd(-12,-634), 2);
    EXPECT_EQ(gcd(-784,-343), 49);
    EXPECT_EQ(gcd(-512,-9), 1);
    EXPECT_EQ(gcd(-645,-52), 1);
    EXPECT_EQ(gcd(-76,-18), 2);
}