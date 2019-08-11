#pragma once

#include <stdint.h>
#include <string>

class RawPixel
{
public:
    RawPixel operator*(int d) const;
    RawPixel operator/(int d) const;
    RawPixel operator+(const RawPixel &rhs);
    void normalize();

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};
