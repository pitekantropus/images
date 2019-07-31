#pragma once

#include <stdint.h>
#include <string>

class Pixel
{
public:
    std::string toString() const;

    uint32_t xPos;
    uint32_t yPos;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint16_t alpha;
};
