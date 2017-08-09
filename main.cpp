#include <iostream>
#include "gtest.h"
#include "manacher.h"
using namespace std;

TEST(Gtest, ManacherTest){
    EXPECT_EQ(5, manacher("abcddddabcdcb"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}