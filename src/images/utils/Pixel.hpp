#pragma once

#include <stdint.h>
#include <string>

class Pixel
{
public:
    std::string toString() const;
    Pixel operator*(int d) const;
    Pixel operator/(int d) const;
    Pixel operator+(const Pixel &rhs);
    void normalize();

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};
