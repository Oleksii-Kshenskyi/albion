#include "gtest/gtest.h"

class BasicPositionalArgumentParsingChecksTest : public ::testing::Test 
{
    protected:
        BasicPositionalArgumentParsingChecksTest() {}

        ~BasicPositionalArgumentParsingChecksTest() override {}

        void SetUp() override {}

        void TearDown() override {}
};

TEST_F(BasicPositionalArgumentParsingChecksTest, DummyCheck) 
{
    EXPECT_EQ(2, 2);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}