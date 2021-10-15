#include "gtest/gtest.h"
#include "polynomial.hpp"
#include "validate.hpp"

TEST(getABCD, ValidInput){
    validate a("3.3 * X^2 = - 5 * X^1 + 3 * X^2");
    try{
        a.setup();
        polynomial aa(a.getFloat(2), a.getFloat(1), a.getFloat(0), a.getDegree());
        EXPECT_FLOAT_EQ(aa.getA(), 0.3);
        EXPECT_FLOAT_EQ(aa.getB(), 5);
        EXPECT_FLOAT_EQ(aa.getC(), 0);
        EXPECT_EQ(aa.getDegree(), 2);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate b("0.5 * X^2 - 4 * X^1 = 0");
    try{
        b.setup();
        polynomial bb(b.getFloat(2), b.getFloat(1), b.getFloat(0), b.getDegree());
        EXPECT_FLOAT_EQ(bb.getA(), 0.5);
        EXPECT_FLOAT_EQ(bb.getB(), -4);
        EXPECT_FLOAT_EQ(bb.getC(), 0);
        EXPECT_EQ(bb.getDegree(), 2);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate c("7 * X^1 = 0.5 * X^0");
    try{
        c.setup();
        polynomial cc(c.getFloat(2), c.getFloat(1), c.getFloat(0), c.getDegree());
        EXPECT_FLOAT_EQ(cc.getA(), 0);
        EXPECT_FLOAT_EQ(cc.getB(), 7);
        EXPECT_FLOAT_EQ(cc.getC(), -0.5);
        EXPECT_EQ(cc.getDegree(), 1);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate d("- 7.5 * X^1 - 0.1667 * X^0 = - 2 * X^1 + 4 * X^2 + 0.1 * X^0");
    try{
        d.setup();
        polynomial dd(d.getFloat(2), d.getFloat(1), d.getFloat(0), d.getDegree());
        EXPECT_FLOAT_EQ(dd.getA(), -4);
        EXPECT_FLOAT_EQ(dd.getB(), -5.5);
        EXPECT_FLOAT_EQ(dd.getC(), -0.2667);
        EXPECT_EQ(dd.getDegree(), 2);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate e("- 3.5 * X^1 + 11 * X^0 = 3.333 * X^2 - 1 * X^1");
    try{
        e.setup();
        polynomial ee(e.getFloat(2), e.getFloat(1), e.getFloat(0), e.getDegree());
        EXPECT_FLOAT_EQ(ee.getA(), -3.333);
        EXPECT_FLOAT_EQ(ee.getB(), -2.5);
        EXPECT_FLOAT_EQ(ee.getC(), 11);
        EXPECT_EQ(ee.getDegree(), 2);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }
}