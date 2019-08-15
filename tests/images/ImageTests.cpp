#include <gtest/gtest.h>
#include <images/ImagePpm.hpp>

TEST(ImageTests, getMatrixWithBorderTest)
{
    PixelMatrix matrix = {{{44, 81, 23}, {251, 34, 19}},
                          {{123, 221, 52}, {55, 22, 86}}};
    PixelMatrix expected1 = {{{44, 81, 23}, {44, 81, 23}, {251, 34, 19}, {251, 34, 19}},
                            {{44, 81, 23}, {44, 81, 23}, {251, 34, 19}, {251, 34, 19}},
                            {{123, 221, 52}, {123, 221, 52}, {55, 22, 86}, {55, 22, 86}},
                            {{123, 221, 52}, {123, 221, 52}, {55, 22, 86}, {55, 22, 86}}};
    PixelMatrix expected2 = {{{44, 81, 23}, {44, 81, 23}, {251, 34, 19}, {251, 34, 19}},
                            {{44, 81, 23}, {44, 81, 23}, {251, 34, 19}, {251, 34, 19}},
                            {{44, 81, 23}, {44, 81, 23}, {251, 34, 19}, {251, 34, 19}},
                            {{123, 221, 52}, {123, 221, 52}, {55, 22, 86}, {55, 22, 86}},
                            {{123, 221, 52}, {123, 221, 52}, {55, 22, 86}, {55, 22, 86}},
                            {{123, 221, 52}, {123, 221, 52}, {55, 22, 86}, {55, 22, 86}}};
    ImagePpm image;
    image.setPixelMatrix(std::move(matrix));

    auto result1 = image.getMatrixWithBorder(1, 1);
    auto result2 = image.getMatrixWithBorder(1, 2);

    EXPECT_EQ(result1, expected1);
    EXPECT_EQ(result2, expected2);
}
