#include "gtest/gtest.h"
#include "validate.hpp"

TEST(getReduced, ValidInput){
    validate x("3 * X^2 = - 1 * X^1 + 0.5 * X^3 - 16 * X^2");
    x.setup();
    EXPECT_EQ(x.getReduced(), std::string("19 * X^2 + 1 * X^1 - 0.5 * X^3 = 0\n"));
    validate y("3.23 * X^2 - 2.5 * X^1 = 7 * X^1 - 0 * X^0");
    y.setup();
    EXPECT_EQ(y.getReduced(), std::string("3.23 * X^2 - 9.5 * X^1 = 0\n"));
    validate z("3 * X^0 = 1.78 * X^1");
    z.setup();
    EXPECT_EQ(z.getReduced(), std::string("3 * X^0 - 1.78 * X^1 = 0\n"));
    validate a("3 * X^1 + 21.34 * X^0 = 1 * X^2");
    a.setup();
    EXPECT_EQ(a.getReduced(), std::string("3 * X^1 + 21.34 * X^0 - 1 * X^2 = 0\n"));
    validate b("0 * X^2 = 5 * X^1");
    b.setup();
    EXPECT_EQ(b.getReduced(), std::string("- 5 * X^1 = 0\n"));
}