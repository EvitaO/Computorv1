#include "gtest/gtest.h"
#include "../header.hpp"

TEST(roottest, HandlesZeroInput){
    EXPECT_NEAR(calculateroot(0), 0, 0.01);
}

TEST(roottest, HandlesPositifinput){
    EXPECT_NEAR(calculateroot(2), 1.414, 0.0002);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}