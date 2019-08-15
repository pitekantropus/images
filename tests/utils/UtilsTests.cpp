#include <gtest/gtest.h>
#include <utils/Utils.hpp>

TEST(UtilsTest, SplitTest)
{
    Item expected = {"key", "value"};
    std::string input = "key=value";
    EXPECT_EQ(split(input, '='), expected);

    expected = {"a", "bcd,efg"};
    input = "a,bcd,efg";
    EXPECT_EQ(split(input, ','), expected);
}

TEST(UtilsTest, TokenizeTest)
{
    std::vector<Item> expected = {{"key", "value"}, {"a", "bcd=efg"}};
    std::vector<std::string> input = {"key=value", "a=bcd=efg"};
    EXPECT_EQ(tokenize(input), expected);

    expected = {{"klucz", "wartosc"}};
    input = {"klucz=wartosc"};
    EXPECT_EQ(tokenize(input), expected);
}
