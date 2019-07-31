#pragma once

#include "../Pixel.hpp"

#include <vector>
#include <functional>

class Image
{
public:
    Image() = default;
    virtual ~Image() = default;
    virtual void saveAsText(const std::string &path) const = 0;
    virtual void saveBinary(const std::string &path) const = 0;
    virtual void loadBitmap(const std::vector<char> &pixels) = 0;
    void forEachPixel(std::function<void(Pixel&)> function);

    std::vector<std::vector<Pixel>> pixelMatrix;
    uint32_t width;
    uint32_t height;
};
