#pragma once

#include "Pixel.hpp"

#include <vector>

class Image
{
public:

// private:
    std::vector<std::vector<Pixel>> pixelMatrix;
    uint32_t width;
    uint32_t height;
};
