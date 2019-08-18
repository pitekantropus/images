#pragma once

#include <algorithms/Algorithm.hpp>

#include <string>

class Shading : public Algorithm
{
public:
    Shading() = default;
    ~Shading() = default;

    void apply(Image &image) const override;
};
