#pragma once

#include "../Pixel.hpp"

#include <vector>

class Image
{
public:
    Image() = default;
    virtual ~Image() = default;
    virtual void save(const std::string &path) const = 0;
    virtual void loadBitmap(const std::vector<char> &pixels) = 0;

    std::vector<std::vector<Pixel>> pixelMatrix;
    uint32_t width;
    uint32_t height;
};
