#include "gtest/gtest.h"
#include "validate.hpp"

TEST(getDegree, ValidInput){
    validate x("3 * X^2 = 0");
    x.setup();
    EXPECT_EQ(x.getDegree(), 2);
    validate y("3.23 * X^2 - 2.5 * X^8 = 0");
    y.setup();
    EXPECT_EQ(y.getDegree(), 8);
    validate z("3 * X^0 = 1.78 * X^1");
    z.setup();
    EXPECT_EQ(z.getDegree(), 1);
    validate a("3 * X^1 + 21.34 * X^0 = 1 * X^2");
    a.setup();
    EXPECT_EQ(a.getDegree(), 2);
    validate b("0 * X^2 = 5 * X^1");
    b.setup();
    EXPECT_EQ(b.getDegree(), 1);
}

TEST(getDegree, InvalidInput){
    validate x("3 * X^2.3 = 0");
    EXPECT_THROW(x.setup(), std::exception);

    validate y("3.23 * X^-2 - 2.5 * X^8 = 0");
    EXPECT_THROW(y.setup(), std::exception);

    validate z("3 * X^0 = 1.78 * X^");
    EXPECT_THROW(z.setup(), std::exception);

}