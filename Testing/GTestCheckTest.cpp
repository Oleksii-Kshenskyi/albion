#include "dummy.h"

#include "gtest/gtest.h"


// The fixture for testing class Foo.
class GTestCheckTest : public ::testing::Test {
 protected:
   DummyObject the_object;
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  GTestCheckTest() {
     // You can do set-up work for each test here.
  }

  ~GTestCheckTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(GTestCheckTest, SimpleCheckThatGTestIsProperlyLinked) {
  EXPECT_EQ(the_object.add(3,4), 7);
  EXPECT_EQ(the_object.add(220,-220), 0);
  EXPECT_EQ(the_object.add(450,-900), -450);
}

TEST_F(GTestCheckTest, DummyTestToTestMultipleGTestFixtures) {
  EXPECT_EQ(1,1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}