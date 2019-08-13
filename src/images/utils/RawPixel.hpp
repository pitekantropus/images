#pragma once

#include <images/utils/Pixel.hpp>

#include <stdint.h>
#include <string>

class RawPixel
{
public:
    RawPixel() = default;
    RawPixel(const Pixel &rhs);
    RawPixel operator*(int d) const;
    RawPixel operator/(int d) const;
    RawPixel operator+(const RawPixel &rhs) const;
    void normalize();
    Pixel getPixel() const;

    std::string toString() const;

    int32_t red;
    int32_t green;
    int32_t blue;
    uint8_t alpha;

private:
    void normalizeOne(int32_t &color);
};
