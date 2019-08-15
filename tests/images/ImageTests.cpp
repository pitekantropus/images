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

TEST(ImageTests, forEachPixelTest)
{
    PixelMatrix matrix = {{{44, 81, 23}, {251, 34, 19}},
                          {{123, 221, 52}, {55, 22, 86}}};
    PixelMatrix expected = {{{46, 85, 29}, {253, 38, 25}},
                          {{125, 225, 58}, {57, 26, 92}}};

    ImagePpm image;
    image.setPixelMatrix(std::move(matrix));
    image.forEachPixel([](Pixel& pixel){
        pixel.red += 2;
        pixel.green += 4;
        pixel.blue += 6;
    });

    EXPECT_EQ(image.getPixelMatrix(), expected);
}
