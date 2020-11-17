#include "gtest/gtest.h"

class BasicPositionalArgumentParsingChecksTest : public ::testing::Test 
{
    protected:
        albion::App the_app;

        BasicPositionalArgumentParsingChecksTest(): the_app(
            albion::App("Positional Argument Test").
                version("1.0.0").
                author("Oleksii Kshenskyi").
                argument(
                    albion::Arg().
                        short_name("f").
                        long_name("first").
                        required(true)
                ).
                argument(
                    albion::Arg().
                        short_name("k").
                        long_name("kekw").
                        required(true)
                )
        )
        {}

        ~BasicPositionalArgumentParsingChecksTest() override {}

        void SetUp() override
        {
        }

        void TearDown() override {}
};

TEST_F(BasicPositionalArgumentParsingChecksTest, DummyCheck) 
{
    std::vector<std::string> vargv { "BasicPositionalArgumentParsingChecksTest", "first_val", "kekw_val" };
    albion::Matches matches = the_app.get_matches(vargv.size(), albion::util::vec_to_ptr_to_cstrs(vargv.size(), vargv));
    ASSERT_TRUE(matches.exists("f"));
    ASSERT_TRUE(matches.exists("k"));
    ASSERT_TRUE(matches.exists("first"));
    ASSERT_TRUE(matches.exists("kekw"));
    ASSERT_FALSE(matches.exists("r"));
    ASSERT_FALSE(matches.exists("random"));

    ASSERT_EQ("first_val", matches.value_of("first"));
    ASSERT_EQ("first_val", matches.value_of("f"));
    ASSERT_EQ("kekw_val", matches.value_of("kekw"));
    ASSERT_EQ("kekw_val", matches.value_of("k"));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}