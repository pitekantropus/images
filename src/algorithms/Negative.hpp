#pragma once

#include <algorithms/Algorithm.hpp>

#include <string>

class Negative : public Algorithm
{
public:
    Negative() = default;
    ~Negative() = default;

    void apply(Image &image) const override;
};
