#pragma once

#include <algorithms/Algorithm.hpp>

#include <string>
#include <vector>

using PixelMask = std::vector<std::vector<int>>;

class Masking : public Algorithm
{
public:
    Masking(PixelMask mask);
    ~Masking() = default;

    void apply(Image &image) const override;

private:
    PixelMask _mask;
    uint32_t _width;
    uint32_t _height;
    int _sum;
};
