#include "gtest/gtest.h"
#include "polynomial.hpp"
#include "validate.hpp"
#include <cmath>

TEST(getSolutions, ValidInputDegree2){
    validate a("3.3 * X^2 = - 5 * X^1 + 3 * X^2");
    try{
        a.setup();
        polynomial aa(a.getFloat(2), a.getFloat(1), a.getFloat(0), a.getDegree());
        aa.solvePolynomial();
        EXPECT_EQ(aa.getSolutions()[0], 0);
        EXPECT_FLOAT_EQ(aa.getSolutions()[1], -50.0/3.0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate b("- 7.5 * X^1 - 0.1667 * X^0 = - 2 * X^1 + 4 * X^2 + 0.1 * X^0");
    try{
        b.setup();
        polynomial bb(b.getFloat(2), b.getFloat(1), b.getFloat(0), b.getDegree());
        bb.solvePolynomial();
        EXPECT_FLOAT_EQ(bb.getSolutions()[0], (-5.5 - sqrt(25.9828))/8);
        EXPECT_FLOAT_EQ(bb.getSolutions()[1], (-5.5 + sqrt(25.9828))/8);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate c("- 3.5 * X^1 + 11 * X^0 = 3.333 * X^2 - 1 * X^1");
    try{
        c.setup();
        polynomial cc(c.getFloat(2), c.getFloat(1), c.getFloat(0), c.getDegree());
        cc.solvePolynomial();
        EXPECT_FLOAT_EQ(cc.getSolutions()[0], (-2.5 - sqrt(152.902))/6.666);
        EXPECT_FLOAT_EQ(cc.getSolutions()[1], (-2.5 + sqrt(152.902))/6.666);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate d("0.5 * X^2 - 4 * X^1 = 0");
    try{
        d.setup();
        polynomial dd(d.getFloat(2), d.getFloat(1), d.getFloat(0), d.getDegree());
        dd.solvePolynomial();
        EXPECT_EQ(dd.getSolutions()[0], 8);
        EXPECT_EQ(dd.getSolutions()[1], 0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate e("2.3 * X^1 - 9.8 * X^1 = 5 * X^2 + 3.333 * X^1");
    try{
        e.setup();
        polynomial ee(e.getFloat(2), e.getFloat(1), e.getFloat(0), e.getDegree());
        ee.solvePolynomial();
        EXPECT_FLOAT_EQ(ee.getSolutions()[0], -(21.666/10));
        EXPECT_EQ(ee.getSolutions()[1], 0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate f("45.234 * X^1 - 2 * X^2 = - 2 * X^2 + 3.35 * X^1");
    try{
        f.setup();
        polynomial ff(f.getFloat(2), f.getFloat(1), f.getFloat(0), f.getDegree());
        ff.solvePolynomial();
        EXPECT_EQ(ff.getSolutions()[0], 0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate g("- 9.3 * X^1 + 2 * X^2 = 0.1 * X^1 + .3 * X^1");
    try{
        g.setup();
        polynomial gg(g.getFloat(2), g.getFloat(1), g.getFloat(0), g.getDegree());
        gg.solvePolynomial();
        EXPECT_FLOAT_EQ(gg.getSolutions()[0], 97.0/20.0);
        EXPECT_FLOAT_EQ(gg.getSolutions()[1], 0.0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }
}

TEST(getSolutions, ValidInputDegree1){
    validate a("3.3 * X^0 = - 5 * X^1 + 3 * X^1");
    try{
        a.setup();
        polynomial aa(a.getFloat(2), a.getFloat(1), a.getFloat(0), a.getDegree());
        aa.solvePolynomial();
        EXPECT_FLOAT_EQ(aa.getSolutions()[0], -1.65);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate b("- 7.5 * X^1 - 0.1667 * X^0 = - 2 * X^1 + 4 * X^0 + 0.1 * X^0");
    try{
        b.setup();
        polynomial bb(b.getFloat(2), b.getFloat(1), b.getFloat(0), b.getDegree());
        bb.solvePolynomial();
        EXPECT_FLOAT_EQ(bb.getSolutions()[0], (-4.2667/5.5));
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate c("- 3.5 * X^1 + 11 * X^0 = 3.333 * X^1 - 1 * X^1");
    try{
        c.setup();
        polynomial cc(c.getFloat(2), c.getFloat(1), c.getFloat(0), c.getDegree());
        cc.solvePolynomial();
        EXPECT_FLOAT_EQ(cc.getSolutions()[0], (11000/5833.0));
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate d("0.5 * X^0 - 4 * X^1 = 0");
    try{
        d.setup();
        polynomial dd(d.getFloat(2), d.getFloat(1), d.getFloat(0), d.getDegree());
        dd.solvePolynomial();
        EXPECT_EQ(dd.getSolutions()[0], 0.125);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate e("2.3 * X^1 - 9.8 * X^1 = 5 * X^0 + 3.333 * X^1");
    try{
        e.setup();
        polynomial ee(e.getFloat(2), e.getFloat(1), e.getFloat(0), e.getDegree());
        ee.solvePolynomial();
        EXPECT_FLOAT_EQ(ee.getSolutions()[0], -(5/10.833));
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate f("45.234 * X^1 - 2 * X^0 = - 2 * X^1 + 3.35 * X^1");
    try{
        f.setup();
        polynomial ff(f.getFloat(2), f.getFloat(1), f.getFloat(0), f.getDegree());
        ff.solvePolynomial();
        EXPECT_FLOAT_EQ(ff.getSolutions()[0], 500.0/10971);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate g("- 9.3 * X^1 + 2 * X^1 = 0.1 * X^1 + .3 * X^1");
    try{
        g.setup();
        polynomial gg(g.getFloat(2), g.getFloat(1), g.getFloat(0), g.getDegree());
        gg.solvePolynomial();
        EXPECT_EQ(gg.getSolutions()[0], 0);
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }
}

TEST(getSolutions, ValidInputDegree0){
    validate a("3.3 * X^0 = - 5 * X^0 + 3 * X^0");
    try{
        a.setup();
        polynomial aa(a.getFloat(2), a.getFloat(1), a.getFloat(0), a.getDegree());
        aa.solvePolynomial();
        EXPECT_EQ(aa.getOutputDegree01(), "No solution possible");
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }

    validate b("3.3 * X^0 = 3.3 * X^0");
    try{
        b.setup();
        polynomial bb(b.getFloat(2), b.getFloat(1), b.getFloat(0), b.getDegree());
        bb.solvePolynomial();
        EXPECT_EQ(bb.getOutputDegree01(), "Every real number is a solutions");
    }
    catch (std::exception & e){
        EXPECT_TRUE(false);
    }
}