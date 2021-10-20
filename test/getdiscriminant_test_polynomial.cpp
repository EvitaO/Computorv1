#include "gtest/gtest.h"
#include "polynomial.hpp"
#include "validate.hpp"

TEST(getDiscriminant, ValidInput){
    validate a("3.3 * X^2 = - 5 * X^1 + 3 * X^2");
    try{
        a.setup();
        polynomial aa(a.getFloat(2), a.getFloat(1), a.getFloat(0), a.getDegree());
        aa.solvePolynomial();
        EXPECT_FLOAT_EQ(aa.getDiscriminant(), 25);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate b("- 7.5 * X^1 - 0.1667 * X^0 = - 2 * X^1 + 4 * X^2 + 0.1 * X^0");
    try{
        b.setup();
        polynomial bb(b.getFloat(2), b.getFloat(1), b.getFloat(0), b.getDegree());
        bb.solvePolynomial();
        EXPECT_FLOAT_EQ(bb.getDiscriminant(), 64957.0/2500.0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate c("- 3.5 * X^1 + 11 * X^0 = 3.333 * X^2 - 1 * X^1");
    try{
        c.setup();
        polynomial cc(c.getFloat(2), c.getFloat(1), c.getFloat(0), c.getDegree());
        cc.solvePolynomial();
        EXPECT_FLOAT_EQ(cc.getDiscriminant(), 76451.0/500.0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate d("0.5 * X^2 - 4 * X^1 = 0");
    try{
        d.setup();
        polynomial dd(d.getFloat(2), d.getFloat(1), d.getFloat(0), d.getDegree());
        dd.solvePolynomial();
        EXPECT_EQ(dd.getDiscriminant(), 16);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }
}