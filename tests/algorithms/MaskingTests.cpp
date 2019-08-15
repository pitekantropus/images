#include <gtest/gtest.h>
#include <images/ImagePpm.hpp>
#include <memory>

#define private public
#include <algorithms/Masking.hpp>
#undef private


TEST(MaskingTests, applyMaskTest1)
{
    PixelMatrix matrix = {{{44, 81, 23}, {251, 34, 19}},
                          {{123, 221, 52}, {55, 22, 86}}};
    PixelMatrix expected = {{{44, 81, 23}, {44, 81, 23}},
                            {{44, 81, 23}, {44, 81, 23}}};
    std::unique_ptr<Image> image = std::make_unique<ImagePpm>();
    image->setPixelMatrix(std::move(matrix));

    Masking mask({{1, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0}});

    mask.applyMask(image);
    EXPECT_EQ(expected, image->getPixelMatrix());
}

TEST(MaskingTests, applyMaskTest2)
{
    PixelMatrix matrix = {{{44, 81, 23}, {251, 34, 19}},
                          {{123, 221, 52}, {55, 22, 86}}};
    std::unique_ptr<Image> image = std::make_unique<ImagePpm>();
    image->setPixelMatrix(matrix);

    Masking mask({{0, 0, 0},
                  {0, 1, 0},
                  {0, 0, 0}});

    mask.applyMask(image);
    EXPECT_EQ(matrix, image->getPixelMatrix());
}